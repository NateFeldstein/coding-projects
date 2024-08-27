#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// class Item count created
class itemCount {
    private:
        ifstream produceFile; //private data members only to be accessed within the class
        vector <string> produceItems;
    public:
        // constructor
        itemCount (string file) {
            produceFile.open(file);
            if (!produceFile.is_open()) {
                cout << "Error opening file" << endl;
            }
        }

    void readItem () { // function for reading items from the txt file and adding them into the vector
        string line;
        while (getline(produceFile, line)) {
            produceItems.push_back(line);
        }
    }   
    int countItems (string &foodItem) { // this will count the items based on user input
        int i;
        int x = 0;
        for (i = 0; i < produceItems.size(); ++i) {
            if (produceItems.at(i) == foodItem){
                x += 1;
            }   
        }
        return x;
    }

    void itemList () { //This will map the items and count to ItemCount array
        map <string, int> itemCount;
        for (string item : produceItems) {
            itemCount[item]++;
        }

        for (auto pair : itemCount) {
            cout << pair.first << " " << to_string(pair.second)<< endl; //print the pairings (first then second)
        }
    }
    
        
    void printItemCount (string &foodItem) { //This will print the food item the user input and the count of that specefic item
        cout << foodItem << " " << countItems(foodItem) << endl;
    }

    void starPrint() { //similar to itemList but will print the * rather than a number
        map <string, int> itemCount;
        int i;
        for (string item : produceItems) {
            itemCount[item]++;
        }

        for (auto pair : itemCount) {
            cout << pair.first << " ";
            for (i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;  
        }
    }

    void writeHistogramFile (string dataFile) { // writing the histogram to the created frequency file
        ofstream file;
        map <string, int> itemCount;
        int i;
        
        file.open (dataFile,ios::app);
        if (!file.is_open()){
            cout << "Error with Frequency file" << endl;
        } 
        // This will give us the histogram
        for (string item : produceItems) {
            itemCount[item]++;
        }

        for (auto pair : itemCount) {
            file << pair.first << " ";
            for (i = 0; i < pair.second; ++i) {
                file << "*";
            }
            file << endl;  
        }
        file.close();
    }
    void writeItemDataFile (string dataFile) { //Writing the food item and the number rather than the *
        ofstream file;
        map <string, int> itemCount;

        file.open (dataFile,ios::app);
        if (!file.is_open()){
            cout << "Error with Frequency file" << endl;
        } 
        
        for (string item : produceItems) {
            itemCount[item]++;
        }

        for (auto pair : itemCount) {
            file << pair.first << " " << to_string(pair.second)<< endl;
        }
        file << endl;
        file.close();
    }
    

    void closeFile () {
        produceFile.close();
    }
};

void displayMenu() { //Provides the options for the user
    cout << "Hello, please follow one of the menu option" << endl;
    cout << "Option 1: Press 1 to search for item" << endl;
    cout << "Option 2: Press 2 to count items in list" << endl;
    cout << "Option 3: Press 3 to view histogram of list" << endl;
    cout << "Option 4: Press 'q' to quit" << endl;
}

int main() {
    string GrocerFile = "C:\\Users\\n.feldstein\\OneDrive - SNHU\\Desktop\\Program\\CS210_Project_Three_Input_File.txt"; // calling the file class GrocerFile
    string food;
    char input;

    itemCount Produce(GrocerFile); //creating object GrocerFile
    Produce.readItem(); // This will read in the file
    string dataFile = "C:\\Users\\n.feldstein\\OneDrive - SNHU\\Desktop\\Program\\Frequency.dat.txt"; //Location of the frequency file for the two functions to write the data
    Produce.writeHistogramFile(dataFile); // calling the two functions to write tot he file
    Produce.writeItemDataFile(dataFile);
 

    displayMenu();
    cin >> input; //based on input, will open up while loop to iterate through the different functions. 
    while (input != 'q') {
        if (input == '1') {
            cout << "Please enter an item to search" << endl;
            cin.ignore();
            getline(cin,food);
            Produce.printItemCount(food);
            cout << endl;
         }

        else if ( input == '2') {
            Produce.itemList();
            cout << endl;
        }

        else if (input == '3') {
            Produce.starPrint();
            cout << endl;
        }

        displayMenu();
        cin >> input;
        cout << endl;
        
    }

    
    

    
    
    
    Produce.closeFile(); // closing the file

    return 0;
}