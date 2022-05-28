#include "Planet.h"
#include "helperFunctions.h"
using namespace std;

int main() {

	Planet planet;
	cin >> planet;

	int option = 0;
	
	printMenu();


	while (true) {
		try {
			inputOption(option);

			if (option == 1) {

				Fauna fauna;
				cin >> fauna;
				planet.addFauna(fauna);
				cout << "Fauna added succsessfully" << endl;
				cout << endl;
			}
			else if (option == 2) {

				char faunaName[faunaNameMax];
				inputFaunaName(faunaName);
				Family family;
				cin >> family;
				planet.addFamilyInFauna(faunaName, family);
				cout << "Family was added successfully" << endl;
				cout << endl;
			}
			else if (option == 3) {

				char faunaName[faunaNameMax];
				inputFaunaName(faunaName);
				char familyName[famNameMax];
				inputFamilyName(familyName);
				Animal animal;
				cin >> animal;
				planet.addAnimalInFamilyInFauna(faunaName, familyName, animal);
				cout << "Animal was addded to the family succsesfully" << endl;
				cout << endl;
			}
			else if (option == 4) {

				Zoo zoo;
				cin >> zoo;
				planet.addZoo(zoo);
				cout << "Zoo was added succsesfully" << endl;
				cout << endl;
			}
			else if (option == 5) {

				char zooName[zooNameMax];
				inputZooName(zooName);
				Family family;
				cin >> family;
				planet.addFamilyInZoo(zooName, family);
				cout << "Family was addded succsesfully" << endl;
				cout << endl;
			}
			else if (option == 6) {

				char zooName[zooNameMax];
				inputZooName(zooName);
				char familyName[famNameMax];
				inputFamilyName(familyName);
				Animal animal;
				cin >> animal;
				planet.addAnimalInFamilyInZoo(zooName, familyName, animal);
				cout << "Animal was added succsesfully" << endl;
				cout << endl;
			}
			else if (option == 7) {

				cout << "There are " << planet.getZooSize() << " zoos in the planet" << endl;
				cout << endl;
			}
			else if (option == 8) {

				cout << "There are " << planet.getFaunaSize() << " faunas in the planet" << endl;
				cout << endl;
			}
			else if (option == 9){
				cout << planet << endl;
				cout << endl;
			}
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			cout << endl;
		}
	}

	return 0;
}