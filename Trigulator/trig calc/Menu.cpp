#include <iostream>
#include <cmath>

using namespace std;

int main ()

{
	cout<<"Trig Calc"<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<"side 'a' is the hypotymuse "<<endl;
	cout<<" "<<endl;
		
	cout<<"                      C"<<endl;
	cout<<"                     /|"<<endl;
	cout<<"                   /  |"<<endl;
	cout<<"                 /    |"<<endl;
	cout<<"               /      |"<<endl;
	cout<<"         a   /        |"<<endl;
	cout<<"           /          |b"<<endl;
	cout<<"         /            |"<<endl;
	cout<<"       /              |"<<endl;
	cout<<"     /                |"<<endl;
	cout<<"   /                  |"<<endl;
	cout<<" B -------------------- A "<<endl;
	cout<<"             c "<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<" "<<endl;
	
	int MainMenu;	

	cout<<"Press 1 for all sides"<<endl;
	cout<<"Press 2 for one side and two angles"<<endl;
	cin>> MainMenu;
	
	switch (MainMenu)
	{	
	case 1: 
	
		cout<<"You have selected all sides"<<endl;
		break;
	

	case 2:
		cout<<"You have selected one side and two angles"<<endl;
		break;
	
}
	

	cin.get ();
	return 0;

}