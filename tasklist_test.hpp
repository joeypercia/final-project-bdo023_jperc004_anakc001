#ifndef __TASKLIST_TEST_HPP__
#define __TASKLIST_TEST_HPP__

#include "gtest/gtest.h"

#include "basetasks.hpp"
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
// Doesn't seem to be a lot to test for this function.
// Just a normal set description function
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
TEST(TaskListDueDate, dueSet_incorrectFormat) {
    // Not sure about this test case:
    // This test case checks if the due date is appropriate
    // Format: MM/DD/YYYY
    // However, this edge case checks if the due date is invalid since
    //  a 13th month doesn't exist, and a 32nd day doesn't exist.

    TaskList test;

    test.set_due_date("13/32/2025");

    EXPECT_EQ(test.get_due_date(), "Invalid");
    // EXPECT_EQ(test.get_due_date(), "13/32/2025");
}
TEST(TaskListDueDate, dueSet_incorrectFormat2) {
    // Another edge test case
    // This function tells the user to set the date in a specific format
    // Format: MM/DD/YYYY
    // But what about the user not following that direction?

    TaskList test;

    test.set_due_date("01012021");

    EXPECT_EQ(test.get_due_date(), "01/01/2021");
    // EXPECT_EQ(test.get_due_date(), "01012021");
}
// end due date test suite

// begin set type test suite
TEST(TaskListType, typeSet_standard) {
    TaskList test;

    test.set_type("Business");

    EXPECT_EQ(test.get_type(), "Business");
}
TEST(TaskListType, typeSet_StringAndNums) {
    TaskList test;

    test.set_type("Admin 2");

    EXPECT_EQ(test.get_type(), "Admin 2");
}
TEST(TaskListType, typeSet_SpecialChar) {
    TaskList test;

    test.set_type("Robotics @ UC Zoom");

    EXPECT_EQ(test.get_type(), "Robotics @ UC Zoom");
}
// note: not sure for edge cases. Only strings.
// end set type test suite

// begin add task functions
TEST(TaskListVector, addTask1) {
    TaskList test;

    BaseTasks* taskSample1 = new Task("task1", "description1", "type1", "01/01/2001", 1);
    BaseTasks* taskSample2 = new Task("task2", "description2", "type2", "02/02/2001", 2);

    test.set_title("TitleTest");
    test.set_description("Description Test");
    test.set_type("Test Type");
    test.set_due_date("01/01/2021");
    test.set_priority(1);

    test.add(taskSample1);
    test.add(taskSample2);
    
    EXPECT_EQ(test.get_task(0), taskSample1);
}
TEST(TaskListVector, addTask2) {
    TaskList test;

    BaseTasks* taskSample1 = new Task("task1", "description1", "type1", "01/01/2001", 1);
    BaseTasks* taskSample2 = new Task("task2", "description2", "type2", "02/02/2001", 2);

    test.set_title("TitleTest");
    test.set_description("Description Test");
    test.set_type("Test Type");
    test.set_due_date("01/01/2021");
    test.set_priority(1);

    test.add(taskSample1);
    test.add(taskSample2);
    
    EXPECT_EQ(test.get_task(1), taskSample2);
}
TEST(TaskListVector, addTask3) {
    TaskList test;

    BaseTasks* taskSample1 = new Task("task1", "description1", "type1", "01/01/2001", 1);
    BaseTasks* taskSample2 = new Task("task2", "description2", "type2", "02/02/2011", 2);
    BaseTasks* taskSample3 = new Task("task3", "description3", "type3", "03/03/2021", 2);
    BaseTasks* taskSample4 = new Task("task4", "description4", "type4", "04/04/2031", 3);
    BaseTasks* taskSample5 = new Task("task5", "description5", "type5", "05/05/2041", 10);

    test.set_title("TitleTest");
    test.set_description("Description Test");
    test.set_type("Test Type");
    test.set_due_date("01/01/2021");
    test.set_priority(1);

    test.add(taskSample1);
    test.add(taskSample2);
    test.add(taskSample3);
    test.add(taskSample4);
    test.add(taskSample5);
    
    EXPECT_EQ(test.get_task(3), taskSample4);
    EXPECT_EQ(test.get_task(3)->get_title(), taskSample4->get_title());
}

// Test for delete/remove function 
TEST(TaskListVector, removeTask1) {
    TaskList test;

    BaseTasks* taskSample1 = new Task("task1", "description1", "type1", "01/01/2001", 1);
    BaseTasks* taskSample2 = new Task("task2", "description2", "type2", "02/02/2011", 2);
    BaseTasks* taskSample3 = new Task("task3", "description3", "type3", "03/03/2021", 2);
    BaseTasks* taskSample4 = new Task("task4", "description4", "type4", "04/04/2031", 3);
    BaseTasks* taskSample5 = new Task("task5", "description5", "type5", "05/05/2041", 10);

    test.set_title("TitleTest");
    test.set_description("Description Test");
    test.set_type("Test Type");
    test.set_due_date("01/01/2021");
    test.set_priority(1);

    test.add(taskSample1);
    test.add(taskSample2);
    test.add(taskSample3);
    test.add(taskSample4);
    test.add(taskSample5);

    test.del(0);  // Checks if function deletes task from list properly.
    
    EXPECT_EQ(test.get_task(0), taskSample2); // Expects first task to be the 2nd task
    EXPECT_EQ(test.get_task(0)->get_title(), taskSample2->get_title());
}
TEST(TaskListVector, removeTask2) {
    TaskList test;

    BaseTasks* taskSample1 = new Task("task1", "description1", "type1", "01/01/2001", 1);
    BaseTasks* taskSample2 = new Task("task2", "description2", "type2", "02/02/2011", 2);
    BaseTasks* taskSample3 = new Task("task3", "description3", "type3", "03/03/2021", 2);
    BaseTasks* taskSample4 = new Task("task4", "description4", "type4", "04/04/2031", 3);
    BaseTasks* taskSample5 = new Task("task5", "description5", "type5", "05/05/2041", 10);

    test.set_title("TitleTest");
    test.set_description("Description Test");
    test.set_type("Test Type");
    test.set_due_date("01/01/2021");
    test.set_priority(1);

    EXPECT_EQ(test.get_size(), 0);

    test.add(taskSample1); // 0
    test.add(taskSample2); // 1
    test.add(taskSample3); // 2
    test.add(taskSample4); // 3
    test.add(taskSample5); // 4

    EXPECT_EQ(test.get_size(), 5);

    test.del(0);  // remove taskSample1 from list
    test.del(2);  // remove taskSample4 from list
    
    EXPECT_EQ(test.get_task(0), taskSample2);
    EXPECT_EQ(test.get_task(0)->get_title(), taskSample2->get_title());
    EXPECT_EQ(test.get_task(2), taskSample5);
    EXPECT_EQ(test.get_task(2)->get_title(), taskSample5->get_title());
    EXPECT_EQ(test.get_size(), 3);
}
// end tasklist vector test suite
// Feel free to add additional unit tests about TaskList class here.

#endif