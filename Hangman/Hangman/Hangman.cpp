
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

char MainMenuChoiceText[8],CategoryChoiceText[8],WrongLetter1 = '*',WrongLetter2 = '*',WrongLetter3 = '*',WrongLetter4 = '*',WrongLetter5 = '*',WrongLetter6 = '*';
int MainMenuChoice = 7, CategoryMenuChoice = 1, DifficultyMenuChoice = 1;

//Word which has current guess progress in it
char *GuessingWord;
//Word which contains the final outcome of what the word is
char *FullWord;

//Links to document containing words
const char *WordsOfCountries[];
const char *WordsOfCapitals[];

//End game functions
bool HasFinishedWon;
bool HasFinishedLose;

//Numeber of guesses remaining
int NumberOfGuesses;

//Runs the game
void GameStatus();
void PrintGame();
void GameLoop();


//Various Functions
void MainMenu();
void Category();
void Difficulty();
void Instructions();
void Quit();
void LoadingScreen();

int main ()

{
//Startup sequence
	system ("CLS");

	cout <<"TGSC Games Presents..." <<endl;
	Sleep (2000);

	system ("CLS");

	cout<<"HANGMAN: The C++ Edition"<<endl;
	Sleep (2000);

	cout <<" " <<endl;
	cout <<"(Now with loading screens)" <<endl << endl ;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;

	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<" " <<endl;
	cout <<"Created By TGSC Games " <<endl;

	Sleep (1500);

	system ("CLS");

	cout<<"Press any key to continue"<<endl;

	LoadingScreen();

	MainMenu();

	cin.get ();

	return 0;

}

void MainMenu()
{
	//Main Menu

	MainMenuChoice = 7;
	CategoryMenuChoice = 1;
	DifficultyMenuChoice = 1;

	system ("CLS");
	cout<<"Hangman"<<endl;

	bool loop;
	do
	{

		loop = false;	
		cout <<"Main Menu" <<endl;
		cout <<" " <<endl;
		cout <<"Please choose one of the following options with the assigned number" << endl;
		cout <<" " <<endl;
		cout <<"1. Start single player game"<<endl;
		cout <<"2. Instructions"<<endl;
		cout <<"3. Exit"<<endl;
		cin >> MainMenuChoiceText;


		//Validation for main menu
		if(strlen(MainMenuChoiceText) == 1 && isdigit(MainMenuChoiceText[0]))
		{
			MainMenuChoice = MainMenuChoiceText[0] - '0';
		}

		// Switch menu system
		switch (MainMenuChoice)
		{
		case 1:
			system ("CLS");
			Category();

			break;

		case 2:
			system ("CLS");
			Instructions();

			break;

		case 3:
			system ("CLS");
			Quit();

			break;

		default :

			cout<<"Invalid option chosen. Please try again!"<<endl;
			cout<<" "<<endl;
			Sleep (1500);
			system ("CLS");
			loop = true;

			break;
		}

	} while (loop==true);	

}

//Choose Category menu system
void Category()
{
	CategoryMenuChoice = 7;
	bool loop;

	do{
		loop = false;
	cout<<"Which Category would you like?"<<endl;
	cout<<" "<<endl;
	cout <<"Please choose one of the following options with the assigned number" << endl;
	cout <<" " <<endl;
	cout<<"1. Countries"<<endl;
	cout<<"2. Capital Cities"<<endl;
	cin >> CategoryChoiceText;


//Validation 
	if(strlen(CategoryChoiceText) == 1 && isdigit(CategoryChoiceText[0]))
		{
			CategoryMenuChoice = CategoryChoiceText[0] - '0';
		}

	switch (CategoryMenuChoice)
	{
	case 1:
		system ("CLS");
		CategoryMenuChoice = 1;
		Difficulty();

		break;

	case 2:
		system ("CLS");
		CategoryMenuChoice = 2;
		Difficulty();

		break;

	default :
		cout<<"Invalid option chosen. Please try again!"<<endl;
			cout<<" "<<endl;
			Sleep (1500);
			system ("CLS");
			loop = true;

			break;
	}
	}while (loop==true);	
}


