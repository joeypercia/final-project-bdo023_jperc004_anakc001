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
    // set priority 999 for test case.
    // Edge case: Task priorities wouldn't go as far out as 999
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
    // set priority -1 for this test case
    // Suggestion: Set off an error?
    TaskList test;
    
    test.set_priority(-1);
    
    EXPECT_EQ(test.get_priority(), -1);
}
// end

// Set title function
TEST(TaskListTitle, titleSet1_normalCase) {
    TaskList test;
    
    test.set_title("TitleTest");
    
    EXPECT_EQ(test.get_title(), "TitleTest");
}
TEST(TaskListTitle, titleSet2_spacedString) {
    TaskList test;
    
    test.set_title("Title Test");
    
    EXPECT_EQ(test.get_title(), "Title Test");
}
TEST(TaskListTitle, titleSet3_NumberedString) {
    TaskList test;
    
    test.set_title("12345");
    
    EXPECT_EQ(test.get_title(), "12345");
}
TEST(TaskListTitle, titleSet4_SpecialChars) {
    TaskList test;
    
    test.set_title("^Test!@#$%");
    
    EXPECT_EQ(test.get_title(), "^Test!@#$%");
}
// end suite

// Set description function
TEST(TaskListDescription, descSet1_normalCase) {
    TaskList test;
    
    test.set_description("DescriptionTest. This task should be done soon.");
    
    EXPECT_EQ(test.get_description(), "DescriptionTest. This task should be done soon.");
}
TEST(TaskListDescription, descSet_longDescription) {
    TaskList test;
    
    test.set_description("test 1 2 3 4 5 !@#$% check, this test requires a check if the class works or not. abcdefghijklmnopqrstuvwxyz Does this class work or not. Create multiple test cases and check if the classes work. This is important");
    EXPECT_EQ(test.get_description(), "test 1 2 3 4 5 !@#$% check, this test requires a check if the class works or not. abcdefghijklmnopqrstuvwxyz Does this class work or not. Create multiple test cases and check if the classes work. This is important");
}
// end suite

// set due date begin
TEST(TaskListDueDate, dueSet_standardDate1) {
    TaskList test;

    test.set_due_date("01/01/1971");

    EXPECT_EQ(test.get_due_date(), "01/01/1971");
}
TEST(TaskListDueDate, dueSet_standardDate2) {
    TaskList test;

    test.set_due_date("12/31/2100");

    EXPECT_EQ(test.get_due_date(), "12/31/2100");
}
TEST(DISABLED_TaskListDueDate, dueSet_incorrectFormat) {
    // Not sure about this test case:
    // This test case checks if the due date is appropriate
    // Format: MM/DD/YYYY
    // However, this edge case checks if the due date is invalid since
    //  a 13th month doesn't exist, and a 32nd day doesn't exist.
    // Disabled this test if we're not going to fix this issue.

    TaskList test;

    test.set_due_date("13/32/2025");

    EXPECT_EQ(test.get_due_date(), "Invalid");
    // EXPECT_EQ(test.get_due_date(), "13/32/2025");
}
// end due date test suite



#endif