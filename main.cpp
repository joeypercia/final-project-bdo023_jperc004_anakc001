#include "task.hpp"
#include "print.hpp"
#include "tasklist.hpp"
#include <iostream> 

int main() 
{
	Task hw("Math#2", "Derivative#1", "study", "5/17/2021", 1);
	//hw.set_print(new Print_top5(&hw));
	//hw.display();
	Task hw1("Math#2", "Derivative#2", "study", "5/18/2021", 3);
        //hw1.set_print(new Print_top5(&hw1));
        //hw1.display();
	Task hw2("Math#2", "Derivative#3", "study", "5/18/2021", 4);
        //hw2.set_print(new Print_top5(&hw2));
        //hw2.display();
	Task hw3("Math#2", "Derivative#4", "study", "5/19/2021", 6);
	Task hw4("Math#2", "Derivative#5", "study", "5/19/2021", 2);
        //hw3.set_print(new Print_top5(&hw3));
        //hw3.display();

	TaskList mathHWs;
	mathHWs.add(&hw);
	mathHWs.add(&hw1);
	mathHWs.add(&hw2);
	mathHWs.add(&hw3);
	mathHWs.add(&hw4);
	
	mathHWs.set_print(new Print_top5(&mathHWs));
	mathHWs.display();	

	return 0;
}
