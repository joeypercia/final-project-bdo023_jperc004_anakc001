#ifndef _TEST_HPP__
#define _TEST_HPP__

#include "gtest/gtest.h"

#include "basetasks.hpp"
#include "task.hpp"
#include "tasklist.hpp"
#include <sstream>
#include <iostream>

TEST(SingleTask, TaskConstructor) {
	const char* agrv[] = {"./test", "study", "work", "personal"};
	Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
    	EXPECT_EQ(test.get_title(), "Test");
	EXPECT_EQ(test.get_description(), "Single task");
	EXPECT_EQ(test.get_type(), "study");
	EXPECT_EQ(test.get_due_date(), "06/01/2021");
	EXPECT_EQ(test.get_priority(), 0);
}
TEST(SingleTask, TaskDisplay) {
        const char* agrv[] = {"./test", "study", "work", "personal"};
        Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
	std::stringstream res;
	test.display(res);
	EXPECT_EQ(res.str(), "Test\nSingle task\nType: study\nDue date: 06/01/2021\nPriority: 0\n====================================\n");
	
}
TEST(SingleTask, PrintType) {
        const char* agrv[] = {"./test", "study", "work", "personal"};
        Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
        test.set_print(new Print_type1(&test));
	std::stringstream res;
        test.display(res);
        EXPECT_EQ(res.str(), "Test\nSingle task\nType: study\nDue date: 06/01/2021\nPriority: 0\n====================================\n");

}
TEST(SingleTask, NotType) {
        const char* agrv[] = {"./test", "study", "work", "personal"};
        Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
        test.set_print(new Print_type2(&test));
        std::stringstream res;
        test.display(res);
        EXPECT_EQ(res.str(), "");

}
TEST(SingleTask, PrintTop5) {
        const char* agrv[] = {"./test", "study", "work", "personal"};
        Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
        test.set_print(new Print_type1(&test));
        std::stringstream res;
        test.display(res);
        EXPECT_EQ(res.str(), "Test\nSingle task\nType: study\nDue date: 06/01/2021\nPriority: 0\n====================================\n");

}
TEST(SingleTask, PrintDate) {
        const char* agrv[] = {"./test", "study", "work", "personal"};
        Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
        test.set_print(new Print_date(&test, "06/01/2021"));
        std::stringstream res;
        test.display(res);
        EXPECT_EQ(res.str(), "Test\nSingle task\nType: study\nDue date: 06/01/2021\nPriority: 0\n====================================\n");

}
TEST(SingleTask, NotDate) {
        const char* agrv[] = {"./test", "study", "work", "personal"};
        Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
        test.set_print(new Print_date(&test, "06/01/2000"));
        std::stringstream res;
        test.display(res);
        EXPECT_EQ(res.str(), "");

}
TEST(SingleTask, Edit){
	const char* agrv[] = {"./test", "study", "work", "personal"};
        Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
	test.edit("Test", "Single task", "personal", "06/01/2021", 0);
	std::stringstream res;
	test.display(res);
        EXPECT_EQ(res.str(), "Test\nSingle task\nType: personal\nDue date: 06/01/2021\nPriority: 0\n====================================\n");
}
TEST(SingleTask, Delete){
	const char* agrv[] = {"./test", "study", "work", "personal"};
        Task test("Test", "Single task", "study", "06/01/2021", 0, agrv);
	test.del();
	std::stringstream res;
        test.display(res);
        EXPECT_EQ(res.str(), "");
}

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

    EXPECT_EQ(test.get_type(), "LIST DOES NOT HAVE TYPE");
}
TEST(TaskListConstructorD, defaultDate) {
    TaskList test = TaskList();

    EXPECT_EQ(test.get_due_date(), "LIST DOES NOT HAVE DUE DATE");
}
TEST(TaskListConstructorP, arguments1Priority) {
    TaskList test = TaskList("Test1", "Desc1", 1);

    EXPECT_EQ(test.get_priority(), 1);
}
TEST(TaskListConstructorP, arguments1Title) {
    TaskList test = TaskList("Test1", "Desc1", 1);

    EXPECT_EQ(test.get_title(), "Test1");
}
TEST(TaskListConstructorP, arguments1Description) {
    TaskList test = TaskList("Test1", "Desc1", 1);

    EXPECT_EQ(test.get_description(), "Desc1");
}
TEST(TaskListConstructorP, arguments1Type) {
    TaskList test = TaskList("Test1", "Desc1", 1);

    EXPECT_EQ(test.get_type(), "LIST DOES NOT HAVE TYPE");
}
TEST(TaskListConstructorP, arguments1Date) {
    TaskList test = TaskList("Test1", "Desc1", 1);

    EXPECT_EQ(test.get_due_date(), "LIST DOES NOT HAVE DUE DATE");
}

