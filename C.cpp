#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "C.h"
#include  "Certificate.h"
#include "Grading.h"
using namespace std;
// Custom exception class for invalid input
class InvalidOptionException :public exception {
public:
    const char* what() const throw () {
        return "Invalid option entered. Please re-enter the option.";
    }
};
// Function to get a valid option from the user
char C::getValidOption() {
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
void C::updateinthefile(int k,string userName){
	string progressFile = "c.txt"; 
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
void C::m3(string userName){
	t[2]=0;
	cout<<"Welcome to the module 3 of c_programming language"<<endl;
	cout<<"here is the video which is used to understand arrays"<<endl;
	cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
	cin>>opinion;
	if(opinion=="YES"){
		std::string url = "https://youtu.be/MOeGnamlUP4?si=vusJU8Z3QZFOeTRE";
        std::string command = "start " + url; // 'start' is a Windows command to open URLs
        system(command.c_str());
        cout<<"successfully you have listen to our video"<<endl;
	}
	cout<<"Let's start your quiz"<<endl;
	cout<<"Question1"<<endl;
	cout<<"How do you initialize an array in C ?"<<endl;
    cout<<"  a.int arr[3] = (1,2,3);"<<endl;
    cout<<"  b.int arr(3) = {1,2,3};"<<endl;
    cout<<"  c.int arr[3] = {1,2,3};"<<endl;
    cout<<"  d.int arr(3) = (1,2,3);"<<endl;
	
	option=getValidOption();
		if(option=='c'){
			t[2]++;
		}
	cout<<"Question 2"<<endl;
	cout<<"Assuming int is of 4bytes, what is the size of int arr[15];?"<<endl;
    cout<<"  a.15"<<endl;
    cout<<"  b.19"<<endl;
    cout<<"  c.11"<<endl;
    cout<<"  d.60"<<endl;
	option=getValidOption();
		if(option=='d'){
			t[2]++;
		}
	cout<<"Question 3"<<endl;
	cout<<"Consider a two dimensional array A[20][10].Assume 4 words per memory cell,"<<endl;;
	cout<<"the base address of array A is 100, elements are stored in row-major order "<<endl;
	cout<<"and first element is A[0][0]. What is the address of A[11][5] ?"<<endl;
    cout<<"  a. 560"<<endl;
    cout<<"  b. 460"<<endl;
    cout<<"  c. 570"<<endl;
    cout<<"  d. 575"<<endl;
	option=getValidOption();
	if(option=='a'){
		t[2]++;
	}
	cout<<"Question4"<<endl;
	cout<<"Which of the following is the limitation of the array?"<<endl;
    cout<<"  a.elements can be accessed from anywhere."<<endl;
    cout<<"  b. The size of the array is fixed."<<endl;
    cout<<"  c. Memory waste if an array's elements are smaller than the size allotted to them"<<endl;
    cout<<"  d. both b&c"<<endl;
	option=getValidOption();
    if(option=='d'){
	        	t[2]++;
			}
			cout<<"Question 5"<<endl;
			cout<<"5.A recursive function can be replaced with __ in C"<<endl;
            cout<<"  a.for loop"<<endl;
            cout<<"  b.while loop"<<endl;
            cout<<"  c.do while loop"<<endl;
            cout<<"  d.All of these"<<endl;
	        option=getValidOption();
	        if(option=='d'){
	        	t[2]++;
			}
			cout<<"Question 6"<<endl;
			cout<<" What are the elements present in the array of the following C code?\n  int array[5] = {5};"<<endl;
            cout<<" a. 5, 5, 5, 5, 5"<<endl;
            cout<<" b. 5, 0, 0, 0, 0"<<endl;
            cout<<" c. 5, (garbage), (garbage), (garbage), (garbage)"<<endl;
            cout<<" d. (garbage), (garbage), (garbage), (garbage), 5"<<endl;
			option=getValidOption();
			if(option=='b'){
				t[2]++;
			}
			cout<<"here is the video which is used to understand strings"<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/b-5beEPeV0c?si=3SByyjzguXhRgZbT";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Let's start your quiz based on strings"<<endl;
			cout<<"Question 7"<<endl;
			cout<<"7.The ______ function appends not more than n characters."<<endl;
            cout<<"  a. strcat()"<<endl;
            cout<<"  b. strcon()"<<endl;  
            cout<<"  c. strncat()"<<endl;
            cout<<"  d. memcat()"<<endl;
			option=getValidOption();
			if(option=='a'){
				t[2]++;

		    }
		    cout<<"question 8"<<endl;
		    cout<<"which keyword is used to declare acharacter array in c"<<endl;
		    cout<<"  a.str"<<endl;
            cout<<"  b.character"<<endl;
            cout<<"  c.arr"<<endl;
            cout<<"  d.char"<<endl;
		    option=getValidOption();
			if(option=='d'){
				t[2]++;
	        }
	        cout<<"question 9"<<endl;
	        cout<<"Where is the pointer variable stored in memory?"<<endl;
	        cout<<"  a.char str[10] = \"Hello\";"<<endl; 
            cout<<"  b.char str = \"Hello\""<<endl;
            cout<<"  c.string str=\"Hello\";"<<endl;
            cout<<"  d.str = \"Hello\";"<<endl;
	        option=getValidOption();
			if(option=='a'){
				t[2]++;
	        }
	        cout<<"question 10"<<endl;
	        cout<<"How can you see if two strings are equal in c?"<<endl;
	        cout<<"  a.Use the == operator"<<endl;
            cout<<"  b.Use the strcmp function"<<endl;
            cout<<"  c.Use the equals function"<<endl;
            cout<<"  d.use the = operator"<<endl;
	        cout<<"enter your answer: ";
			cin>>option;
			if(option=='b'){
				t[2]++;
	}
	cout<<t[2]<<" are the marks you scored in the module 3 out of 10"<<endl;
    updateinthefile(2,userName);
}
void  C::m4(string userName){
			t[3]=0;
			cout<<"Welcome to the module 3 of c_programming language"<<endl;
			cout<<"here is the video which is used to understand user defined data type structure and unions"<<endl;
			cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/KL65a0TyeYo?si=G39lWFmNySTbGUM4";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"Let's start your quiz"<<endl;
			cout<<"Question1"<<endl;
			cout<<"What is a structure in C language?"<<endl;
            cout<<"  a. A structure is a collection of elements that can be of same datatype"<<endl;
            cout<<"  b. A structure is a collection of elements that can be of different datatype"<<endl;
            cout<<"  c. Elements of a structure are called members"<<endl;
            cout<<"  d. All of the these"<<endl;
            option=getValidOption();
			if(option=='d'){
				t[3]++;
			}
			cout<<"Question 2";
			cout<<"which keywords are used to define structure and unions in c respectively?"<<endl;
            cout<<"  a.struct ,UNION"<<endl;
            cout<<"  b.union struct"<<endl;
            cout<<"  c.structure union;"<<endl;
            cout<<"  d.struct,union"<<endl;
			option=getValidOption();
			if(option=='d'){
				t[3]++;
			}
			cout<<"Question 3"<<endl;
			cout<<" The size of a union is determined by the size of the __________"<<endl;
            cout<<"  a. First member in the union"<<endl;
            cout<<"  b. Last member in the union"<<endl;
            cout<<"  c. Biggest member in the union"<<endl;
            cout<<"  d. Sum of the sizes of all members"<<endl;
			option=getValidOption();
			if(option=='c'){
				t[3]++;
			}
			cout<<"Question 4"<<endl;
			cout<<"Members of a union are accessed as__"<<endl;;
            cout<<"  a. union-name.member"<<endl;
            cout<<"  b. union-pointer->member"<<endl;
            cout<<"  c. both union-name.member & union-pointer->member"<<endl;
            cout<<"  d. none of the above"<<endl;
			option=getValidOption();
			if(option=='c'){
				t[3]++;
			}
			cout<<"Question 5"<<endl;
			cout<<"Which of the following structure declaration will throw an error?"<<endl;
            cout<<"  a. struct temp{}s; main(){}"<<endl;
            cout<<"  b. struct temp{}; struct temp s; main(){}"<<endl;
            cout<<"  c. struct temp s; struct temp{}; main(){}"<<endl;
            cout<<"  d. none of the above"<<endl;
	        option=getValidOption();
	        if(option=='d'){
	        	t[3]++;
			}
			cout<<"Question 6"<<endl;
			cout<<"What is the size of a C structure?"<<endl;
            cout<<"  a. C structure is always 128 bytes"<<endl; 
			cout<<"  b. Size of C structure is the totatl bytes of all elements of structure"<<endl;
            cout<<"  c. Size of C structure is the size of largest elements"<<endl;
            cout<<"  d. None of the above"<<endl;
	        option=getValidOption();
	        if(option=='b'){
	        	t[3]++;
			}
			cout<<"Question 7"<<endl;
			cout<<" Choose a correct statement about C structure elements?"<<endl;
            cout<<"   a. Structure elements are stored on random free memory locations"<<endl;
            cout<<"   b. structure elements are stored in register memory locations"<<endl;
            cout<<"   c. structure elements are stored in contiguous memory locations"<<endl;
            cout<<"   d. None of the above"<<endl;
			option=getValidOption();
			if(option=='c'){
				t[3]++;
			}
			
			cout<<"Question 8"<<endl;
			cout<<"What is the main purpose of using unions in C?"<<endl;
            cout<<"  a. To store data of different types in the same memory location."<<endl;
			cout<<"  b. To store arrays of different types."<<endl;
			cout<<"  c. To allocate memory dynamically."<<endl;
			cout<<"  d. To prevent memory leaks."<<endl;
			option=getValidOption();
			if(option=='a'){
				t[3]++;

		    }
		    cout<<"question 9"<<endl;
		    cout<<"Which of the following is the correct way to declare a structure in C?"<<endl;
		    cout<<"  a. struct Point { int x; int y; }"<<endl;
			cout<<"  b. struct { int x; int y; } Point;"<<endl;
			cout<<"  c. struct Point { int x; int y; };"<<endl;
			cout<<"  d. structure Point { int x; int y; };"<<endl;
		    option=getValidOption();
			if(option=='d'){
				t[3]++;
	        }
	        cout<<"Question 10"<<endl;
	        cout<<"What is the purpose of the typedef keyword in C when used with structures?"<<endl;
	        cout<<"  a. To allocate memory for the structure."<<endl;
			cout<<"  b. To define a new data type name for the structure."<<endl;
			cout<<"  c. To initialize structure members."<<endl;
			cout<<"  d. To include structure definitions in multiple files."<<endl;
			option=getValidOption();
			if(option=='b'){
				t[3]++;
	        }
	        cout<<t[3]<<" are the mrks you scored in this module 4 out of 10"<<endl;
	         updateinthefile(3,userName);
	
 }


void C::m1(string userName){
			t[0]=0;
			cout<<"in this module you will see about basics of c"<<endl;
			cout<<"shall we start our learning process"<<endl;
			cout<<"Do you want to listen the video1 say YES if you want to listen otherwise it directly take you to the quiz"<<endl;
			cout<<" page where you have to tack the quiz"<<endl;;
			cin>>opinion;
			if(opinion=="YES"){
				std::string url = "https://youtu.be/kfZEZj1IOBE?si=zeDIEhtb8Bv6qgmQ";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout<<"successfully you have listen to our video"<<endl;
			}
			cout<<"take your quiz"<<endl;
			cout<<"Question1"<<endl;
			cout<<"1.what are the decision control statements?"<<endl;
			cout<<"  a.statements that control the flow of execution based on conditions"<<endl;
			cout<<"  b.statements that allocate memory dynamically"<<endl;
			cout<<"  c.statements that perform input/output operations"<<endl;
			cout<<"  d.statements that define functions and procedures"<<endl;
			option=getValidOption();
			if(option=='a'){
				t[0]++;
			}
			cout<<"Question 2"<<endl;
			cout<<"what does ths following line tells us condition?statement1:statement2; ?"<<endl;
			cout<<"  a.if the condition is false statemnt1 is executed statement2 is executed"<<endl;
			cout<<"  b.if the condition is true statemnt 1 is executed else statement 2 is executed"<<endl;
			cout<<"  c.if the condition is true statement2 is executed else statement1 is executed"<<endl;
			cout<<"  d.none of the above"<<endl;
			option=getValidOption();
			if(option=='b'){
				t[0]++;
			}
			cout<<"Question 3"<<endl;
			cout<<"switch(a){\n"<<"  case(90...100):printf(\"GradeA\");\nbreak;"<<endl;
			cout<<"  case(71...89):printf(\"grade B\");\nbreak;"<<endl;
			cout<<"  case(50...70):printf(\"grade C\");\nbreak;"<<endl;
			cout<<"  case(35...49):printf(\"grade D\");\nbreak;"<<endl;
			cout<<"  default:printf(\"grade e\");\n}"<<endl;
			cout<<"if a value is 32 what will be the output on the above snippet code"<<endl;
			cout<<"   a.grade A"<<endl;
			cout<<"   b.grade B"<<endl;
			cout<<"   c.grade e"<<endl;
			cout<<"   D.grade D"<<endl;
			option=getValidOption();
			if(option=='c'){
				t[0]++;
			}
			cout<<"Question 4"<<endl;
			cout<<"what is the syntax of for loop?"<<endl;
			cout<<"  a.for(iniialization;condition;increment){}"<<endl;
			cout<<"  b.for(condition;increment;initialization){}"<<endl;
			cout<<"  c.for(iniialization;increment;condition){}"<<endl;					
	        cout<<"  d.none of the above";
	        option=getValidOption();
	        if(option=='a'){
	        	t[0]++;
			}
			cout<<"Question 5"<<endl;
			cout<<"what is the difference between while and do-while loop?"<<endl;
	        cout<<"  a.while loop is the pre-condition loop where do while is the post condition loop"<<endl;
			cout<<"  b.if the condition is false at beginning in while loop body may not execute at all where in do while body is executed atleast once"<<endl;
	        cout<<"  c.both a&b"<<endl;
	        cout<<"  d.none of the above"<<endl;
	        option=getValidOption();
	        if(option=='c'){
	        	t[0]++;
			}
			cout<<"Question 6"<<endl;
			cout<<"what is the difference between = and == operators?"<<endl;
			cout<<"  a. = is a comparison operator and == is an assignment operator."<<endl;
			cout<<"  b. = is an assignment operator and == is a comparison operator."<<endl;
			cout<<"  c. Both are assignment operators."<<endl;
			cout<<"  d.Both are comparison operators."<<endl;
			option=getValidOption();
			if(option=='b'){
				t[0]++;
			}
			cout<<"Question 7"<<endl;
			cout<<"int x = 0;\nwhile(x < 3){\nx++;\n}\nprintf(\"%d\", x);"<<endl;
			cout<<"a. 1"<<endl;
			cout<<"b. 2"<<endl;
			cout<<"c. 3"<<endl;
			cout<<"d. 4"<<endl;
			option=getValidOption();
	if(option=='c'){
		t[0]++;
	}
	cout<<"question 8"<<endl;
	cout<<"Which of the following is a correct way to declare a constant in C?"<<endl;
	cout<<"  a. int const x = 10;"<<endl;
	cout<<"  b. const int x = 10;"<<endl;
	cout<<"  c. both a and b"<<endl;
	cout<<"  d. int x = const 10;"<<endl;
	option=getValidOption();
	if(option=='c'){
		t[0]++;
	}
	cout<<"question 9"<<endl;
	cout<<"who invented c language?"<<endl;
	cout<<"  a.Dennis Ritchie"<<endl;
	cout<<"  b.Bjarne strostrup"<<endl;
	cout<<"  c.James Gosling"<<endl;
	cout<<"  d.Guido van Rossum"<<endl;
	option=getValidOption();
	if(option=='a'){
		t[0]++;
	}
	cout<<"question 10"<<endl;
	cout<<"int y=123;\nint x=printf(\"%d\",y);\nprintf(\"%d \",x)"<<endl;
	cout<<"  a.error"<<endl;
	cout<<"  b.0"<<endl;
	cout<<"  c.1"<<endl;
	cout<<"  d.3"<<endl;
    option=getValidOption();
	if(option=='d'){
		t[0]++;
	}
	cout<<t[0]<<" are the marks you scored in the module 1 out of 10"<<endl;
	updateinthefile(0,userName);
}
 
 
void C::m2(string userName){
	t[1]=0;
	cout<<"Welcome to the module 2 of c_programming language"<<endl;
	cout<<"here is the video which is used to understand functions"<<endl;
	cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
	cin>>opinion;
	if(opinion=="YES"){
		std::string url = "https://youtu.be/NGQoKF2Ggt8?si=lQMG38vYXekAtV-8";
        std::string command = "start " + url; // 'start' is a Windows command to open URLs
        system(command.c_str());
        cout<<"successfully you have listen to our video"<<endl;
	}
	cout<<"Let's start your quiz"<<endl;
	cout<<"Question1"<<endl;
	cout<<"1.Which of the following is true about function prototypes in C?"<<endl;
    cout<<"  a. Function prototypes must always be declared before their use."<<endl;
	cout<<"  b. Function prototypes are optional."<<endl;
	cout<<"  c. Function prototypes must always be declared inside main()."<<endl; 
	cout<<"  d. none of the above"<<endl;
	option=getValidOption();
	if(option=='a'){
	   t[1]++;
	}
	cout<<"Question 2"<<endl;
	cout<<"What is the purpose of the return statement in a function?"<<endl;
    cout<<"  a. To print the function result"<<endl;
	cout<<"  b. To terminate the program "<<endl;
	cout<<"  c. To terminate the function and return a value to the caller"<<endl;
	cout<<"  d. To initialize a variable"<<endl;
	option=getValidOption();
	if(option=='c'){
		t[1]++;
	}
	cout<<"Question 3"<<endl;
	cout<<"what does it mean if the return type of a function is void"<<endl;
	cout<<"  a.It means the function return an integer value to the caller"<<endl;
	cout<<"  b.It means the function return a character to the caller"<<endl;
	cout<<"  c.It means the function return an float to the caller"<<endl;
	cout<<"  d.It means the function doen't return any value'"<<endl;
	option=getValidOption();
	if(option=='d'){
		t[1]++;
	}
	cout<<"here is the video which is used to understand recursive functions"<<endl;
	cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
	cin>>opinion;
	if(opinion=="YES"){
		std::string url = "https://youtu.be/KQZIBckWK-s?si=yj2LYM3FSUuBNFfR";
        std::string command = "start " + url; // 'start' is a Windows command to open URLs
        system(command.c_str());
        cout<<"successfully you have listen to our video"<<endl;
	}
	cout<<"Let's start your quiz based on recurion"<<endl;
	cout<<"Question 4"<<endl;
	cout<<"Recursion is a process in which a function calls"<<endl;
    cout<<" a. itself"<<endl;
    cout<<" b. another function"<<endl;
    cout<<" c.	main() function"<<endl;
    cout<<" d.	None of these"<<endl;
	option=getValidOption();
	if(option=='a'){
	    t[1]++;
	}
	cout<<"Question 5"<<endl;
	cout<<"5.A recursive function can be replaced with __ in C"<<endl;
    cout<<"  a.for loop"<<endl;
    cout<<"  b.while loop"<<endl;
    cout<<"  c.do while loop"<<endl;
    cout<<"  d.All of these"<<endl;
	option=getValidOption();
	if(option=='d'){
	    t[1]++;
	}
	cout<<"Question 6"<<endl;
	cout<<"6.The data structure used to implement recursive function calls _____"<<endl;
    cout<<"  a.Array"<<endl;
	cout<<"  b.Linked List"<<endl;
    cout<<"  c.Queue"<<endl;
    cout<<"  d.stack"<<endl;
	option=getValidOption();
	if(option=='d'){
		t[1]++;
	}
	cout<<"here is the video which is used to understand pointers"<<endl;
	cout<<"say YES if you want to see the video otherwise it directly take you to the quiz"<<endl;
	cin>>opinion;
	if(opinion=="YES"){
		std::string url = "https://youtu.be/f2i0CnUOniA?si=3Qb642IiV4LwE07k";
        std::string command = "start " + url; // 'start' is a Windows command to open URLs
        system(command.c_str());
        cout<<"successfully you have listen to our video"<<endl;
	}
	cout<<"Let's start your quiz based on pointers"<<endl;
	cout<<"Question 7"<<endl;
	cout<<"what is a pointer?"<<endl;
	cout<<"   a.it stores the address of another variable"<<endl;
	cout<<"   b.it stores the value of another variable"<<endl;
	cout<<"   c.it is a keyword used to define a variable"<<endl;
	cout<<"   d.none of the above"<<endl;
	option=getValidOption();
	if(option=='a'){
		t[1]++;

	}
	cout<<"question 8"<<endl;
	cout<<"what are the uses of pointers?"<<endl;
	cout<<"  a.To access array elements"<<endl;
    cout<<"  b.Used in Dynamic memory Allocation"<<endl;
    cout<<"  c.It help us to build complex data structures like a linked list, stack, queues, trees, and graphs."<<endl;
    cout<<"  d.All the above"<<endl;
	option=getValidOption();
	if(option=='d'){
		t[1]++;
	}
	cout<<"question 9"<<endl;
	cout<<"Where is the pointer variable stored in memory?"<<endl;
	cout<<"  a.heap memory"<<endl;
	cout<<"  b.stack memory"<<endl;
    cout<<"  c.Register memory"<<endl;
    cout<<"  d.Cache memory"<<endl;
    option=getValidOption();
	if(option=='b'){
		t[1]++;
	}
	cout<<"question 10"<<endl;
	cout<<"what are the operations that can be performed on the pointers"<<endl;
	cout<<"  a.addition with integers"<<endl;
	cout<<"  b.subtraction"<<endl;
	cout<<"  c.incrementing and decrementing"<<endl;
	cout<<"  d.All the above"<<endl;
	option=getValidOption();
	if(option=='d'){
		t[1]++;
	}
	cout<<t[1]<<" are the marks you scored in the module 2 out of 10"<<endl;
	updateinthefile(1,userName);
}


void C::modules(string userName) {
    cout << "Modules in C: " << endl;
    string modules[] = {"Intro to C", "Functions, Recursion and Pointers", "Arrays & Strings", "Structure and Unions"};
    string progressFile = "c.txt";
    string line, name;
    bool foundUser = false;
    int completedModules = 0;

    ifstream file(progressFile);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Check user progress
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, name, ','); // Read username

        if (name == userName) {
            foundUser = true;
            string moduleProgress;
            cout << "Current Progress for " << userName << ":" << endl;

            // Display module progress for the found user
            for (int i = 0; i < 4; i++) {
                if (getline(ss, moduleProgress, ',')) {
                    if (moduleProgress == "$") {
                        cout << (i + 1) << ". " << modules[i] << " (Quiz not taken)" << endl;
                    } else {
                        cout << (i + 1) << ". " << modules[i] << " (Quiz completed)" << endl;
                        completedModules++;
                    }
                }
            }
            break; // Stop processing further lines once the user is found
        }
    }
    file.close();

    if (!foundUser) {
        cout << "User not found!" << endl;
        return;
    }

    if (completedModules == 4) {
        cout << "You have completed all the Modules in C." << endl;
        Certificate obj;
        Grading g;
        int marks = g.grade(userName, 1);
        obj.generateCertificate(userName, 1, marks);
        return;
    }

    int choice;
    cout << "Enter the module you want to learn: ";
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice!" << endl;
        return;
    }
    // Module learning logic
    switch (choice) {
    case 1: m1(userName); break;
    case 2: m2(userName); break;
    case 3: m3(userName); break;
    case 4: m4(userName); break;
    }
    cout << "Quiz for module " << choice << " has been completed." << endl;
}
