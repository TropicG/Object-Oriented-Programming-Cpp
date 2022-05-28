#include "Calendar.h"
using namespace std;

void inputCommand(int& command);
void printMenu();
void printChange();

int main() {

	Calendar cal(MAX_DAYS);

	int command = 0;

	printMenu();

	while (true) {

		inputCommand(command);

		if (command == 1) {

			cout << "Enter the meeting\n";

			//reads the new meeting and adding it to the calendar
			Meeting temp;
			temp.read();
			cal.addMeeting(temp);
		}
		else if (command == 2) {

			cout << "Enter the meeting\n";

			//reads the new meeting and removing it from the calendar
			Meeting temp;
			temp.read();
			cal.remMeeting(temp);
		}

		else if (command == 3) {
			
			cout << "Enter the day\n";

			//reads the day and prints this's day schedule
			Date temp;
			temp.read();
			cal.showSchedule(temp);
		}

		else if (command == 4) {

			cout << "Enter the meeting \n";

			//reads a meeting
			Meeting meet;
			meet.read();

			//removes the meeting from the calendar
			cal.remMeeting(meet);

			int newCommand = 0;
			printChange();
			inputCommand(newCommand);

			if (newCommand == 1) {

				String newName;
				cout << "Enter the new string\n";
				newName.read();

				meet.setName(newName);
			}
			else if (newCommand == 2) {

				String newCom;
				cout << "Enter the new commentar \n";
				newCom.read();

				meet.setCommentar(newCom);
			}
			else if (newCommand == 3) {

				Date newDate;
				cout << "Enter the new date \n";
				newDate.read();

				meet.setDate(newDate);
			}
			else if (newCommand == 4) {

				Hour newStart;
				cout << "Enter the new starting hour \n";
				newStart.read();

				meet.setStart(newStart);
			}
			else {

				Hour newEnd;
				cout << "Enter the new ending hour \n";
				newEnd.read();

				meet.setStart(newEnd);
			}

			//then after we have changed that meeting we add it again to the meeting
			cal.addMeeting(meet);
		}

		else if (command == 5) {

			cout << "Enter the name or the comment \n";

			//enters a name or a comment and add it to the calendar
			String temp;
			temp.read();
			cal.search(temp);
		}

		else if (command == 7) {

			cout << "Enter the start week: \n";
			Date start;
			start.read();

			cout << "Enter the end of week: \n";
			Date end;
			end.read();

			cout << "Enter the start hour: \n";
			Hour startHour;
			startHour.read();

			cout << "Enter the ending hour: \n";
			Hour endHour;
			endHour.read();

			cout << "Enter the period: \n";
			Hour period;
			period.read();

			//gets the freeDay for the meeting
			Date freeDay = cal.findFreeTime(start, end, startHour, endHour, period);

			if (freeDay.getDay() == 0) cout << "There is no free day \n";
			else { cout << "The free date is: "; freeDay.print(); }
		}
		else {
			break;
		}
	}

	return 0;

}

void inputCommand(int& command) {

	cout << "Enter a command: ";
	cin >> command;
	cout << "\n";
}

void printMenu() {

	cout << "1 - add a meeting \n";
	cout << "2 - remove a meeting \n";
	cout << "3 - see all meetings in chronological order for a given day \n";
	cout << "4 - change a thing about the meating \n";
	cout << "5 - search for a meeting \n";
	cout << "7 - seach for a free time for a meeting \n \n";
}

void printChange() {

	cout << "1 - the name \n";
	cout << "2 - the commentar \n";
	cout << "3 - the date \n";
	cout << "4 - the starting hour \n";
	cout << "5 - the ending hour \n \n";

}

	/*Meeting meet, meet2, meet3;

	meet.read();
	meet2.read();
	meet3.read();
	
	Day day;

	day.addMeeting(meet);
	day.addMeeting(meet2);
	day.addMeeting(meet3);

	day.removeMeeting(meet2);

	day.print();

	return 0;
	*/