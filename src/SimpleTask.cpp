#include "SimpleTask.hpp"

SimpleTask::SimpleTask(std::string _taskName)
    :   Task{_taskName},
        deadline{}
{
    type = Type::ONCE;
}

void SimpleTask::finishTask()
{
    isFinished = true;
}

tm SimpleTask::getDeadline() const
{
    return deadline;
}

void SimpleTask::setDeadline(tm newDeadline)
{
    deadline = newDeadline;
}