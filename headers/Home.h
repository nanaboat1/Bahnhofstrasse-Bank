
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
#include <iostream>                 // the standard io library
#include <string>                   // the standard string class
#include "../headers/Createacct.h"  // a subprogram of Bank
#include "../headers/Login.h"       // a subprogram of Bank
#include "../headers/Transaction.h" // a subprogram of Bank

// This function takes in User input used to Access home.
char usr_input()
{

    char choice[20];
    choice[1] = '\0';
    bool leave_input = false;

    std::cout << " NOTE: Program will loop until correct input is gotten" << std::endl
              << std::endl;
    while (!leave_input)
    {

        std::cout << "Enter the correct choice --> ";
        std::cin >> choice[0];
        std::cin.clear();

        if (choice[0] == '2' || choice[0] == '1')
        {
            leave_input = true;
        }
        else
        {
            leave_input = false;
        }
    }
    std::cin.ignore(1000, '\n'); // Major Problem here:: Fix it

    return choice[0];
}

// The Home function that enables the program to run.
void home()
{

    // declaring variables
    int choice;
    bool leave_input = false;

    // Used to exit HOME.
    bool exit = false;

    // Welcome information
    std::cout << " WELCOME TO BRN BANK " << std::endl
              << std::endl;

    do
    {

        do
        {
            // General Information to Prompt the User.
            std::cout << "------------------------------------------------------------------------ " << std::endl;

            std::cout << " WELCOME TO BRN BANK AGAIN" << std::endl
                      << std::endl;

            std::cout << " SELECT <1> TO CREATE A NEW ACCOUNT. Note, you  get $ 700.00 for creating an Account today. " << std::endl
                      << std::endl;

            std::cout << " SELECT <2> TO LOGIN INTO AN EXISTING ACCOUNT " << std::endl;

            std::cout << "------------------------------------------------------------------------ " << std::endl;

            std::cout << " NOTE , ONLY NUMBERS ARE ACCEPTED:: OR PROGRAM WILL CRASH " << std::endl;
            std::cout << " Enter your choice ==> ";
            std::cin >> choice;

            if (choice == 1 || choice == 2)
            {
                leave_input = true;
            }

        } while (!leave_input);

        // clears display
        clear_disp();

        // Using Statements to go to the specified sub-program
        switch (choice)
        {

        // Call create account
        case 1:
            create_account();
            // clears display
            clear_disp();
            break;
        // Log's in and Perform Transaction.
        case 2:
            login_bank();
            // clears display
            clear_disp();
            break;
        default:
            // clears display
            clear_disp();
            break;
        }

        // Ask the user if it wants to exit
        std::cout << " HELLO, DO YOU WANT TO EXIT THE PROGRAM " << std::endl;
        std::cout << " PRESS <1> TO EXIT OR <2> TO CONTIUNE USING THE PROGRAM " << std::endl;
        std::cout << " NOTE , ONLY NUMBERS ARE ACCEPTED:: OR PROGRAM WILL CRASH " << std::endl;
        std::cout << " Enter your choice ==> ";
        std::cin >> choice;

        // Set's exit value based on choice.
        if (choice == 1 || choice == 2)
        {
            exit = true;
        }

        // clears display
        clear_disp();
       


    }while(!exit);
}