//Difficulty menu (incomplete so has no difficulty)
void Difficulty()
{
	/*cout<<"Which difficulty would you like?"<<endl;
	cout<<" "<<endl;
	cout <<"Please choose one of the following options with the assigned number" << endl;
	cout <<" " <<endl;
	cout<<"1. Easy (3-5 letters long)"<<endl;
	cout<<"2. Medium (6-9 letters long)"<<endl;
	cout<<"3. Hard (10+ letters)"<<endl;
	cin >> DifficultyMenuChoice;

	switch (DifficultyMenuChoice)
	{
	case 1:
		system ("CLS");
		DifficultyMenuChoice = 1;

		break;

	case 2:
		system ("CLS");
		DifficultyMenuChoice = 2;


		break;

	case 3:
		system ("CLS");
		DifficultyMenuChoice = 3;


	default :

		cout<<"Invalid option chosen. Please try again!"<<endl;
		cout<<" "<<endl;
	}
	*/
	if (CategoryMenuChoice == 1 && DifficultyMenuChoice == 1)
	{
		//Generate random number of index based on the amount of words
		int WordListLength = 174;
		srand((unsigned)time(NULL));
		int random = rand() % WordListLength;

		//Get the random word from the words list and assign it to the new word char
		int WordList = strlen(WordsOfCountries[random]);
		FullWord = new char[WordList + 1];
		strcpy(FullWord,WordsOfCountries[random]);

		//Fill in guess word
		GuessingWord = new char[WordList + 1];
		strcpy(GuessingWord,FullWord);
		for (int i=0; i<strlen(GuessingWord); i++){
			GuessingWord[i] = '*';
		}
	}
	/*
	if (CategoryMenuChoice == 1 && DifficultyMenuChoice == 2)
	{

	}

	if (CategoryMenuChoice == 1 && DifficultyMenuChoice == 3)
	{

	}
	*/
	if (CategoryMenuChoice == 2 && DifficultyMenuChoice == 1)
	{
		//Generate random number of index based on the amount of words
		int WordListLength = 231;
		srand((unsigned)time(NULL));
		int random = rand() % WordListLength;

		//Get the random word from the words list and assign it to the new word char
		int WordList = strlen(WordsOfCapitals[random]);
		FullWord = new char[WordList + 1];
		strcpy(FullWord,WordsOfCapitals[random]);

		//Fill in guess word
		GuessingWord = new char[WordList + 1];
		strcpy(GuessingWord,FullWord);
		for (int i=0; i<strlen(GuessingWord); i++){
			GuessingWord[i] = '*';

		}
	
	}
	/*
	if (CategoryMenuChoice == 2 && DifficultyMenuChoice == 2)
	{

	}

	if (CategoryMenuChoice == 2 && DifficultyMenuChoice == 3)
	{

	}
	*/

	//Setup
	NumberOfGuesses = 6;
	HasFinishedWon = false;
	HasFinishedLose = false;
	WrongLetter1 = '*';
	WrongLetter2 = '*';
	WrongLetter3 = '*';
	WrongLetter4 = '*';
	WrongLetter5 = '*';
	WrongLetter6 = '*';

	//Sets up game
	PrintGame();
	do{
		GameLoop();
		PrintGame();
		GameStatus();
	}while(!HasFinishedWon && !HasFinishedLose);

	//Finish sequence
	system ("CLS");
	cout << "  +----+" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |    O" <<endl;
	cout << "  |   /|\\" <<endl;
	cout << "  |   / \\" <<endl;
	cout << "  |" <<endl;
	cout << "  +=========" <<endl;
	cout << " "<<endl;
	cout<< " The word so far: " << GuessingWord<<endl;
	cout << " "<<endl;
	if (HasFinishedWon){
		cout << " You won! :)"<<endl;
	}else if (HasFinishedLose){
		cout << " You lose! :("<<endl;
	}
	cout << " The word was "<<FullWord<<endl;
	cout<<" Letters you have guessed wrong: "<<WrongLetter1<<", "<<WrongLetter2<<", "<<WrongLetter3<<", "<<WrongLetter4<<", "<<WrongLetter5<<", "<<WrongLetter6<<endl;
	Sleep(5000);
	cout<<"	Press enter to return to the menu"<<endl;

	//Release memory
	delete FullWord;
	delete GuessingWord;

	//Main menu
	MainMenu();
}

