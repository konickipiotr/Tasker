#pragma once

enum class Type
{
    ONCE,
    EVERY_DAY,
    EVERYD_RAND
};

enum class Priority
{
    MEDIUM,
    HIGH,
    LOW
};

enum class Deadline
{
    NONE,
    TODAY,
    TOMORROW,
    YESTERDAY
};

enum class DayOfWeek
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};