//Mohammed Sapin
//RUID: 170006256
#include <iostream>
#include "header_file.h"

int main(){
    vector <Account> bankAccounts; //declare list of account here. The size of the list is not fixed.
    int input = 0;
    menu(&input);
    //run loop to continue program until terminated by user
    while(input != 9){
        switch(input){
            //cases: call functions to perform tasks
    case 1:
        makeAccount(bankAccounts);
        break;
    case 2:
        depositAccount(bankAccounts);
        break;
    case 3:
        withdrawAccount(bankAccounts);
        break;
    case 4:
        transfer(bankAccounts);
        break;
    case 5:
        printAccount(bankAccounts);
        break;
    case 6:
        ActiveDeactive(bankAccounts);
        break;
    case 7:
        deleteAccount(bankAccounts);
        break;
    case 8:
        PrintAllAcount(bankAccounts);
        break;
    case 9:
        return 0; //close bank
    default:
        cout << "Invalid Entry."; //if input is not 1-9
        }
        cout << "\n\n"; //add space when new menu appears
        menu(&input); //display menu again
    }
    cout << "\nBank is closed!" << endl; //when option 9 is selected
    return 0; //end program
}
