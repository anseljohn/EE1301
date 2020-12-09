#include <iostream>
#include <fstream>
using namespace std;

int parseStringForArray(string pLine, int array[]);
//take an array, value to find, start location, stop location, and return the index of that integer value, or -1 if the value is not 
int binarySearch(int pArray[], int pToFind, int pStart, int pStop);

int main() {

    // "x.txt" vs "x"
    string fullFileName;
    string fileName;
    ifstream file;
    int array[1000] = {0};
    int newSize;
    int numToFind;

    cout << "What is the file with the array you want to search? ";
    cin >> fullFileName;
    fileName = fullFileName.substr(0, fullFileName.find('.'));

    cout << "What is the number you want to find? Please provide an integer: ";
    cin >> numToFind;

    file.open(fullFileName);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            newSize = parseStringForArray(line, array);
        }
    }
    file.close();

    int indexFound = binarySearch(array, numToFind, 0, newSize);
    if (indexFound == -1) {
        cout << numToFind << " is not in " << fileName << endl;
    } else {
        cout << numToFind << " can be found at " << fileName << "[" << indexFound << "]" << endl;
    }

    return 0;
}


int binarySearch(int pArray[], int pToFind, int pStart, int pStop) {
    int index = (pStart + pStop) / 2; // Index right in the middle;
    int valueAtIndex = pArray[index];

    if (pArray[index] == pToFind) {
        return index;
    } else if (valueAtIndex > pToFind && pStart != pStop) {
        return binarySearch(pArray, pToFind, pStart, index - 1);
    } else if (valueAtIndex < pToFind && pStart != pStop) {
        return binarySearch(pArray, pToFind, index + 1, pStop);
    } else {
        return -1;
    }
}


int parseStringForArray(string pLine, int array[]) {
    string integer = "";
    int arrayIndex = 0;
    for (int i = 0; i < pLine.size(); i++) {
        if (pLine.at(i) == ' ' || i == pLine.size() - 1) {
            if (i == pLine.size() - 1) {
                integer += pLine.at(i);
            }
            array[arrayIndex] = stoi(integer);
            integer = "";
            arrayIndex++;
        } else {
            integer += pLine.at(i);
        }
    }
    return arrayIndex;
}