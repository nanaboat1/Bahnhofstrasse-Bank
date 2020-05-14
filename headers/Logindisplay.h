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
// Purpose: Final Project- Display file for Login of  account. 
//
////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream> // the standard io stream library
#include <string> // the standard string library
#include <vector> // the standard string library.
#include "../headers/Accdisplay.h" // Contains some diaply functions.
#include "../headers/Createacct.h" // contains some data entering functions.



// Welcomes user to enter his login details.
std::string login_welcome_display() {

    std::string horizontal_line =" __________________________________________________" ;// horizontal borders for display
    std::string line_of_pixels = "|                                                  |";// vertical borders for display
    std::string info_welcome =   "|   Hello User, welcome to BR_N Bank login Page    |" + std::string("\n"); // displays information in welcome
                info_welcome +=  "|                                                  |" + std::string("\n");
                info_welcome +=  "|   Press <1> to Proceed to Login Page .           |" + std::string("\n"); 

    
    // Case: The Display Informs the user to Log in.

    std::cout << horizontal_line << std::endl;
    // Case: Create Welcome Screen.
    for ( int i=0; i <4; i++) {
        std::cout << line_of_pixels <<std::endl;
        if ( i==2 ) {
            std::cout << info_welcome << std::endl;
        }
    }
    std::cout << line_of_pixels << std::endl;
    std::cout << horizontal_line << std::endl;


    std::string choice;
    choice = user_input(); // Ask for user input.

    // clear display.
    clear_disp();

    return choice; 
}

// Takes in user's Account Number & PIn
void login_form( std::vector <std::string> & usr_details ) {


    std::string horizontal_line =" __________________________________________________" + std::string("\n");// horizontal borders for display
    std::string line_of_pixels = "|                                                  |";// vertical borders for display
    std::string info_welcome =   "|   Hello, the next Prompt will ask for your       |" + std::string("\n"); // displays information in welcome
                info_welcome +=  "|     <1> Account number                           |" + std::string("\n");
                info_welcome +=  "|     <2>  PIN  .                                  |" + std::string("\n");
    // 

    std::cout << horizontal_line << std::endl; 
    for( int i=0; i <5; i++ ) {
        std::cout << line_of_pixels << std::endl;
        if ( i==2 ){
            std::cout << info_welcome << std::endl;
        }
    }
    std::cout << horizontal_line << std::endl;

    std::string take_input;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Enter your Account number |\n" << std::endl;
    std::cout << "--------------------------" << std::endl;
    input_gettor( take_input);
    usr_details.push_back( take_input); // usr_details[0] == Account number

    std::cout << "--------------------------" << std::endl;
    std::cout << "Enter your PIN number     |\n" << std::endl;
    std::cout << "--------------------------" << std::endl;
    input_gettor( take_input );
    usr_details.push_back( take_input ); // usr_details[1] == login PIN

    return;
}

// 
