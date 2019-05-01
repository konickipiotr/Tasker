#include "EveryWeek.hpp"

EveryWeekTask::EveryWeekTask(std::string _taskName, DayOfWeek _dayOfWeek)
    :   Task(_taskName)
{
    dayOfWeekMap[_dayOfWeek] = true;
}

void EveryWeekTask::finishTask()
{
    isFinished = true;
}