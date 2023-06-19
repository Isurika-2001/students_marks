#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int no = 2;

string BioAstu[2], BioBstu[2], BioCstu[2];
string MathsAstu[2], MathsBstu[2], MathsCstu[2], MathsDstu[2], MathsEstu[2];

double BioAmarks[2], BioBmarks[2], BioCmarks[2];
double MathsAmarks[2], MathsBmarks[2], MathsCmarks[2], MathsDmarks[2], MathsEmarks[2];

void MainMenu() {
    cout << "Select the option:" << endl;
    cout << "1. Enter marks - Bio Science stream\n";
    cout << "2. Enter marks - Math stream\n";
    cout << "3. Exit\n";
}

double calculateTotal(double sub1, double sub2, double sub3) {
    double total = sub1 + sub2 + sub3;
    return total;
}

void get_marks_bio(ofstream& file, string classLabel, string* stuArray, double* marksArray) {
    file << left << setw(30) << "Student name";
    file << left << setw(10) << "Biology";
    file << left << setw(10) << "Physics";
    file << left << setw(10) << "Chemistry" << endl;
    file << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < no; i++) {
        string stu_name;
        double biology_mark = 0;
        double physics_mark = 0;
        double chemistry_mark = 0;

        cout << "Enter student name: ";
        cin >> stu_name;
        cout << "Enter Biology mark: ";
        cin >> biology_mark;
        cout << "Enter Physics mark: ";
        cin >> physics_mark;
        cout << "Enter Chemistry mark: ";
        cin >> chemistry_mark;

        file << left << setw(30) << stu_name;
        file << left << setw(10) << biology_mark;
        file << left << setw(10) << physics_mark;
        file << left << setw(10) << chemistry_mark << endl;
        cout << endl;

        double total = calculateTotal(biology_mark, physics_mark, chemistry_mark);

        stuArray[i] = stu_name;
        marksArray[i] = total;
    }

    file << endl << endl;
    cout << endl << endl;
}

void BioScience() {
    ofstream file("bioscience.txt", ios::trunc);
    if (file.is_open()) {
        file << "                              Bio Science" << endl;
        file << "======================================================================" << endl << endl;
        file << "                                Class A" << endl;
        cout << "Enter marks of class A students\n";
        get_marks_bio(file, "Class A", BioAstu, BioAmarks);

        file << "                                Class B" << endl;
        cout << "Enter marks of class B students\n";
        get_marks_bio(file, "Class B", BioBstu, BioBmarks);

        file << "                                Class C" << endl;
        cout << "Enter marks of class C students\n";
        get_marks_bio(file, "Class C", BioCstu, BioCmarks);

        file.close();
        cout << "File written successfully.\n";


        ofstream file("rankBio.txt", ios::trunc);
        if (file.is_open()) {
            cout << "Bio Science\n\n";
            cout << "Class A:\n";
            file << "Class A" << endl;
            file << left << setw(30) << "Student name";
            file << left << setw(20) << "Total mark";
            file << left << setw(20) << "Class Rank";
            file << left << setw(20) << "School Rank" << endl;
            
            for (int i = 0; i < no; i++)
            {
                cout << BioAstu[i] << " " << BioAmarks[i] << endl;
                file << left << setw(30) << BioAstu[i];
                file << left << setw(20) << BioAmarks[i] << endl;
            }
            file << endl << endl;

            cout << "Class B:\n";
            file << "Class B" << endl;
            file << left << setw(30) << "Student name";
            file << left << setw(20) << "Total mark";
            file << left << setw(20) << "Class Rank";
            file << left << setw(20) << "School Rank" << endl;
            for (int i = 0; i < no; i++)
            {
                cout << BioBstu[i] << " " << BioBmarks[i] << endl;
                file << left << setw(30) << BioBstu[i];
                file << left << setw(20) << BioBmarks[i] << endl;
            }
            file << endl << endl;

            cout << "Class C:\n";
            file << "Class C" << endl;
            file << left << setw(30) << "Student name";
            file << left << setw(20) << "Total mark";
            file << left << setw(20) << "Class Rank";
            file << left << setw(20) << "School Rank" << endl;
            for (int i = 0; i < no; i++)
            {
                cout << BioCstu[i] << " " << BioCmarks[i] << endl;
                file << left << setw(30) << BioCstu[i];
                file << left << setw(20) << BioCmarks[i] << endl;
            }
            file << endl << endl;
        }
    }
    
    else {
        cout << "Failed to open the file.\n";
    }
}




