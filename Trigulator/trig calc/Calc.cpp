/*-This is my code, there are many like it, but this one is mine.
Without my code, I am nothing, without me, my code is nothing!-*/	

//-FYI: A dyslexic wrote this code. Spellings of the word hypotenuse may differ.

#include <iostream>
#include <cmath>

using namespace std;


double Adj = 0, Opp = 0, Hyp = 0, A = 0, B = 0, C = 0, Ans = 0, Area = 0, a = 0, b = 0, c = 0;
char MainMenuChoiceText[8];
int MainMenuChoice = 7;
bool Repeat;

double toDegrees(double radians);
double toRadians(double degrees);

void RightAngledTriangle();
void NonRightAngledTriangle1();
void NonRightAngledTriangle2();

int main()
{

	//-Setting up a loop to validate the main menu and displays main menu

	bool loop;
	do
	{
		system ("CLS");

		loop = false;	

		cout<<" _____     _             _       _             "<<endl;
		cout<<"|_   _| __(_) __ _ _   _| | __ _| |_ ___  _ __ "<<endl;
		cout<<"  | || '__| |/ _` | | | | |/ _` | __/ _ \\| '__|"<<endl;
		cout<<"  | || |  | | (_| | |_| | | (_| | || (_) | |   "<<endl;
		cout<<"  |_||_|  |_|\\__, |\\__,_|_|\\__,_|\\__\\___/|_|   "<<endl;
		cout<<"             |___/                             "<<endl;
		cout<<" "<<endl;
		cout <<"Trigonometry/Pythagoras Calculator: C++ Edition"<<endl; 
		cout <<" "<<endl;
		cout <<" "<<endl;
		cout <<"MAIN MENU" <<endl;
		cout <<" " <<endl;
		cout <<"Please choose one of the following options with the assigned number" << endl;
		cout <<" " <<endl;
		cout <<"1. Right Angled Triangle with at least 1 side and 1 angle known"<<endl;
		cout <<"2. Non Right Angled Triangle with at least 1 side and 1 angle known"<<endl;
		cout <<"3. Triangle with all 3 sides known"<<endl;
		cout <<"4. Quit"<<endl;
		cin >> MainMenuChoiceText;

		//-Validation for main menu

		if(strlen(MainMenuChoiceText) == 1 && isdigit(MainMenuChoiceText[0]))
		{
			MainMenuChoice = MainMenuChoiceText[0] - '0';
		}

		//-Main Menu

		switch (MainMenuChoice)
		{

			//- Linked to right angled triangle with at least 1 side and 1 angle

		case 1:

			RightAngledTriangle ();

			break;

			//- 

		case 2:
			cout<<"Non Right Angled Triangle with at least 1 side and 1 angle known"<<endl;

			NonRightAngledTriangle1 ();

			break;

			//- Linked to non right angled triangle with all sides

		case 3:

			NonRightAngledTriangle2 ();

			break;

			//- Quit option

		case 4:
			cout<<"Thanks for using the C++ Trigonometry calulator"<<endl;
			return 0;

			//- Validation

		default :
			cout<<"Invalid option chosen. Please try again!"<<endl;
			loop = true;
			break;
		}

		//-Offers the end user to use the calculator for another probelem

		cout<<"Would you like to use the calculator again?"<<endl;
		cout<<"1. Yes"<<endl;
		cout<<"2. No"<<endl;
		cin>>Repeat;
		if (Repeat == 1){
			main();
			return 0;
		}
		else{
		}
	}

	while (loop==true);

	cin.get ();

	return 0;
}

