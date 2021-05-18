#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__

#include <string>
#include "basetasks.hpp"
#include "task.hpp"
#include "print.hpp"
#include <vector>

class Print;

class TaskList: public BaseTasks{
        private:
			std::string title;
			std::string description;
			int priority;
			std::vector<BaseTasks*> list;
			Print* print = nullptr;
        public:
			TaskList(){ };
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
				if(this->print == nullptr){
					for(auto task: list){
						task->display();
					}
				}
				if(this->print != nullptr){
					for(auto task: list){
						if (this->print->print(task)){
							task->display();
						}
					}
				}
			}

			virtual void del() {
				// TODO : Implement function to completely remove the task list.
				title = "";
				description = "";
				priority = -1;
				for(unsigned i = 0; i < list.size(); i++) { // Deallocate vector of pointers
					list.at(i)->del();
				}
				delete this->print;

				return;
			}

			virtual void remove(Task* taskName) {
				// TODO: Implement function to remove one task in the list.
				taskName->del();
				
			}

};
#endif //__TASKLIST_HPP__
 
			
