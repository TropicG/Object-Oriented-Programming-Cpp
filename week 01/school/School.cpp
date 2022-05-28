#include "School.h"

void School::addStudent()
{
	Student newStudent;
	newStudent.read();
	students[count++] = newStudent;
}

void School::bornMarch()
{
	for (int i = 0; i < count; ++i)
	{
		if (students[i].getMonth() == 3)
			students[i].print();
	}
}

void School::printBestStudent()
{
	Student best = students[0];
	for(int i=1; i<count;++i)
	{
		if (best.avarage() < students[i].avarage())
			best = students[i];
	}
	best.print();
}

void School::clear()
{
	for (int i = 0; i < count; ++i)
	{
		students[i].clear();
	}
}
