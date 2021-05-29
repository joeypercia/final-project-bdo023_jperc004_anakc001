#ifndef __TASK_HPP__
#define __TASK_HPP__

#include<string>
#include "basetasks.hpp"
#include "print.hpp"


class Print;

class Task : public BaseTasks {
private:
	std::string title;
	std::string description;
	std::string type;
	std::string due_date;
	int priority;
	Print* print = nullptr;
public:
	Task(std::string title, std::string des, std::string type, std::string due_date, int priority) {
		this->title = title;
		this->description = des;
		this->type = type;
		this->priority = priority;
		this->due_date = due_date;
	};
	void set_print(Print* new_print) {
		delete this->print;
		print = new_print;
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
		return this->due_date;
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
		this->due_date = userduedate;
	}
	void set_type(std::string usertype) {
		this->type = usertype;
	}

	virtual void display() {
		if (this->print == nullptr) {
			std::cout << this->get_title() << std::endl;
			std::cout << this->get_description() << std::endl;
			std::cout << this->get_type() << std::endl;
			std::cout << this->get_due_date() << std::endl;
			std::cout << this->get_priority() << std::endl;
			std::cout << "====================================" << std::endl;
		}
		if (this->print != nullptr) {
			if (this->print->print(this)) {
				std::cout << this->get_title() << std::endl;
				std::cout << this->get_description() << std::endl;
				std::cout << this->get_type() << std::endl;
				std::cout << this->get_due_date() << std::endl;
				std::cout << this->get_priority() << std::endl;
				std::cout << "=================================" << std::endl;
			}
		}
	}
	bool islist() { return false; }
};
#endif //__TASK_HPP__
