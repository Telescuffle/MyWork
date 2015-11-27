#include <iostream>
#include <cmath>

using namespace std;

int main ()

{
	cout<<"Trig Calc"<<endl;

	int TwoSidesMenu;	
	
	cout<<"Press 1 if you have Sides A + B"<<endl;
	cout<<"Press 2 if you have sides B + C"<<endl;
	cout<<"Press 3 if you have sides A + C"<<endl;

	switch (TwoSidesMenu)
	{	
	case 1: 
		cout<<"You have selected Sides A + B"<<endl;
		Break;
	

	case 2:
		cout<<"You have selected sides B + C"<<endl;
		Break;


	case 3:
		cout<<"you have selected sides A + C"<<endl;
		Break;
	}
}