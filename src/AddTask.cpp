#include "AddTask.hpp"

AddTask::AddTask(IInput& _input, std::vector<std::string>& _categories) 
    : input(_input), categories(_categories) {}

std::unique_ptr<SimpleTask> AddTask::addSimpleTask()
{
    char decistion;
    std::string taskName = input.getTaskName();

    while(taskName.empty())
        taskName = input.getTaskName();

    decistion = input.getDecision();
    while(decistion != 'y' && decistion != 'a' && decistion != 'x')
        decistion = input.getDecision();

    if(decistion == 'y')
        return std::make_unique<SimpleTask>(taskName);
    else  if(decistion == 'x')
        return nullptr;
    
    std::unique_ptr<SimpleTask> newTask = std::make_unique<SimpleTask>(taskName);
    newTask->setDescription(input.getTaskDescription());
    newTask->setPriority(input.ChangePriority());
    newTask->setCategory(input.SetCategories(categories));
    newTask->setDurarion(input.SetDuration());
    newTask->setDeadline(input.SetDeadline());

    return newTask;
}

std::unique_ptr<RandomTask> AddTask::addRandomTask()
{
    char decistion{};
    std::string taskName{};
    std::string firstSubTask{};

    while(taskName.empty())
        taskName = input.getTaskName();

    while(firstSubTask.empty())
        firstSubTask = input.GetRandomTaskSub();

    while(decistion != 'y' && decistion != 'a' && decistion != 'x')
        decistion = input.getDecision();

    if(decistion == 'y')
        return std::make_unique<RandomTask>(taskName, firstSubTask);
    else  if(decistion == 'x')
        return nullptr;
    decistion = {};

    std::unique_ptr<RandomTask> newTask = std::make_unique<RandomTask>(taskName, firstSubTask);

    while(input.getDecision() == 'y')
    {
        newTask->addSubTask(input.GetRandomTaskSub());
    }

    while(decistion != 'y' && decistion != 'a' && decistion != 'x')
        decistion = input.getDecision();

    if(decistion == 'y')
        return newTask;
    else  if(decistion == 'x')
        return nullptr;

    newTask->setDescription(input.getTaskDescription());
    newTask->setPriority(input.ChangePriority());
    newTask->setCategory(input.SetCategories(categories));
    newTask->setDurarion(input.SetDuration());
    
    return newTask;
}