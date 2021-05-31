#pragma once
//#include "basetasks.hpp"
#include "task.hpp"
#include "print.hpp"
#include "tasklist.hpp"
#include <iostream> 
#include <string>
#include <stack>

BaseTasks* inputTask();
TaskList* inputTaskList();
void modifyTask(int index, std::string parameter, TaskList& userList);
TaskList undo(std::stack<TaskList>& userStack);
void addtoStack(std::stack<TaskList>& userStack, TaskList userList);

int main() 
	{
	char userinput = '0';
	int userindex = 0;
	std::string userparameter = "0";
	TaskList userList;
	std::stack<TaskList> undoStack;
	addtoStack(undoStack, userList);

	while (userinput != 'q') {
		std::cout << "Main Menu" << std::endl;
		std::cout << "a - Add a task" << std::endl;
		std::cout << "l - Add a tasklist" << std::endl;
		std::cout << "r - Remove a task/tasklist" << std::endl;
		std::cout << "p - Print all tasks" << std::endl;
		std::cout << "v - View your tasklists" << std::endl; 
		//std::cout << "s - Select a strategy to display certain tasks" << std::endl;
		std::cout << "m - Modify a task/tasklist" << std::endl;
		std::cout << "u - Undo previous operation" << std::endl;
		std::cout << "q - Quit Task Scheduler" << std::endl;
		std::cout << "Please enter a character: ";
		std::cin >> userinput;
		std::cout << std::endl;

		if (userinput == 'a')
		{
			BaseTasks* userTask = inputTask();
			userList.add(userTask);
			addtoStack(undoStack, userList);
		}
		else if (userinput == 'l')
		{
			TaskList* newTaskList = inputTaskList();
			
			while (userinput != 'n') {
				userinput = '0';
				BaseTasks* userTask = inputTask();
				newTaskList->add(userTask);
				//addtoStack(undoStack, userList);
				std::cout << "Continue inputting tasks to your tasklist? Input y/n" << std::endl;
				while (userinput != 'y' && userinput != 'n')
				{
					std::cin >> userinput;
				}
				
			}
			BaseTasks* userTask = newTaskList;
			userList.add(userTask);
			addtoStack(undoStack, userList);
		}
		else if (userinput == 'r')
		{
			if(userList.getsize() <= 0) {
				std::cout << "There are no tasks to be removed." << std::endl;
				std::cout << std::endl;
			}
			else {
				for (int i = 0; i < userList.getsize(); ++i)
				{
					std::cout << i << ": " << userList.get_title(i) << std::endl;
				}

				std::cout << "Please enter the index of the task or tasklist you'd like to remove:" << std::endl;
				std::cin >> userindex;
				userList.removeTask(userindex);
				addtoStack(undoStack, userList);
			}
		}
		else if (userinput == 'p') {
			for (int i = 0; i < userList.getsize(); ++i) {
				std::cout << userList.get_title(i) << ": " << userList.get_description(i) << std::endl << userList.get_type(i) << std::endl << userList.get_due_date(i)
					<< std::endl << userList.get_priority(i) << std::endl << std::endl;
			}
		}
		
		//todo: Change modify function to be able to modify the subtasks of a user's tasklist.
		else if (userinput == 'm')
		{
			for (int i = 0; i < userList.getsize(); ++i)
			{
				std::cout << i << ": " << userList.get_title(i) << std::endl;
			}
			// add error checking
			std::cout << "Please enter the index of the task or tasklist you'd like to modify:" << std::endl;
			std::cin >> userindex;
			std::cout << "Please enter the parameter you'd like to modify (title, description, type, duedate, priority, or subtask)"
				<< std::endl;
			std::cin >> userparameter;
			modifyTask(userindex, userparameter, userList);
			addtoStack(undoStack, userList);
		}
		else if (userinput == 'v') {
			for (int i = 0; i < userList.getsize(); ++i)
			{
				if (userList.islist() == true) {
					std::cout << i << ": " << userList.get_title(i) << std::endl;
				}
			}
				
			std::cout << "Please enter the index of the tasklist you'd like to view:" << std::endl;
			std::cin >> userindex;
			userList.getTask(userindex)->display();
		}
		else if (userinput == 'u') {
			if (undoStack.size() == 1) {
				std::cout << "Can not undo, list is already empty" << std::endl;
			}
			else {
				userList = undo(undoStack);
			}
		}
		else if (userinput == 'q') {
			return 0;
		}
	}

	return 0;
};

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

