#ifndef __TASK_HPP__
#define __TASK_HPP__

#include<string>
#include "basetasks.hpp"
#include "print.hpp"


class Print;

class Task: public BaseTasks{
	private:
		std::string title;
		std::string description;
		std::string type;
		std::string due_date;
		int priority;
		Print* print = nullptr;
	public:
		Task(std::string title, std::string des, std::string type, std::string due_date, int priority){
			this->title = title;
                        this->description = des;
                        if(type == "personal" || type == "study" || type == "work"){
                                this->type = type;
                        }
                        else{
                                while(type != "personal" && type != "study" && type != "work"){
                                        std::cout << "Type can only be \"personal\", \"study\", or \"work\". Please enter again: " << std::endl;
                                        std::string t;
                                        std::cin >> t;
                                        type = t;
                                }
                                this->type = type;
                        }
                        this->priority = priority;
                        this-> due_date = due_date;
		};
		void set_print(Print* new_print){
			delete this->print;
			print = new_print;
		}
		void set_priority(int t){ 
			this->priority = t;
		}
		void set_title(std::string t){
			this->title = t;
		}
		void set_type(std::string t){
			this->type = t;
		}
   		void set_description(std::string t){
			this->description = t;
		}
		void set_due_date(std::string t){
			this->due_date = t;
		}
		int get_priority(){
			return this->priority;
		}
		std::string get_title() {
			return this->title;
		}
		std::string get_description(){
			return this->description;
		}
		std::string get_type(){
			return this->type;
		}
		std::string get_due_date(){
			return this->due_date;
		}
		
		virtual void display(){
			if(this->print == nullptr){
				std::cout << this->get_title() << std::endl;
				std::cout << this->get_description() << std::endl;
				std::cout << "Type: " << this->get_type() << std::endl;
				std::cout << "Due date: " <<  this->get_due_date() << std::endl;
				std::cout << "Priority: " <<  this->get_priority() << std::endl;
				std::cout << "====================================" << std::endl;
			}
			if (this->print != nullptr){
				if(this->print->print(this)){
					std::cout << this->get_title() << std::endl;
                                	std::cout << this->get_description() << std::endl;
					std::cout << "Type: " << this->get_type() << std::endl;
                                	std::cout << "Due date: " << this->get_due_date() << std::endl;
                                	std::cout << "Priority: " <<  this->get_priority() << std::endl;
					std::cout << "=================================" << std::endl;
				}
			}
		}

};
#endif //__TASK_HPP__
