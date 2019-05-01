#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "AddTask.hpp"
#include "InputMock.hpp"
#include <memory>
#include <vector>

using namespace testing;

class AddTaskTesting : public ::Test
{
protected:
    std::vector<std::string> categories {"Home","IT","Hobby"};
    StrictMock<InputMock> mockInput;
    AddTask addTask{mockInput, categories};
};


TEST_F(AddTaskTesting, method_addSimpleTask_should_return_uniqe_ptr_Task_correct_filelds)
{
    std::string newTaskName = "Cleaning";
    EXPECT_CALL(mockInput, getTaskName()).WillOnce(Return(newTaskName));
    EXPECT_CALL(mockInput, getDecision()).WillOnce(Return('y'));
    auto simpleTask = addTask.addSimpleTask();

    EXPECT_EQ(std::string("Cleaning"), simpleTask->getTaskName());
    EXPECT_EQ(std::string(""), simpleTask->getDescription());
    EXPECT_EQ(std::string(""), simpleTask->getCategory());
    EXPECT_EQ(Type::ONCE, simpleTask->getType());
    EXPECT_EQ(Priority::MEDIUM, simpleTask->getPriority());
    EXPECT_EQ(0, simpleTask->getDuration());
    EXPECT_EQ(false, simpleTask->getIsFinieshed());
    EXPECT_EQ(0, simpleTask->getDeadline().tm_mday);
    EXPECT_EQ(0, simpleTask->getDeadline().tm_mon);
    EXPECT_EQ(0, simpleTask->getDeadline().tm_year);
    EXPECT_EQ(0, simpleTask->getDeadline().tm_wday);
}

TEST_F(AddTaskTesting, can_not_set_empty_taskName)
{
    EXPECT_CALL(mockInput, getTaskName())
        .WillOnce(Return(""))
        .WillOnce(Return(""))
        .WillOnce(Return(""))
        .WillOnce(Return("Cleaning"));
    EXPECT_CALL(mockInput, getDecision()).WillOnce(Return('y'));

    auto simpleTask = addTask.addSimpleTask();

    EXPECT_EQ(std::string("Cleaning"), simpleTask->getTaskName());
}


TEST_F(AddTaskTesting, if_decision_is_x_return_nullptr)
{
    EXPECT_CALL(mockInput, getTaskName()).WillOnce(Return("Cleaning"));
    EXPECT_CALL(mockInput, getDecision()).WillOnce(Return('x'));

    auto simpleTask = addTask.addSimpleTask();
    EXPECT_EQ(nullptr, simpleTask);
}

TEST_F(AddTaskTesting, if_decision_is_a_method_addSimpeTask_return_Taks_with_custom_options)
{
    EXPECT_CALL(mockInput, getTaskName()).WillOnce(Return("Cleaning"));
    EXPECT_CALL(mockInput, getDecision()).WillOnce(Return('a'));
    EXPECT_CALL(mockInput, getTaskDescription()).WillOnce(Return("cleaning window"));
    EXPECT_CALL(mockInput, ChangePriority()).WillOnce(Return(Priority::HIGH));
    tm newTime{};
    newTime.tm_mday = 20;
    newTime.tm_mon = 5;
    newTime.tm_year = 2000;
    EXPECT_CALL(mockInput, SetDeadline()).WillOnce(Return(newTime));
    EXPECT_CALL(mockInput, SetCategories(categories)).WillOnce(Return("Home"));
    EXPECT_CALL(mockInput, SetDuration()).WillOnce(Return(30));

    auto simpleTask = addTask.addSimpleTask();

    EXPECT_EQ("Cleaning", simpleTask->getTaskName());
    EXPECT_EQ("cleaning window", simpleTask->getDescription());
    EXPECT_EQ(Priority::HIGH, simpleTask->getPriority());
    EXPECT_EQ(30, simpleTask->getDuration());

    EXPECT_EQ(20, simpleTask->getDeadline().tm_mday);
    EXPECT_EQ(5, simpleTask->getDeadline().tm_mon);
    EXPECT_EQ(2000, simpleTask->getDeadline().tm_year);
    EXPECT_EQ("Home", simpleTask->getCategory());
}


TEST_F(AddTaskTesting, simple_RandomTask_should_ne_with_at_least_one_subTask)
{
    EXPECT_CALL(mockInput, getTaskName()).WillOnce(Return("Programing"));
    EXPECT_CALL(mockInput, GetRandomTaskSub()).WillOnce(Return("C++"));
    EXPECT_CALL(mockInput, getDecision()).WillOnce(Return('y'));

    auto randomTask = addTask.addRandomTask();
    EXPECT_EQ(std::string("Programing"), randomTask->getTaskName());
    EXPECT_EQ(std::string("C++"), randomTask->getCurrentSubTask());
    EXPECT_EQ(false, randomTask->getIsFinieshed());
}

