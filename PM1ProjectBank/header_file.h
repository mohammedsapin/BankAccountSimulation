#ifndef HEADER_FILE_H_INCLUDED
#define HEADER_FILE_H_INCLUDED
//header_file.h
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Account{ //create structure to use throughout program
    int accountNumber; //all account numbers
    string lastName; //all first names
    string firstName; //all last names
    double accountBalance; //all starting balances
    bool active; //active boolean for active/deactivate function
};

void menu(int*); //display the menu

void makeAccount(vector<Account>& Accounts); //create new account

void printAccount(vector<Account>& Accounts); //print account

void transfer(vector<Account>& Accounts); //transfer account

void PrintAllAcount(vector<Account>& Accounts); //print all accounts

void depositAccount(vector<Account>& Accounts); //deposit account

void ActiveDeactive(vector<Account>& Accounts); //activate or deactivate account

void withdrawAccount(vector<Account>& Accounts); //withdraw account

void sortAcounts(vector<Account>& Accounts); //sort the accounts using the account numbers

void deleteAccount(vector<Account>& Accounts); //delete an account

#endif // HEADER_FILE_H_INCLUDED
