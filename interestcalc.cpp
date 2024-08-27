#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class BankingCalculator {
private:
    double initialAmount;
    double monthlyDeposit;
    double interestRate;
    int numYears;

public:
    BankingCalculator(double initialAmount, double monthlyDeposit, double interestRate, int numYears) 
        : initialAmount(initialAmount), monthlyDeposit(monthlyDeposit), interestRate(interestRate), numYears(numYears) {}

    void updateValues(double initialAmount, double monthlyDeposit, double interestRate, int numYears) {
        this->initialAmount = initialAmount;
        this->monthlyDeposit = monthlyDeposit;
        this->interestRate = interestRate;
        this->numYears = numYears;
    }
        

// Create a function that uses the longest length of text for the desplay menu to align with difference in user inputs
    int spacing () {
    // converts the ints and doubles to strings to count length of string for the vector
        string initialLength = "Initial Investment Amount: " + to_string(initialAmount);
        string depositLength = "Monthly Deposit Amount: " + to_string(monthlyDeposit);
        string interestLength = "Annual Interest: " + to_string(interestRate);
        string yearsLength = "Number of years: " + to_string(numYears);
        string toContinue = "Press any key to continue, press 'q' to quit";
        int lengthToUse = 0;
        int i;

// Creates a list and the elements are determined by the length of string including the user input
        vector<int> maxSpace = {};
        maxSpace.push_back(initialLength.length());
        maxSpace.push_back(depositLength.length());
        maxSpace.push_back(interestLength.length());
        maxSpace.push_back(yearsLength.length());
        maxSpace.push_back(toContinue.length());

// for loop to determine longest string
        for (i = 0; i < maxSpace.size(); i++) {
            if (maxSpace.at(i) > lengthToUse) {
                lengthToUse = maxSpace.at(i);
            }

        }

        return lengthToUse;  
    }

// prints the input menu
    void dataInputMenu () {
        cout << setfill('*') << setw (45) << "" << endl;
        cout << setfill ('*') << setw(16) << ""<< " Data Input " << setfill('*') << setw(17) << "" << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit Amount: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;
        cout << "Press any key to continue, press 'q' to quit" << endl;
    }

// this prints the input mennu with the inclusion of the user input and embeds the spacing function
    void userDataInput() {
        cout << setfill('*') << setw(spacing()) << "" << endl; 
        cout << setfill ('*') << setw(((spacing())/2)-6) << ""<< " Data Input " // below line is continuation of this line of code
         << setfill('*') << setw(((spacing())/2)-5) << "" << endl;
        cout << fixed << setprecision(2);
        cout << "Initial Investment Amount: $" << initialAmount << endl;
        cout << "Monthly Deposit Amount: $" << monthlyDeposit << endl;
        cout << "Annual Interest: %"  << interestRate << endl;
        cout << "Number of years: " << numYears << endl;
        cout << "Press any key to confirm and continue, press 'q' to quit or 'r' to re-enter information" << endl;
        cout << endl;
    }

// calculation for the accrrued interest and monthly deposit
    void interestWithDeposit () {
        double monthlyCompounded = initialAmount;
        int i;
        int year = 0;
        cout << "YEARLY BALANCE WITH MONTHLY DEPOSIT AND ACCRUED INTEREST" << endl;
        cout << "Starting amount: $" << initialAmount << endl;
    // for loop to compound the interest and monthly deposits
        for (i = 1; i < (numYears * 12)+1; ++i) {
            monthlyCompounded += monthlyDeposit; //adds monthly depoist to current amount
            monthlyCompounded += (monthlyCompounded * ((interestRate/100)/12)); //adds the interest to the current compounded amount, increases every iteration
            if (i % 12 == 0) { // this will ensure that the yearly amount is printed using the modulus method. 
                year += 1;
                cout << "Year: " << year << " " << monthlyCompounded << endl;
            }
        }
    }

// same as the interest but this is without the monthly depost
    void interestWithoutDeposit() {
        double monthlyCompounded = initialAmount;
        int i;
        int year = 0;
        cout << "BALANCE WITHOUT A MONTHLY DEPOSIT" << endl;
        cout << "Starting amount: $" << initialAmount << endl;
        for (i = 1; i < (numYears * 12)+1; ++i) {
            monthlyCompounded += (monthlyCompounded * ((interestRate/100)/12));
            if (i % 12 == 0) {
                year += 1;
                cout << "Year: " << year << " " << monthlyCompounded << endl;
            }
        }

    }
};

// main function
int main() {
    
    //user variables we will use throughout the entire program
    double userInitialDeposit = 0.0;
    double userMonthlyDeposit = 0.0;
    double userInterestRate = 0.0;
    char userInput = 0.0;
    int userNumYears = 0;
    BankingCalculator calc(0.0,0.0,0.0,0);
    
    cout << "Would you like to use the compounding interest calculator (y/n?)" << endl;
    cin >> userInput;
    tolower(userInput); //ensures a capitalization issue doesn't arise
    while (userInput != 'y' && userInput != 'n') { //checks for valid input
        cout << "Please enter a valid input (y/n)" << endl; // pormpting for input
        cin >> userInput;
    }
    
    while (userInput == 'y') { // while loop opens
        calc.dataInputMenu();
        cin >> userInput;
        tolower(userInput);
        if (userInput == 'q') { //unless user enters 'q' then while loop will run
            break;
        }
            while (userInput != 'q') { //second while loop opens if user wants to proceed
                cout << "Enter intial deposit: ";
                cin >> userInitialDeposit;
                cout << "Enter monthly deposit: ";
                cin >> userMonthlyDeposit;
                cout << "Enter interest rate: ";
                cin >> userInterestRate;
                cout <<  "Enter number of years: ";
                cin >> userNumYears;
                cout << endl;

                calc.updateValues(userInitialDeposit, userMonthlyDeposit, userInterestRate, userNumYears);
                calc.userDataInput(); //calls the data input function
                calc.interestWithDeposit();//call and calculates the interest with monthly accrual
                calc.interestWithoutDeposit(); // calls and calculates the interest without monthly deposit

                cout << "Would you like to enter in another input and compare 'y' for yes or 'q' for quit?" << endl; /*if user enteres 'y' then will run through program again and 
                'q' will terminate */
                cin >> userInput;    
            }
    }
    return 0;
}