void GameStatus(){
	//Get guessed letter count
	bool found = false;
	for (int i=0; i<strlen(GuessingWord); i++){
		if (GuessingWord[i] == '*'){
			found = true;
		}
	}

	//Check game status
	if (NumberOfGuesses == 0){
		HasFinishedLose = true;
	}else if (!found){
		HasFinishedWon = true;
	}
}

//Voids the game loop
void GameLoop(){
	cout << " Please enter a letter" << endl;
	char letter;
	cin >> letter;

	if (!isalpha(letter)){
		return;
	}
	//If letter hasnt been found
	bool HasBeenFound = false;
	for (int i=0; i<strlen(FullWord); i++){
		if (tolower(FullWord[i]) == tolower(letter) && FullWord[i] != ' '){
			GuessingWord[i] = FullWord[i];
			HasBeenFound = true;
		}
	}

	//If letter has been found
	if (!HasBeenFound){
		if (WrongLetter1 == '*'){
			WrongLetter1 = letter;
		}else if (WrongLetter2 == '*'){
			WrongLetter2 = letter;
		}else if (WrongLetter3 == '*'){
			WrongLetter3 = letter;
		}else if (WrongLetter4 == '*'){
			WrongLetter4 = letter;
		}else if (WrongLetter5 == '*'){
			WrongLetter5 = letter;
		}else if (WrongLetter6 == '*'){
			WrongLetter6 = letter;
		}
		NumberOfGuesses--;
	}
}

//Prints the gallows
void PrintGame()
{
	if (NumberOfGuesses == 6)
	{		system ("CLS");
	cout << "  +----+" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  +=========" <<endl;
	cout << " "<<endl;
	cout<< " The word so far: " << GuessingWord<<endl;
	cout << " "<<endl;
	cout << " You have 5 remaining Guesses"<<endl;
	cout<<" Letters you have guessed wrong: "<<endl;
	}
	if (NumberOfGuesses == 5)
	{		system ("CLS");
	cout << "  +----+" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |    O" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  +=========" <<endl;
	cout << " "<<endl;
	cout<< " The word so far: " << GuessingWord<<endl;
	cout << " "<<endl;
	cout << " You have 4 remaining Guesses"<<endl;
	cout<<" Letters you have guessed wrong: "<<WrongLetter1<<endl;
	}
	if (NumberOfGuesses == 4)
	{		system ("CLS");
	cout << "  +----+" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |    O" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  |" <<endl;
	cout << "  +=========" <<endl;
	cout << " "<<endl;
	cout<< " The word so far: " << GuessingWord<<endl;
	cout << " "<<endl;
	cout << " You have 3 remaining Guesses"<<endl;
	cout<<" Letters you have guessed wrong: "<<WrongLetter1<<", "<<WrongLetter2<<endl;
	}
	if (NumberOfGuesses == 3)
	{		system ("CLS");
	cout << "  +----+" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |    O" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |     \\" <<endl;
	cout << "  |" <<endl;
	cout << "  +=========" <<endl;
	cout << " "<<endl;
	cout<< " The word so far: " << GuessingWord<<endl;
	cout << " "<<endl;
	cout << " You have 2 remaining Guesses"<<endl;
	cout<<" Letters you have guessed wrong: "<<WrongLetter1<<", "<<WrongLetter2<<", "<<WrongLetter3<<endl;
	}
	if (NumberOfGuesses == 2)
	{		system ("CLS");
	cout << "  +----+" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |    O" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |   / \\" <<endl;
	cout << "  |" <<endl;
	cout << "  +=========" <<endl;
	cout << " "<<endl;
	cout<< " The word so far: " << GuessingWord<<endl;
	cout << " "<<endl;
	cout << " You have 1 remaining Guesses"<<endl;
	cout<<" Letters you have guessed wrong: "<<WrongLetter1<<", "<<WrongLetter2<<", "<<WrongLetter3<<", "<<WrongLetter4<<endl;
	}
	if (NumberOfGuesses == 1)
	{		system ("CLS");
	cout << "  +----+" <<endl;
	cout << "  |    |" <<endl;
	cout << "  |    O" <<endl;
	cout << "  |   /|" <<endl;
	cout << "  |   / \\" <<endl;
	cout << "  |" <<endl;
	cout << "  +=========" <<endl;
	cout << " "<<endl;
	cout<< " The word so far: " << GuessingWord<<endl;
	cout << " "<<endl;
	cout << " You have 0 remaining Guess"<<endl;
	cout<<" Letters you have guessed wrong: "<<WrongLetter1<<", "<<WrongLetter2<<", "<<WrongLetter3<<", "<<WrongLetter4<<", "<<WrongLetter5<<endl;
	}
}


