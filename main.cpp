#include <iostream>
#include <fstream>
#include <conio.h>
#include "Student.h"
#include "Enroll.h"
#include "Html.h"
#include "C.h"
#include "Cplus.h"
#include "Grading.h"
#include "Certificate.h"
#include "Admin.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	int choice;
	std::cout<<"\t\t\t\t---ONLINE LEARNING PLATFORM WITH GRADING AND CERTIFICATION---"<<std::endl;
	std::cout<<"WELCOME"<<endl;
	std::cout<<"1.Admin"<<std::endl;
	std::cout<<"2.User"<<std::endl;
	std::cout<<"Enter Your Choice: ";
	std::cin>>choice;
	std::string u_name;
	std::string pass_w;
	if(choice==1){
		switch(choice){
		case 1:{
			Admin adobj;
			std::cout<<"Enter your  Admin user-name: ";
			std::cin>>u_name;
			std::cout<<"Enter your Admin password: ";
			std::cin>>pass_w;
			adobj.admin_login(u_name,pass_w);
			Admin a;
			a.display();
			break;
		}
		case 2:{
			break;
		}
		default:{
			std::cout<<"Inavlid choice!"<<std::endl;
			std::cout<<"\t\t\t\t---THANK YOU---"<<std::endl;
		}
	}
	}
	else{
		system("cls");
		std::cout<<"\t\t\t\t---ONLINE LEARNING PLATFORM WITH GRADING AND CERTIFICATION---"<<std::endl;
		std::cout<<"1.Login"<<std::endl;
		std::cout<<"2.Sign-up"<<std::endl;
		std::cout<<"Enter Your Choice: ";
		std::cin>>choice;
		Student obj;
		std::cin.ignore();
	switch(choice){
		case 1:{
			std::cout<<"Enter your user-name: ";
			std::cin>>u_name;
			std::cout<<"Enter your password: ";
			std::cin>>pass_w;
			system("cls");
			obj.login(u_name,pass_w);
			break;
		} 
		case 2:{
			u_name=obj.sign_up();
			break;
		}
		default:{
				std::cout<<"Inavlid choice!"<<std::endl;
				std::cout<<"\t\t\t\t---THANK YOU---"<<std::endl;
				return 0;
			break;
		}
	}
	system("cls");
	while(1){
		system("cls");
		std::cout<<"\t\t\t\t---ONLINE LEARNING PLATFORM WITH GRADING AND CERTIFICATION---"<<std::endl;
	std::cout<<"online learning grading and certification"<<std::endl;
	std::cout<<"Welcome User: "<<u_name<<endl;
	std::cout<<"1.Display Courses"<<endl;
	std::cout<<"2.current Courses"<<std::endl;
	std::cout<<"3.Enroll-Course"<<std::endl;
	std::cout<<"4.Learning-Courses"<<std::endl;
	std::cout<<"5.Certificates"<<endl;
	std::cout<<"6.Exit"<<endl;
	std::cout<<"Enter Your Choice: ";
	std::cin>>choice;
	Enroll e;
	switch(choice){
		case 1:{
			e.display_courses();
			break;
		}
		case 2:{
			e.current_courses(u_name);
			break;
		}
		case 3:{
			e.enroll_courses(u_name);
			break;
		}
		case 4:{
			string str;
			e.goto_courses(u_name);
			cout<<"Enter your choice: ";
			cin>>str;
			system("cls");
			if(str=="c"){
				//learning c
				C cobj;
				cobj.modules(u_name);
			}
			else if(str=="cpp"){
				Cplus pobj;
				pobj.modules(u_name);
				//learning cpp
			}
			else if(str=="html"){
				Html hobj;
				hobj.modules(u_name);
				//learning html
			}
			break;
		}
		case 5:{
			Certificate cerobj;
			cerobj.displaycertificates(u_name);
			break;
		}
		case 6:{
			return 0;
			break;
		}
	}
	system("pause");
	}
	
	}
	return 0;
}