void RightAngledTriangle (){

	//-Giving angle 'A' a fixed value for the right angle

	A = 90;

	cout <<"Right Angled Triangle with at least 1 side and 1 angle known"<<endl;

	//-System gets users known values and displays triange to aid user input

	cout<<"For any information that you do not have, please enter 0"<<endl;
	cout<<" "<<endl;
	cout<<"What is the size of angle B?"<<endl;
	cin>>B;

	if (B != 0) {


		cout<<"                      C"<<endl;
		cout<<"                     /|"<<endl;
		cout<<"                   /  |"<<endl;
		cout<<"                 /    |"<<endl;
		cout<<"               /      |"<<endl;
		cout<<"       Hyp   /        |"<<endl;
		cout<<"           /          |Opp"<<endl;
		cout<<"         /            |"<<endl;
		cout<<"       /              |"<<endl;
		cout<<"     /               _|"<<endl;
		cout<<"   /                | |"<<endl;
		cout<<" B --------------------A "<<endl;
		cout<<"           Adj "<<endl;
	}
	else if (B == 0){


		cout<<"                      C"<<endl;
		cout<<"                     /|"<<endl;
		cout<<"                   /  |"<<endl;
		cout<<"                 /    |"<<endl;
		cout<<"               /      |"<<endl;
		cout<<"       Hyp   /        |"<<endl;
		cout<<"           /          |Adj"<<endl;
		cout<<"         /            |"<<endl;
		cout<<"       /              |"<<endl;
		cout<<"     /               _|"<<endl;
		cout<<"   /                | |"<<endl;
		cout<<" B -------------------- A "<<endl;
		cout<<"           Opp "<<endl;
		cout<<" "<<endl;
		cout<<"What is the size of angle C?"<<endl;
		cin>>C; 
	}

	cout<<"What is the hypotenuse side length?"<<endl;
	cin>>Hyp;

	cout<<"What is the Adjacent side length?"<<endl;
	cin>>Adj;

	cout<<"What is the Opposite side length?"<<endl;
	cin>>Opp;


	//-System figures out one missing angle and all sides

	if (B !=0){
		if (Hyp !=0){
			Ans = Hyp*(sin(toRadians(B)));
			Opp = Ans;
			Adj = sqrt((Hyp * Hyp) - (Opp * Opp));
		}
		else if (Adj !=0){
			Ans = Adj*(tan(toRadians(B)));
			Opp = Ans;
			Hyp = sqrt((Adj * Adj) + (Opp * Opp));
		}
		else if (Opp !=0){
			Ans = Opp/(sin(toRadians(B)));
			Hyp = Ans;
			Adj = sqrt((Hyp * Hyp) - (Opp * Opp));

		}
	}
	else if (C !=0){

		double temp = Adj;
		Adj = Opp;
		Opp = temp;

		if (Hyp !=0){
			Ans = Hyp*(sin(toRadians(C)));
			Opp = Ans;
			Adj = sqrt((Hyp * Hyp) - (Opp * Opp));
		}							   
		else if (Adj !=0){			   
			Ans = Adj*(tan(toRadians(C)));
			Opp = Ans;
			Hyp = sqrt((Adj * Adj) + (Opp * Opp));
		}							   
		else if (Opp !=0){			   
			Ans = Opp*(sin(toRadians(C)));
			Hyp = Ans;
			Adj = sqrt((Hyp * Hyp) - (Opp * Opp));
		}
	}

	//-Using deduction to work out the final missing angle

	if (B != 0)
	{
		C= 180 - (B+A);
	}
	else if (C != 0)
	{
		B= 180 - (C+A);
	}

	//- Displays the results for the user to see in order to aid understanding of the figures

	Area = 0.5*(Opp*Adj);

	cout<<" "<<endl; 
	cout<<"                     "<<C<<endl;
	cout<<"                     /|"<<endl;
	cout<<"                   /  |"<<endl;
	cout<<"                 /    |"<<endl;
	cout<<"               /      |"<<endl;
	cout<<"            "<<Hyp<<"      "<<Opp<<endl;
	cout<<"           /          |"<<endl;
	cout<<"         /            |"<<endl;
	cout<<"       /              |"<<endl;
	cout<<"     /               _|"<<endl;
	cout<<"   /                | |"<<endl;
	cout<<" "<<B<<"-------------------- "<<A <<endl;
	cout<<"           "<<Adj<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;

	//-Displays the information for the triangle

	cout<<"The area of the triangle is "<<Area<<endl;
	cout<<"The hypotenuse side length is "<<Hyp<<endl;
	cout<<"The Opposite side length is "<<Opp<<endl;
	cout<<"The Adjacent side length is "<<Adj<<endl;
	cout<<"The angle 'A' is "<<A<<endl;
	cout<<"The angle 'B' is "<<B<<endl;
	cout<<"The angle 'C' is "<<C<<endl;
	cout<<" "<<endl;
}


