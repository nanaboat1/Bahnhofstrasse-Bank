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
#include "../headers/Accdisplay.h" // the header file for Welcome display.
#include <cstdlib> // used for rand.
#include <ctime> // the standard time library
#include <cmath> // the standard math library
#include <fstream> // the standard file library.
#include <typeinfo> // type info library

////////////////////////////
// function prototypes   //
//////////////////////////
void str_get( std::string & b, int num_chars );

////////////////////////
//                   //
//////////////////////

//////////////////////////////////////////////////////////////////
// This template function, takes in User Data of any type.     //
// and help in entering data field.                           //
// Testing quality: High                                     //
//////////////////////////////////////////////////////////////
template <typename Type> 
void input_gettor( Type & a ) {

    // Case: variable to hold user input of type 
    Type input_a_ptr;
    Type input_b_ptr;
    bool rentering = false; // tracks user's input

    // Case: inform the user of what's going on.
    std::cout << std::endl;
    std::cout << " NOTE: Program will prompt you until both input's are correct." << std::endl;
    std::cout << std::endl;
    do{ 

        std::cout << " Enter Your input --> ";
        getline(std::cin, input_a_ptr);
        // std::cin.ignore();
        
        std::cout << std::endl;
        std::cout << " Enter Your input again --> ";
        getline(std::cin, input_b_ptr);

    }while( input_a_ptr != input_b_ptr );

    // a get's correct verified input.
    a = input_a_ptr;
}

// Case: function generates account number string for user.
// Testing quality: High
void generate_accNum( std::string & a, int accntType ) {

    // Case: Depending on acc type, Acct number get's generated.
    const std::string acc_label[2] = {"Sv", "Cu"}; // selects, string based on accntType value.

    // append acc_label index depending on value
    // of accType
    a = acc_label[accntType -1]; 

    // Case: Call function to append generated type string 
    str_get( a, 5 );
    return;
}

// this function generates num chars randomized string
// Testing Quality: High
void str_get( std::string & b, int num_chars ) { 

    // Case: Custom Template, to generate string from
    const std::string frame_string_a = "adjofnhwfqhrwqpdfdortpartuwvczxrrwgvdy";
    const std::string frame_string_b = "0123456789";
    srand(time(NULL)); // seed rand with current time.
    int index =0;
    

    // Case: loop attaches num of chars to string.
    for ( int i=0; i < num_chars; i++){

        index = rand() % 10;
        b+= frame_string_b[index];
    
    }

    return;
}

// Function aids writing of data of type Client to Vault.dat
// Testing Quality: 
void accnt_to_file( Client & customer ) {

    // Case: Instantiate File object object here.
    std::fstream secured_write; 

    // Case: Open data File, to write to file.
    secured_write.open("Vault.dat", std::ios::out | std::ios::app);

    // NOTE : This only happens in a worst case scenario.
    if(secured_write.fail() ) {
        std::cout << " Can't Open file" << std::endl;
        return;
    }

    std::string to_file = customer.to_file();

    // Case: Write Data of type client to file.
    secured_write << to_file << std::endl;

    // close file.
    secured_write.close();

    return;
}



void create_account( ) {

    

    // Case: Display The Welcome Screen for Creating an Account. 
    int type_of_account = std::stoi(welcome_display()); // get's user's choice on type of account to create.
    ////////
    std::cin.clear(); // clear stream errors


    // Case: Get Data, used for creating an Account. 

    // Sub-Case: Organizes user data.
    std::vector <std::string> user_info;

    std::string user_name; // calls user name input function.
    data_field_display(0);// get user name display
    input_gettor( user_name );
    user_info.push_back( user_name );

    std::string user_address; 
    data_field_display(1);// get adrress display
    input_gettor( user_address ); // generates address 
    user_info.push_back( user_address);

    std::string user_accountNumber; //  generates account num. 
    generate_accNum( user_accountNumber, type_of_account ); // generates address.
    user_info.push_back( user_accountNumber);

    // get pin display
    std::string user_pin; // get's user's chosen pin through a fxn. 
    data_field_display(2);// get's pin display
    input_gettor( user_pin );
    user_info.push_back( user_pin );

    // clear display here
    clear_disp();
    ///////

    // Displays information to the User. Before it moves on to instantiate the Client object.
    show_infoDisplay( user_info );

    //sec Feature :  Press Enter to Clear

    // Case : Instantiate the Client Class here. 
    // Sub-case : Utilize dynamic Memory.

    // Dynimically creating Biodata class.
    Biodata *bio_account = nullptr;
    bio_account = new Biodata(user_name, user_address );

    // Sub-case: 
    Client *account_created = nullptr;

    // Case: Dynamically Create memory to hold Type Client
    account_created = new Client(*bio_account, user_accountNumber, user_pin );

    // Case: dynamically deallocate bio_account
    delete bio_account;

    // Case: Send to file. Nicely using the to_file method of the class. 


    // Create a function, that sends the data to file.
    // The Specific file, is called Vault.dat and it acts 
    // as the database of the Bank.
    accnt_to_file( *account_created );

    //deallocate memory.
    delete account_created; // dele pointer
    account_created = nullptr;
    user_info.empty(); // empty vector

    char delay ; // delays the program
    std::cout << " ACCOUNT SUCCESSFULLY CREATED " << std::endl;
    std::cout << " MOVE ON TO LOG IN " << std::endl;


    std::cout << "Enter any key to exit Create Account " << std::endl;
    std::cin >> delay;


    return;
}
















