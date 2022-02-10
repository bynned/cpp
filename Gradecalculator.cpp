#include <iostream>
#include <sstream>
#include <string>
using namespace std;


/*
Course grading program by Benny Cascarino.
*/
int main() {

	//Variables

	int students; // The amount of students to add to the table.
	string name; // Student name.
	int week; // Amount of weekly exercises done.
	int final; // Final assignment grade.
	double grade; // This is the precise grade. Using double for decimals.
	int roundgrade; // Rounded grade.
	int weekgrade; // 0-5 Grade for done weekly assignments
	int emphasis; // Emphasis for weekly assignments
	double weekemphasis; // Decimal emphasis to turning 40% to 0.4
	double finalemphasis; // -""-

	stringstream summary; // This is for printing all the added students in the end.

	cout << "\t----------Grade counter by Benny Cascarino----------\n" << endl;


	/*
	Asking user for emphasis.
	*/
	do {
		cin.clear();
		cout << "Enter the emphasis of weekly assignments for course grade: (0-100) \n Example: 30-> 30%/70% " << endl;
		cin >> emphasis;
	} while (cin.bad() || emphasis < 0 || emphasis > 100);


	// Getting input for the amount of students.
	cout << "Enter the amount of students you would like to input:" << endl;
	cin >> students;
	cin.ignore();


	for (int i = 0; i < students; i++) {

		// Imput for student name:
		cout << "Enter student " << i + 1 << " name: " << endl;
		getline(cin, name);

		/*
		Using do-while loop for asking Weekly assignments and for final assignment grade,
		because we want a input from a specific range e.g. 0-40 and 0-5.
		*/
		do { // Weekly assignments.
			cin.clear();
			cout << "Enter the amount of accepted weekly exercises: (0-40) " << endl;
			cin >> week;
		} while (cin.bad() || week < 0 || week > 40);

		do { // Final assignment grade.
			cin.clear();
			cout << "Enter grade for final assignment: (0-5)" << endl;
			cin >> final;
			cin.ignore();
		} while (cin.bad() || final < 0 || final > 5);

		//	Using if/else if to get a rounded grade for weekly assignments.
		//	This information was taken from the moodle page.

		if (week >= 37 && week <= 40)
			weekgrade = 5;
		else if (week >= 33 && week <= 36)
			weekgrade = 4;
		else if (week >= 28 && week <= 32)
			weekgrade = 3;
		else if (week >= 24 && week <= 27)
			weekgrade = 2;
		else if (week >= 20 && week <= 23)
			weekgrade = 1;
		else if (week >= 0 && week <= 19)
			weekgrade = 0;


		weekemphasis = (emphasis * 0.01); // turning the whole number to decimal for multiplication 
		finalemphasis = ((100 - emphasis) * 0.01); // For example: if we choose 30% as our emphasis: 100% - 30% = 70% so it will be 30%/70% 
													// By doing this we will always stay in the 0-100%

		// Grade = precise grade.
		grade = (weekgrade * weekemphasis + final * finalemphasis); // Calculating Emphasis of the weekly assignments and final assignment. 40%/60%


		// Using if/else if to round up the grade from precise.

		if (grade >= 4.5 && grade <= 5.0)
			roundgrade = 5;
		else if (grade >= 3.5 && grade <= 4.4)
			roundgrade = 4;
		else if (grade >= 2.5 && grade <= 3.4)
			roundgrade = 3;
		else if (grade >= 1.5 && grade <= 2.4)
			roundgrade = 2;
		else if (grade >= 0.5 && grade <= 1.4)
			roundgrade = 1;
		else if (grade >= 0.0 && grade <= 0.4)
			roundgrade = 0;

		// Defining summary:
		summary << name << ": " << "Amount of weekly exercises: " << week << " Precise grade: " << grade << " Rounded grade: " << roundgrade << "\n" << endl;
	}

	// Printing the summary:
	cout << summary.str();;

	return 0;

}



