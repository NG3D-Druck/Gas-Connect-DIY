// Tests for gas-costs.h on the PC, see test/run-tests.ps1
#include <cmath>
#include <cstdio>
#include <ctime>

#include "../gas-costs.h"

using namespace gas_costs;

static int failures = 0;

#define CHECK(cond)                                         \
  do {                                                      \
    if (!(cond)) {                                          \
      std::printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); \
      failures++;                                           \
    }                                                       \
  } while (0)

static bool near(double a, double b, double eps = 1e-6) { return std::fabs(a - b) < eps; }

// Days since 1970 and weekday (1 = Sunday) from the C library, as reference
static void reference(int y, int m, int d, int32_t &days, int &dow) {
  std::tm t{};
  t.tm_year = y - 1900;
  t.tm_mon = m - 1;
  t.tm_mday = d;
  t.tm_hour = 12;
  const std::time_t s = _mkgmtime(&t);
  days = (int32_t) (s / 86400);
  dow = t.tm_wday + 1;
}

int main() {
  // Calendar
  CHECK(days_from_civil(1970, 1, 1) == 0);
  CHECK(days_in_month(2028, 2) == 29 && days_in_month(2100, 2) == 28 && days_in_month(2000, 2) == 29);
  for (int y = 2019; y <= 2040; y++)
    for (int m = 1; m <= 12; m++)
      for (int d = 1; d <= days_in_month(y, m); d++) {
        int32_t days;
        int dow;
        reference(y, m, d, days, dow);
        CHECK(days_from_civil(y, m, d) == days);
        // The week starts on Monday
        const uint32_t week = period_key(WEEK, y, m, d, dow, 1, 1);
        CHECK(week <= (uint32_t) days && (uint32_t) days - week < 7);
        std::tm t{};
        const std::time_t s = (std::time_t) week * 86400;
        gmtime_s(&t, &s);
        CHECK(t.tm_wday == 1);
      }

  // Period keys and lengths
  CHECK(next_key(MONTH, 202612) == 202701 && next_key(MONTH, 202611) == 202612);
  CHECK(period_days(MONTH, 202802, 1, 1) == 29);
  CHECK(period_days(YEAR, 2028, 1, 1) == 366 && period_days(YEAR, 2027, 1, 1) == 365);
  CHECK(period_days(WEEK, period_key(WEEK, 2026, 11, 21, 7, 1, 1), 1, 1) == 7);
  CHECK(period_days(DAY, 20000, 1, 1) == 1);
  CHECK(period_days(BILLING, 2026, 10, 1) == 365);
  // Start on 29 February: 28 February in other years
  CHECK(period_start(BILLING, 2027, 2, 29) == days_from_civil(2027, 2, 28));
  CHECK(period_days(BILLING, 2027, 2, 29) == 366);
  // Start on 31 April does not exist: 30 April
  CHECK(billing_year(2026, 4, 30, 4, 31) == 2026 && billing_year(2026, 4, 29, 4, 31) == 2025);

  // Billing year
  CHECK(billing_year(2026, 10, 14, 10, 15) == 2025);
  CHECK(billing_year(2026, 10, 15, 10, 15) == 2026);
  CHECK(billing_year(2026, 1, 1, 1, 1) == 2026 && billing_year(2026, 12, 31, 1, 1) == 2026);

  // Share of the year: 0 at the start, 1 at the end, monotonic
  for (int sm = 1; sm <= 12; sm++) {
    const int sd = 1 + sm * 2;  // 3 ... 25
    CHECK(near(billing_share_elapsed(2026, sm, sd, 0, sm, sd), 0));
    // Last day of the billing year, completely
    const int32_t last = billing_start(2027, sm, sd) - 1;
    std::tm t{};
    const std::time_t s = (std::time_t) last * 86400;
    gmtime_s(&t, &s);
    const double full = billing_share_elapsed(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, 1, sm, sd);
    CHECK(near(full, 1, 0.002));
    double prev = -1;
    for (int32_t day = billing_start(2026, sm, sd); day <= last; day++) {
      const std::time_t ds = (std::time_t) day * 86400;
      gmtime_s(&t, &ds);
      const double share = billing_share_elapsed(t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, 0, sm, sd);
      CHECK(share > prev);
      prev = share;
    }
  }
  // Calendar year until 1 July: January to June
  const double first_half = 0.85 * (170 + 150 + 130 + 80 + 40 + 13.33) / 1000 + 0.15 * 6 / 12;
  CHECK(near(billing_share_elapsed(2026, 7, 1, 0, 1, 1), first_half));
  // Winter days count more than summer days
  CHECK(day_share(2026, 1) > 5 * day_share(2026, 7));

  // Installments
  CHECK(installments_due(2026, 1, 1, 1, 1) == 1);
  CHECK(installments_due(2026, 12, 31, 1, 1) == 12);
  CHECK(installments_due(2026, 10, 15, 10, 15) == 1);
  CHECK(installments_due(2026, 11, 14, 10, 15) == 1);
  CHECK(installments_due(2026, 11, 15, 10, 15) == 2);
  CHECK(installments_due(2027, 10, 14, 10, 15) == 12);

  if (failures == 0) std::printf("All tests passed\n");
  return failures == 0 ? 0 : 1;
}
