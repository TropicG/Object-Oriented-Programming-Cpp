#ifndef doList
#define doList
#include "Task.h"

class ToDoList {
private:
	Task* tasks;
	short index = 0, capacity = 128;
public:
	void resize();
public:
	ToDoList();
	~ToDoList();

	void pushTask(const Task& task);
	void popTask();	

	void printSize() const;
	bool isEmpty() const;

	void print() const;
};



#endif