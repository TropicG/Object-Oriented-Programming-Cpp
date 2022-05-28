#ifndef TASK
#define TASK
#include <String>
#include <iostream>
class Task
{
private:
	std::string title;
	std::string desc;
public:
	Task();
	Task(std::string& title, std::string& desc);
	Task(const Task& other);

	std::string getTitle() const;
	std::string getDesc() const;

	void setTitle(const std::string& title);
	void setDesc(const std::string& desc);

	void print() const;
};

#endif 
