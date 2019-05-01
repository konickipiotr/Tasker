#include "Task.hpp"

Task::Task(std::string _taskName) 
    :   taskName{_taskName},
        description{""},
        priority{Priority::MEDIUM},
        duration{},
        isFinished{false}
{}

std::string Task::getTaskName() const 
{
    return taskName; 
}

std::string Task::getDescription() const 
{ 
    return description; 
}

Type Task::getType() const 
{ 
    return type; 
}

Priority Task::getPriority() const 
{ 
    return priority; 
}

int Task::getDuration() const 
{ 
    return duration; 
}

std::string Task::getCategory() 
{ 
    return category; 
}

bool Task::getIsFinieshed() const 
{ 
    return isFinished; 
}

void Task::setName(std::string newTaskName)
{
    taskName = newTaskName;
}

void Task::setDescription(std::string newDescriprion)
{
    description = newDescriprion;
}
void Task::setPriority(Priority newPriority)
{
    priority = newPriority;
}
void Task::setDurarion(int newDuration)
{
    duration = newDuration;
}

void Task::setCategory(std::string newCategory)
{
    category = newCategory;
}