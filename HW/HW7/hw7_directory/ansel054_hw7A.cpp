// EE 1301 
// HW 7A
// John Anselmo
// ansel054


// EE1301 HW7A Starting File
//
// This example goes into how to create and use a linked list, and store a very large amount of data in dynamic data, 
// in this case house records. This solution uses a single linked list (i.e. only points in one direction, vs a double 
// linked list that points in the other direction as well).
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class houseData {
public:
    // Basic static data:
    //   id,value,bedrooms,bathrooms,sqft,yr_built,zipcode
    long long int id = 0;
    int price = 0;
    int bedrooms = 0;
    int bathrooms = 0;
    int sqft = 0;
    int yr_built = 0;
    int zipcode = 0;

    // an empty pointer that will eventually point to the next house in the database
    //   You can assume that the houses will be in sorted order (ie., zipCode <= next-->zipCode) 
    // NOTE: There's no magic here, the programmer has to determine how this is set in AddRecord()
    houseData *next = nullptr;

    void printShort();
    void printRecord();

};

void houseData::printRecord() {
    cout << "Printing House Record:" << endl;
    cout << "ID:" << id << endl;
    cout << "Price:" << price << endl;
    cout << "Bedrooms:" << bedrooms << endl;
    cout << "Bathrooms:" << bathrooms << endl;
    cout << "Square Feet:" << sqft << endl;
    cout << "Year Built:" << yr_built << endl;
    cout << "Zipcode:" << zipcode << endl;
}

void houseData::printShort() {
    cout << id << "," << zipcode << endl;
}


// Basic functions supporting House class, but not utilizing links:
void ProcHeader(ifstream &file);
houseData* ReadRecord(ifstream &file);
void DelRecord(houseData *record);

// Advanced function creating and using links:
houseData* AddRecord(houseData* listHead, houseData* houseToAdd);
houseData* FindNodeLessThanZip(houseData* head, int zipcode);
void DelAllRecords(houseData* listHead);
void PrintAllHousesByZip(houseData* head);

// *** Function you need to define ***
void PrintAveragePriceByZip(houseData* listHead);


int main() {
    // File Input
    ifstream fin;
    fin.open("./house-info-v4.csv");  // Small file to test with
    //fin.open("./house-info-v4.csv");  // Use this file for final

    // Setup head of linked list
    houseData* listHead = nullptr;

    if(!fin.is_open()) {cout << "File missing!" << endl; return 1;}

    ProcHeader(fin);  // Just dumps the file header line

    int numRec = 0;
    while(!fin.eof()) {
        houseData* tempHouse = ReadRecord(fin);

        // ReadRecord creates a ptr to a house record that has been creating dynamically, so we then need to take that 
        // record and add it to the linked list in the appropriate location with the function AddRecord().

        if(tempHouse != nullptr) {
            // Insert Element into linked list
            listHead = AddRecord(listHead,tempHouse);

            numRec++;

            // Periodically print message on number of records processed
            if (numRec % 1000 == 1){
                cout << "Still working...num records processed: " << numRec << endl;
                //tempHouse->printRecord();
            }
        }
    }

    //PrintAllHousesByZip(listHead);
    PrintAveragePriceByZip(listHead);

    DelAllRecords(listHead); // Delete entire linked list

    fin.close();

    return 0;
}


// Function: AddRecord
// Inputs: 
//  listHead - a houseData pointer to the head (first element) of linked list
//  houseToAdd - a houseData pointer to the new element to add to the linked list
// Outputs:
//  listHead - a houseData pointer, possibly modified, to the head of the linked list
//
// This function will add a new record to the linked list in the correct location, so that the linked list is always 
// ordered by zip code
houseData* AddRecord(houseData* listHead, houseData* houseToAdd) {
    if(listHead == nullptr) {return houseToAdd;} // handle empty head case

    houseData* lPrevNode = FindNodeLessThanZip(listHead, houseToAdd->zipcode);
    if(lPrevNode == nullptr) { // handle case where new node at beginning
        houseToAdd->next = listHead;
        listHead = houseToAdd;
    } else {  // put new node after node found
        houseData* temp = lPrevNode->next;
        lPrevNode->next = houseToAdd;
        houseToAdd->next = temp;
    }
    return listHead;
}

houseData* FindNodeLessThanZip(houseData* head, int zipcode) {
    houseData* previous = head;
    houseData* current = head->next;
    if(head->zipcode >= zipcode) {return nullptr;}
    while ((current!=nullptr) &&
           !(current->zipcode >= zipcode)) {
        previous = current;
        current = current->next;
    }
    return previous;
}

// Function: PrintAveragePriceByZip(HouseData*)
// Inputs:
//   listHead - a HouseData pointer, pointing to the top element in a sorted linked list
// Outputs: None
void PrintAveragePriceByZip(houseData* head) {
    houseData* current = head;
    houseData* prev = current;
    int totalForZip = 0;
    int housesInZip = 0;
    while (current != NULL) {
        // cout << "Prev: " << prev->zipcode << endl << "Curr: " << current->zipcode << "\n\n";
        if (current == head) {
            totalForZip += current->price;
            housesInZip++;
            prev = current;
            current = current->next;
            continue;
        } else if (current->zipcode == prev->zipcode) {
            totalForZip += current->price;
            housesInZip++;
            if (current->next == NULL) {
                cout << prev->zipcode << ":average price=" << (totalForZip / housesInZip) << endl;
                totalForZip = current->price;
                housesInZip = 1;
            }
        } else {
            cout << prev->zipcode << ":average price=" << (totalForZip / housesInZip) << endl;
            totalForZip = current->price;
            housesInZip = 1;
        }
        prev = current;
        current = current->next;
    }
}

// Function to deallocate entire linked list
void DelAllRecords(houseData *head) {
    houseData* currentHouse = head;
    while(currentHouse != nullptr) {
        houseData* nextHouse = currentHouse->next; // save ptr to next house        
        DelRecord(currentHouse); // deallocate
        currentHouse = nextHouse; // update currentHouse to point to next element
    }
}

// Rest of Functions are given in HouseDB.cpp
void ProcHeader(ifstream &file) {
    string garbage;
    getline(file,garbage);
}

houseData* ReadRecord(ifstream &file) {
    int b = 0;
    int endOfLine = 0;
    int c = 0;
    long long int tempData[7] = {0};
    houseData* localhouseData = new houseData();
    string tempString = " ";

    while(!endOfLine) {
        char curChar;

        //Get the next character in file
        curChar = file.get();

        //Check what the character is
        if (curChar == EOF) {
            return nullptr;
        } else if (curChar == '\n') {
            //Final symbol of row found: put in array and end loop
            tempString.append(1,'\0');
            tempData[c++] = stoll(tempString);
            endOfLine = 1;
        } else if (curChar == ',') {
            //End of current symbol found: put in array
            tempString.append(1,'\0');
            tempData[c++] = stoll(tempString);
            tempString.clear();
        } else {
            // Append to array
            tempString.append(1,curChar);
            b++;
        }
    }

    localhouseData->id = tempData[0];
    localhouseData->price = tempData[1];
    localhouseData->bedrooms = tempData[2];
    localhouseData->bathrooms = tempData[3];
    localhouseData->sqft = tempData[4];
    localhouseData->yr_built = tempData[5];
    localhouseData->zipcode = tempData[6];

    return localhouseData;
}

void DelRecord(houseData *record) {
    delete record;
}

void PrintAllHousesByZip(houseData* head){
    cout << endl << "Printing List of All Houses by Zip:" << endl;
    houseData* current = head;
    while(current != nullptr) {
        current->printShort();
        current = current->next;
    }
}
