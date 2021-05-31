#ifndef __TASKLIST_TEST_HPP__
#define __TASKLIST_TEST_HPP__

#include "gtest/gtest.h"

#include "task.hpp"
#include "tasklist.hpp"

// TaskList Constructors
/* 
TaskListConstructors test suite checks if the constructors initiated 
correctly in both default constructors and paramaterized constructors. 
This suite also tests if the getter functions work correctly.
*/
// default Constructor tests begin
TEST(TaskListConstructorD, defaultPriority) {
    TaskList test = TaskList();

    EXPECT_EQ(test.get_priority(), 0);
}
TEST(TaskListConstructorD, defaultTitle) {
    TaskList test = TaskList();

    EXPECT_EQ(test.get_title(), "");
}
TEST(TaskListConstructorD, defaultDescription) {
    TaskList test = TaskList();

    EXPECT_EQ(test.get_description(), "");
}
TEST(TaskListConstructorD, defaultType) {
    TaskList test = TaskList();

    EXPECT_EQ(test.get_type(), "");
}
TEST(TaskListConstructorD, defaultDate) {
    TaskList test = TaskList();

    EXPECT_EQ(test.get_due_date(), "");
}
// default constructor test end

// Constructor with parameters tests begin
// Parameter/Arguments Constructor 1
// Checks if parameterized constructor initialized correctly with selected arguments
TEST(TaskListConstructorP, arguments1Priority) {
    TaskList test = TaskList("Test1", "Desc1", "Type1", "01/01/2020", 1);

    EXPECT_EQ(test.get_priority(), 1);
}
TEST(TaskListConstructorP, arguments1Title) {
    TaskList test = TaskList("Test1", "Desc1", "Type1", "01/01/2020", 1);

    EXPECT_EQ(test.get_title(), "Test1");
}
TEST(TaskListConstructorP, arguments1Description) {
    TaskList test = TaskList("Test1", "Desc1", "Type1", "01/01/2020", 1);

    EXPECT_EQ(test.get_description(), "Desc1");
}
TEST(TaskListConstructorP, arguments1Type) {
    TaskList test = TaskList("Test1", "Desc1", "Type1", "01/01/2020", 1);

    EXPECT_EQ(test.get_type(), "Type1");
}
TEST(TaskListConstructorP, arguments1Date) {
    TaskList test = TaskList("Test1", "Desc1", "Type1", "01/01/2020", 1);

    EXPECT_EQ(test.get_due_date(), "01/01/2020");
}
// constructor with parameters test end

// Set Priority Function
// begin
TEST(TaskListPriority, prioritySet1) {
    // set priority 1 for this test case
    TaskList test;
    
    test.set_priority(1);
    
    EXPECT_EQ(test.get_priority(), 1);
}
TEST(TaskListPriority, prioritySet2) {
    TaskList test;

    test.set_priority(999);

    EXPECT_EQ(test.get_priority(), 999);
}
TEST(TaskListPriority, prioritySet3) {
    // set priority 0 for this test case
    // Suggestion: Set off an error?
    TaskList test;
    
    test.set_priority(0);
    
    EXPECT_EQ(test.get_priority(), 0);
}
TEST(TaskListPriority, prioritySet4) {
    // set priority 0 for this test case
    // Suggestion: Set off an error?
    TaskList test;
    
    test.set_priority(-1);
    
    EXPECT_EQ(test.get_priority(), -1);
}
// end

// Set title function





#endif