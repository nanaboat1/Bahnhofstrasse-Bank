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
// Resources used: < Used for time manipulation --> https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm>
// Collaborators: <If you worked with others place their name here> 
//
// Purpose: Final Project- Transactdisplay, header file.
//
////////////////////////////////////////////////////////////////////////////////////////
#pragma once 
#include <iostream> // the standard io library
#include <string> // the standard string library
#include <stack> // stack library
#include "../headers/Accdisplay.h" // for getting clear disp
#include <iomanip> // for manipulating cout

#include  <ctime> // the standard time library 

//////
// function prototype
std::string disp_time( ); // used to display time
std::string transact_home( );


// welcomes User to Transaction and ask about the type of transaction being conducted. 
std::string transact_home( ) {

    std::string horizontal_line =" __________________________________________________" ;// horizontal borders for display
    std::string line_of_pixels = "|                                                  |";// vertical borders for display
    std::string info_welcome =   "| Select an Option::      BR_N BANK                |" + std::string("\n"); // displays information in welcome
                info_welcome +=  "|  <1> Cash Withdraw           <2> Cash Deposit    |" + std::string("\n");
                info_welcome +=  "|  <3>  Cash Transfer                              |";   

    // Case: The Display Informs the user to choose a type of Bank Account
    
    std::cout << horizontal_line << std::endl; 
    // Case: Create Welcome Screen.
    for( int i=0; i < 5; i++ ) {
        std::cout <<  line_of_pixels << std::endl;
        if( i == 2) {
            std::cout << "|             Welcome to BR_N BANK.                |" << std::endl;
            std::cout << "| Please choose your preferred Transaction         |" << std::endl;
            std::cout << "|                                                  |" << std::endl;
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

// Display for cash_withdraw transaction
void withdraw_cash_disp( ) {

    // Welcome info for Cash_withdraw

    // get time.
    std::string sistm = disp_time();

    const std::string titl = "|                          "    + sistm +   "|";

    std::string horizontal_line =" __________________________________________________" ;// horizontal borders for display
    std::string line_of_pixels = "|                                                 |";// vertical borders for display
    std::string info_welcome =   "|________________CASH_WITHDRAW____________________|" + std::string("\n"); // displays information in welcome
                info_welcome +=  "|___________________BR_N BANK_____________________|" + std::string("\n");

    
    for ( int i=0; i < 3; i++ ) {
        if ( i == 1 ) {
            std::cout << horizontal_line << std::endl;
            std::cout << titl << std::endl; // displays the date
            std::cout << info_welcome << std::endl;
        }
        std::cout << line_of_pixels << std::endl;
    }
    std::cout << horizontal_line << std::endl << std::endl;

    std::cout << " NOTE:  The Program will ask you the amount to be withdrawn " << std::endl;

}

void deposit_cash_disp() {

    // Welcome info for Cash_withdraw

    // get time.
    std::string sistm = disp_time();

    const std::string titl = "|                          "    + sistm +   "|";

    std::string horizontal_line =" __________________________________________________" ;// horizontal borders for display
    std::string line_of_pixels = "|                                                 |";// vertical borders for display
    std::string info_welcome =   "|________________TRANSFER_________________________|" + std::string("\n"); // displays information in welcome
                info_welcome +=  "|___________________BR_N BANK_____________________|" + std::string("\n");

    
    for ( int i=0; i < 3; i++ ) {
        if ( i == 1 ) {
            std::cout << horizontal_line << std::endl;
            std::cout << titl << std::endl; // displays the date
            std::cout << info_welcome << std::endl;
        }
        std::cout << line_of_pixels << std::endl;
    }
    std::cout << horizontal_line << std::endl << std::endl;

    std::cout << " NOTE:  The Program will ask you the amount to be Deposited " << std::endl;

}

void transfer_cash_disp() {

    // Welcome info for Cash_withdraw

    // get time.
    std::string sistm = disp_time();

    const std::string titl = "|                          "    + sistm +   "|";

    std::string horizontal_line = "__________________________________________________" ;// horizontal borders for display
    std::string line_of_pixels = "|                                                 |";// vertical borders for display
    std::string info_welcome =   "|________________TRANSFER_________________________|" + std::string("\n"); // displays information in welcome
                info_welcome +=  "|___________________BR_N BANK_____________________|" + std::string("\n");

    
    for ( int i=0; i < 3; i++ ) {
        if ( i == 1 ) {
            std::cout << horizontal_line << std::endl;
            std::cout << titl << std::endl; // displays the date
            std::cout << info_welcome << std::endl;
        }
        std::cout << line_of_pixels << std::endl;
    }
    std::cout << horizontal_line << std::endl << std::endl;

    std::cout << " NOTE:  The Program will ask you the amount to be TRANSFER  " << std::endl;

}


// Takes in input of type float from user. 
// Testing Quality: High
void input_gettor_fl( float & a ) {

    // Case: variable to hold user input of type 
    float input_a_ptr;
    float input_b_ptr;
    bool rentering = false; // tracks user's input

    // Case: inform the user of what's going on.
    std::cout << std::endl;
    std::cout << " NOTE: Program will prompt you until both input's are correct." << std::endl;
    std::cout << std::endl;
    do{ 

        std::cout << " Enter Your input --> ";
        std::cin >> input_a_ptr;
        // std::cin.ignore();
        
        std::cout << std::endl;
        std::cout << " Enter Your input again --> ";
        std::cin >> input_b_ptr;
        
    }while( input_a_ptr != input_b_ptr );

    // a get's correct verified input.
    a = input_a_ptr;
}

// This function prints receipt after each Transaction.
void print_receipt( Client & _clien, int type_trsct, float amnt_transacted, std::string trnsfr = "NONE" ) {


    // for alternating the type of receipt being used.
    std::string trnst_type[3] = { "WithDrawal", "Transfer ", "Deposit  "};

    // for creating receipt output
    std::string receipt_border_hori = "-------------------------------------------------";
    std::string receipt_border_ver =  "|                                               |";
    std::string  recp_disp =          "|____Transaction type: " + trnst_type[type_trsct] + "_________________";

    // Case: Stores User's Accnumber for manipulating in output
    const std::string acc_num_re = _clien.get_accNum();
    const int acc_num_length = _clien.get_accNum().length(); // 
    const std::string d_ate = disp_time(); 

    // Creating the receipt 
    
    std::cout << receipt_border_hori << std::endl;
            std::cout << "| RECEIPT                                        " << std::endl;
    for ( int i=0; i < 4; i++ ) {
        std::cout << receipt_border_ver << std::endl;
        if ( i == 3) {
            std::cout << recp_disp << std::endl << std::endl;
            std::cout << " Name : " << _clien.get_bio_name() << std::endl << std::endl;
            std::cout << " AcctNum : " << std::setfill('x') << std::setw(4) << acc_num_re[acc_num_length-3] << acc_num_re[acc_num_length-2] <<
            acc_num_re[acc_num_length-1] << std::endl << std::endl;
            std::cout << " Amnt Trasacted :" << amnt_transacted << std::endl << std::endl;
            std::cout << " Time Transacted :" << d_ate << std::endl << std::endl;

        }
        
    }
    if( type_trsct == 1){ 
        std::cout << " Transfer made to: " << trnsfr << std::endl;
    }
    std::cout << receipt_border_hori << std::endl;

}


// Displays System Date into Program.
// NOTE:  Couldn't manipulate to PST,  that's a feature I need. 
std::string disp_time( ) {


   // https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
   //                                     // ^
    // Date manipulation source is cited above|

    // current data & time based on system
    time_t now = time(0);
    

   // convert now to string form
   char* dt = ctime(&now);

    // getting UTC time. 

    tm *gmtm = gmtime(&now);
    
    dt = asctime(gmtm);

    std::string date = dt;

    return date;
}




