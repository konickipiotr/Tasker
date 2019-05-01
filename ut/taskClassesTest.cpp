#include <gtest/gtest.h>
#include "SimpleTask.hpp"
#include "RandomTask.hpp"
#include "EveryDay.hpp"
#include "EveryWeek.hpp"
#include <string>
#include <ctime>

using namespace testing;

class taskClassesTesting : public ::testing::Test
{
protected:
    SimpleTask simpleTask{"Cleaning"};
    EveryDay everyDay{"Running"};
    RandomTask randomTask{"Programing","C++"};
    RandomTask randomTask2{"Programing","C++"};

    void SetUp()
    {
        randomTask2.addSubTask("Java");
        randomTask2.addSubTask("C#");
    }
};

TEST_F(taskClassesTesting, new_simple_task_should_has_custom_taskName_and_default_other_fields)
{
    EXPECT_EQ(std::string("Cleaning"), simpleTask.getTaskName());
    EXPECT_EQ(std::string(""), simpleTask.getDescription());
    EXPECT_EQ(std::string(""), simpleTask.getCategory());
    EXPECT_EQ(Type::ONCE, simpleTask.getType());
    EXPECT_EQ(Priority::MEDIUM, simpleTask.getPriority());
    EXPECT_EQ(0, simpleTask.getDuration());
    EXPECT_EQ(false, simpleTask.getIsFinieshed());
    EXPECT_EQ(0, simpleTask.getDeadline().tm_mday);
    EXPECT_EQ(0, simpleTask.getDeadline().tm_mon);
    EXPECT_EQ(0, simpleTask.getDeadline().tm_year);
    EXPECT_EQ(0, simpleTask.getDeadline().tm_wday);
}

TEST_F(taskClassesTesting, test_setters_in_Task_and_simpleTask_class)
{
    simpleTask.setName("Reading");
    simpleTask.setDescription("Reading fantasy book");
    simpleTask.setPriority(Priority::LOW);
    simpleTask.setCategory("Hobby");
    simpleTask.setDurarion(30);
    tm newDeadline{};
    newDeadline.tm_mday = 20;
    newDeadline.tm_mon = 5;
    newDeadline.tm_year = 2000;
    simpleTask.setDeadline(newDeadline);
    
    EXPECT_EQ(std::string("Reading"), simpleTask.getTaskName());
    EXPECT_EQ(std::string("Reading fantasy book"), simpleTask.getDescription());
    EXPECT_EQ(std::string("Hobby"), simpleTask.getCategory());
    EXPECT_EQ(Priority::LOW, simpleTask.getPriority());
    EXPECT_EQ(30, simpleTask.getDuration());
    EXPECT_EQ(false, simpleTask.getIsFinieshed());
    EXPECT_EQ(20, simpleTask.getDeadline().tm_mday);
    EXPECT_EQ(5, simpleTask.getDeadline().tm_mon);
    EXPECT_EQ(2000, simpleTask.getDeadline().tm_year);
    EXPECT_EQ(0, simpleTask.getDeadline().tm_wday);

    simpleTask.finishTask();
    EXPECT_EQ(true, simpleTask.getIsFinieshed());
}

TEST_F(taskClassesTesting, new_EveryDayTask_should_start_form_tomorrow)
{
    EXPECT_EQ(TodayTomorrow::TOMORROW, everyDay.getTodayTomorrow());
}

TEST_F(taskClassesTesting, if_task_should_be_done_tomorrow_finishTask_is_not_working)
{
    everyDay.finishTask();
    EXPECT_EQ(TodayTomorrow::TOMORROW, everyDay.getTodayTomorrow());
}

TEST_F(taskClassesTesting, method_isToday_change_todayTomorrow_filed_to_Today_and_finishTask_is_posible)
{
    EXPECT_EQ(TodayTomorrow::TOMORROW, everyDay.getTodayTomorrow());
    EXPECT_EQ(true, everyDay.getIsFinieshed());
    everyDay.isToday();
    EXPECT_EQ(TodayTomorrow::TODAY, everyDay.getTodayTomorrow());
    EXPECT_EQ(false, everyDay.getIsFinieshed());
    everyDay.finishTask();
    EXPECT_EQ(TodayTomorrow::TOMORROW, everyDay.getTodayTomorrow());
    EXPECT_EQ(true, everyDay.getIsFinieshed());
}

