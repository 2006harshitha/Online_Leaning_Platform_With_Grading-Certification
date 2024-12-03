using namespace std;
class Student{
	protected:
		string name;
		string username;
		string password;
		string phoneNumber;
	public:	
    string sign_up();
    void login(string u,string p);
    int isUnique(string);
};
