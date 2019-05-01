#pragma once
#include <string>
#include "Enums.hpp"
#include <vector>

class IInput
{
public:
    virtual std::string getTaskName() = 0;    
    virtual std::string getTaskDescription() = 0;    
    virtual char getDecision() = 0;
    virtual Priority ChangePriority() = 0;
    virtual tm SetDeadline() = 0;
    virtual std::string SetCategories(std::vector<std::string>&) = 0;
    virtual int SetDuration() = 0;
    virtual std::string GetRandomTaskSub() = 0;
    virtual char getMenuPosition(const std::vector<char>&) = 0;
    virtual ~IInput(){}
};