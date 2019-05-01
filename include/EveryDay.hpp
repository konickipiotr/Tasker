#pragma once
#include "Task.hpp"

class EveryDay : public Task
{
public:
    EveryDay(std::string);
    TodayTomorrow getTodayTomorrow() const;
    void finishTask() override;
    void isToday();
    
private:
    TodayTomorrow todayTomorrow; 
};