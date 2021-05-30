#include "task.hpp"
#include "print.hpp"
#include "tasklist.hpp"
#include <iostream> 

int main(int argc, const char* argv[]) 
{
	Task hw("Math#2", "Derivative#1", "study", "5/17/2021", 1, argv);
	Task hw1("Math#2", "Derivative#2", "study", "5/18/2021", 5, argv);
	Task hw2("Math#2", "Derivative#3", "study", "5/18/2021", 7, argv);
	Task hw3("Math#2", "Derivative#4", "study", "5/19/2021", 10, argv);
	Task hw4("Math#2", "Derivative#5", "study", "5/19/2021", 3, argv);
	Task hw5("Math#2", "Derivative#10", "study", "5/19/2021", 11, argv);
	Task fam1("Family", "Sister's graduation", "personal", "5/19/2021", 12, argv);
	Task fam2("Family", "celebration", "personal", "5/19/2021", 15, argv);	

	TaskList mathHWs("Calc HWs", "Hws & family meeting", 0);
	mathHWs.add(&hw);
	mathHWs.add(&hw1);
	mathHWs.add(&hw2);
	mathHWs.add(&hw3);
	mathHWs.add(&hw4);
	mathHWs.add(&hw5);

	TaskList family("Family", "meeting", 1);
	family.add(&fam1);
	family.add(&fam2);
	
	TaskList HW_fam("HW&fam", "to do this week", 0);
	HW_fam.add(&family);
	HW_fam.add(&mathHWs);
	
	//HW_fam.display();
	HW_fam.set_print(new Print_top5(&HW_fam));
	HW_fam.display();
	
	//std::cout << std::endl << "Family tasks: " << std::endl;
	//mathHWs.set_print(new Print_type1(&mathHWs));
        //mathHWs.display();


	return 0;
}
