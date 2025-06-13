#include <iostream>
#include<iomanip>
using namespace std;

// function prototypes
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

//global variable
char menuInput;

struct BankAccount{
	int userid;
	int password;
	float money;
};

BankAccount NewUser, User; //struct variable declaration


int main()
{
	cout << "Hi! Welcome to MEBENG ATM Machine!" << endl; 
	cout << endl;
	
	start();
	
	return 0;
}

//function to print first menu
void printIntroMenu()
{
	cout << "Please select an option from the menu below: " << endl << endl;
	cout << "l -> Login" << endl;
	cout << "c -> Create New Account" << endl;
	cout << "q -> Quit" << endl;
	cout << endl << "> "; 
}

//function to print menu after login success
void printMainMenu()
{
	cout << "d -> Deposit Money" << endl;
	cout << "w -> Withdraw Money" << endl;
	cout << "r -> Request Balance" << endl;
	cout << "q -> Quit" << endl;
	cout << endl << "> ";
}
 
void start()
{
	printIntroMenu();
	cin >> menuInput;
	cout << endl;
	
	//switch statement after user input letter
	switch (menuInput){
		case 'l': 
		login();
		break;
		
		case 'c':
		createAccount();
		break;
		
		case 'q':
		exit(0);
		
	}
}

//function for user to create account
void createAccount()
{
	cout << "Please enter your user id: ";
	cin >> NewUser.userid;
	cout << "Please enter your password: ";
	cin >> NewUser.password;
	NewUser.money = 0.0;
	cout << endl;
	User = NewUser;
	cout << "Thank You! Your account has been created!" << endl;
	cout << endl;
	start();
}

//function if user choose login
void login()
{
	bool userlogin = false;
	
	cout << "Please enter your user id: ";
	cin >> User.userid;
	cout << "Please enter your password: ";
	cin >> User.password;
	cout << endl;
	
	if (User.userid == NewUser.userid && User.password == NewUser.password)
	{
		userlogin = true;
		cout << "Acess Granted!" << endl;
		cout << endl;
		
		while (menuInput != 'q')
		{
			printMainMenu(); //menu display after login success
			cin >> menuInput;
			cout << endl;
		
			if(menuInput == 'd')
			{
				float deposit;
				cout << "Amount of deposit: RM";
				cin >> deposit;
				User.money = User.money + deposit;
				cout << endl;
			}
		
			else if(menuInput == 'w')
			{
				float withdraw;
				cout << "Amount of withdrawal: RM";
				cin >> withdraw;
				
				if(withdraw < User.money)
					User.money = User.money - withdraw;
				else
					cout << endl << "Error! Not enough money to withdraw..." << endl;
				
				cout << endl;
			}
			
			else if (menuInput == 'r')
			{
				cout << fixed << showpoint;
				cout << setprecision(2);
				cout << "Your balance is RM" << User.money << endl;
				cout << endl;
			}
		}
			cout << "Thanks for stopping by!";
			exit (0);
		
	}
	//if login failed
	else
	{
		cout << "**********LOGIN FAILED!**********" << endl;
		cout << endl;
		start();
	}
		
}
