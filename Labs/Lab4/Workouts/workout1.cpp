#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void append(char pP1[], char pP2[], char result[100]);

int main() {
    char p1[] = "Hello, ";
    char p2[] = {'w', 'o', 'r', 'l', 'd', '!', '\0'};
    char result[100];
    append(p1, p2, result);
    cout << result << endl;

    return 1;
}

void append(char pP1[], char pP2[], char pResult[100]) {
    int i = 0;
    for (i = 0; i < strlen(pP1); i++) {
        pResult[i] = pP1[i];
    }

    for (int j = 0; j < strlen(pP2); j++) {
        pResult[i + j] = pP2[j];
    }
}