#include "Website.h"
#include "helperfunctions.h"
using namespace std;

int main() {
	
	Website website;
	Facebook face;
	
	website.load(face);

	printMenu();

	while (true) {
		try {

			unsigned option = 0;
			inputOption(option);

			if (option == 1) {

				UserData user;
				user.read();

				face.addUser(user);
				cout << "User added succsesfully" << endl << endl;
			}
			else if (option == 2) {

				string name;
				cout << "Enter the username of the user: "; cin >> name;

				PictureData pic;
				pic.read();

				face.addPicToUser(name, pic);
				cout << "Picture added to user succsesfully" << endl << endl;
			}
			else if (option == 3) {

				string name;
				std::cout << "Enter the username of the user: "; cin >> name;

				PictureData pic;
				pic.read();

				Comment com;
				com.read();

				face.addComToPicToUser(name, pic, com);
				std::cout << "Comment added to pic to user succsessfully" << endl << endl;
			}
			else if (option == 4) {

				UserData user;
				user.read();

				face.delUser(user);
				cout << "User removed succsesfully" << endl << endl;
			}
			else if (option == 5) {

				string name;
				cout << "Enter the username of the user: "; cin >> name;

				PictureData pic;
				pic.read();

				face.delPicFromUser(name, pic);
				cout << "Pic removed from user succsesfully" << endl << endl;
			}
			else if (option == 6) {

				string name;
				std::cout << "Enter the username of the user: "; cin >> name;

				PictureData pic;
				pic.read();

				Comment com;
				com.read();

				face.delComFromPicFromUser(name, pic, com);
				std::cout << "Com removed from pic from user succsesfully" << endl << endl;
			}
			else if (option == 7) {

				face.print();
				cout << endl << endl;
			}
			else {
				website.save(face);
				break;
			}
		}
		catch (const exception& e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}