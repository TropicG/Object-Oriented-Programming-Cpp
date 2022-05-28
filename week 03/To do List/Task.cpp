#include "Task.h"

Task::Task() : title("none"), desc("none")
{
}

Task::Task(std::string& title, std::string& desc)
{
	this->setTitle(title);
	this->setDesc(desc);
}

Task::Task(const Task& other)
{
	this->setTitle(other.getTitle());
	this->setDesc(other.getDesc());
}

std::string Task::getTitle() const
{
	return this->title;
}

std::string Task::getDesc() const
{
	return this->desc;
}

void Task::setTitle(const std::string& title)
{
	this->title = title;
}

void Task::setDesc(const std::string& desc)
{
	this->desc = desc;
}

void Task::print() const
{
	std::cout << "The name of the task is: " << getTitle() << " and its description is: " << getDesc() << std::endl;
}
