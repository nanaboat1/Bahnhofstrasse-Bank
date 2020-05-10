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
#include <cstdlib> // used for rand.
#include <ctime> // the standard time library
#include <cmath> // the standard math library

////////////////////////////
// function prototypes   //
//////////////////////////
void str_get( std::string & b, int num_chars );

////////////////////////
//                   //
//////////////////////


// This template function, takes in User Data of any type. 
template <typename Type> 
void input_gettor( Type & a ) {

    // Case: Pointer to hold user input of type 
    Type input_a_ptr;
    Type input_b_ptr;


    std::cout << " NOTE: Program will prompt you until both input's are correct." << std::endl;
    do{ 

    
        std::cout << " Enter Your input --> ";
        getline(std::cin, input_a_ptr);
        std::cin.ignore();
        
        std::cout << std::endl;
        std::cout << " Enter Your input again --> ";
        getline(std::cin, input_b_ptr);

    }while( input_a_ptr != input_b_ptr );

    a = input_a_ptr;
}

// Case: function creates account number string for user.
// Testing quality: High
void generate_accNum( std::string & a, int accntType ) {

    // Case: Depending on acc type, Acct number get's generated.
    const std::string acc_label[2] = {"Sv", "Cu"}; // selects, string based on accntType value.

    // append acc_label index depending on value
    // of accType
    a += acc_label[accntType]; 

    // Case: Call function to append generated type string 
    str_get( a, 5 );
    return;
}

// this function generates num chars randomized string
// Testing Quality: High
void str_get( std::string & b, int num_chars ) { 

    // Case: Custom Template, to generate string from
    const std::string frame_string_a = "adjofnhwfqhrwqpdfdortpartuwvczxrrwgvdy";
    const std::string frame_string_b = "01234567890123534539012345547456123456";
    srand(time(NULL)); // seed rand with current time.
    int index =0;

    // Case: loop attaches num of chars to string.
    for ( int i=0; i< num_chars; i++){

        // Case: when i is even.
        if( (i%2) == 0 ) {

            index = rand( ) % 34;
            b += frame_string_a[index];
        } else {
            index = rand() % 25;
            b += frame_string_b[index];
        }

    }




    return;
}







void create_account( ) {


    // Case: Display The Welcome Screen for Creating an Account. 
    int type_of_account = std::stoi(welcome_display()); // get's user's choice on type of account to create.
    ////////

    // Case: Get Data, used for creating an Account. 

    std::string user_name; // calls user name input function.
    user_name_display(1);// get user name display
    input_gettor( user_name );

    std::string user_address; 
    user_name_display(2);// get adrress display
    input_gettor( user_address ); // generates address 

    std::string user_accountNumber; //  generates account num. 
    generate_accNum( user_accountNumber, 5 ); // generates address.

    // get pin display
    std::string user_pin; // get's user's chosen pin through a fxn. 
    user_name_display(3);// get's pin display
    input_gettor( user_pin );
    ///////




    return;
}
















