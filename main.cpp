#include "task.hpp"
#include "print.hpp"

#include <iostream> 

int main() 
{
	Task hw("Math#2", "Derivative", "study", "5/17/2021", 6);
	hw.set_print(new Print_top5(&hw));
	hw.display();

	return 0;
}
