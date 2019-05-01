#include "EveryDay.hpp"

EveryDay::EveryDay(std::string _taskName)
    : Task{_taskName},
        todayTomorrow{TodayTomorrow::TOMORROW}
{
    type = Type::EVERY_DAY;
    isFinished = true;
}

TodayTomorrow EveryDay::getTodayTomorrow() const
{
    return todayTomorrow;
}

void EveryDay::finishTask()
{
    if(TodayTomorrow::TODAY == todayTomorrow)
    {
        isFinished = true;
        todayTomorrow = TodayTomorrow::TOMORROW;
    }
}

void EveryDay::isToday()
{
    todayTomorrow = TodayTomorrow::TODAY;
    isFinished = false;
}