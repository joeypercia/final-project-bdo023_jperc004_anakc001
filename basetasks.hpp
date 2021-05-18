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
		virtual std::string get_title() { }
		virtual std::string get_description() { }
		virtual std::string get_type() { }
		virtual std::string get_due_date(){ } 
		
		virtual void display() = 0;
		//virtual void edit() = 0;
		//virtual void del() = 0;

};
#endif //__BASETASKS_HPP__
