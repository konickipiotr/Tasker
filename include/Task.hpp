#pragma once
#include <string>
#include "Enums.hpp"

class Task
{
public:
    Task(std::string);

    std::string getTaskName() const;
    std::string getDescription() const;
    Type getType() const;
    Priority getPriority() const;
    int getDuration() const;
    std::string getCategory();
    bool getIsFinieshed() const;

    void setName(std::string);
    void setDescription(std::string);
    void setPriority(Priority);
    void setDurarion(int);

    virtual void finishTask() = 0;

protected:
    std::string taskName;
    std::string description;
    Type type;
    Priority priority;
    std::string category;
    int duration;
    bool isFinished;
};