TEST_F(taskClassesTesting, new_RandomTask_should_has_one_subTask)
{
    EXPECT_EQ(1, randomTask.getAllSubTaskNumber());
    EXPECT_EQ(1, randomTask.getleftSubTasksNumber());
    EXPECT_EQ(std::string("Programing"), randomTask.getTaskName());
    EXPECT_EQ(std::string("C++"), randomTask.getCurrentSubTask());
    EXPECT_EQ(false, randomTask.getIsFinieshed());
}

TEST_F(taskClassesTesting, finshed_randomTask_with_one_subtask_should_change_only_isFineshed)
{
    randomTask.finishTask();
    EXPECT_EQ(1, randomTask.getAllSubTaskNumber());
    EXPECT_EQ(1, randomTask.getleftSubTasksNumber());
    EXPECT_EQ(std::string("Programing"), randomTask.getTaskName());
    EXPECT_EQ(std::string("C++"), randomTask.getCurrentSubTask());
    EXPECT_EQ(true, randomTask.getIsFinieshed());
}

TEST_F(taskClassesTesting, add_three_new_subTask_shuld_increase_number_of_subtask)
{
    randomTask.addSubTask("Java");
    randomTask.addSubTask("Python");
    randomTask.addSubTask("C#");

    EXPECT_EQ(4, randomTask.getAllSubTaskNumber());
    EXPECT_EQ(4, randomTask.getleftSubTasksNumber());
    EXPECT_EQ(std::string("C++"), randomTask.getCurrentSubTask());
}

TEST_F(taskClassesTesting, it_is_possible_to_finish_one_randomTask_perday)
{
    EXPECT_EQ(3, randomTask2.getAllSubTaskNumber());
    EXPECT_EQ(3, randomTask2.getleftSubTasksNumber());
    EXPECT_EQ(std::string("C++"), randomTask2.getCurrentSubTask());

    randomTask2.finishTask();
    EXPECT_EQ(3, randomTask2.getAllSubTaskNumber());
    EXPECT_EQ(2, randomTask2.getleftSubTasksNumber());
    EXPECT_EQ(std::string("C++"), randomTask2.getCurrentSubTask());
    
    randomTask2.finishTask();
    EXPECT_EQ(3, randomTask2.getAllSubTaskNumber());
    EXPECT_EQ(2, randomTask2.getleftSubTasksNumber());
    EXPECT_EQ(std::string("C++"), randomTask2.getCurrentSubTask());
}

TEST_F(taskClassesTesting, finish_task_should_decrese_only_leftSubTask_vector_and_currentSubTask)
{
    EXPECT_EQ(3, randomTask2.getAllSubTaskNumber());
    EXPECT_EQ(3, randomTask2.getleftSubTasksNumber());
    EXPECT_EQ(std::string("C++"), randomTask2.getCurrentSubTask());

    randomTask2.finishTask();
    EXPECT_EQ(3, randomTask2.getAllSubTaskNumber());
    EXPECT_EQ(2, randomTask2.getleftSubTasksNumber());
    EXPECT_TRUE("Java" || "C#" == randomTask2.getCurrentSubTask());

    randomTask2.resetState();
    randomTask2.finishTask();
    EXPECT_EQ(3, randomTask2.getAllSubTaskNumber());
    EXPECT_EQ(1, randomTask2.getleftSubTasksNumber());
    EXPECT_TRUE("Java" || "C#" == randomTask2.getCurrentSubTask());

    randomTask2.resetState();
    randomTask2.finishTask();
    EXPECT_EQ(3, randomTask2.getAllSubTaskNumber());
    EXPECT_EQ(3, randomTask2.getleftSubTasksNumber());
    EXPECT_TRUE("Java" || "C#" || "C++" == randomTask2.getCurrentSubTask());

    randomTask2.resetState();
    randomTask2.finishTask();
    EXPECT_EQ(3, randomTask2.getAllSubTaskNumber());
    EXPECT_EQ(2, randomTask2.getleftSubTasksNumber());
    EXPECT_TRUE("Java" || "C#" || "C++" == randomTask2.getCurrentSubTask());
}