void get_marks_maths(ofstream& file, string classLabel, string* stuArray, double* marksArray) {
    file << left << setw(30) << "Student name";
    file << left << setw(20) << "Combine Maths";
    file << left << setw(20) << "Physics";
    file << left << setw(20) << "Chemistry" << endl;
    file << "------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < no; i++) {
        string stu_name;
        double CombineMaths_mark = 0;
        double physics_mark = 0;
        double chemistry_mark = 0;

        cout << "Enter student name: ";
        cin >> stu_name;
        cout << "Enter Combine Maths mark: ";
        cin >> CombineMaths_mark;
        cout << "Enter Physics mark: ";
        cin >> physics_mark;
        cout << "Enter Chemistry mark: ";
        cin >> chemistry_mark;

        file << left << setw(30) << stu_name;
        file << left << setw(20) << CombineMaths_mark;
        file << left << setw(20) << physics_mark;
        file << left << setw(20) << chemistry_mark << endl;
        cout << endl;

        double total = calculateTotal(CombineMaths_mark, physics_mark, chemistry_mark);

        stuArray[i] = stu_name;
        marksArray[i] = total;
    }
    file << endl << endl;
    cout << endl << endl;
}

void Maths() {
    ofstream file("maths.txt", ios::trunc);
    if (file.is_open()) {
        file << "                                       Maths" << endl;
        file << "==============================================================================" << endl << endl;
        file << "                                Class A" << endl;
        cout << "Enter marks of class A students\n";
        get_marks_maths(file, "Class A", MathsAstu, MathsAmarks);

        file << "                                Class B" << endl;
        cout << "Enter marks of class B students\n";
        get_marks_maths(file, "Class B", MathsBstu, MathsBmarks);

        file << "                                Class C" << endl;
        cout << "Enter marks of class C students\n";
        get_marks_maths(file, "Class C", MathsCstu, MathsCmarks);

        file << "                                Class D" << endl;
        cout << "Enter marks of class D students\n";
        get_marks_maths(file, "Class D", MathsDstu, MathsDmarks);

        file << "                                Class E" << endl;
        cout << "Enter marks of class E students\n";
        get_marks_maths(file, "Class E", MathsEstu, MathsEmarks);

        file.close();
        cout << "File written successfully.\n";


        ofstream file("rankMaths.txt", ios::trunc);
        if (file.is_open()) {
            cout << "Maths\n\n";
            cout << "Class A:\n";
            file << "Class A" << endl;
            file << left << setw(30) << "Student name";
            file << left << setw(20) << "Total mark";
            file << left << setw(20) << "Class Rank";
            file << left << setw(20) << "School Rank" << endl;

            for (int i = 0; i < no; i++)
            {
                cout << MathsAstu[i] << " " << MathsAmarks[i] << endl;
                file << left << setw(30) << MathsAstu[i];
                file << left << setw(20) << MathsAmarks[i] << endl;
            }
            file << endl << endl;

            cout << "Class B:\n";
            file << "Class B" << endl;
            file << left << setw(30) << "Student name";
            file << left << setw(20) << "Total mark";
            file << left << setw(20) << "Class Rank";
            file << left << setw(20) << "School Rank" << endl;
            for (int i = 0; i < no; i++)
            {
                cout << MathsBstu[i] << " " << MathsBmarks[i] << endl;
                file << left << setw(30) << MathsBstu[i];
                file << left << setw(20) << MathsBmarks[i] << endl;
            }
            file << endl << endl;

            cout << "Class C:\n";
            file << "Class C" << endl;
            file << left << setw(30) << "Student name";
            file << left << setw(20) << "Total mark";
            file << left << setw(20) << "Class Rank";
            file << left << setw(20) << "School Rank" << endl;
            for (int i = 0; i < no; i++)
            {
                cout << MathsCstu[i] << " " << MathsCmarks[i] << endl;
                file << left << setw(30) << MathsCstu[i];
                file << left << setw(20) << MathsCmarks[i] << endl;
            }
            file << endl << endl;

            cout << "Class D:\n";
            file << "Class D" << endl;
            file << left << setw(30) << "Student name";
            file << left << setw(20) << "Total mark";
            file << left << setw(20) << "Class Rank";
            file << left << setw(20) << "School Rank" << endl;
            for (int i = 0; i < no; i++)
            {
                cout << MathsDstu[i] << " " << MathsDmarks[i] << endl;
                file << left << setw(30) << MathsDstu[i];
                file << left << setw(20) << MathsDmarks[i] << endl;
            }
            file << endl << endl;

            cout << "Class E:\n";
            file << "Class E" << endl;
            file << left << setw(30) << "Student name";
            file << left << setw(20) << "Total mark";
            file << left << setw(20) << "Class Rank";
            file << left << setw(20) << "School Rank" << endl;
            for (int i = 0; i < no; i++)
            {
                cout << MathsEstu[i] << " " << MathsEmarks[i] << endl;
                file << left << setw(30) << MathsEstu[i];
                file << left << setw(20) << MathsEmarks[i] << endl;
            }
            file << endl << endl;
        }
    }

    else {
        cout << "Failed to open the file.\n";
    }
}

int main() {
    int MenuSelection;

    MainMenu();
    cin >> MenuSelection;

    while (MenuSelection < 3)
    {
        switch (MenuSelection)
        {
        case 1: BioScience();
            MainMenu();
            cin >> MenuSelection;
            break;
        case 2: Maths();
            MainMenu();
            cin >> MenuSelection;
            break;
        default:
            cout << "invalid choice";
            cin >> MenuSelection;
            break;
        }
    }
}
