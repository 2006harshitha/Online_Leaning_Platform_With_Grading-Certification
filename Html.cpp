#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Html.h"
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
char Html::getValidOption() {
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
void Html::updateinthefile(int k, string userName) {
    string progressFile = "html.txt";
    ifstream inFile(progressFile);
    string fileContent, line;

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(inFile, line)) {
        stringstream ss(line);
        string name;
        getline(ss, name, ',');

        if (name == userName) {
            stringstream updatedLine;
            updatedLine << name;

            for (int j = 0; j < 4; j++) { // Iterating through 4 modules for HTML
                string mark;
                if (getline(ss, mark, ',')) {
                    if (j == k) {
                        mark = to_string(t[k]); // Updating the mark for the selected module
                    }
                    updatedLine << "," << mark;
                }
            }
            fileContent += updatedLine.str() + "\n";
        } else {
            fileContent += line + "\n";
        }
    }

    inFile.close();

    ofstream outFile(progressFile);
    if (!outFile) {
        cout << "Error writing to file!" << endl;
        return;
    }

    outFile << fileContent;
    outFile.close();

    cout << "Your score for module " << k + 1 << " has been updated." << endl;
}

void Html::m1(string userName) {
    t[0] = 0;
     cout << "Welcome to the module 1 of HTML: Basic Structure" << endl;
    cout << "Here is the video which explains the basics of HTML" << endl;
    cout << "Say YES if you want to see the video otherwise it directly takes you to the quiz" << endl;
     cin >> opinion;
            if (opinion == "YES") {
                std::string url = "https://www.youtube.com/watch?v=UB1O30fR-EE";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout << "Successfully you have accessed our video tutorial on HTML basics!" << endl;
            }
            cout << "Let's start your quiz" << endl;

            cout << "Question 1" << endl;
            cout << "1. What does the <!DOCTYPE html> declaration do?" << endl;
            cout << "  a. Declares the document to be HTML5" << endl;
            cout << "  b. Declares the document to be HTML4" << endl;
            cout << "  c. Declares the document to be XML" << endl;
            cout << "  d. Declares the document to be SGML" << endl;
          option=getValidOption();
            if (option == 'a') {
                t[0]++;
            }

            cout << "Question 2" << endl;
            cout << "2. Which HTML tag is used to define the document's header section?" << endl;
            cout << "  a. <header>" << endl;
            cout << "  b. <head>" << endl;
            cout << "  c. <meta>" << endl;
            cout << "  d. <body>" << endl;
                     option=getValidOption();

            if (option == 'b') {
                t[0]++;
            }

            cout << "Question 3" << endl;
            cout << "3. Which tag is used to define the main content of an HTML document?" << endl;
            cout << "  a. <head>" << endl;
            cout << "  b. <body>" << endl;
            cout << "  c. <title>" << endl;
            cout << "  d. <footer>" << endl;
            option=getValidOption();

            if (option == 'b') {
                t[0]++;
            }

            cout << "Question 4" << endl;
            cout << "4. Which tag is used to define a paragraph in HTML?" << endl;
            cout << "  a. <p>" << endl;
            cout << "  b. <para>" << endl;
            cout << "  c. <paragraph>" << endl;
            cout << "  d. <text>" << endl;
            option=getValidOption();

            if (option == 'a') {
                t[0]++;
            }

            cout << "Question 5" << endl;
            cout << "5. Which tag is used to define the title of the HTML document?" << endl;
            cout << "  a. <title>" << endl;
            cout << "  b. <header>" << endl;
            cout << "  c. <head>" << endl;
            cout << "  d. <meta>" << endl;
            option=getValidOption();

            if (option == 'a') {
                t[0]++;
            }

            cout << "Question 6" << endl;
            cout << "6. Which tag is used to create a line break in HTML?" << endl;
            cout << "  a. <br>" << endl;
            cout << "  b. <lb>" << endl;
            cout << "  c. <break>" << endl;
            cout << "  d. <line>" << endl;
            option=getValidOption();

            if (option == 'a') {
                t[0]++;
            }

            cout << "Question 7" << endl;
            cout << "7. Which tag is used to define an unordered list in HTML?" << endl;
            cout << "  a. <ul>" << endl;
            cout << "  b. <ol>" << endl;
            cout << "  c. <li>" << endl;
            cout << "  d. <list>" << endl;
            option=getValidOption();

            if (option == 'a') {
                t[0]++;
            }

            cout << "Question 8" << endl;
            cout << "8. Which tag is used to define an ordered list in HTML?" << endl;
            cout << "  a. <ul>" << endl;
            cout << "  b. <ol>" << endl;
            cout << "  c. <li>" << endl;
            cout << "  d. <list>" << endl;
            option=getValidOption();

            if (option == 'b') {
                t[0]++;
            }

            cout << "Question 9" << endl;
            cout << "9. Which tag is used to define a list item in HTML?" << endl;
            cout << "  a. <li>" << endl;
            cout << "  b. <item>" << endl;
            cout << "  c. <listitem>" << endl;
            cout << "  d. <ol>" << endl;
                  option=getValidOption();

            if (option == 'a') {
                t[0]++;
            }

            cout << "Question 10" << endl;
            cout << "10. Which attribute is used to provide an alternate text for an image?" << endl;
            cout << "  a. title" << endl;
            cout << "  b. alt" << endl;
            cout << "  c. src" << endl;
            cout << "  d. href" << endl;
                   option=getValidOption();

            if (option == 'b') {
                t[0]++;
            }
            cout <<"your score :" << t[0] << endl;
            updateinthefile(0,userName);
        }

 void Html::m2(string userName) {   
          t[1] = 0;
            cout << "Welcome to the module 2 of HTML: Text Formatting" << endl;
            cout << "Here is the video which explains the basics of HTML text formatting" << endl;
            cout << "Say YES if you want to see the video otherwise it directly takes you to the quiz" << endl;
            cin >> opinion;
            if (opinion == "YES") {
                std::string url = "https://www.youtube.com/watch?v=7FqQLqNIEY8&list=PLP9IO4UYNF0VdAajP_5pYG-jG2JRrG72s";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout << "Successfully you have accessed our video tutorial on HTML text formatting!" << endl;
            }
            cout << "Let's start your quiz" << endl;

            cout << "Question 1" << endl;
            cout << "1. Which tag is used to make text bold in HTML?" << endl;
            cout << "  a. <b>" << endl;
            cout << "  b. <strong>" << endl;
            cout << "  c. <bold>" << endl;
            cout << "  d. <em>" << endl;
                     option=getValidOption();

            if (option == 'a') {
                t[1]++;
            }

            cout << "Question 2" << endl;
            cout << "2. Which tag is used to make text italic in HTML?" << endl;
            cout << "  a. <i>" << endl;
            cout << "  b. <em>" << endl;
            cout << "  c. <italic>" << endl;
            cout << "  d. <strong>" << endl;
                    option=getValidOption();

            if (option == 'a') {
                t[1]++;
            }

            cout << "Question 3" << endl;
            cout << "3. Which tag is used to underline text in HTML?" << endl;
            cout << "  a. <u>" << endl;
            cout << "  b. <underline>" << endl;
            cout << "  c. <ul>" << endl;
            cout << "  d. <li>" << endl;
                     option=getValidOption();

            if (option == 'a') {
                t[1]++;
            }

            cout << "Question 4" << endl;
            cout << "4. Which tag is used to create a line break in HTML?" << endl;
            cout << "  a. <lb>" << endl;
            cout << "  b. <break>" << endl;
            cout << "  c. <br>" << endl;
            cout << "  d. <hr>" << endl;
                    option=getValidOption();

            if (option == 'c') {
                t[1]++;
            }

            cout << "Question 5" << endl;
            cout << "5. Which tag is used for creating a paragraph in HTML?" << endl;
            cout << "  a. <para>" << endl;
            cout << "  b. <p>" << endl;
            cout << "  c. <text>" << endl;
            cout << "  d. <div>" << endl;
                    option=getValidOption();

            if (option == 'b') {
                t[1]++;
            }

            cout << "Question 6" << endl;
            cout << "6. Which tag is used to make text emphasized in HTML?" << endl;
            cout << "  a. <em>" << endl;
            cout << "  b. <strong>" << endl;
            cout << "  c. <i>" << endl;
            cout << "  d. <b>" << endl;
                   option=getValidOption();

            if (option == 'a') {
                t[1]++;
            }

            cout << "Question 7" << endl;
            cout << "7. How can you make text bold using CSS?" << endl;
            cout << "  a. font-weight: bold;" << endl;
            cout << "  b. text-decoration: bold;" << endl;
            cout << "  c. font-style: bold;" << endl;
            cout << "  d. font-family: bold;" << endl;
                   option=getValidOption();

            if (option == 'a') {
                t[1]++;
            }

            cout << "Question 8" << endl;
            cout << "8. How do you set a background color for all <h1> elements?" << endl;
            cout << "  a. h1 {background-color: yellow;}" << endl;
            cout << "  b. h1 {color: yellow;}" << endl;
            cout << "  c. h1 {background: yellow;}" << endl;
            cout << "  d. h1 {bgcolor: yellow;}" << endl;
                  option=getValidOption();

            if (option == 'a') {
                t[1]++;
            }

            cout << "Question 9" << endl;
            cout << "9. Which HTML tag is used to define emphasized text?" << endl;
            cout << "  a. <em>" << endl;
            cout << "  b. <italic>" << endl;
            cout << "  c. <i>" << endl;
            cout << "  d. <strong>" << endl;
                    option=getValidOption();

            if (option == 'a') {
                t[1]++;
            }

            cout << "Question 10" << endl;
            cout << "10. How do you make a list that lists the items with numbers?" << endl;
            cout << "  a. <ul>" << endl;
            cout << "  b. <list>" << endl;
            cout << "  c. <ol>" << endl;
            cout << "  d. <dl>" << endl;
                    option=getValidOption();

            if (option == 'c') {
                t[1]++;
            }
            cout << "your score :" <<t[1] << endl;
            updateinthefile(1,userName);

}
 void Html::m3(string userName) {
    t[2] = 0;
    cout << "Welcome to the module 3 of HTML: Links and Images" << endl;
     cout << "Here is the video which explains the basics of HTML links and images" << endl;
            cout << "Say YES if you want to see the video otherwise it directly takes you to the quiz" << endl;
            cin >> opinion;
            if (opinion == "YES") {
                std::string url = "https://www.youtube.com/watch?v=HA6bByKdAQM&list=PLP9IO4UYNF0VdAajP_5pYG-jG2JRrG72s";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout << "Successfully you have accessed our video tutorial on HTML links and images!" << endl;
            }
            cout << "Let's start your quiz" << endl;

            cout << "Question 1" << endl;
            cout << "1. Which HTML tag is used to create a hyperlink?" << endl;
            cout << "  a. <a>" << endl;
            cout << "  b. <link>" << endl;
            cout << "  c. <href>" << endl;
            cout << "  d. <h1>" << endl;
                    option=getValidOption();

            if (option == 'a') {
                t[2]++;
            }

            cout << "Question 2" << endl;
            cout << "2. Which attribute is used to specify the URL of a hyperlink?" << endl;
            cout << "  a. src" << endl;
            cout << "  b. link" << endl;
            cout << "  c. href" << endl;
            cout << "  d. url" << endl;
                     option=getValidOption();

            if (option == 'c') {
                t[2]++;
            }

            cout << "Question 3" << endl;
            cout << "3. Which tag is used to embed an image in HTML?" << endl;
            cout << "  a. <img>" << endl;
            cout << "  b. <image>" << endl;
            cout << "  c. <pic>" << endl;
            cout << "  d. <src>" << endl;
                   option=getValidOption();

            if (option == 'a') {
                t[2]++;
            }

            cout << "Question 4" << endl;
            cout << "4. Which attribute is used to specify the source of an image?" << endl;
            cout << "  a. href" << endl;
            cout << "  b. src" << endl;
            cout << "  c. source" << endl;
            cout << "  d. link" << endl;
                  option=getValidOption();

            if (option == 'b') {
                t[2]++;
            }

            cout << "Question 5" << endl;
            cout << "5. Which attribute is used to specify alternative text for an image?" << endl;
            cout << "  a. title" << endl;
            cout << "  b. alt" << endl;
            cout << "  c. src" << endl;
            cout << "  d. href" << endl;
                   option=getValidOption();

            if (option == 'b') {
                t[2]++;
            }

            cout << "Question 6" << endl;
            cout << "6. Which attribute is used to open a hyperlink in a new tab?" << endl;
            cout << "  a. src" << endl;
            cout << "  b. target='_blank'" << endl;
            cout << "  c. new" << endl;
            cout << "  d. url" << endl;
                    option=getValidOption();

            if (option == 'b') {
                t[2]++;
            }

            cout << "Question 7" << endl;
            cout << "7. Which attribute is used to define the width of an image?" << endl;
            cout << "  a. width" << endl;
            cout << "  b. size" << endl;
            cout << "  c. length" << endl;
            cout << "  d. src" << endl;
                 option=getValidOption();

            if (option == 'a') {
                t[2]++;
            }

            cout << "Question 8" << endl;
            cout << "8. Which attribute is used to define the height of an image?" << endl;
            cout << "  a. height" << endl;
            cout << "  b. size" << endl;
            cout << "  c. length" << endl;
            cout << "  d. src" << endl;
                      option=getValidOption();

            if (option == 'a') {
                t[2]++;
            }

            cout << "Question 9" << endl;
            cout << "9. Which HTML tag is used to embed a video?" << endl;
            cout << "  a. <video>" << endl;
            cout << "  b. <movie>" << endl;
            cout << "  c. <media>" << endl;
            cout << "  d. <vid>" << endl;
                    option=getValidOption();

            if (option == 'a') {
                t[2]++;
            }

            cout << "Question 10" << endl;
            cout << "10. Which HTML tag is used to embed audio?" << endl;
            cout << "  a. <audio>" << endl;
            cout << "  b. <sound>" << endl;
            cout << "  c. <media>" << endl;
            cout << "  d. <song>" << endl;
                     option=getValidOption();

            if (option == 'a') {
                t[2]++;
            }

            cout <<"your score :" << t[2]<< endl;
            updateinthefile(2,userName);

        }


