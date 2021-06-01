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
	      	}
		
	      	friend class Print_top5;
        public:
		
		~TaskList(){
			delete print;
		}
		TaskList(){ }
		TaskList(std::string title, std::string description, int p){
			this->priority = p;
			this->title = title;
			this->description = description;	
		};
		void edit_list(std::string t, std::string d, int p){
			this->priority = p;
                        this->title = t;
                        this->description = d;
		}
		void edit_list_at(std::string t, std::string d, std::string type, std::string date, int p, int id ){
			if(dynamic_cast<Task*>(list.at(id)) != nullptr){
				list.at(id)->edit(t,d,type,date,p);
			}
			else if(dynamic_cast<TaskList*>(list.at(id)) != nullptr){
				list.at(id)->edit_list(t,d,p);
			}
		}
		int get_size(){
                        return list.size();
                }
		std::vector<BaseTasks*> get_list(){
			return this->list;
		}
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
		std::string get_type(){
			return "LIST DOES NOT HAVE TYPE";
		}
		std::string get_due_date(){
			return "LIST DOES NOT HAVE DUE DATE";
		}
		void set_print(Print* new_print){
                        delete this->print;
                        print = new_print;
                }
		virtual void display(std::ostream& cout){
			if(list.size() ==0){
				cout << "";
			}
			else{
			cout<< std::endl << "======== " << this->title << " ========= "<< this->description << " ============ Priority: " << this->priority << std::endl;
			if(this->print == nullptr){
				for(auto task: list){
					task->display(cout);
				}
			}
			else if(dynamic_cast<Print_top5*>(print) != nullptr){
				for(auto task: list){
					if (this->print->print(task)){
						task->display(cout);
					}
				}
			}
			else if(dynamic_cast<Print_type1*>(print) != nullptr || dynamic_cast<Print_type2*>(print) != nullptr || dynamic_cast<Print_type3*>(print) != nullptr || 
			dynamic_cast<Print_date*>(print) != nullptr){
				for(auto task: list){
                                	if(dynamic_cast<Task*>(task) != nullptr){
						if (this->print->print(task)){
                                        		task->display(cout);
                                		}
					}
					else if(dynamic_cast<TaskList*>(task) != nullptr){
						for(auto task2: task->get_list()){
							if(this->print->print(task2)){
								task2->display(cout);
							}
						
						}
					}
                                }
  			}
			}
		}
		virtual void del(){
			std::vector<BaseTasks*>::iterator it;
			for(it = list.begin(); it != list.end(); it++){
				list.erase(it);
			}
			list.resize(0);
		}
		virtual void del_at(int id){
			auto it = list.begin() + id;
			list.erase(it);
		}
			 		
};
#endif //__TASKLIST_HPP__
 
			
