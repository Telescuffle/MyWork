#include <iostream>
#include <fstream>
using namespace std;

int main ()

{
	//Main Menu

	
	char MainMenuChoiceText[8];
	int MainMenuChoice = 7;

	//cout<<"01001000 01100001 01101110 01100111 01101101 01100001 01101110 00101110 00101110 00101110"<<endl;
	system ("CLS");
	cout<<"Hangman: C++ Edition"<<endl;

	bool loop;
	do
	{
	
	loop = false;	
	cout <<"Main Menu" <<endl;
	cout <<" " <<endl;
	cout <<"Please choose one of the following options with the assigned number" << endl;
	cout <<" " <<endl;
	cout <<"1. Start new single player game"<<endl;
	cout <<"2. Load single player saved game"<<endl;
	cout <<"3. Start a two player game"<<endl;
	cout <<"4. Instructions"<<endl;
	cout <<"5. View single player high score"<<endl;
	cout <<"6. Exit"<<endl;
	cin >> MainMenuChoiceText;

	if(strlen(MainMenuChoiceText) == 1 && isdigit(MainMenuChoiceText[0]))
	{
		MainMenuChoice = MainMenuChoiceText[0] - '0';
	}

	switch (MainMenuChoice)
	{
	case 1:
		
		cout <<"Let the game begin!"<<endl;

		//rest of the code here
	break;

	case 2:
		cout<<"Loading..."<<endl;
		//rest of the code here
	break;

	case 3:
		cout<<"Both players, get ready!"<<endl;
		//rest of the code here
	break;

	case 4:
		cout<<"Intructions page loading"<<endl;
		//rest of the code here
	break;

	case 5:
		cout<<"Loading high score page"<<endl;
		//rest of the code here
	break;

	case 6:
		cout<<"Exiting"<<endl;
		//rest of the code here
	break;

	default :
		cout<<"Invalid option chosen. Please try again!"<<endl;
		loop = true;
		break;
	}

	} while (loop==true);	
	
cin.get ();
	
return 0;

}