TEST_F(AddTaskTesting, taskName_and_firstTask_should_not_be_empty)
{
    EXPECT_CALL(mockInput, getTaskName())
        .WillOnce(Return(""))
        .WillOnce(Return(""))
        .WillOnce(Return(""))
        .WillOnce(Return("Programing"));
    EXPECT_CALL(mockInput, GetRandomTaskSub())
        .WillOnce(Return(""))
        .WillOnce(Return(""))
        .WillOnce(Return("C++"));
    EXPECT_CALL(mockInput, getDecision()).WillOnce(Return('y'));

    auto randomTask = addTask.addRandomTask();

    EXPECT_EQ(std::string("Programing"), randomTask->getTaskName());
    EXPECT_EQ(std::string("C++"), randomTask->getCurrentSubTask());
}

TEST_F(AddTaskTesting, if_decision_is_x_return_nullptr_addRandomTask)
{
    EXPECT_CALL(mockInput, getTaskName()).WillOnce(Return("Programing"));
    EXPECT_CALL(mockInput, GetRandomTaskSub()).WillOnce(Return("C++"));
    EXPECT_CALL(mockInput, getDecision()).WillOnce(Return('x'));

    auto randomTask = addTask.addRandomTask();
    EXPECT_EQ(nullptr, randomTask);
}
  
TEST_F(AddTaskTesting, create_new_Random_Task_With_three_subTask)
{
    EXPECT_CALL(mockInput, getTaskName()).WillOnce(Return("Programing"));
    EXPECT_CALL(mockInput, GetRandomTaskSub())
        .WillOnce(Return("C++"))
        .WillOnce(Return("Java"))
        .WillOnce(Return("C#"));
    EXPECT_CALL(mockInput, getDecision())
        .WillOnce(Return('a'))
        .WillOnce(Return('y'))
        .WillOnce(Return('y'))
        .WillOnce(Return('n'))
        .WillOnce(Return('y'));

    auto randomTask = addTask.addRandomTask();

    EXPECT_EQ(std::string("C++"), randomTask->getCurrentSubTask());
    EXPECT_EQ(3, randomTask->getAllSubTaskNumber());
    EXPECT_EQ(3, randomTask->getleftSubTasksNumber());
}

TEST_F(AddTaskTesting, cancelin_create_randomTask_after_add_two_SubTask)
{
    EXPECT_CALL(mockInput, getTaskName()).WillOnce(Return("Programing"));
    EXPECT_CALL(mockInput, GetRandomTaskSub())
        .WillOnce(Return("C++"))
        .WillOnce(Return("C#"));
    EXPECT_CALL(mockInput, getDecision())
        .WillOnce(Return('a'))
        .WillOnce(Return('y'))
        .WillOnce(Return('n'))
        .WillOnce(Return('x'));

    auto randomTask = addTask.addRandomTask();
    EXPECT_EQ(nullptr, randomTask);
}


TEST_F(AddTaskTesting, create_new_Random_Task_With_two_subTask_and_other_options)
{
    EXPECT_CALL(mockInput, getTaskName()).WillOnce(Return("Programing"));
    EXPECT_CALL(mockInput, GetRandomTaskSub())
        .WillOnce(Return("C++"))
        .WillOnce(Return("C#"));
    EXPECT_CALL(mockInput, getDecision())
        .WillOnce(Return('a'))
        .WillOnce(Return('y'))
        .WillOnce(Return('n'))
        .WillOnce(Return('a'));
    
    EXPECT_CALL(mockInput, getTaskDescription()).WillOnce(Return("dev"));
    EXPECT_CALL(mockInput, ChangePriority()).WillOnce(Return(Priority::HIGH));
    EXPECT_CALL(mockInput, SetCategories(categories)).WillOnce(Return("IT"));
    EXPECT_CALL(mockInput, SetDuration()).WillOnce(Return(60));

    auto randomTask = addTask.addRandomTask();

    EXPECT_EQ("Programing", randomTask->getTaskName());
    EXPECT_EQ("dev", randomTask->getDescription());
    EXPECT_EQ(Priority::HIGH, randomTask->getPriority());
    EXPECT_EQ(60, randomTask->getDuration());
    EXPECT_EQ("IT", randomTask->getCategory());
    EXPECT_EQ(std::string("C++"), randomTask->getCurrentSubTask());
    EXPECT_EQ(2, randomTask->getAllSubTaskNumber());
    EXPECT_EQ(2, randomTask->getleftSubTasksNumber());
}