TaskList* inputTaskList() {
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

	TaskList* userTask = new TaskList(title, description, tasktype, duedate, priority);
	return userTask;
	// userList.add(userTask);
}

void modifyTask(int index, std::string parameter, TaskList& userList) {
	std::string userentry;
	if (parameter == "title")
	{
		std::cout << "Please enter the new title" << std::endl;
		std::cin >> userentry;
		userList.getTask(index)->set_title(userentry);
		return;
		// prompt for user to modify another task/parameter?
	}
	else if (parameter == "description")
	{
		std::cout << "Please enter the new description" << std::endl;
		std::cin.ignore(100, '\n');
		std::getline(std::cin, userentry);
		userList.getTask(index)->set_description(userentry);
		return;
	}
	else if (parameter == "type")
	{
		std::cout << "Please enter the new type" << std::endl;
		std::cin >> userentry;
		userList.getTask(index)->set_type(userentry);
		return;
	}
	else if (parameter == "duedate")
	{
		std::cout << "Please enter the new duedate" << std::endl;
		std::cin >> userentry;
		userList.getTask(index)->set_due_date(userentry);
		return;
	}
	else if (parameter == "priority")
	{
		std::cout << "Please enter the new priority" << std::endl;
		std::cin >> userentry;
		int userentryint = std::stoi(userentry);
		userList.getTask(index)->set_priority(userentryint);
		return;
	}
	else if (parameter == "subtask")
	{
		int userindex;
		std::string userparameter;
		//print all subtasks with indexes? 
		//userList.getTask(index)->display();
		// enter index of subtask
		for (int i = 0; i < userList.getTask(index)->get_size(); ++i)
		{
			std::cout << i << ": " << userList.getTask(index)->get_task(i)->get_title() << std::endl;
		}
		
		std::cout << "Please enter the parameter you'd like to modify(title/description/type/duedate/priority)" << std::endl;
		std::cout << "if you wish to add a new subtask to this tasklist, enter: add" << std::endl;
		std::cout << "to delete the subtask, enter: delete" << std::endl;
		std::cin >> userentry;
		if (userentry == "add")
		{
			BaseTasks* newTask = inputTask();
			userList.getTask(index)->add(newTask);
			return;
		}
		std::cout << "Please enter the index of the subtask you'd like to modify:" << std::endl;
		std::cin >> userindex;
		if (userentry == "delete")
		{
			userList.getTask(index)->del(userindex);
			return;
		}
		std::cout << "Please enter the new " << userentry << std::endl;
		if (userentry == "description")
		{
			
			std::cin.ignore(100, '\n');
			std::getline(std::cin, userparameter);
			userList.getTask(index)->get_task(userindex)->set_description(userparameter);
			return;
		}

		std::cin >> userparameter;


		int userentryint = 0;

		if (userentry == "priority") {
			userentryint = std::stoi(userparameter);
			userList.getTask(index)->get_task(userindex)->set_priority(userentryint);
			return;
		}

		if (userentry == "title")
		{
			userList.getTask(index)->get_task(userindex)->set_title(userparameter);
			return;
		}

		else if (userentry == "type")
		{
			userList.getTask(index)->get_task(userindex)->set_type(userparameter);
			return;
		}
		else // userentry == duedate
		{
			userList.getTask(index)->get_task(userindex)->set_due_date(userparameter);
			return;
		}



	}
}

TaskList undo(std::stack<TaskList>& userStack)
{
	userStack.pop();
	return userStack.top();
};
void addtoStack(std::stack<TaskList>& userStack, TaskList userList)
{
	userStack.push(userList);
};
