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
// Purpose: Final Project- Makes the client to login, header file.
//
////////////////////////////////////////////////////////////////////////////////////////
#include <string> // the standard string library 
#include "../headers/Biodata.h" // the header file Biodata class
#include "../headers/Client.h" // the header file for Client class
#include <vector> // the standard vector library
#include <stack> // the standard stack library.
#include <fstream> // for handling files.

// More include libraries 
#include "../headers/Logindisplay.h" // for display handling.







// Case : Sub-function that searches through file to get User Data.
// function returns bool to indicate that data is existent in file. of login details.
int from_vault( std::vector <std::string> & client_data ) {

    // Case : Instantiate Fsstream Class.
    std::ifstream fin; 

    fin.open("Vault.dat");

    // Error checking
    // happens absolutely to none.
    if(fin.fail() ) {
        std::cout << "File can't open " << std::endl;
        return -1;
    }

    






    return 0;
}


// Case : Sub-function that creates a temporary customer class from data from file.

// Case : Mother function for user to log into bank.
void login_bank( ) {


    // Create Efficient Displays
    login_welcome_display();

    // Instantiate a vector
    std::vector <std::string> from_file;  // Vector get's Customer data from file.
    std::vector <std::string> user_login_info; // stores user's input 



    // Nice Login Page. to Get user's data
    login_form(user_login_info);



    // Case: Function makes user to Enter data and search through vault.
    // Utilizing a Vector to do that.





    






    return;
}