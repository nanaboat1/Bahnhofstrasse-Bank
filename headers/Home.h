
///////////////////////////////////////////////////////////////////////////////////////
//
// Name: <Nana Boateng > <Amoah>
// Date: <05/14/2020>
// Course Code: CS-172-<1>
//
// License: CS172 students at whitworth may edit this file but not share this 
// file electronically with other students.
//
// Copyright (C) <Nana Boateng Amoah> 2020 - 2021
//
// Resources used: <If applicable add the URL or RESOUCE used here>
// Collaborators: <If you worked with others place their name here> 
//
// Purpose: Final Project- Home Bank, header file.
//
////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream> // the standard io library
#include <string> // the standard string class
#include "../headers/Createacct.h"
#include "../headers/Login.h"
#include "../headers/Transaction.h"



// takes in input from the user.
char usr_input() {

    char  choice[20];
    choice[1]= '\0';
    bool leave_input = false;

    std::cout << " NOTE: Program will loop until correct input is gotten" << std::endl << std::endl;
    while( !leave_input ) {

        std::cout << "Enter the correct choice --> ";
        std::cin >> choice[0];
        std::cin.clear();
        
        if ( choice[0] == '2' || choice[0] == '1') {
            leave_input = true;
        } else {
            leave_input = false;
        }
    }
    std::cin.ignore(1000, '\n'); // Major Problem here:: Fix it 

    return choice[0];
}




void Home(  )  {

    // declaring variables
    int choice;
    int choi;
    

    bool exit = false;

    // Welcome information
    std::cout << " WELCOME TO BRN BANK " << std::endl << std::endl; 

    while ( !exit ) {

        std::cout << " WELCOME TO BRN BANK AGAIN" << std::endl << std::endl;

        std::cout << " SELECT <1> TO CREATE A NEW ACCOUNT. YOU get 700 for creating one. " << std::endl << std::endl;

        std::cout << " SELECT <2> TO LOGIN INTO AN EXISTING ACCOUNT " << std::endl;


        std::cout << " NOTE , ONLY NUMBERS ARE ACCEPTED:: OR PROGRAM WILL CRASH" << std::endl;
        std::cout << " Enter your choice ==> ";
        std::cin >> choice;

        // clears screen.
        #ifdef _WIN32
            system("cls");
        #else 
            system("clear");
        #endif



        

        // Using Statements to go to the specified sub-program
        switch( choice ) {

            // Call create account
            case 1 : create_account();
                system("clear");

            break;

            // Log's in and Perform Transaction.
            case 2 : login_bank(); 
                system("clear");
                
            break;

            default :
                create_account();
                system("clear");

            break;

        }













    }

}