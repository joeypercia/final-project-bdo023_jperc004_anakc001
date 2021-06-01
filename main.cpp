#include "task.hpp"
#include "print.hpp"
#include "tasklist.hpp"
#include <iostream> 

int main(int argc, const char* argv[]) 
{
	Task hw("Math#2", "Derivative#1", "study", "05/17/2021", 1, argv);
	Task hw1("Math#2", "Derivative#2", "study", "05/18/2021", 5, argv);
	Task hw2("Math#2", "Derivative#3", "study", "05/18/2021", 7, argv);
	Task hw3("Math#2", "Derivative#4", "study", "05/19/2021", 10, argv);
	Task hw4("Math#2", "Derivative#5", "study", "05/19/2021", 3, argv);
	Task work("Intern", "Talk with professor", "work", "05/19/2021", 11, argv);
	Task fam1("Family", "Sister's graduation", "personal", "05/19/2021", 12, argv);
	Task fam2("Family", "celebration", "personal", "05/19/2021", 15, argv);	

	TaskList school("School works", "Hws & intern", 0);
	school.add(&hw);
	school.add(&hw1);
	school.add(&hw2);
	school.add(&hw3);
	school.add(&hw4);
	school.add(&work);

	TaskList family("Family", "meeting", 1);
	family.add(&fam1);
	family.add(&fam2);
	
	TaskList HW_fam("HW&fam", "to do this week", 0);
	HW_fam.add(&family);
	HW_fam.add(&school);
	
	HW_fam.display();
	//work.del();
	school.del_at(5);
	HW_fam.display();
	
	/*
	HW_fam.set_print(new Print_top5(&HW_fam));
        HW_fam.display();
	hw1.edit("Math#2", "Integral#1", "study", "05/17/2021", 1);
	HW_fam.edit_list("School&fam", "to do this week", 0);
			
	HW_fam.set_print(new Print_type1(&HW_fam));
	HW_fam.display();
	HW_fam.set_print(new Print_type2(&HW_fam));
	HW_fam.display();
	work.del();
	HW_fam.set_print(new Print_type3(&HW_fam));
	HW_fam.display();
	HW_fam.set_print(new Print_date(&HW_fam, "05/19/2021"));
	HW_fam.display();
	*/
	


	return 0;
}
