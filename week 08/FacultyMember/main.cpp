#include "FacultyNum.h"
#include <fstream>
using namespace std;

int main() {
	
	FacultyMember fac;

	ifstream file;
	file.open("database.txt");
	if (!file) {
		cout << "Text file couldnt open";
		return -1;
	}

	file >> fac;

	fac.print();

	fac.read();

	file.close();
	ofstream file2;
	file2.open("database.txt");
	if (!file2) {
		cout << "Text file couldnt open";
		return -2;
	}

	file2 << fac;

	return 0;
}