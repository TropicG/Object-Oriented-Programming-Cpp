#include "doList.h"
using namespace std;

void printMenu()
{
	cout << "1 - add task to your list" << endl;
	cout << "2 - remove a task from your list" << endl;
	cout << "3 - print your list" << endl;
}

int main()
{

	ToDoList list;
	int option = 0;

	printMenu();

	while(true)
	{

		cin >> option;

		if (option == 1)
		{
			string title, desc;

			cout << "Enter the name of the task: ";
			cin >> title;
			while (title.size() > 32) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Bad input, try again: ";
				cin >> title;
			}

			cout << "Enter the description of the task: ";
			cin.ignore();
			getline(cin, desc, '\n');
			while (desc.size() > 128) {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Bad input, try again: ";
				getline(cin, desc, '\n');
			}

			Task task(title,desc);
			list.pushTask(task);
		}
		else if (option == 2)
		{
			list.popTask();
		}
		else if(option == 3)
		{
			list.print();
		}
		else
		{
			break;
		}
	}

	return 0;
}