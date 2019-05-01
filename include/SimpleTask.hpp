#pragma once
#include "Task.hpp"
#include <ctime>

class SimpleTask : public Task
{
public:
    SimpleTask(std::string);

    void finishTask() override;
    tm getDeadline() const;
    void setDeadline(tm);
private:
    tm deadline; 
};