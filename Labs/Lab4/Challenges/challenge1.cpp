#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

void append(char pP1[], char pP2[], char pResult[100]);

int main() {
    char p1[] = "Hello, ";
    char p2[] = {'w', 'o', 'r', 'l', 'd', '!', '\0'};
    char result[100];
    append(p1, p2, result);
    cout << result << endl;

    return 1;
}

void append(char pP1[], char pP2[], char pResult[100]) {
    char concatenated[100];
    int i = 0;
    int j = 0;
    int uniqueCharacters = 0;
    for (i = 0; i < strlen(pP1); i++) {
        concatenated[i] = pP1[i];
    }

    for (j = 0; j < strlen(pP2); j++) {
        concatenated[i + j] = pP2[j];
    }

    cout << concatenated << endl;

    concatenated[i + j + 1] = '\0';



    for (int k = 0; k < 100; k++) {
        bool contains = false;
        for (int l = 0; l < 100; l++) {
            if (pResult[l] == concatenated[k]) {
                contains = true;
            }
        }
        if (!contains) {
            pResult[uniqueCharacters] = concatenated[k];
            uniqueCharacters++;
        }
    }
    pResult[uniqueCharacters] = '\0';
}