//Instructions for the game
void Instructions()
{
	char Continue;

	cout<<"Hangman: C++ Edition instuctions"<<endl;
	cout<<" "<<endl;
	cout<<"A random word shall be selected by the computer."<<endl; 
	cout<<"Each letter of the word will be consealed by a '*'."<<endl;
	cout<<"Your job is to guess the letters that make up the word chosen by the computer."<<endl;
	cout<<"However, after six wrong guesses, it game over and the hangman wins!"<<endl;
	cout<<" "<<endl;
	cout<<"Please note, there are no spaces between words."<<endl;
	cout<<"Words which should be two words are only seperated by capital letter."<<endl;
	cout<<" "<<endl;
	cout<<"Enter '1' to return to the main menu"<<endl;
	cin>>Continue;
	if (Continue == '1')
	{
		MainMenu();
	}
	else 
	{
		system ("CLS");
		Instructions();
	}
}	

//Quits the game menu
void Quit()
{
	char answer;
	bool repeat;
	repeat = false;
	{
	cout<<"Are you sure that you want to quit?"<<endl;
	cout <<" " <<endl;
	cout <<"Please choose one of the following options with the assigned number" << endl;
	cout <<" " <<endl;
	cout<<"1. Yes"<<endl;
	cout<<"2. No"<<endl;
	cin>>answer;

	if (answer == '1')
	{
		system ("CLS");
		cout<<"Thanks for playing Hangman C++ Edition, see you soon!"<<endl;
		cout<<" "<<endl;
		Sleep (1500);
		exit(0);
		exit(0);
	}
	else if (answer == '2')
	{
		MainMenu();
		repeat = true;
	}
	if (repeat == false)
	{
		Quit();
	}
	}
}

//Pointless loading screen 
void LoadingScreen()
{
	int count;
	bool loop;

	count = 0;

	system ("CLS");

	while (count < 2)
	{
		cout<<"Loading"<<endl;
		cout<<"[         ]"<<endl;
		Sleep (500);

		system ("CLS");

		cout<<"Loading."<<endl;
		cout<<"[|||      ]"<<endl;
		Sleep (500);

		system ("CLS");

		cout<<"Loading.."<<endl;
		cout<<"[||||||   ]"<<endl;
		Sleep (500);

		system ("CLS");

		cout<<"Loading..."<<endl;
		cout<<"[|||||||||]"<<endl;
		Sleep (500);

		system ("CLS");

		count = count +1;

	}
}