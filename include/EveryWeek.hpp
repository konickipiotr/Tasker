#pragma once
#include "Task.hpp"
#include <map>

class EveryWeekTask : public Task
{
public:
    EveryWeekTask(std::string,DayOfWeek);
    void finishTask() override;
private:
    std::map<DayOfWeek, bool> dayOfWeekMap;
};