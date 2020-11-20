#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();
void humanTower(string pFullNames[2], double pHeights[2]);

const int numPeople = 100;

int main() 
{
	string fullNames[numPeople];
	double heights[numPeople];

    for (int i = 0; i < numPeople; i++) {
        fullNames[i] = requestName();
        if (fullNames[i] == "-1") {
            break;
        } else {
            heights[i] = requestHeight(fullNames[i]);
        }
    }
    
	humanTower(fullNames, heights);
}

void humanTower(string pFullNames[numPeople], double pHeights[numPeople]) {
    int sumHeights = 0;
    cout << "If ";
    int i = 0;
    for (i = 0; i < numPeople && pFullNames[i + 1] != "-1"; i++) {
        cout << pFullNames[i] << " and ";
        sumHeights += pHeights[i];
    }
    cout << pFullNames[i] << " form a human tower, their combined height will be " << sumHeights << endl;
}

string requestName()
{
	string name;
	cout << "Please enter full name (enter -1 to stop): ";
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

