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
#include <cstdlib> // for comparing chars
#include <vector> // the standard vector class

////////////////////////////
// function prototypes   //
//////////////////////////
void clear_disp( );



////////////////////////
//                   //
//////////////////////
// This Function takes in User input on the type of account to create
std::string user_input() {

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
    return choice;
}

// Case: function generates prompt to tell user about entering a specific data field.
void data_field_display( int type_of_data ) {

    std::string horizontal_line =" __________________________________________________" ;// horizontal borders for display
    std::string line_of_pixels = "|                                                  |";// vertical borders for display
    std::string user_type[3]= {"Name   ", "Address", "PIN    "};// alternate type of data asked.
    std::string prompt_line = "| Enter your legal " +  user_type[type_of_data] +  "                         |";// Prompts line with specific data.

    std::cout << horizontal_line << std::endl;
    for( int i=0; i < 3; i++ ) {

        if ( i == 2 ) {
            std::cout << "| Proceed to Enter in the data fields              |" << std::endl << std::endl;
            std::cout << prompt_line  <<std::endl;
        } else {
            std::cout << line_of_pixels << std::endl;
        }
    }
    std::cout << horizontal_line << std::endl; 
}

// Case:  This function Welcomes the user, when the user is about to create an
// account. 
// Testing quality : High
std::string welcome_display( ) {

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
    std::string choice;
    choice = user_input();

    clear_disp();

    return choice;
}
// Function displays user inputted info to console.
void show_infoDisplay( std::vector <std::string> info_vec ) {

    std::string horizontal_line =" __________________________________________________" ;// horizontal borders for display
    std::string line_of_pixels = "|                                                  |";// vertical borders for display


    std::cout<< horizontal_line << std::endl;
    for( int i=0; i <4; i++) {

        std::cout << line_of_pixels << std::endl;
        if ( i == 2) {
            std::cout<< horizontal_line << std::endl;
            std::cout << " Below is the information you Provided  \n" << std::endl;
            std::cout << " Name :==> " << info_vec[0] << std::endl;
            std::cout << " Address :==> " << info_vec[1] << std::endl << std::endl;
            std::cout<< horizontal_line << "\n"<< std::endl;

            std::cout << " NOTE: Please keep this information secured:: It's needed for Login \n " << std::endl;
            std::cout << " Account number :==> " << info_vec[2] << std::endl;
            std::cout << " PIN :==>  " << info_vec[3] << std::endl << std::endl;
            
        }
        std::cout << horizontal_line << std::endl;


        
    }




}


// Case: clears the display.
void clear_disp( ) {

    #ifdef _WIN32
        system("CLS");
    #else
        system("clear");
    #endif



    return;
}



