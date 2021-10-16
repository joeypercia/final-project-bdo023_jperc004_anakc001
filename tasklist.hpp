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
	int priority = 0;
	std::vector<BaseTasks*> list;
	Print* print = nullptr;
public:
	TaskList() {
		this->title = "";
		this->description = "";
		this->type = "";
		this->duedate = "";
		this->TaskList::priority = 0;
		this->print = nullptr;
	}
	TaskList(std::string title, std::string description, std::string type, std::string duedate, int priority) {
		this->title = title;
		this->description = description;
		this->type = type;
		this->duedate = duedate;
		this->priority = priority;
		this->print = nullptr;
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
	BaseTasks* getTask(int index)
	{
		return this->list.at(index);
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
	void set_priority(int userpriority) {
		this->priority = userpriority;
	}
	void set_title(std::string usertitle) {
		this->title = usertitle;
	}
	void set_description(std::string userdescription) {
		this->description = userdescription;
	}
	void set_due_date(std::string userduedate) {
		this->duedate = userduedate;
	}
	void set_type(std::string usertype) {
		this->type = usertype;
	}
	bool islist() { return true; }
	int get_size() { return this->list.size(); }
	BaseTasks* get_task(int index) { return this->list.at(index); }
	void add(BaseTasks* task) { this->list.push_back(task); }
	void del(int index) { this->list.erase(list.begin() + index); }
};
#endif //__TASKLIST_HPP__
 
			