TEST(TaskListDisplay, MultipleTasks){
	const char* agrv[] = {"./test", "study", "work", "personal"};		
	Task fam1("Family", "Sister's graduation", "personal", "05/19/2021", 12, agrv);
	Task fam2("Family", "celebration", "personal", "05/19/2021", 15, agrv);
	TaskList family("Family", "meeting", 1);
	family.add(&fam1);
	family.add(&fam2);
	std::stringstream res;
	family.display(res);
	EXPECT_EQ(res.str(),"\n======== Family ========= meeting ============ Priority: 1\nFamily\nSister's graduation\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 15\n====================================\n" );
}
TEST(TaskListDisplay, Top5){
        const char* agrv[] = {"./test", "study", "work", "personal"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/19/2021", 15, agrv);
	Task fam3("Family", "Sister's graduation", "personal", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);
	Task fam5("Family", "celebration", "personal", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "personal", "05/19/2021", 10, agrv);


        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
	family.add(&fam3);
        family.add(&fam4);
	family.add(&fam5);
	family.add(&fam6);
        std::stringstream res;
	family.set_print(new Print_top5(&family));
        family.display(res);
        EXPECT_EQ(res.str(),"\n======== Family ========= meeting ============ Priority: 1\nFamily\nSister's graduation\nType: personal\nDue date: 05/19/2021\nPriority: 3\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 4\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 9\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 10\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\n");
}
TEST(TaskListDisplay, PrintType1){
        const char* agrv[] = {"./test", "party", "work", "personal"};
        Task fam1("Family", "celebration", "party", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "party", "05/19/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "personal", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "party", "05/19/2021", 4, agrv);
        Task fam5("Family", "celebration", "party", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "party", "05/19/2021", 10, agrv);


        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);
        family.add(&fam5);
        family.add(&fam6);
        std::stringstream res;
        family.set_print(new Print_type3(&family));
        family.display(res);
        EXPECT_EQ(res.str(),"\n======== Family ========= meeting ============ Priority: 1\nFamily\nSister's graduation\nType: personal\nDue date: 05/19/2021\nPriority: 3\n====================================\n");
}
TEST(TaskListDisplay, PrintType2){
        const char* agrv[] = {"./test", "personal", "work", "ceremony"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/19/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "ceremony", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);
        Task fam5("Family", "celebration", "personal", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "personal", "05/19/2021", 10, agrv);


        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);
        family.add(&fam5);
        family.add(&fam6);
        std::stringstream res;
        family.set_print(new Print_type1(&family));
        family.display(res);
        EXPECT_EQ(res.str(), "\n======== Family ========= meeting ============ Priority: 1\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 15\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 4\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 9\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 10\n====================================\n");
}
TEST(TaskListDisplay, PrintDate){
        const char* agrv[] = {"./test", "personal", "work", "ceremony"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/10/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "ceremony", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);
        Task fam5("Family", "celebration", "personal", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "personal", "05/10/2021", 10, agrv);
	
	TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);
        family.add(&fam5);
        family.add(&fam6);
	std::stringstream res;
        family.set_print(new Print_date(&family, "05/19/2021"));
        family.display(res);
        EXPECT_EQ(res.str(), "\n======== Family ========= meeting ============ Priority: 1\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\nFamily\nSister's graduation\nType: ceremony\nDue date: 05/19/2021\nPriority: 3\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 4\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 9\n====================================\n");
}
TEST(TaskListDisplay, Edit_Delete){
        const char* agrv[] = {"./test", "personal", "work", "ceremony"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/10/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "ceremony", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);
        Task fam5("Family", "celebration", "personal", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "personal", "05/10/2021", 10, agrv);

        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);
        family.add(&fam5);
        family.add(&fam6);
        std::stringstream res;
	family.edit_list("Family", "Union", 0);
	family.del_at(2);
        family.set_print(new Print_date(&family, "05/19/2021"));
        family.display(res);
        EXPECT_EQ(res.str(), "\n======== Family ========= Union ============ Priority: 0\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 4\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 9\n====================================\n");
}
TEST(TaskListDisplay, DeleteList){
        const char* agrv[] = {"./test", "personal", "work", "ceremony"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/10/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "ceremony", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);
        Task fam5("Family", "celebration", "personal", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "personal", "05/10/2021", 10, agrv);

        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);
        family.add(&fam5);
        family.add(&fam6);
        std::stringstream res;
        family.edit_list("Family", "Union", 0);
        family.del();
        family.display(res);
        EXPECT_EQ(res.str(), "");
}
TEST(TaskListDisplay, SubList){
        const char* agrv[] = {"./test", "personal", "party", "ceremony"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/10/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "ceremony", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);

        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);
	
	TaskList party("Graduation Party", "grill", 2);
	Task fam5("Family", "celebration", "party", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "party", "05/10/2021", 10, agrv);
	party.add(&fam5);
	party.add(&fam6);
	
	TaskList P_F("Family Party", "Celebration & party", 0);
	P_F.add(&family);
	P_F.add(&party);
	
	
	
        std::stringstream res;
        P_F.display(res);
        EXPECT_EQ(res.str(), "\n======== Family Party ========= Celebration & party ============ Priority: 0\n\n======== Family ========= meeting ============ Priority: 1\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/10/2021\nPriority: 15\n====================================\nFamily\nSister's graduation\nType: ceremony\nDue date: 05/19/2021\nPriority: 3\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 4\n====================================\n\n======== Graduation Party ========= grill ============ Priority: 2\nFamily\ncelebration\nType: party\nDue date: 05/19/2021\nPriority: 9\n====================================\nFamily\ncelebration\nType: party\nDue date: 05/10/2021\nPriority: 10\n====================================\n");
}
TEST(TaskListDisplay, SubTop5){
        const char* agrv[] = {"./test", "personal", "party", "ceremony"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/10/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "ceremony", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);

        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);

        TaskList party("Graduation Party", "grill", 2);
        Task fam5("Family", "celebration", "party", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "party", "05/10/2021", 10, agrv);
        party.add(&fam5);
        party.add(&fam6);

        TaskList P_F("Family Party", "Celebration & party", 0);
        P_F.add(&family);
        P_F.add(&party);



        std::stringstream res;
	P_F.set_print(new Print_top5(&P_F));
        P_F.display(res);
        EXPECT_EQ(res.str(), "\n======== Family Party ========= Celebration & party ============ Priority: 0\n\n======== Family ========= meeting ============ Priority: 1\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/10/2021\nPriority: 15\n====================================\nFamily\nSister's graduation\nType: ceremony\nDue date: 05/19/2021\nPriority: 3\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 4\n====================================\n\n======== Graduation Party ========= grill ============ Priority: 2\nFamily\ncelebration\nType: party\nDue date: 05/19/2021\nPriority: 9\n====================================\nFamily\ncelebration\nType: party\nDue date: 05/10/2021\nPriority: 10\n====================================\n"); 
}
TEST(TaskListDisplay, SubPrintType){
        const char* agrv[] = {"./test", "personal", "party", "ceremony"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/10/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "ceremony", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);

        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);

        TaskList party("Graduation Party", "grill", 2);
        Task fam5("Family", "celebration", "party", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "party", "05/10/2021", 10, agrv);
	Task fam7("Buying meeat", "celebration", "personal", "05/10/2021", 5, agrv);
        party.add(&fam5);
        party.add(&fam6);
	party.add(&fam7);

        TaskList P_F("Family Party", "Celebration & party", 0);
        P_F.add(&family);
        P_F.add(&party);



        std::stringstream res;
        P_F.set_print(new Print_type1(&P_F));
        P_F.display(res);
        EXPECT_EQ(res.str(), "\n======== Family Party ========= Celebration & party ============ Priority: 0\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/10/2021\nPriority: 15\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 4\n====================================\nBuying meeat\ncelebration\nType: personal\nDue date: 05/10/2021\nPriority: 5\n====================================\n");
}
TEST(TaskListDisplay, SubListDelete){
        const char* agrv[] = {"./test", "personal", "party", "ceremony"};
        Task fam1("Family", "celebration", "personal", "05/19/2021", 12, agrv);
        Task fam2("Family", "celebration", "personal", "05/10/2021", 15, agrv);
        Task fam3("Family", "Sister's graduation", "ceremony", "05/19/2021", 3, agrv);
        Task fam4("Family", "celebration", "personal", "05/19/2021", 4, agrv);

        TaskList family("Family", "meeting", 1);
        family.add(&fam1);
        family.add(&fam2);
        family.add(&fam3);
        family.add(&fam4);

        TaskList party("Graduation Party", "grill", 2);
        Task fam5("Family", "celebration", "party", "05/19/2021", 9, agrv);
        Task fam6("Family", "celebration", "party", "05/10/2021", 10, agrv);
        Task fam7("Buying meeat", "celebration", "personal", "05/10/2021", 5, agrv);
        party.add(&fam5);
        party.add(&fam6);
        party.add(&fam7);

        TaskList P_F("Family Party", "Celebration & party", 0);
        P_F.add(&family);
        P_F.add(&party);
	//party.del();
	P_F.del_at(1);

        std::stringstream res;
        P_F.set_print(new Print_type1(&P_F));
        P_F.display(res);
	EXPECT_EQ(res.str(),  "\n======== Family Party ========= Celebration & party ============ Priority: 0\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 12\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/10/2021\nPriority: 15\n====================================\nFamily\ncelebration\nType: personal\nDue date: 05/19/2021\nPriority: 4\n====================================\n");
}

#endif
