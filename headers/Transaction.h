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
// Purpose: Final Project- Transaction header file.
//
////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream> // the standard io library
#include <string> // the standard string library
#include <vector> // the standard vector class
#include "../headers/Biodata.h" // header file for Biodata class
#include "../headers/Client.h" // header file for Client class
#include "../headers/Transactdisplay.h"
#include "../headers/Createacct.h" // for getting input gettor

#include <stack> // standard stack class

/////
// function prototypes
void cash_withraw( std::stack <Client> & clier  );
void cash_deposit( std::stack <Client> & clir );
void cash_transfer( std::stack <Client> & clr  );
void over_ridefile( std::stack <Client> & clie );

////

// Mother func for performing transactions.
// Motherfunc takes in Client as Parameter.
void mother_func( std::stack <Client> & clien ) { 

    // Case: Call Transaction Display
    int choice =  std::stoi(transact_home());

    // clears display.
    clear_disp();


    // Calling the Specific function to process the Client.
    switch(choice ) {

        case 1 : 
            cash_withraw( clien );
        break;

        case 2 :
            cash_deposit( clien );
        break;


        case 3 :
            cash_transfer( clien );
        break;

    }

    return;
}


void cash_withraw( std::stack <Client> & clier  ) {

    // Call the cash withdraw display function.
    withdraw_cash_disp(); 

    clear_disp();

    float amnt_withdraw = 0.0;

    // get's current reserve
    float cur_cash_rsrv = clier.top().get_cash_resrv();

    // Takes in user input.
    input_gettor_fl( amnt_withdraw );

    // deducut amnt withdrawn from bank.
    cur_cash_rsrv -= amnt_withdraw;

    // update cash reserve.
    clier.top().update_cash_reserve(cur_cash_rsrv);

    // Print receipt later. Gotcha.
    print_receipt(clier.top(),0, amnt_withdraw );

}

void cash_deposit( std::stack <Client> & clir ) { 

    // Cash Deposit Display
    // Call the cash withdraw display function.
    withdraw_cash_disp(); 

    clear_disp();



    float amnt_deposit = 0.0;

    // get's current reserve
    float cur_cash_rsrv = clir.top().get_cash_resrv();

    // Takes in user input.
    input_gettor_fl( amnt_deposit );

    // credit amnt into from bank.
    cur_cash_rsrv = clir.top() + amnt_deposit  ;

    // update cash reserve.
    clir.top().update_cash_reserve(cur_cash_rsrv);

    // Print receipt later. Gotcha.
    // Print receipt later. Gotcha.
    print_receipt(clir.top(),2,amnt_deposit);

}

void cash_transfer( std::stack <Client> & clir) {


    // Cash Deposit Display
    // Call the cash withdraw display function.
    withdraw_cash_disp(); 

    clear_disp();

    float amnt_deposit = 0.0;

    // get's current reserve
    float cur_cash_rsrv = clir.top().get_cash_resrv();

    // Takes in user input.
    input_gettor_fl( amnt_deposit );

    // trnsfr amount from bank.
    cur_cash_rsrv = clir.top() - amnt_deposit;

    // update cash reserve.
    clir.top().update_cash_reserve(cur_cash_rsrv);

    // Print receipt later. Gotcha.
    // Print receipt later. Gotcha.
    print_receipt(clir.top(),1,amnt_deposit);

}


void over_ridefile( std::stack <Client> & clie ) {

    // instantiate fstream class
    std::fstream file_1;
    std::fstream file_2;


    file_1.open("Vault.dat", std::ios::in | std::ios::out);

    // Check if file is opened
    if(file_1.fail()) {
        std::cout << " Can't open file" << std::endl;
        return;
    }

    std::string line_vault;
    std::string line_tempvault;
    std::vector <std::string> file_content;

    // keeps track if there's still content in file.
    bool file_content = true

    // Push All contents of Vault to vector

    while ( file_content ) {

    }

    // Case :: compare string lines.
    while ( file_1 >> line_vault ) {


        std::string line_file = clie.top().to_file();

        bool equal = compr_line( line_vault, line_file);

        if ( equal ) {



        }




    }

    
}

bool compr_line(std::string & line_1, std::string & cli_2) {


    for ( int i=0; i < 15; i++ ) {

        if ( !(line_1[i] == cli_2[i]) ) {
            return false;
        }

    }


    return true;
}







