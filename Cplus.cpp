#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Cplus.h"
#include "Grading.h"
#include "Certificate.h"
using namespace std;
// Custom exception class for invalid input
class InvalidOptionException : public exception {
public:
    const char* what() const throw () {
        return "Invalid option entered. Please re-enter the option.";
    }
};
// Function to get a valid option from the user
char Cplus::getValidOption() {
   while (true) {
        try {
            cout << "Enter your option (a, b, c, d): ";
            cin >> option;
           // Check if the entered option is valid
            if (option != 'a' && option != 'b' && option != 'c' && option != 'd') {
                throw InvalidOptionException();
            }
            return option;
        } catch (InvalidOptionException &e) {
            cout << e.what() << endl;
        }
    }
}
void Cplus::updateinthefile(int k,string userName){
	string progressFile = "cpp.txt"; 
	ifstream inFile(progressFile); 
	string fileContent, line; 
	while (getline(inFile, line)) { 
	stringstream ss(line); 
	string name; 
	getline(ss, name, ','); 
	   if(name==userName) {  
	        stringstream updatedLine; 
	        updatedLine << name; 
	        for (int j = 0; j < 4; j++) { 
	            string mark; 
		    	if (getline(ss, mark, ',')) { 
			        if (j == k) { 
				        mark = to_string(t[k]); 
					}
					updatedLine << "," << mark; 
			    } 
	    	} 
		    fileContent += updatedLine.str() + "\n"; 
     	} 
    	else { 
	        fileContent += line + "\n"; 
	    } 
	} 
	inFile.close(); 
	ofstream outFile(progressFile); 
	outFile << fileContent; 
	outFile.close();
	cout << "Your score for module"<<k+1<<" has been updated." << endl; 
}
void Cplus::m1(string userName){
			t[0]=0;
			cout<<"Welcome to the module 1 of Oops with c++"<<endl;
			cout<<"here is the video which is used to understand about  Oops "<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/pTB0EiLXUC8?si=wmvy21pZZXdIO5uy";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Let's start your quiz"<<endl;
			cout<<"Question 1"<<endl;
			cout<<"1. Which of the following is not a fundamental concept of OOP?"<<endl;
            cout<<"  a. Encapsulation "<<endl;
			cout<<"  b. Inheritance"<<endl;
			cout<<"  c. Polymorphism "<<endl;
			cout<<"  d. Compilation"<<endl;
			option=getValidOption();
			if(option=='d'){
				t[0]++;
			}
			cout<<"Question 2"<<endl;
			cout<<"2.Which of the following best describes Object-Oriented Programming (OOP)?"<<endl;
            cout<<"  a. A programming paradigm based on functions."<<endl;
			cout<<"  b. A programming paradigm based on objects that contain data and methods."<<endl;
			cout<<"  c. A way to use preprocessor directives to simplify code."<<endl;
			cout<<"  d. A method for writing parallel programs."<<endl;
			option=getValidOption();
			if(option=='b'){
				t[0]++;
			}
			cout<<"here is the video which is used to understand about pop vs Oops "<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/wm8avOTPbmo?si=ecTS8rHyaH4-Kdxb";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Question 3"<<endl;
			cout<<"3.What is the primary advantage of using OOP over POP?"<<endl;
            cout<<"  a. Easier syntax."<<endl;
			cout<<"  b. Better performance."<<endl;
			cout<<"  c. Enhanced code reuse and maintainability through inheritance and polymorphism."<<endl;
			cout<<"  d. Simplified debugging."<<endl;
			option=getValidOption();
			if(option=='c'){
				t[0]++;
			}
			cout<<"Question 4"<<endl;
			cout<<" 4.In POP, which approach is generally followed for program development?"<<endl;
            cout<<"  a. Bottom-up approach."<<endl;
			cout<<"  b. Inside-out approach."<<endl;
			cout<<"  c. Top-down approach."<<endl;
			cout<<"  d. Hybrid approach."<<endl;
			option=getValidOption();
			if(option=='c'){
				t[0]++;
			}
			cout<<"Question 5";
			cout<<"5. In OOP, how is data typically handled?"<<endl;
            cout<<"  a. Data is passed directly between functions."<<endl;
			cout<<"  b. Data is hidden and accessed through methods."<<endl;
			cout<<"  c. Data is always global."<<endl;
			cout<<"  d. Data is never modified."<<endl;
			option=getValidOption();
			if(option=='b'){
				t[0]++;
			}
			cout<<"here is the video which is used to understand about classes, objects and access specifiers "<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/x8T0eSPeydA?si=_bjKLWyCkuoc4skh";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Question 6"<<endl;
			cout<<"6. What is a class in C++?"<<endl;
            cout<<"  a. A blueprint for creating objects."<<endl;
			cout<<"  b. A data type that holds only integer values."<<endl;
			cout<<"  c. A function that takes no parameters."<<endl;
			cout<<"  d. A module that contains only global variables."<<endl;
			option=getValidOption();
			if(option=='a'){
				t[0]++;
			}
            cout<<"Question 7"<<endl;
            cout<<"7. What is an object in C++?"<<endl;
            cout<<"  a. A type of variable that holds a single value."<<endl;
			cout<<"  b. An instance of a class."<<endl;
			cout<<"  c. A function that returns an integer."<<endl;
			cout<<"  d. A predefined function in C++."<<endl;
           option=getValidOption();
			if(option=='b'){
				t[0]++;
			}
			cout<<"Question 8";
			cout<<"8. What is the default access specifier for members of a class if none is specified?"<<endl;
            cout<<"  a. public"<<endl;
			cout<<"  b. protected"<<endl;
			cout<<"  c. private"<<endl;
			cout<<"  d. secured"<<endl;
		option=getValidOption();
			if(option=='c'){
				t[0]++;
			}
			cout<<"Question 9"<<endl;
			cout<<"9. How do you create an object of a class named MyClass in C++?"<<endl;
            cout<<"  a. MyClass obj;"<<endl;
			cout<<"  b. class MyClass obj;"<<endl;
			cout<<"  c. object MyClass obj;"<<endl;
			cout<<"  d. MyClass obj();"<<endl;
            option=getValidOption();
			if(option=='a'){
				t[0]++;
			}
			cout<<"Question 10"<<endl;
			cout<<"What is the primary purpose of an object in C++?"<<endl;
            cout<<"  a. To define new data types."<<endl;
			cout<<"  b. To hold and manipulate data."<<endl;
			cout<<"  c. To allocate memory dynamically."<<endl;
			cout<<"  d. To run the main function."<<endl;
			option=getValidOption();
			if(option=='b'){
				t[0]++;
			}
		    updateinthefile(0,userName);
	        cout<<t[0]<<"are the marks you scored in module 1"<<endl;
        }
