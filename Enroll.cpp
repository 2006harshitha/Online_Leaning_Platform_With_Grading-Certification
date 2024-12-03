#include<iostream>
#include<fstream>
#include<string.h>
#include <sstream>
#include <vector>
#include "Enroll.h"
using namespace std;

void Enroll::display_courses() {
    cout << "1. C Language" << endl;
    cout << "2. Oops With C++" << endl;
    cout << "3. HTML" << endl;
}


void Enroll::enroll_courses(string userName) {
    string n = current_courses(userName); // Get current enrollment status as "111", "101", etc.
    if (n == "111") {
        cout << "You have already enrolled in all courses." << endl;
        return;
    }

    cout << "Available courses for enrollment: " << endl;
    string courses[] = {"C", "Oops with C++", "HTML"};
    int availableCourseIndex = 0;

    // Display available courses
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == '0') { // Not enrolled
            cout << ++availableCourseIndex << ". " << courses[i] << endl;
        }
    }

    int choice;
    cout << "Enter course number to enroll: ";
    cin >> choice;

    if (choice < 1 || choice > availableCourseIndex) {
        cout << "Invalid course number! Please try again." << endl;
        return;
    }

    // Find the course index in the string
    int courseIndex = -1;
    for (int i = 0, availableIndex = 1; i < n.length(); i++) {
        if (n[i] == '0') {
            if (availableIndex == choice) {
                courseIndex = i;
                break;
            }
            availableIndex++;
        }
    }

    if (courseIndex == -1) {
        cout << "Error: Invalid course selection!" << endl;
        return;
    }

    // Mark the course as enrolled in the n string
    n[courseIndex] = '1';

    // Update the file
    ifstream file("Student.txt");
    if (!file.is_open()) {
        cout << "Error: Unable to open Student.txt!" << endl;
        return;
    }

    string updatedFileContent;
    string line, name, uname, password, phone, cStatus, cppStatus, htmlStatus;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, uname, ',');
        getline(ss, password, ',');
        getline(ss, phone, ',');
        getline(ss, cStatus, ',');
        getline(ss, cppStatus, ',');
        getline(ss, htmlStatus);

        if (uname == userName) {
            // Update the specific course status
            switch (courseIndex) {
                case 0: cStatus = "C"; break;
                case 1: cppStatus = "Oops with C++"; break;
                case 2: htmlStatus = "HTML"; break;
            }

            // Construct the updated line
            stringstream updatedLine;
            updatedLine << name << "," << uname << "," << password << "," << phone
                        << "," << cStatus << "," << cppStatus << "," << htmlStatus;
            updatedFileContent += updatedLine.str() + "\n";
        } else {
            // Keep other lines unchanged
            updatedFileContent += line + "\n";
        }
    }
    file.close();

    ofstream outFile("Student.txt");
    if (!outFile.is_open()) {
        cout << "Error: Unable to write to Student.txt!" << endl;
        return;
    }
    outFile << updatedFileContent;
    outFile.close();

    // Add user to specific course file
    // Add user to specific course file with appropriate module placeholders
string courseFileName;
string modulePlaceholders;

switch (courseIndex) {
    case 0: 
        courseFileName = "c.txt"; 
        modulePlaceholders = ",$,$,$,$,"; // 4 modules
        break;
    case 1: 
        courseFileName = "cpp.txt"; 
        modulePlaceholders = ",$,$,$,$,"; // 4 modules
        break;
    case 2: 
        courseFileName = "html.txt"; 
        modulePlaceholders = ",$,$,$,$,$,"; // 5 modules
        break;
}

ofstream courseFile(courseFileName, ios_base::app);
courseFile << userName << modulePlaceholders << "\n";
courseFile.close();

}
string Enroll::current_courses(string userName) {
    ifstream file("Student.txt", ios_base::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return "";
    }

    string name, uname, password, phone, cl, cppl, htmll, css;
    string str = ""; // Tracks enrollment status (0 = not enrolled, 1 = enrolled)
    bool userFound = false;
    int courseIndex = 1; // Tracks the display order of courses

    // Read each line in the file
    while (getline(file, name, ',') && 
           getline(file, uname, ',') && 
           getline(file, password, ',') && 
           getline(file, phone, ',') && 
           getline(file, cl, ',') && 
           getline(file, cppl, ',') && 
           getline(file, htmll)) {

        if (uname == userName) {
            userFound = true;

            // Check C enrollment
            if (cl == "0") {
                str += "0";
            } else {
                cout << courseIndex++ << ". C (Already Enrolled)" << endl;
                str += "1";
            }

            // Check CPP enrollment
            if (cppl == "0") {
                str += "0";
            } else {
                cout << courseIndex++ << ". CPP (Already Enrolled)" << endl;
                str += "1";
            }

            // Check HTML enrollment
            if (htmll == "0") {
                str += "0";
            } else {
                cout << courseIndex++ << ". HTML (Already Enrolled)" << endl;
                str += "1";
            }

            // Optional: Check CSS enrollment (if needed later)
        }
    }

    if (!userFound) {
        cout << "User not found!" << endl;
        return "";
    }

    if (courseIndex == 1) { // No courses displayed, no enrollments
        cout << "You haven't enrolled in any courses!" << endl;
    }

    file.close();
    return str;
}

void Enroll::goto_courses(string userName) {
    ifstream file("student.txt", ios_base::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    } 

    string name, phone, uname, password, cl, cppl, htmll;
    int availableCourses = 0;
    bool userFound = false;

    while (getline(file, name, ',') && getline(file, uname, ',') &&
           getline(file, password, ',') && getline(file, phone, ',') &&
           getline(file, cl, ',') && getline(file, cppl, ',') &&
           getline(file, htmll)) {

        if (uname == userName) {
            userFound = true;
            if (cl != "0") {
                availableCourses++;
                cout << availableCourses << ". C (enter \"c\")" << endl;
            }
            if (cppl != "0") {
                availableCourses++;
                cout << availableCourses << ". CPP (enter \"cpp\")" << endl;
            }
            if (htmll != "0") {
                availableCourses++;
                cout << availableCourses << ". HTML (enter \"html\")" << endl;
            }
            break;
        }
    }

    if (!userFound) {
        cout << "User not found." << endl;
    } else if (availableCourses == 0) {
        cout << "No courses available for this user." << endl;
    }

    file.close();
}
