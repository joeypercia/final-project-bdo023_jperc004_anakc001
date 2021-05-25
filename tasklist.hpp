#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include<string>
#include "basetasks.hpp"
#include "print.hpp"
#include <vector>

class Print;

class TaskList : public BaseTasks {
private:
	std::string title;
	std::string description;
	std::string type;
	std::string duedate;
	int priority;
	std::vector<BaseTasks*> list;
	Print* print = nullptr;
public:
	TaskList() {

	};
	void add(BaseTasks* add) {
		list.push_back(add);
	}
	int get_priority() {
		return this->priority;
	}
	std::string get_title() {
		return this->title;
	}
	std::string get_description() {
		return this->description;
	}
	std::string get_type() {
		return this->type;
	}
	std::string get_due_date() {
		return this->duedate;
	}
	void set_print(Print* new_print) {
		delete this->print;
		print = new_print;
	}
	
	virtual void display() {
		if (this->print == nullptr) {
			for (auto task : list) {
				task->display();
			}
		}
		if (this->print != nullptr) {
			for (auto task : list) {
				if (this->print->print(task)) {
					task->display();
				}
			}
		}
	}
	void removeTask(int index)
	{
		list.erase(list.begin() + index);
	}
	int getsize() {
		return list.size();
	}
	std::string get_title(int index)
	{
		return list.at(index)->get_title();
	}
	std::string get_description(int index) {
		return list.at(index)->get_description();
	}
	std::string get_type(int index)
	{
		return list.at(index)->get_type();
	}
	std::string get_due_date(int index)
	{
		return list.at(index)->get_due_date();
	}
	int get_priority(int index)
	{
		return list.at(index)->get_priority();
	}
};
#endif //__TASKLIST_HPP__
 
			
