//Mohammed Sapin
//RUID: 170006256
//function_file.cpp
#include "header_file.h"
#include <time.h>
#include <cstdlib>
#include <ctime>

vector <Account> bankAccounts; //declare list of account here. The size of the list is not fixed.

void menu(int *num){ //display menu
    int select = 0;
    cout << "Welcome! Select options below:" << endl;
    cout << "\t1. Make new account."
    << "\n\t2. Deposit to an account."
    << "\n\t3. Withdraw from an account."
    << "\n\t4. Transfer money." << "\n\t5. Print account."
    << "\n\t6. Activate/Deactivate an account."
    << "\n\t7. Delete an account."
    << "\n\t8. Display all accounts."
    << "\n\t9. Quit." << endl;
    cout << "Selection: ";

    cin >> select;
    *num = select;
}
void makeAccount(vector<Account>& Accounts){ //function to make a new account
    srand(time(0)); //initialize random number generator

    Account a; //set structure a

    a.accountNumber = rand() % 9000 + 1000; //generate random account number
    cout << "Creating bank account number: " << a.accountNumber << endl; //display random account number

    cout << "Enter First Name: "; //ask for first name
    cin >> a.firstName;
    cout << "Enter Last Name: "; //ask for last name
    cin >> a.lastName;

    cout << "Enter Starting Balance: "; //ask for starting balance
    cin >> a.accountBalance;

    if (a.accountBalance > 0){ //balance must be positive and greater than zero
    bankAccounts.push_back(a); //add new account to vector list
    }
    else{
       cout<< "Invalid Input."; //if balance is less than 0.
    }
}
void printAccount(vector<Account>& Accounts){ //function to print an account
    int accnum; // initialize an account number to check with vector list
    int check = -1; // check for loop
    cout << "Enter account number to print: "; //ask for account number
    cin >> accnum;

    for(int i = 0; i<bankAccounts.size(); i++){
        if(bankAccounts[i].accountNumber == accnum){ //check account number with vector list.
            check = i; //set check to i
            break;
        }
    }
    if(check!=-1){ //loop to print account number for value of i.
        cout << "Account Number: " << bankAccounts[check].accountNumber << "\t" << "Balance: " << bankAccounts[check].accountBalance << endl;
        cout << "Last name: " << bankAccounts[check].lastName << "\t" << "First name: " << bankAccounts[check].firstName << endl;
    }
    else{
        cout << "Invalid account number." << endl; //valid input check
    }
}
void transfer(vector<Account>& Accounts){ //function to transfer money
    int accnum; //first account number
    int accnum2; //second account number
    int check = -1; //check 1
    int check2 = -1; //check 2
    int amount; //transfer amount

    cout << "Enter account number for the sender: "; //ask for account number of sender
    cin >> accnum;
    for(int i = 0; i<bankAccounts.size(); i++){ //loop to check input with vector string for first account
        if(bankAccounts[i].accountNumber == accnum){
            check = i;
            break;
        }
    }
    cout << "Enter account number for the receiver: "; //ask for account of receiver
    cin >> accnum2;
    for(int j = 0; j<bankAccounts.size(); j++){ //loop to check input with vector string for second account
        if(bankAccounts[j].accountNumber == accnum2){
            check2 = j;
            break;
        }
    }
    if (check!=-1 && check2!=-1){ //when both accounts are valid continue with this loop for transfer.
    cout << "Amount to transfer: "; //ask for amount
    cin >> amount;
    if (amount > 0){ //amount has to be greater than zero
    if (amount > bankAccounts[check].accountBalance) //balance must be available in the account
        {
           cout << "\nInsufficient funds.\n"; //not enough money in account
        }
        else{
           bankAccounts[check].accountBalance -= amount; //withdraw from first account
           bankAccounts[check2].accountBalance +=amount; //deposit in second account
        }
    }
    else{
        cout << "Invalid Input."; //if input negative number
    }
    }
    else{
        cout <<"Invalid account number" << endl; //valid input check for account number
    }
}
void PrintAllAcount(vector<Account>& Accounts){ //function to print all accounts
    sortAcounts(bankAccounts);
    for (int i=0; i<bankAccounts.size(); i++){ //loop to go through all accounts in vector
    cout << "Account number: " << bankAccounts[i].accountNumber << "\t" << "Balance: " << bankAccounts[i].accountBalance << endl;
    cout << "Last name: " << bankAccounts[i].lastName << "\t" << "First name: " << bankAccounts[i].firstName << endl;
    }
}
void depositAccount(vector<Account>& Accounts){ //function to deposit accounts
    int accnum; //variable to input account number
    int check = -1; //check for loop
    double amount; //amount to deposit

    cout << "Enter account number for deposit: "; //ask for account number
    cin >> accnum;

    for(int i = 0; i<bankAccounts.size(); i++){ //check if account exists
        if(bankAccounts[i].accountNumber == accnum){
            check = i;
            break;
        }
    }
    if (check!=-1){ //if account exists continue
        cout << "Enter amount to be deposited: "; //ask for deposit amount
        cin >> amount;
        if (amount > 0){ //amount must be greater than 0
        bankAccounts[check].accountBalance += amount; //add to current balance
    }
    else
            cout << "Invalid input."; //if amount is negative
    }
    else
        cout << "Invalid account number." << endl; //check if valid input for account number
}
void ActiveDeactive(vector<Account>& Accounts){ //function to activate and deactivate
    int accnum; //account number to check
    int check = -1; //check for loop
    int trigger; //trigger to activate or deactivate
    cout << "Enter account number for activation/deactivation: "; //ask for account number
    cin >> accnum;
    for(int i = 0; i<bankAccounts.size(); i++){ //loop to check if account exists
        if(bankAccounts[i].accountNumber == accnum){
            check = i;
            break;
        }
    }
    if (check!= -1){ //if account exists continue
    cout << "Press 1 to activate, 0 to deactivate: "; //ask for trigger
    cin >> trigger;
    if (trigger == 0){
        bankAccounts[check].active == false; //if 0 set boolean active to false
    }
    else{
       bankAccounts[check].active == true; //if 1 set boolean active to true
    }
    }
    else
        cout << "Invalid account number." << endl; //account does not exist
}
void withdrawAccount(vector<Account>& Accounts){ //function to withdraw account
    int accnum; //account number to check
    int check = -1; //check for loop
    double amount; //amount to withdraw

    cout << "Enter account number for withdrawal: "; //ask for account number
    cin >> accnum;

    for(int i = 0; i<bankAccounts.size(); i++){ //loop to see if account exists
        if(bankAccounts[i].accountNumber == accnum){
            check = i;
            break;
        }
    }
    if (check!=-1){ //if account exists continue
        cout << "Enter amount to be withdrawn: "; //ask for withdrawal amount
        cin >> amount;
        if (amount < bankAccounts[check].accountBalance){ //if amount is less than current balance withdrawal is possible
        bankAccounts[check].accountBalance -= amount; //subtract from current balance by amount
    }
    else
            cout << "Insufficient funds."; //not enough money
    }
    else
        cout << "Invalid account number." << endl; //account does not exist
}
void sortAcounts(vector<Account>& Accounts){ //sort the accounts using the account numbers
    //bubble sort function to sort vector
    int accounts = bankAccounts.size(); //initialize size
    int sorting; //set temp variable to hold
    for(int i = 0; i < (accounts-1); i++){ //start loop to check accounts
        for(int j = 0; j<(accounts-1);j++){ //loop again to check each account
            if(bankAccounts[j+1].accountNumber<bankAccounts[j].accountNumber){ //if second account is less than first account start sorting
                    sorting = bankAccounts[j].accountNumber; //set temp to first account
                    bankAccounts[j].accountNumber = bankAccounts[j+1].accountNumber; //set first account to second account
                    bankAccounts[j+1].accountNumber = sorting; //swap accounts
            }
        }
    }
}
void deleteAccount(vector<Account>& Accounts){ //function to delete an account
    int accnum; //check account number
    int check = -1; //check for loop

    cout << "Enter account number to be deleted: "; //ask for account number they want to be deleted
    cin >> accnum;

    for (int i = 0; i<bankAccounts.size(); i++){ //check if account exists
        if (bankAccounts[i].accountNumber == accnum){
            check = i;
            break;
        }
    }
    if (check != -1){ //if account exists continue
        bankAccounts.erase(bankAccounts.begin()+check); //function to delete a value from a vector
    }
    else{
        cout << "Invalid account number." << endl; //account does not exist
    }
}
