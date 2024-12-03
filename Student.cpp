#include<fstream>
#include<iostream>
#include<string>
#include "Student.h"
using namespace std;
void Student::login(string u,string p){
	ifstream file("student.txt", ios_base::in);
	string name,phone,uname,password;
	if(!file){
		cout<<"Error opening file!"<<endl;
	}
	while(file.good()){		
		getline(file,name,',');
		getline(file,uname,',');
		getline(file,password,',');
		getline(file,phone,',');
		if(uname==u && password==p){
			cout<<"Welcome "<<name<<endl;
			file.close();
			return ;
		}
	}
	if(!file.good()){
		cout<<"Can't find "<<u<<" ,please check your credentials"<<endl;
		exit(0);
	}
	file.close();
}
string Student::sign_up() {
    ofstream file("student.txt",ios_base::app);
    if(!file){
		cout<<"Error opening file!"<<endl;
		exit(0) ;
	}
	cout<<"Enter Name: ";
    getline(cin, name);
    while(1){
		cout<<"Enter username: ";
    	cin>>username;
		if(!isUnique(username)) {
			cout<<"The Username is taken try another one!"<<endl;			
		}
		else{
			break;
		} 
	}
	while(1){
		cout<<"Enter Password: ";
    	cin>>password;
		if(!isUnique(password)) {
			cout<<"The password is taken try another one!"<<endl;			
		}
		else{
			break;
		} 
	}
	while(1){
		cout<<"Enter Phone Number: ";
    	cin>>phoneNumber;
		if(!isUnique(phoneNumber)) {
			cout<<"The Phone Number already exists!"<<endl;			
		}
		else{
			break;
		} 
	}	
    while(phoneNumber.length()!=10){
    	cout<<"The Number is invalid!"<<endl;
    	cout<<"Enter a valid Phone Number: ";
    	cin>>phoneNumber;
	}
	file<<name<<","<<username<<","<<password<<","<<phoneNumber<<","<<"$"<<","<<"$"<<","<<"$"<<","<<"$"<<","<<endl;
    cout<<"Signup Successful!\n";
    return username;
}

int Student::isUnique(string toCheck){
	ifstream file("student.txt",ios_base::in);
	string name,phone,uname,password;
	if(!file){
		cout<<"Error opening file!"<<endl;
	}
	while(file.good()){		
		getline(file,name,',');
		getline(file,uname,',');
		getline(file,password,',');
		getline(file,phone,',');
		if(toCheck==uname||toCheck==password||toCheck==phone){
			return 0;
		}
	}
	file.close();
	return 1;
}
