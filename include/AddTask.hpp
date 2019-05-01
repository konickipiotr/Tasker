#pragma once
#include "IInput.hpp"
#include <memory>
#include "SimpleTask.hpp"
#include "RandomTask.hpp"

class AddTask
{
public:
    AddTask(IInput&, std::vector<std::string>&);
    std::unique_ptr<SimpleTask> addSimpleTask();
    std::unique_ptr<RandomTask> addRandomTask();

private:
    IInput& input;
    std::vector<std::string>& categories;
};