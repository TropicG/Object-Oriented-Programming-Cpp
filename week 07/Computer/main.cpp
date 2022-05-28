#include "Computer.h"
#include "helperfunctions.h"
using namespace std;

int main() {

	Computer comp;
	comp.read();

	printMenu();

	int option = 0;

	while (true) {

		initialiseOption(option);

		if (option == 1) {

			Ram ram;
			ram.read();
			comp.setRam(ram);
			cout << "Ram added succsessfully!" << endl;
			cout << endl;
		}
		else if (option == 2) {

			Processor pro;
			pro.read();
			comp.setProcessor(pro);
			cout << "Processor added succsesfully" << endl;
			cout << endl;
		}
		else if (option == 3) {

			HardDrive hd;
			hd.read();
			comp.setHardDrive(hd);
			cout << "Hard drive added succsesfully" << endl;
			cout << endl;
		}
		else if (option == 4) {

			VideoCard video;
			video.read();
			comp.setVideoCard(video);
			cout << "Video card added succsesfully" << endl;
			cout << endl;
		}
		else if (option == 5) {

			comp.print();
			cout << endl;
		}
		else {
			break;
		}
	}

	return 0;
}