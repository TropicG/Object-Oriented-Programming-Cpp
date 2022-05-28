#include <iostream>
#include "Library.h"
using namespace std;

void printMenu()
{
    cout << "Choose option:\n";
    cout << "1 - Add Book to Library\n";
    cout << "2 - Remove Book from Library\n";
    cout << "3 - Print library\n";
    cout << "0 - Exit\n";
}

int main() {

    int option;
    Library myLibrary;

    printMenu();

    do {

        cin >> option;
        switch (option) {

        case 1:
            myLibrary.addBook();
            break;
        case 2:
            myLibrary.removeBook();
            break;
        case 3:
            myLibrary.print();
            break;
        }
    } while (option);

    myLibrary.clean();
	return 0;
}
