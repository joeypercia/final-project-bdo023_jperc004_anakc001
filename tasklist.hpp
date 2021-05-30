#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include<string>
#include "basetasks.hpp"
#include "task.hpp"
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
		void swap(int _1, int _2){
		  BaseTasks* temp = list.at(_1);
		  list.at(_1) = list.at(_2);
		  list.at(_2) = temp; 
		/*if(l->get_size() == 1 && r->get_size() == 1){	
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
		   }*/
		   
	      }
	      friend class Print_top5;
        public:
		
		~TaskList(){
			delete print;
		}
		TaskList(std::string title, std::string description, int p){
			this->priority = p;
			this->title = title;
			this->description = description;	
		};
		int top_priority(){
                        this->sortP();
			if(list.size() >= 5)
				return list.at(4)->get_priority();
			else return list.at(list.size()-1)->get_priority();
              	}

                void sortP(){
			for(int i = 1; i < list.size(); i++){
				for(int j = 0; j < list.size()-1; j++){
					if(list.at(j)->get_priority() > list.at(j+1)->get_priority()){
						swap(j,j+1);
					}
				}
			}
		}
		void add(BaseTasks* add){
			list.push_back(add);
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
		void set_print(Print* new_print){
                        delete this->print;
                        print = new_print;
                }
		virtual void display(){
			std::cout<< std::endl << "======== " << this->title << " ========= "<< this->description << " ============ Priority: " << this->priority << std::endl;
			//if (list.size() <= 5){
				//for(auto task: list){
					//task->display();
                        	//}
			//}
			if(this->print == nullptr){
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
 
			
