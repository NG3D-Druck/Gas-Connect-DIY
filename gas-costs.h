#pragma once

// Date helpers for the costs package (gas-costs.yaml). Pure functions only,
// so they can also be tested on the PC (see test/gas-costs-test.cpp).

#include <algorithm>
#include <cstdint>

namespace gas_costs {

// Periods of the consumption, energy and cost statistics
enum Period : int { DAY = 0, WEEK, MONTH, YEAR, BILLING, PERIOD_COUNT };

// Share of the yearly heating demand per month in ‰ (degree days, VDI 2067,
// as used for heating cost bills), January first
static constexpr double HEATING_PER_MILLE[12] = {170, 150, 130, 80, 40, 13.33, 13.33, 13.34, 30, 80, 120, 160};
// Part of the gas used evenly over the year, mainly for hot water
static constexpr double EVEN_SHARE = 0.15;

inline bool is_leap_year(int y) { return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0; }

inline int days_in_month(int y, int m) {
  static constexpr int DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return m == 2 && is_leap_year(y) ? 29 : DAYS[m - 1];
}

// Days since 1970-01-01 (H. Hinnant's days_from_civil)
inline int32_t days_from_civil(int y, int m, int d) {
  y -= m <= 2;
  const int era = (y >= 0 ? y : y - 399) / 400;
  const int yoe = y - era * 400;
  const int doy = (153 * (m + (m > 2 ? -3 : 9)) + 2) / 5 + d - 1;
  const int doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
  return era * 146097 + doe - 719468;
}

// Day the billing year starts in month m of year y: the set start day, or the
// last day of the month if the month is shorter
inline int billing_day(int y, int m, int start_day) { return std::min(start_day, days_in_month(y, m)); }

// Year in which the billing year containing the date y-m-d started
inline int billing_year(int y, int m, int d, int start_month, int start_day) {
  if (m > start_month || (m == start_month && d >= billing_day(y, m, start_day)))
    return y;
  return y - 1;
}

inline int32_t billing_start(int by, int start_month, int start_day) {
  return days_from_civil(by, start_month, billing_day(by, start_month, start_day));
}

// Key of the period containing the date y-m-d (dow: 1 = Sunday ... 7 = Saturday)
// day: days since 1970, week: day of its Monday, month: y * 100 + m,
// year: y, billing year: the year it started in
inline uint32_t period_key(int p, int y, int m, int d, int dow, int start_month, int start_day) {
  const int32_t day = days_from_civil(y, m, d);
  switch (p) {
    case DAY:
      return day;
    case WEEK:
      return day - (dow + 5) % 7;
    case MONTH:
      return y * 100 + m;
    case YEAR:
      return y;
    default:
      return billing_year(y, m, d, start_month, start_day);
  }
}

// Key of the period following the period with the given key
inline uint32_t next_key(int p, uint32_t key) {
  switch (p) {
    case WEEK:
      return key + 7;
    case MONTH:
      return key % 100 == 12 ? (key / 100 + 1) * 100 + 1 : key + 1;
    default:
      return key + 1;
  }
}

// First day (days since 1970) of the period with the given key
inline int32_t period_start(int p, uint32_t key, int start_month, int start_day) {
  switch (p) {
    case DAY:
    case WEEK:
      return key;
    case MONTH:
      return days_from_civil(key / 100, key % 100, 1);
    case YEAR:
      return days_from_civil(key, 1, 1);
    default:
      return billing_start(key, start_month, start_day);
  }
}

// Length of the period with the given key in days
inline int period_days(int p, uint32_t key, int start_month, int start_day) {
  return period_start(p, next_key(p, key), start_month, start_day) - period_start(p, key, start_month, start_day);
}

// Expected share of the yearly gas consumption for one day of month m
inline double day_share(int y, int m) {
  return ((1 - EVEN_SHARE) * HEATING_PER_MILLE[m - 1] / 1000 + EVEN_SHARE / 12) / days_in_month(y, m);
}

// Expected share of the yearly consumption used from the start of the billing
// year until the date y-m-d plus the fraction day_fraction of that day
inline double billing_share_elapsed(int y, int m, int d, double day_fraction, int start_month, int start_day) {
  const int by = billing_year(y, m, d, start_month, start_day);
  int cy = by, cm = start_month, cd = billing_day(by, start_month, start_day);
  double share = 0;
  // At most one year of days
  for (int i = 0; i < 366 && !(cy == y && cm == m && cd == d); i++) {
    share += day_share(cy, cm);
    if (++cd > days_in_month(cy, cm)) {
      cd = 1;
      if (++cm > 12) {
        cm = 1;
        cy++;
      }
    }
  }
  return share + day_share(y, m) * day_fraction;
}

// Number of monthly installments due in the billing year up to the date y-m-d,
// counting one at the start of each month of the billing year
inline int installments_due(int y, int m, int d, int start_month, int start_day) {
  const int by = billing_year(y, m, d, start_month, start_day);
  int n = (y * 12 + m) - (by * 12 + start_month);
  if (d >= billing_day(y, m, start_day))
    n++;
  return std::max(0, std::min(12, n));
}

}  // namespace gas_costs
