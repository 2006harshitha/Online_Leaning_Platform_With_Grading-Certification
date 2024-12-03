#include <iostream>
#include <fstream>
#include <string>
#include "Certificate.h"
using namespace std;


void Certificate::displaycertificates(string userName) {
    // Open the certificate files for the user
    std::ifstream f1(userName + "_C_certificate.txt");
    std::ifstream f2(userName + "_Cpp_certificate.txt");
    std::ifstream f3(userName + "_html_certificate.txt");

    bool certificatesFound = false;

    // Check and display the C certificate
    if (f1.good() && f1.peek() != -1) {
        std::cout << "Here is the completion certificate of C_programming:" << std::endl;
        std::string dis;
        while (getline(f1, dis)) {
            std::cout << dis << std::endl;
        }
        certificatesFound = true;
        f1.close();
    }

    // Check and display the CPP certificate
    if (f2.good() && f2.peek() != -1) {
        std::cout << "Here is the completion certificate of Oops with C++:" << std::endl;
        std::string dis;
        while (getline(f2, dis)) {
            std::cout << dis << std::endl;
        }
        certificatesFound = true;
        f2.close();
    }

    // Check and display the HTML certificate
    if (f3.good() && f3.peek() != -1) {
        std::cout << "Here is the completion certificate of HTML:" << std::endl;
        std::string dis;
        while (getline(f3, dis)) {
            std::cout << dis << std::endl;
        }
        certificatesFound = true;
        f3.close();
    }

    // If no certificates were found
    if (!certificatesFound) {
        std::cout << "There are no certificates because you haven't completed any of the three available courses." << std::endl;
    }
}



void Certificate::generateCertificate(string userName, int c, int score){ 
    string course;
    ofstream cf1,cf2,cf3;
    if(c==1){
  	    cf1.open(userName+"_C_certificate.txt");
  	    course="C_programming";
  	    cf1 << "Certificate of Completion"<<endl; 
        cf1<< "This is to certify that " << userName << " has successfully completed the " << course << " course with a score of " << score << "."<<endl;
  	    
    }
    else if(c==2){
  	    cf2.open(userName+"_Cpp_certificate.txt");
  	    course="Oops with c++";
  	    cf2<< "Certificate of Completion"<<endl; 
        cf2<< "This is to certify that " << userName << " has successfully completed the " << course << " course with a score of " << score << "."<<endl;
    }
    else if(c==3){
  	    cf3.open(userName+"_html_certificate.txt");
  	    course="html course";
  	    cf3<< "Certificate of Completion"<<endl; 
        cf3<< "This is to certify that " << userName << " has successfully completed the " << course << " course with a score of " << score << "."<<endl;
    }
    cf1.close(); 
    cf2.close(); 
    cf3.close(); 
}
