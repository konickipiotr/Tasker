#include "RandomTask.hpp"
#include <random>

RandomTask::RandomTask(std::string _taskName, std::string firstSubTask)
    :   Task{_taskName},
        currentSubTask{firstSubTask}
{
    type = Type::EVERYD_RAND;
    allSubTasks.push_back(firstSubTask);
    leftSubTasks.push_back(firstSubTask);
}

int RandomTask::getAllSubTaskNumber() const
{
    return allSubTasks.size();
}

int RandomTask::getleftSubTasksNumber() const
{
    return leftSubTasks.size();
}

std::string RandomTask::getCurrentSubTask() const
{
    return currentSubTask;
}

void RandomTask::finishTask()
{
    if(isFinished)
        return;

    for(unsigned int i = 0; i < leftSubTasks.size(); i++)
    {
        if(leftSubTasks.at(i) == currentSubTask)
            leftSubTasks.erase( std::begin(leftSubTasks) + i);
    }

    isFinished = true;

    if(leftSubTasks.size() == 0)
        leftSubTasks = allSubTasks;
}

void RandomTask::addSubTask(std::string newSubTask)
{
    if(!newSubTask.empty())
    {
        allSubTasks.push_back(newSubTask);
        leftSubTasks.push_back(newSubTask);
    }
}

void RandomTask::resetState()
{
    if(isFinished)
    {
        isFinished = false;
        randTask();
    }
}

void RandomTask::randTask()
{
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<int> dist(0, leftSubTasks.size()-1);
    int numGen = dist(gen);
    currentSubTask = leftSubTasks.at(numGen);
}