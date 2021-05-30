#include "task.hpp"
#include "print.hpp"
#include "tasklist.hpp"
#include <iostream> 

int main(int argc, const char* argv[]) 
{
	Task hw("Math#2", "Derivative#1", "gg", "5/17/2021", 1, argv);
	Task hw1("Math#2", "Derivative#2", "study", "5/18/2021", 3, argv);
	Task hw2("Math#2", "Derivative#3", "study", "5/18/2021", 4, argv);
	Task hw3("Math#2", "Derivative#4", "study", "5/19/2021", 6, argv);
	Task hw4("Math#2", "Derivative#5", "study", "5/19/2021", 2, argv);

	TaskList mathHWs;
	mathHWs.add(&hw);
	mathHWs.add(&hw1);
	mathHWs.add(&hw2);
	mathHWs.add(&hw3);
	mathHWs.add(&hw4);
	mathHWs.sortP();
	
	mathHWs.set_print(new Print_top5(&mathHWs));
	mathHWs.display();	

	return 0;
}
