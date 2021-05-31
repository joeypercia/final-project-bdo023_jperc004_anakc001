#ifndef __BASETASKS_HPP__
#define __BASETASKS_HPP__
#include <vector>
class Print;

class BaseTasks {
	protected:
		Print* print = nullptr;
		virtual void set_priority(int t){ }
                virtual void set_title(std::string t){ }
                virtual void set_type(std::string t){ }
                virtual void set_description(std::string t){ }
                virtual void set_due_date(std::string t){ }

	public:
		BaseTasks(){ }
		virtual ~BaseTasks() { }
		
			
		virtual int top_priority(){ }
		virtual void sortP() { }
		virtual int get_size(){ }
		virtual std::string get_type1(){ }
		virtual std::string get_type2(){ }
		virtual std::string get_type3(){ }
		virtual std::vector<BaseTasks*> get_list(){ }
 
		virtual int get_priority() { }
		virtual std::string get_title() { }
		virtual std::string get_description() { }
		virtual std::string get_type() { }
		virtual std::string get_due_date(){ } 
		
		virtual void display() = 0;
		virtual void edit(std::string t, std::string d, std::string type, std::string date, int p) { }
		virtual void edit_list(std::string t, std::string d, int p){ }
		virtual void edit_list_at(std::string t, std::string d, std::string type, std::string date, int p, int id){ }
		virtual void del() = 0;
		virtual void del_task(BaseTasks* t){ }
		virtual void del_at(int id){ }
		friend class TaskList;
};
#endif //__BASETASKS_HPP__
