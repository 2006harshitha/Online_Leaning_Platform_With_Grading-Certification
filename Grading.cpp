#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>  // For isdigit
#include "Grading.h"

using namespace std;

int Grading::is_completed(string u_name, int c) {
    fstream file;

    // Open the appropriate file based on the course code
    if (c == 1) {
        file.open("c.txt");
    } else if (c == 2) {
        file.open("cpp.txt");
    } else if (c == 3) {
       
        file.open("html.txt");
    }

    if (!file) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    string name, marks;
    bool user_found = false;

    // Search for the username in the file
    while (getline(file, name, ',')) {
        if (name == u_name) {
            user_found = true;
            break;
        }
    }

    if (!user_found) {
        cout << "User not found!" << endl;
        file.close();
        return 0;
    }

    // Check course completion status
    for (int i = 0; i < 4; i++) {
        if (getline(file, marks, ',')) {
            if (marks == "$") {
            	cout<<marks<<" ";
                file.close();
                return 0;  // Incomplete course
            }
        }
    }

    file.close();
    return 1;  // Course completed
}


int Grading::grade(string u_name, int c) {
    // Check course completion status first
    if (!is_completed(u_name, c)) {  // Assuming this checks if the course is complete
        cout << "You haven't completed the whole course!" << endl;
        return -1;
    }

    fstream file;
    if (c == 1) {
        file.open("c.txt");
    } else if (c == 2) {
        file.open("cpp.txt");
    } else if (c == 3) {
        file.open("html.txt");
    }

    if (!file) {
        cout << "Error opening file!" << endl;
        return -1;
    }

    string name, marks, line;
    double sum = 0;
    bool user_found = false;

    // Search for the username in the file
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');

        if (name == u_name) {
            user_found = true;

            // Calculate total marks for the user
            for (int i = 0; i < 4; i++) {
                if (getline(ss, marks, ',')) {
                    if (marks != "$" && !marks.empty()) {
                        sum += stoi(marks);  // Assuming marks are always numeric in valid input
                    }
                }
            }
            break; // Stop after finding the user
        }
    }

    file.close();

    if (!user_found) {
        cout << "User not found!" << endl;
        return -1;
    }

    cout << "Total marks: " << sum <<" out of 40."<< endl;
    return static_cast<int>(sum);
}
