#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();
void humanTower(string pFullNames[2], double pHeights[2]);

int main() 
{
	string fullNames[2];
	double heights[2];
	fullNames[0] = requestName();
	heights[0] = requestHeight(fullNames[0]);
	fullNames[1] = requestName();
	heights[1] = requestHeight(fullNames[1]);
	humanTower(fullNames, heights);
}

void humanTower(string pFullNames[2], double pHeights[2]) {
	cout << "If " << pFullNames[0] << " and " << pFullNames[1]
	     << " form a human tower, their combined height will be "
	     << (pHeights[0] + pHeights[1]) << endl;
	
}

string requestName()
{
	string name;
	cout << "Please enter full name: ";
	getline(cin, name);
	return name;
}

double requestHeight(string fullName)
{
	double height;
	cout << "Please enter " << fullName << "'s height: ";
	cin >> height;
	cin.ignore(2, '\n'); // gets rid of \n in the buffer
	
	return height;
}

int requestNumberOfPartners()
{
	int numberOfPartners; 
	cout << "How many partners are there?";
	cin >> numberOfPartners;
	
	return numberOfPartners;
}

