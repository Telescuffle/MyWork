#include <iostream>
#include <cmath>

using namespace std;

int main ()

{
	cout<<"Trig Calc"<<endl;

	int AngleAndSide;	
	
	cout<<"Press 1 if you have side A & Angle a"<<endl;
	cout<<"Press 2 if you have side A & Angle b"<<endl;
	cout<<"Press 3 if you have side A & Angle c"<<endl;
	cout<<"Press 4 if you have side B & Angle a"<<endl;
	cout<<"Press 5 if you have side B & Angle b"<<endl;
	cout<<"Press 6 if you have side B & Angle c"<<endl;
	cout<<"Press 7 if you have side C & Angle a"<<endl;
	cout<<"Press 8 if you have side C & Angle b"<<endl;
	cout<<"Press 9 if you have side C & Angle c"<<endl;

	switch (AngleAndSide)
	{	
	case 1: 
		cout<<"You have selected side A & Angle a"<<endl;
		Break;
	

	case 2:
		cout<<"You have selected side A & Angle b"<<endl;
		Break;


	case 3:
		cout<<"you have selected side A & Angle c"<<endl;
		Break;
		
	case 4: 
		cout<<"You have selected side B & Angle a"<<endl;
		Break;
	

	case 5:
		cout<<"You have selected side B & Angle b"<<endl;
		Break;


	case 6:
		cout<<"you have selected side B & Angle c"<<endl;
		Break;

	case 7: 
		cout<<"You have selected side C & Angle a"<<endl;
		Break;
	

	case 8:
		cout<<"You have selected side C & Angle b"<<endl;
		Break;


	case 9:
		cout<<"you have selected side C & Angle c"<<endl;
		Break;
	}
}