#include "doList.h"

//creating a newlist with the last capacity
//copping tasks from the old list to the new one
//creating a bigger one with double capacity
//moving all the elements from newList to the old one
void ToDoList::resize()
{

	ToDoList newList;
	newList.tasks = new (std::nothrow) Task[capacity];

	for (int i = 0; i < index; ++i) {
		newList.tasks[i] = this->tasks[i];
	}
	delete[] this->tasks;

	this->capacity *= 2;

	this->tasks = new (std::nothrow) Task[capacity];
	for (int i = 0; i < index; ++i) {
		tasks[i] = newList.tasks[i];
	}
}

ToDoList::ToDoList() : index(0), capacity(128)
{
	this->tasks = new (std::nothrow) Task[capacity];
}

ToDoList::~ToDoList()
{
	delete[] tasks;
}

void ToDoList::pushTask(const Task& task)
{
	if (index + 1 >= capacity) {
		resize();
	}

	tasks[index++] = task;
}

void ToDoList::popTask()
{
	if (isEmpty())
	{
		std::cout << "The list is empty!" << std::endl;
		return;
	}
	index--;
}

void ToDoList::printSize() const
{
	std::cout << this->index;
}

bool ToDoList::isEmpty() const
{
	return index == 0;
}

void ToDoList::print() const
{
	if (isEmpty())
	{
		std::cout << "The list is empty!" << std::endl;
		return;
	}
	for (int i = 0; i < index; ++i)
	{
		tasks[i].print();
	}
}
