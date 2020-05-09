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
// Purpose: Final Project- Display file for creating account. 
//
////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream> // the standard io library
#include <string> // the standard string library
#include "../headers/Client.h" // the header file for Client 
#include "../headers/Biodata.h" // the header file for Biodata

////////////////////////////
// function prototypes   //
//////////////////////////
void clear_disp( );



////////////////////////
//                   //
//////////////////////


// This Function takes in User input on the type of account to create

int user_input( ) {

    int  choice = 0;
    bool leave_input = false;

    std::cout << " NOTE: Program will loop until correct input is gotten" << std::endl << std::endl;
    while( !leave_input ) {

        std::cout << "Enter the correct choice --> ";
        std::cin >> choice;

        if ( choice > 2 || choice < 1) {

            leave_input = false;
        } else {
            leave_input = true;
        }

    }
    
    return choice;
}


// Case:  This function Welcomes the user, when the user is about to create an
// account. 
// Testing quality : High
int welcome_display( ) {

    std::string horizontal_line =" __________________________________________________" ;// horizontal borders for display
    std::string line_of_pixels = "|                                                  |";// vertical borders for display
    std::string info_welcome =   "|______________                      ______________|" + std::string("\n"); // displays information in welcome
                info_welcome +=  "|Savings ACCNT |     BR_N BANK      | Current ACCNT|" + std::string("\n");
                info_welcome +=  "|______________|                    |______________|";   

    // Case: The Display Informs the user to choose a type of Bank Account
    
    std::cout << horizontal_line << std::endl; 
    // Case: Create Welcome Screen.
    for( int i=0; i < 5; i++ ) {
        std::cout <<  line_of_pixels << std::endl;
        if( i == 2) {
            std::cout << "|             Welcome to BR_N BANK.                |" << std::endl;
            std::cout << "| Select the Type of Account you want to Create    |" << std::endl;
            std::cout << "| Select 1 for savings. Select 2 for Current       |" << std::endl;
        }

    }
    std::cout << info_welcome << std::endl;
    for( int i=0; i < 2; i++) {
        std::cout << line_of_pixels << std::endl;
    }
    std::cout << horizontal_line << std::endl;
    std::cout << std::endl;

    // Get's User Input
    int choice =0;
    choice = user_input();

    clear_disp();

    return choice;
}

// This function clears the display.
void clear_disp( ) {

    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif



    return;
}



