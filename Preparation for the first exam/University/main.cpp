#include "Student.h"
#include <fstream>
using namespace std;

int main(){

    Student student;

    ifstream file;
    file.open("uni.txt");

    file >> student;

    cout << student.getName() << " " << student.getAveScore() << " " << student.getGroup() << " " << student.getFacNum() << endl;


    return 0;
}