void Cplus::m2(string userName){
			t[1]=0;
			cout<<"Welcome to the module 2 of Oops with c++"<<endl;
			cout<<"here is the video which is used to understand about constructors and destructors in c++"<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/oRBK0Mh_gG0?si=dDOCQ7q6Ler3NF2l";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Let's start your quiz"<<endl;
			cout<<"Question 1"<<endl;
			cout<<"1. What are the roles of constructors and destructors in C++?"<<endl;
            cout<<"   a. A constructor allocates resources for an object, and a destructor deallocates those resources."<<endl;
			cout<<"   b. A constructor deallocates resources for an object, and a destructor allocates those resources."<<endl;
			cout<<"   c. Both a constructor and a destructor allocate resources."<<endl;
			cout<<"   d. Both a constructor and a destructor deallocate resources."<<endl;
			option=getValidOption();
			if(option=='d'){
				t[1]++;
			}
			cout<<"Question 2"<<endl;
			cout<<"2.which type of constructor is called when an object is created without arguments?"<<endl;
            cout<<"  a. Parameterized constructor"<<endl;
			cout<<"  b. Default construtor"<<endl;
			cout<<"  c. copy constructor"<<endl;
			cout<<"  d. none of the above"<<endl;
			option=getValidOption();
			if(option=='b'){
				t[1]++;
			}
			cout<<"Question 3"<<endl;
			cout<<"3.What will happen if both a constructor with default arguments and a default constructor"<<endl;
			cout<<" are present as members of a class in C++?"<<endl;
            cout<<"  a. The program will not compile due to ambiguity."<<endl;
			cout<<"  b. Only the constructor with default arguments will be called."<<endl;
			cout<<"  c. The default constructor will be called, and the constructor with default arguments will be ignored."<<endl;
			cout<<"  d. Both constructors will be called, causing a conflict."<<endl;
			option=getValidOption();
			if(option=='a'){
				t[1]++;
			}
			cout<<"Question 4"<<endl;
			cout<<" 4.Which of the following is the correct syntax for defining a copy constructor in C++?"<<endl;
            cout<<"  a. ClassName(ClassName obj);"<<endl;
			cout<<"  b. ClassName(const ClassName &obj);"<<endl;
			cout<<"  c. ClassName(const ClassName *obj);"<<endl;
			cout<<"  d. ClassName(ClassName *obj);"<<endl;
			option=getValidOption();
			if(option=='b'){
				t[1]++;
			}
			cout<<"Question 5"<<endl;
			cout<<"5. What will happen if no constructor is defined in a class?"<<endl;
            cout<<"  a. The class cannot be instantiated."<<endl;
			cout<<"  b. The compiler will provide a default constructor."<<endl;
			cout<<"  c. The class will not have any member functions."<<endl;
			cout<<"  d. The compiler will generate a compilation error."<<endl;
			option=getValidOption();
			if(option=='b'){
				t[1]++;
			}
			cout<<"here is the video which is used to understand about passing and returning objects "<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/g2glDePsTdg?si=9XMerYVelBLaee6Z";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Question 6"<<endl;
			cout<<"When an object is passed by value to a function, what happens to the original object? "<<endl;
            cout<<"  a. The function receives a reference to the original object."<<endl;
			cout<<"  b. The function receives a pointer to the original object."<<endl;
			cout<<"  c. The function receives a copy of the object, and modifications do not affect the original object."<<endl;
			cout<<"  d. The function can directly modify the members of the original object."<<endl;
			option=getValidOption();
			if(option=='c'){
				t[1]++;
			}
            cout<<"Question 7"<<endl;
            cout<<"7. What is the effect of returning an object by reference from a function in C++?"<<endl;
            cout<<"  a. The function provides direct access to the local object."<<endl;
			cout<<"  b. The function creates a copy of the object."<<endl;
			cout<<"  c. The function returns a pointer to the object."<<endl;
			cout<<"  d. The function cannot return an object by reference."<<endl;
            option=getValidOption();
			if(option=='a'){
				t[1]++;
			}
			cout<<"Question 8";
			cout<<"8. What is the main advantage of passing an object by constant reference to a function?"<<endl;
            cout<<"  a. It creates a copy of the object, ensuring the original object remains unchanged."<<endl;
			cout<<"  b. It allows the function to modify the object."<<endl;
			cout<<"  c. It avoids the overhead of copying the object, thus improving performance, while preventing modifications."<<endl;
			cout<<"  d. It automatically initializes the object with default values."<<endl;
			option=getValidOption();
			if(option=='c'){
				t[1]++;
			}
			cout<<"Question 9"<<endl;
			cout<<"9. Which of the following is the correct syntax for returning an object by value from a function in C++?"<<endl;
            cout<<"  a. ClassName& functionName();"<<endl;
			cout<<"  b. ClassName* functionName();"<<endl;
			cout<<"  c. ClassName functionName(); "<<endl;
			cout<<"  d. const ClassName& functionName();"<<endl;
            option=getValidOption();
			if(option=='c'){
				t[1]++;
			}
			cout<<"Question 10"<<endl;
			cout<<"Which of the following is the correct syntax for passing an object by reference to a function in C++?"<<endl;
            cout<<"  a. void functionName(ClassName obj);"<<endl;
			cout<<"  b. void functionName(ClassName* obj);"<<endl;
			cout<<"  c. void functionName(const ClassName& obj);"<<endl;
			cout<<"  d. void functionName(ClassName& obj);"<<endl;
			option=getValidOption();
			if(option=='d'){
				t[1]++;
			}
		    
	        cout<<t[1]<<endl;
	        updateinthefile(1,userName);
        }
    	void Cplus::m3(string userName){
			t[2]=0;
			cout<<"Welcome to the module 3 of 0ops with c++"<<endl;
			cout<<"here is the video which is used to understand user defined polymorphism"<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/pcMSlWLKzOE?si=oU5WLw08mja0XHDH";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Let's start your quiz"<<endl;
			cout<<"Question1"<<endl;
			cout<<"what are the different types of polymorphism"<<endl;
            cout<<"  a. Static polymorphism"<<endl;
            cout<<"  b. Dynamic polymorphism"<<endl;
            cout<<"  c. both a&b"<<endl;
            cout<<"  d. none of the above"<<endl;
            cout<<"enter your answer: ";
		    option=getValidOption();
			if(option=='c'){
				t[2]++;
			}
			cout<<"Question 2";
			cout<<"in operator overloading one operator must be _______________ "<<endl;
            cout<<"  a.primitive data types"<<endl;
            cout<<"  b.derived data types"<<endl;
            cout<<"  c.user defined data types"<<endl;
            cout<<"  d.all the above"<<endl;
			option=getValidOption();
			if(option=='c'){
				t[2]++;
			}
			cout<<"Question 3"<<endl;
			cout<<"when function overloading does occur when two or more functions having same name but_"<<endl;
            cout<<"  a. Different no. of parameters"<<endl;
            cout<<"  b. Different type of parameters"<<endl;
            cout<<"  c. return type of function"<<endl;
            cout<<"  d. both a&b"<<endl;
		option=getValidOption();
			if(option=='d'){
				t[2]++;
			}
			cout<<"Question 4"<<endl;
			cout<<"what are the rules of operator overloading?"<<endl;;
            cout<<"  a. cannot define new symbols as operators"<<endl;
            cout<<"  b. operators associativity cannot be changed"<<endl;
            cout<<"  c. one of the operand must be user defined data type"<<endl;
            cout<<"  d. all the above"<<endl;
			option=getValidOption();
			if(option=='d'){
				t[2]++;
			}
			cout<<"Question 5"<<endl;
			cout<<"What are the operators that cannot be overloaded?"<<endl;
            cout<<"  a. ::  scope resolution operator"<<endl;
            cout<<"  b. ? : terenary operator"<<endl;
            cout<<"  c. .*  member access operator"<<endl;
            cout<<"  d. all the above"<<endl;
	        option=getValidOption();
	        if(option=='d'){
	        	t[2]++;
			}
			cout<<"Question 6"<<endl;
			cout<<"What is compile time polymorphism?"<<endl;
            cout<<"  a. the type of polymorphism which can be resolved during run time"<<endl; 
			cout<<"  b. the type of polymorphism which can be resolved during compile time"<<endl;
            cout<<"  c. both a&b"<<endl;
            cout<<"  d. None of the above"<<endl;
	        option=getValidOption();
	        if(option=='b'){
	        	t[2]++;
			}
			cout<<"Question 7"<<endl;
			cout<<"what are the real world cases for polymorphism?"<<endl;
            cout<<"   a. UI components and frameworks"<<endl;
            cout<<"   b. Game development"<<endl;
            cout<<"   c. Payment systems"<<endl;
            cout<<"   d. all the above"<<endl;
			option=getValidOption();
			if(option=='d'){
				t[2]++;
			}
			
			cout<<"Question 8"<<endl;
			cout<<"Which of the following describes runtime polymorphism?"<<endl;
            cout<<"  a. Function overloading"<<endl;
			cout<<"  b. Operator overloading"<<endl;
			cout<<"  c. Function overriding"<<endl;
			cout<<"  d. all the above"<<endl;
		option=getValidOption();
			if(option=='c'){
				t[2]++;

		    }
		    cout<<"question 9"<<endl;
		    cout<<"What is the purpose of the override keyword in C++?"<<endl;
            cout<<"  a. To prevent a function from being overloaded. "<<endl;
			cout<<"  b. To indicate that a function is an overridden virtual function in a derived class."<<endl;
			cout<<"  c. To declare a pure virtual function."<<endl;
			cout<<"  d. To prevent a class from being inherited."<<endl;
		    option=getValidOption();
			if(option=='b'){
				t[2]++;
	        }
	        cout<<"Question 10"<<endl;
	        cout<<"What does the keyword virtual indicate in a member function declaration?"<<endl;
            cout<<"  a. The function is inline."<<endl;
			cout<<"  b. The function can be overridden in a derived class."<<endl;
			cout<<"  c. The function cannot be overridden in a derived class."<<endl;
			cout<<"  d. The function is private."<<endl;
			option=getValidOption();
			if(option=='b'){
				t[2]++;
	        }
	        cout<<t[2]<<endl;
	        updateinthefile(2,userName);
        }