//- Function to calculate a non right angled triangle when given a mix of angles and side or only angles (Semi working)
void NonRightAngledTriangle1 (){
	
	double small_1, small_2; 

	//Work out the third angle thing
	cout<<" "<<endl;
	cout<<"                      C"<<endl;
	cout<<"                     /\\"<<endl;
	cout<<"                   /    \\"<<endl;
	cout<<"                 /        \\"<<endl;
	cout<<"               /            \\"<<endl;
	cout<<"         a   /                \\"<<endl;
	cout<<"           /                    \\ b"<<endl;
	cout<<"         /                        \\"<<endl;
	cout<<"       /                            \\"<<endl;
	cout<<"     /                                \\"<<endl;
	cout<<"   /                                    \\"<<endl;
	cout<<" B --------------------------------------- A "<<endl;
	cout<<"                       c "<<endl;
	cout<<" "<<endl;
	cout<<"For any information that you do not have, please enter 0"<<endl;
	cout<<" "<<endl;
	cout<<"What is the side 'a' length?"<<endl;
	cin>>a;
	cout<<"What is the side 'b' length?"<<endl;
	cin>>b;
	cout<<"What is the side 'c' length?"<<endl;
	cin>>c;
	cout<<"What is angle 'A'?"<<endl;
	cin>>A;
	cout<<"What is angle 'B'?"<<endl;
	cin>>B;
	cout<<"What is angle 'C'?"<<endl;
	cin>>C;

	//-Works out final angle when given 2 angles
	
	if ((A != 0) && (C != 0))
	{
		B= 180 - (C+A);
	}
	if ((A != 0) && (B != 0))
	{
		C= 180 - (B+A);
	}
	if ((C != 0) && (B != 0))
	{
		A = 180 - (C+B);
	}

	//-Work out the sides from angles
	if ((B != 0) && (C !=0))
	{
		b = (a * sin(toRadians( B ))) / sin(toRadians( C ));
	}

	if ((A != 0) && (C !=0))
	{
		a = (b * sin(toRadians(A)))/sin(toRadians(C)); 
	}

	if ((A != 0) && (B !=0))
	{
		c = (b * sin(toRadians( B ))) / sin(toRadians( A ));
	}


	/*if ((a !=0) && (b !=0))
	{

	}
	
	if ((b != 0) && (c != 0))
	{
	
	}

	if ((a !=0) && (c !=0))
	{

	}*/

		if (a > b && a > c){
		small_1 = b;
		small_2 = c;
	}else if (b > a && b > c){
		small_1 = a;
		small_2 = c;
	}else if (c > a && c > b){
		small_1 = a;
		small_2 = b;
	}

	//-Displays the results
	
	Area = 0.5*(small_1*small_2);

	cout<<" "<<endl;
	cout<<"                     "<<C<<endl;
	cout<<"                     /\\"<<endl;
	cout<<"                   /    \\"<<endl;
	cout<<"                 /        \\"<<endl;
	cout<<"               /            \\"<<endl;
	cout<<"          "<<a<<"              "<<b<<endl;
	cout<<"           /                    \\ "<<endl;
	cout<<"         /                        \\"<<endl;
	cout<<"       /                            \\"<<endl;
	cout<<"     /                                \\"<<endl;
	cout<<"   /                                    \\"<<endl;
	cout<<" --------------------------------------- "<<endl;
	cout<< B<<"            "<<c<<"               "<<A<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<"The area of the triangle is "<<Area<<endl;
	cout<<"The 'A' side length is "<<a<<endl;
	cout<<"The 'B' side length is "<<b<<endl;
	cout<<"The 'C' side length is "<<c<<endl;
	cout<<"The angle 'A' is "<<A<<endl;
	cout<<"The angle 'B' is "<<B<<endl;
	cout<<"The angle 'C' is "<<C<<endl;
	cout<<" "<<endl;
}


