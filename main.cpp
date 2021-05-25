#include "task.hpp"
#include "print.hpp"
#include "tasklist.hpp"
#include <iostream> 

BaseTasks* inputTask() {
	std::cout << "Please enter title" << std::endl;
	std::string title, description, tasktype, duedate;
	int priority;
	std::cin >> title;
	std::cout << "Please enter a description" << std::endl;
	std::cin.ignore(100, '\n');
	std::getline(std::cin, description);
	std::cout << "Please enter the tasktype" << std::endl;
	std::cin >> tasktype;
	std::cout << "Please enter the duedate (MM/DD/YYYY)" << std::endl;
	std::cin >> duedate;
	std::cout << "Please enter the priority (#)" << std::endl;
	std::cin >> priority;

	BaseTasks* userTask = new Task(title, description, tasktype, duedate, priority);
	return userTask;
	// userList.add(userTask);
}

int main() 
{
#pragma once
	//#include "basetasks.hpp"
#include "print.hpp"
#include "tasklist.hpp"
#include "task.hpp"
#include "print.hpp"

		char userinput = '0';
		int userindex = 0;
		TaskList userList;


		while (userinput != 'q') {
			std::cout << "Main Menu" << std::endl;
			std::cout << "a - Add a task" << std::endl;
			std::cout << "l - Add a tasklist" << std::endl;
			std::cout << "r - Remove a task/tasklist" << std::endl;
			std::cout << "q - Quit Task Scheduler" << std::endl;
			std::cout << "p - Print all tasks" << std::endl;
			std::cout << "Please enter a character: ";
			std::cin >> userinput;
			std::cout << std::endl;

			if (userinput == 'a')
			{

				BaseTasks* userTask = inputTask();
				userList.add(userTask);
			}
			else if (userinput == 'l')
			{
				//todo: make for loop to get inputs until told to stop by user
			}
			else if (userinput == 'r')
			{
				for (int i = 0; i < userList.getsize(); ++i)
				{
					std::cout << i << ": " << userList.get_title(i) << std::endl;
				}

				std::cout << "Please enter the index of the task or tasklist you'd like to remove:" << std::endl;
				std::cin >> userindex;
				userList.removeTask(userindex);
			}
			else if (userinput == 'p') {
				for (int i = 0; i < userList.getsize(); ++i) {
					std::cout << userList.get_title(i) << ": " << userList.get_description(i) << std::endl << userList.get_type(i) << std::endl << userList.get_due_date(i)
						<< std::endl << userList.get_priority(i) << std::endl << std::endl;
				}
			}
			else if (userinput == 'q') {
				return 0;
			}
		}

		Task hw("Math#2", "Derivative", "study", "5/17/2021", 6);
		hw.set_print(new Print_top5(&hw));
		hw.display();
	return 0;
};
	//Task hw("Math#2", "Derivative#1", "study", "5/17/2021", 1);
	////hw.set_print(new Print_top5(&hw));
	////hw.display();
	//Task hw1("Math#2", "Derivative#2", "study", "5/18/2021", 3);
 //       //hw1.set_print(new Print_top5(&hw1));
 //       //hw1.display();
	//Task hw2("Math#2", "Derivative#3", "study", "5/18/2021", 4);
 //       //hw2.set_print(new Print_top5(&hw2));
 //       //hw2.display();
	//Task hw3("Math#2", "Derivative#4", "study", "5/19/2021", 6);
	//Task hw4("Math#2", "Derivative#5", "study", "5/19/2021", 2);
 //       //hw3.set_print(new Print_top5(&hw3));
 //       //hw3.display();

	//TaskList mathHWs;
	//mathHWs.add(&hw);
	//mathHWs.add(&hw1);
	//mathHWs.add(&hw2);
	//mathHWs.add(&hw3);
	//mathHWs.add(&hw4);
	//
	//mathHWs.set_print(new Print_top5(&mathHWs));
	//mathHWs.display();	