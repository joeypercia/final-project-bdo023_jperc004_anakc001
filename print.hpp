#ifndef __PRINT_HPP__
#define __PRINT_HPP__

#include "basetasks.hpp" 
#include "task.hpp"


#include <string>
#include <cstring>
#include <iostream>

class Print{
	public:
		virtual bool print(BaseTasks* t) = 0;
		Print(){ }
		//virtual bool print_str(BaseTasks* t, string temp) = 0;
};

class Print_top5: public Print{
	private:
		BaseTasks* list = nullptr;
	public:	
		Print_top5(BaseTasks* t){
			t->sortP();
			list = t;
		}
		
		virtual bool print(BaseTasks* t){
			if (t->get_priority() <= list->top_priority() ){
				return true;
			}
			else return false;
		}
};
class Print_type1: public Print{
        private:
                BaseTasks* list = nullptr;
        public:
                Print_type1(BaseTasks* t){
                        list = t;
                }

                virtual bool print(BaseTasks* t){
			if (t->get_type() == t->get_type1()){
                        	return true;
                        }
                        else return false;
                }
};
class Print_type2: public Print{
        private:
                BaseTasks* list = nullptr;
        public:
                Print_type2(BaseTasks* t){
                        list = t;
                }

                virtual bool print(BaseTasks* t){
                	if (t->get_type() == t->get_type2()){
                        	return true;
                  	}       
                       	else return false;
		}
};
class Print_type3: public Print{
        private:
                BaseTasks* list = nullptr;
        public:
                Print_type3(BaseTasks* t){
                        list = t;
                }

                virtual bool print(BaseTasks* t){
               		if (t->get_type() == t->get_type3()){
                        	return true;
                       	}
                       	else return false;
       		}
};



#endif //__PRINT_HPP__
