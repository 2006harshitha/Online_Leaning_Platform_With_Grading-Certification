#include <iostream>
#include <fstream>
#include<vector>
#include<sstream>

#include "Admin.h"
using namespace std;


void Admin::admin_login(string adname,string adpassword){
	fstream file("admin.txt", ios_base::in);
	string name,password;
	if(!file){
		cout<<"Error opening file!"<<endl;
	}
	getline(file,name,',');
	getline(file,password);
	file.close();
	if(name==adname and adpassword==password){
		cout<<"Welcome Admin "<<name<<endl;
	}
	else{
		cout<<"Can't find "<<name<<" ,please check your credentials"<<endl;
		exit(0);
	}
}
void Admin::display(){
	cout<<"details of a student"<<endl;
	string fileName = "student.txt";
    ifstream file(fileName);

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string studentName, username, password, phoneNumber;
        string cStatus, oopsStatus, htmlStatus;

        // Extract fields from the line
        getline(ss, studentName, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, cStatus, ',');
        getline(ss, oopsStatus, ',');
        getline(ss, htmlStatus, ',');

        // Prepare enrolled and not-enrolled courses
        vector<string> enrolledCourses;
        vector<string> notEnrolledCourses;

        if (cStatus == "0") notEnrolledCourses.push_back("C");
        else enrolledCourses.push_back("C");

        if (oopsStatus == "0") notEnrolledCourses.push_back("OOPS with C++");
        else enrolledCourses.push_back("OOPS with C++");

        if (htmlStatus == "0") notEnrolledCourses.push_back("HTML");
        else enrolledCourses.push_back("HTML");

        // Display details
        cout << "Student Name: " << studentName << endl;
        cout << "Student Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Enrolled Courses: ";

        if (!enrolledCourses.empty()) {
            for (size_t i = 0; i < enrolledCourses.size(); i++) {
                cout << enrolledCourses[i];
                if (i != enrolledCourses.size() - 1) cout << ", ";
            }
        } else {
            cout << "None";
        }

        cout << endl;

        cout << "Not Enrolled Courses: ";
        if (!notEnrolledCourses.empty()) {
            for (size_t i = 0; i < notEnrolledCourses.size(); i++) {
                cout << notEnrolledCourses[i];
                if (i != notEnrolledCourses.size() - 1) cout << ", ";
            }
        } else {
            cout << "None";
        }

        cout << endl ;
    }
    
    
}
