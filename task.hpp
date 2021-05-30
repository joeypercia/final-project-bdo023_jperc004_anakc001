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
		
		std:: string t1;
		std:: string t2;
		std:: string t3;
		void set_available_type(const char* agrv[]){
                        t1 = agrv[1];
                        t2 = agrv[2];
                        t3 = agrv[3];
                }
		std::string get_type1(){
                        return t1;
                }
                std::string get_type2(){
                        return t2;
                }
                std::string get_type3(){
                        return t3;
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

		friend class Print_type1;
		friend class TaskList;

	public:
		Task(std::string title, std::string des, std::string type, std::string due_date, int priority, const char* argv[]){
			this->title = title;
                        this->description = des;
			set_available_type(argv);
                        if(type == t1 || type == t2 || type == t3){
                                this->type = type;
                        }
                        else{
                               	while(type != t1 && type != t2 && type != t3){
                                   std::cout << "Type " << type << " is invalid. Type can only be \"" << t1 << "\", \"" << t2 << "\", or \"" <<t3<< "\". Please enter again: " << std::endl;
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
		int get_size(){
			return 1;
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
			std::cout << this->get_title() << std::endl;
			std::cout << this->get_description() << std::endl;
			std::cout << "Type: " << this->get_type() << std::endl;
			std::cout << "Due date: " <<  this->get_due_date() << std::endl;
			std::cout << "Priority: " <<  this->get_priority() << std::endl;
			std::cout << "====================================" << std::endl;
		}

};
#endif //__TASK_HPP__
