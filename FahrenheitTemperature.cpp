#include <iostream>
#include <fstream>
using namespace std;

int main () {

    ifstream File; // calling file stream class "File"
    string city1;
    string city2;
    string city3;
    string city4;
    string city5;
    string city6;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    
    File.open( "C:\\Users\\n.feldstein\\OneDrive - SNHU\\Desktop\\Program\\FahrenheitTemperature.txt"); // file path

    if (!File.is_open()) { // checking if file is open, print error if not
        cout << "orig file error";
    }
    // reading and storing all the cities and temperatures
    File >> city1;
    File >> temp1;
    File >> city2;
    File >> temp2;
    File >> city3;
    File >> temp3;
    File >> city4;
    File >> temp4;
    File >> city5;
    File >> temp5;
    File >> city6;
    File >> temp6;



    File.close();

    ofstream newFile; // naming ofstream class for the new file

    newFile.open("C:\\Users\\n.feldstein\\OneDrive - SNHU\\Desktop\\Program\\CelsiusTemperature.txt"); // new file to output

    if (!newFile.is_open()) {
        cout << "New file error"; //checking if errors if it does not open
    }
    // celsius conversion
    temp1 = (temp1 - 32) * (5.0 / 9.0);
    temp2 = (temp2 - 32) * (5.0 / 9.0);
    temp3 = (temp3 - 32) * (5.0 / 9.0);
    temp4 = (temp4 - 32) * (5.0 / 9.0);
    temp5 = (temp5 - 32) * (5.0 / 9.0);
    temp6 = (temp6 - 32) * (5.0 / 9.0);
    
    // adding city and temp in celsius to new file
    newFile << city1 << " "<< temp1 << endl;
    newFile << city2 << " "<< temp2 << endl;
    newFile << city3 << " "<< temp3 << endl;
    newFile << city4 << " "<< temp4 << endl;
    newFile << city5 << " "<< temp5 << endl;
    newFile << city6 << " "<< temp6 << endl;
    
    newFile.close(); // closing new file
}