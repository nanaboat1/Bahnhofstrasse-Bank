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
// Purpose: Final Project- Enables the Client to create a bank account.
//
////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string> // the standard string library
#include <vector> // the standard vector class
#include "../headers/Client.h" // the header file for Client class
#include "../headers/Biodata.h" // the header file for Biodata Class
#include "../headers/Crtaccdisplay.h" // the header file for Welcome display.



// Appropriate Display :: From the Display Folder.



void create_account( ) {


    // Case: Display The Welcome Screen for Creating an Account. 
    int type_of_account = welcome_display(); // get's user's choice on type of account to create.

    ////////
    // Case: Data, used for creating an Account. 
    std::string user_name; // calls user name input function.

    std::string user_address; // calls user address input function.

    std::string user_accountNumber; // generates user account number through a fxn

    std::string user_pin; // get's user's chosen pin through a fxn. 
    ///////




    return;
}












