#ifndef __BASETASKS_HPP__
#define __BASETASKS_HPP__

class Print;

class BaseTasks {
	private:
		Print* print = nullptr;
	public:
		BaseTasks(){ }
		virtual ~BaseTasks() { }
		
		virtual int get_priority() = 0;
		virtual std::string get_title() = 0;
		virtual std::string get_description() = 0;
		virtual std::string get_type() = 0;
		virtual std::string get_due_date() = 0;
		
		virtual void display() = 0;
		//virtual void edit() = 0;
		//virtual void del() = 0;

};
#endif //__BASETASKS_HPP__
