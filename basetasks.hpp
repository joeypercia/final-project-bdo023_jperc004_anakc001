#ifndef __BASETASKS_HPP__
#define __BASETASKS_HPP__

class Print;

class BaseTasks {
	private:
		Print* print = nullptr;
	public:
		BaseTasks(){ }
		virtual ~BaseTasks() { }
		
		virtual int get_priority() { }

                virtual void set_priority(int t){ }
		virtual void set_title(std::string t){ }
		virtual void set_type(std::string t){ }
		virtual void set_description(std::string t){ }
		virtual void set_due_date(std::string t){ } 
 
		virtual std::string get_title() { }
		virtual std::string get_description() { }
		virtual std::string get_type() { }
		virtual std::string get_due_date(){ } 
		
		virtual void display() = 0;
		//virtual void edit() = 0;
		//virtual void del() = 0;

};
#endif //__BASETASKS_HPP__
