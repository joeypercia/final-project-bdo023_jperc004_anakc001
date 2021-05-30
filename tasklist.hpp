#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include<string>
#include "basetasks.hpp"
#include "print.hpp"
#include <vector>
#include <algorithm>

class Print;

class TaskList: public BaseTasks{
        private:
                std::string title;
                std::string description;
                int priority;
		std::vector<BaseTasks*> list;
                Print* print = nullptr;
		void swap(BaseTasks* l, BaseTasks* r){
			int pt;
			std::string title;
			std::string type;
			std::string des;
			std::string due;
			
			pt = l->get_priority();
			title = l->get_title();
			type = l->get_type();
			des = l->get_description();
			due = l->get_due_date();
			
			l->set_priority(r->get_priority());
			l->set_title(r->get_title());
			l->set_type(r->get_type());
			l->set_description(r->get_description());
			l->set_due_date(r->get_due_date());

			r->set_priority(pt);
			r->set_title(title);
                        r->set_type(type);
                        r->set_description(des);
                        r->set_due_date(due);
	      }
        public:
		int top_priority(){
			this->sortP();
                	return list.at(4)->get_priority();
             	}

		TaskList(){
		
		};
                void sortP(){
			for(int i = 1; i < list.size(); i++){
				for(int j = 0; j < list.size()-1; j++){
					if(this->get_priority(j) > this->get_priority(j+1)){
						swap(list.at(j),list.at(j+1));
					}
				}
			}
			//sort(list.begin(), list.end());		
		}
		void add(BaseTasks* add){
			list.push_back(add);
		}
		int get_priority(int id){
                        return list.at(id)->get_priority();
                }
                std::string get_title(int id) {
                        return list.at(id)->get_title();
                }
                std::string get_description(int id){
                        return list.at(id)->get_description();
                }
		void set_print(Print* new_print){
                        delete this->print;
                        print = new_print;
                }
		virtual void display(){
			if (list.size() <= 5){
				for(auto task: list){
                                	task->display();
                        	}
			}
			else if(this->print == nullptr){
				for(auto task: list){
					task->display();
				}
			}
			else if(this->print != nullptr){
				for(auto task: list){
					if (this->print->print(task)){
						task->display();
					}
				}
			}
		}
};
#endif //__TASKLIST_HPP__
 
			
