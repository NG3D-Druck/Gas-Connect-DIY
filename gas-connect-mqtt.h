#pragma once

#include <esp_attr.h>
#include <esp_system.h>

// Survives a software restart (not a power cycle): lets "Save and restart"
// keep the settings window open for the rest of its 15 minutes
static constexpr uint32_t SETTINGS_WINDOW_MAGIC = 0x53455457;  // "SETW"
static RTC_NOINIT_ATTR uint32_t settings_window_magic;
static RTC_NOINIT_ATTR uint32_t settings_window_left_ms;