void Html::m4(string userName) {
            t[3]= 0;
            cout << "Welcome to the module 4 of HTML: Tables" << endl;
            cout << "Here is the video which explains the basics of HTML tables" << endl;
            cout << "Say YES if you want to see the video otherwise it directly takes you to the quiz" << endl;
            cin >> opinion;
            if (opinion == "YES") {
                std::string url = "https://www.youtube.com/watch?v=e62D-aayveY&list=PLP9IO4UYNF0VdAajP_5pYG-jG2JRrG72s";
                std::string command = "start " + url; // 'start' is a Windows command to open URLs
                system(command.c_str());
                cout << "Successfully you have accessed our video tutorial on HTML tables!" << endl;
            }
            cout << "Let's start your quiz" << endl;

            cout << "Question 1" << endl;
            cout << "1. Which HTML tag is used to define a table?" << endl;
            cout << "  a. <table>" << endl;
            cout << "  b. <tr>" << endl;
            cout << "  c. <td>" << endl;
            cout << "  d. <th>" << endl;
                   option=getValidOption();

            if (option == 'a') {
                t[3]++;
            }

            cout << "Question 2" << endl;
            cout << "2. Which HTML tag is used to define a table row?" << endl;
            cout << "  a. <table>" << endl;
            cout << "  b. <tr>" << endl;
            cout << "  c. <td>" << endl;
            cout << "  d. <th>" << endl;
                    option=getValidOption();

            if (option == 'b') {
                t[3]++;
            }

            cout << "Question 3" << endl;
            cout << "3. Which HTML tag is used to define a table cell?" << endl;
            cout << "  a. <table>" << endl;
            cout << "  b. <tr>" << endl;
            cout << "  c. <td>" << endl;
            cout << "  d. <th>" << endl;
                      option=getValidOption();

            if (option == 'c') {
                t[3]++;
            }

            cout << "Question 4" << endl;
            cout << "4. Which HTML tag is used to define a table header?" << endl;
            cout << "  a. <table>" << endl;
            cout << "  b. <tr>" << endl;
            cout << "  c. <td>" << endl;
            cout << "  d. <th>" << endl;
                    option=getValidOption();

            if (option == 'd') {
                t[3]++;
            }

            cout << "Question 5" << endl;
            cout << "5. Which attribute is used to merge two or more cells horizontally in a table?" << endl;
            cout << "  a. rowspan" << endl;
            cout << "  b. colspan" << endl;
            cout << "  c. merge" << endl;
            cout << "  d. span" << endl;
                    option=getValidOption();

            if (option == 'b') {
                t[3]++;
            }

            cout << "Question 6" << endl;
            cout << "6. Which attribute is used to merge two or more cells vertically in a table?" << endl;
            cout << "  a. rowspan" << endl;
            cout << "  b. colspan" << endl;
            cout << "  c. merge" << endl;
            cout << "  d. span" << endl;
                    option=getValidOption();

            if (option == 'a') {
                t[3]++;
            }

            cout << "Question 7" << endl;
            cout << "7. Which HTML tag is used to group header content in a table?" << endl;
            cout << "  a. <thead>" << endl;
            cout << "  b. <tbody>" << endl;
            cout << "  c. <tfoot>" << endl;
            cout << "  d. <tr>" << endl;
                     option=getValidOption();

            if (option == 'a') {
                t[3]++;
            }

            cout << "Question 8" << endl;
            cout << "8. Which HTML tag is used to group body content in a table?" << endl;
            cout << "  a. <thead>" << endl;
            cout << "  b. <tbody>" << endl;
            cout << "  c. <tfoot>" << endl;
            cout << "  d. <tr>" << endl;
                     option=getValidOption();

            if (option == 'b') {
                t[3]++;
            }

            cout << "Question 9" << endl;
            cout << "9. Which HTML tag is used to group footer content in a table?" << endl;
            cout << "  a. <thead>" << endl;
            cout << "  b. <tbody>" << endl;
            cout << "  c. <tfoot>" << endl;
            cout << "  d. <tr>" << endl;
                    option=getValidOption();

            if (option == 'c') {
                t[3]++;
            }

            cout << "Question 10" << endl;
            cout << "10. Which attribute is used to add a border to a table?" << endl;
            cout << "  a. border" << endl;
            cout << "  b. frame" << endl;
            cout << "  c. outline" << endl;
            cout << "  d. edge" << endl;
                      option=getValidOption();

            if (option == 'a') {
                t[3]++;
            }

            cout <<"your score :" << t[3] << endl;
            updateinthefile(3,userName);

}


void Html::modules(string userName) {
    cout << "Modules in HTML: " << endl;
    string modules[] = {"Basic Structures", "Text Formatting", "Links and Images", "Tables"};
    string progressFile = "html.txt";
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
        cout << "You have completed all the Modules in HTML." << endl;
        Certificate obj;
        Grading g;
        int marks = g.grade(userName, 3); 
        obj.generateCertificate(userName, 3, marks);
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
