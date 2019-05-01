#pragma once
#include <gmock/gmock.h>
#include "IInput.hpp"

class InputMock : public IInput
{
public:
    InputMock() = default;
    ~InputMock() override = default;
    MOCK_METHOD0(getTaskName, std::string());
    MOCK_METHOD0(getTaskDescription, std::string());
    MOCK_METHOD0(getDecision, char());
    MOCK_METHOD0(ChangePriority, Priority());
    MOCK_METHOD0(SetDeadline, tm());
    MOCK_METHOD1(SetCategories, std::string(std::vector<std::string>&));
    MOCK_METHOD0(SetDuration, int());
    MOCK_METHOD0(GetRandomTaskSub, std::string());
    MOCK_METHOD1(getMenuPosition, char(const std::vector<char>&));
};