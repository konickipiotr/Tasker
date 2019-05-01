#pragma once
#include "Task.hpp"
#include <vector>

class RandomTask : public Task
{
public:
    RandomTask(std::string, std::string);

    int getAllSubTaskNumber() const;
    int getleftSubTasksNumber() const;
    std::string getCurrentSubTask() const;

    void finishTask() override;
    void addSubTask(std::string);
    void resetState();

private:
    
    void randTask();

    std::vector<std::string> allSubTasks;
    std::vector<std::string> leftSubTasks;
    std::string currentSubTask;
};