//-Function to calculate a non rightangled triangle when only give sides
void NonRightAngledTriangle2 (){

double small_1, small_2; 

	//-Displays triangle and gathers required data

	cout<<"Non Right Angled Triangle with at least 2 sides known"<<endl;

	cout<<" "<<endl;
	cout<<"                      C"<<endl;
	cout<<"                     /\\"<<endl;
	cout<<"                   /    \\"<<endl;
	cout<<"                 /        \\"<<endl;
	cout<<"               /            \\"<<endl;
	cout<<"         a   /                \\"<<endl;
	cout<<"           /                    \\ b"<<endl;
	cout<<"         /                        \\"<<endl;
	cout<<"       /                            \\"<<endl;
	cout<<"     /                                \\"<<endl;
	cout<<"   /                                    \\"<<endl;
	cout<<" B --------------------------------------- A "<<endl;
	cout<<"                       c "<<endl;
	cout<<" "<<endl;
	cout<<"For any information that you do not have, please enter 0"<<endl;
	cout<<" "<<endl;
	cout<<"What is the side 'a' length?"<<endl;
	cin>>a;
	cout<<"What is the side 'b' length?"<<endl;
	cin>>b;
	cout<<"What is the side 'c' length?"<<endl;
	cin>>c;

	//-Calculates the missing angles

	A = ((b * b) + (c * c) - (a * a)) / (2*b*c);
	A = toDegrees(acos(A));
	B = ((c * c) + (a * a) - (b * b)) / (2*c*a);
	B = toDegrees(acos(B));
	C = ((b * b) + (a * a) - (c * c)) / (2*b*a);
	C = toDegrees(acos(C));

	if (a > b && a > c){
		small_1 = b;
		small_2 = c;
	}else if (b > a && b > c){
		small_1 = a;
		small_2 = c;
	}else if (c > a && c > b){
		small_1 = a;
		small_2 = b;
	}
	Area = 0.5*(small_1*small_2);

	//-Displays the missing data

	cout<<" "<<endl;
	cout<<"                     "<<C<<endl;
	cout<<"                     /\\"<<endl;
	cout<<"                   /    \\"<<endl;
	cout<<"                 /        \\"<<endl;
	cout<<"               /            \\"<<endl;
	cout<<"          "<<a<<"              "<<b<<endl;
	cout<<"           /                    \\ "<<endl;
	cout<<"         /                        \\"<<endl;
	cout<<"       /                            \\"<<endl;
	cout<<"     /                                \\"<<endl;
	cout<<"   /                                    \\"<<endl;
	cout<<" --------------------------------------- "<<endl;
	cout<< B<<"            "<<c<<"               "<<A<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<"The area of the triangle is "<<Area<<endl;
	cout<<"The 'A' side length is "<<a<<endl;
	cout<<"The 'B' side length is "<<b<<endl;
	cout<<"The 'C' side length is "<<c<<endl;
	cout<<"The angle 'A' is "<<A<<endl;
	cout<<"The angle 'B' is "<<B<<endl;
	cout<<"The angle 'C' is "<<C<<endl;
	cout<<" "<<endl;

}

//-Degrees to Radian converter and visa versa

double toDegrees(double radians) 
{
	double radians_2 = radians * 180;
	return radians_2 / 3.14159265;
}
double toRadians(double degrees) 
{
	double degrees_2 = degrees * 3.14159265;
	return degrees_2 / 180;
}