void Cplus::m4(string userName){
			t[3]=0;
			cout<<"Welcome to the module 4 of Oops with c++"<<endl;
			cout<<"here is the video which is used to understand about inheritance"<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/RO1ZYW9NAzg?si=CznQ4aaesgoT-EU3";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Let's start your quiz"<<endl;
			cout<<"Question1"<<endl;
			cout<<"What is Inheritance in C++?"<<endl;
            cout<<"  a. Wrapping of data into a single class"<<endl;
            cout<<"  b. Deriving new classes from existing classes"<<endl;
            cout<<"  c. Overloading of classes"<<endl;
            cout<<"  d. Classes with same names"<<endl;
           option=getValidOption();
			if(option=='b'){
				t[3]++;
			}
			cout<<"Question 2";
			cout<<"Which specifier makes all the data members and functions of base class inaccessible by the derived class?"<<endl;
			cout<<"  a. private"<<endl;
            cout<<"  b. protected"<<endl;
            cout<<"  c. public"<<endl;
            cout<<"  d. both private and protected"<<endl;
			option=getValidOption();
			if(option=='c'){
				t[3]++;
			}
			cout<<"Question 3"<<endl;
			cout<<"In c++ which type of inheritance allows a class to inherit properties and behaviours from base class."<<endl;                         cout<<"  a. Multilevel inheritance"<<endl;
			cout<<"  b. Hierarchical inheritance"<<endl;
            cout<<"  c. Multiple inheritance"<<endl;
            cout<<"  d. Single inheritance"<<endl;
           option=getValidOption();
			if(option=='d'){
				t[3]++;
			}
			cout<<"Question 4"<<endl;
			cout<<"In c++ which access specified allows members of a base class to be accessible in the derived class but not to the outside world"<<endl;
			cout<<"  a. friend"<<endl; 
            cout<<"  b. private"<<endl;
            cout<<"  c. public"<<endl;
            cout<<"  d. protected"<<endl;
		option=getValidOption();
			if(option=='d'){
				t[3]++;
			}
			cout<<"Question 5"<<endl;
			cout<<"In c++ which type of inheritance is not supported directly but can be achieved using a combination of other types of inheritance"<<endl;
            cout<<"  a. Multiple inheritance"<<endl;
            cout<<"  b. Single inheritance"<<endl;
            cout<<"  c. Hierarchical inheritance"<<endl;
            cout<<"  d. Hybrid inheritance;"<<endl;
	        option=getValidOption();
	        if(option=='d'){
	        	t[3]++;
			}
			cout<<"Question 6"<<endl;
			cout<<"In c++ if a derived class does not define a constructor,"<<endl;
			cout<<"which constructor of the base class is called during the object creation of the derived class?"<<endl;
            cout<<"  a. No constructor is called"<<endl;
			cout<<"  b. structor of the base class"<<endl;
            cout<<"  c. Parameterized constructor of the base class"<<endl;
            cout<<"  d. Default constructor of the base class"<<endl;
            option=getValidOption();
	        if(option=='d'){
	        	t[3]++;
			}
			cout<<"Question 7"<<endl;
			cout<<"When you declare inheritance in C++ without specifying an access specifier before the base class,"<<endl;
			cout<<" the default access specifier"<<endl;
            cout<<"   a. public"<<endl;
            cout<<"   b. private"<<endl;
            cout<<"   c. protected"<<endl;
            cout<<"   d. friend"<<endl;
		option=getValidOption();
			if(option=='b'){
				t[3]++;
			}
			cout<<"Question 8"<<endl;
			cout<<"What is the correct way to access a protected member of a base class from a derived class?"<<endl;
            cout<<"  a. baseObj.member"<<endl;
			cout<<"  b. this->member"<<endl;
			cout<<"  c. derivedObj.member"<<endl;
			cout<<"  d. super.member"<<endl;
		option=getValidOption();
			if(option=='b'){
				t[3]++;

		    }
		    cout<<"question 9"<<endl;
		    cout<<"What is true about constructors in inheritance?"<<endl;
            cout<<"  a. Constructors are inherited from the base class."<<endl;
			cout<<"  b. Constructors of the base class are called after the derived class constructors."<<endl;
			cout<<"  c. Constructors of the base class are called before the derived class constructors."<<endl;
			cout<<"  d. Constructors are never called in inheritance."<<endl;
		    option=getValidOption();
			if(option=='b'){
				t[3]++;
	        }
	        cout<<"Question 10"<<endl;
	        cout<<"What is the effect of the virtual keyword in C++ inheritance?"<<endl;
            cout<<"  a. It makes the base class methods private."<<endl;
			cout<<"  b. It ensures that the base class method can be overridden in the derived class."<<endl;
			cout<<"  c. It disables inheritance."<<endl;
			cout<<"  d. It makes the class abstract."<<endl;
			option=getValidOption();
    		if(option=='b'){
				t[3]++;
	        }
	        cout<<t[3]<<endl;
	        updateinthefile(3,userName);
}
void Cplus::modules(string userName) {
    cout << "Modules in C++: " << endl;
    string modules[] = {
        "Intro to OOP concepts: classes, objects, and access specifiers", 
        "Constructors, destructors, and passing objects", 
        "Polymorphism", 
        "Inheritance"
    };
    string progressFile = "cpp.txt";
    string line, name;
    int completedModules = 0;
    bool foundUser = false;

    // Check if the file exists
    ifstream file(progressFile);
    if (!file) {
        cout << "Error: Unable to open progress file (" << progressFile << "). Ensure the file exists." << endl;
        return;
    }
 // Read user progress
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        if (name == userName) {
            foundUser = true;
            string moduleStatus;
            // Display user progress for each module
            for (int k = 0; k < 4; k++) {
                if (getline(ss, moduleStatus, ',')) {
                    if (moduleStatus != "$") {
                        completedModules++;
                        cout << (k + 1) << ". " << modules[k] << " (Quiz completed)" << endl;
                    } else {
                        cout << (k + 1) << ". " << modules[k] << " (Quiz not taken)" << endl;
                    }
                } else {
                    cout << (k + 1) << ". " << modules[k] << " (No data available)" << endl;
                }
            }
        }
    }
    file.close();
    // Handle user not found
    if (!foundUser) {
        cout << "Error: User \"" << userName << "\" not found in the progress file." << endl;
        return;
    }

    // Check if all modules are completed
    if (completedModules == 4) {
        cout << "You have completed all the modules in OOPs with C++." << endl;
        // Generate certificate
        Grading g;
        Certificate cert;
        int marks = g.grade(userName, 2);
        cert.generateCertificate(userName, 2, marks);
        return;
    }
    // Prompt the user to select a module to learn
    int choice;
    cout << "Enter the module you want to learn (1-4): ";
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice! Please enter a valid module number (1-4)." << endl;
        return;
    }

    // Call the corresponding module function
    switch (choice) {
    case 1:
        m1(userName);
        break;
    case 2:
        m2(userName);
        break;
    case 3:
        m3(userName);
        break;
    case 4:
        m4(userName);
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }

    cout << "Quiz for module " << choice << " has been completed." << endl;
}
