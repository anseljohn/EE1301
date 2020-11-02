#include <iostream>
using namespace std;
int main()
{
	int F0, F1, FN;
	int N; // the index of the last Fibonacci number
	cout << "Enter the value for F0 and F1:\n";
	cin >> F0 >> F1; // read two inputs from the terminal  
	cout << "Enter last Fibonacci numbers you want FN (Enter N):\n";
	cin >> N; // read the index N from the terminal
	for (int i = 2; i <= N; i=i+1 ) {   
		FN = F0 + F1; // represent the next Fibonacci number with F0 and F1
		cout << "F" << i << "=F" << i-1 << "+F" << i-2 << "=" << F1 << "+" << F0 << "=" << FN << endl;
		F0=F1; // update F0
		F1=FN; // update F1
	}
	return 0;
}
