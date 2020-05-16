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
bool compr_line(std::string & line_1, std::string & cli_2);
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

// Performs Cash withdraw processes.
void cash_withraw( std::stack <Client> & clier  ) {

    // Call the cash withdraw display function.
    withdraw_cash_disp(); 

    clear_disp();

    float amnt_withdraw = 0.0;

    // Takes in user input.
    input_gettor_fl( amnt_withdraw );

    // update cash reserve.
    clier.top().dcrs_cash_reserve(amnt_withdraw);

    // Print receipt later. Gotcha.
    print_receipt(clier.top(),0, amnt_withdraw );

    over_ridefile( clier );
}

// Performs Cash deposit processes.
void cash_deposit( std::stack <Client> & clir ) { 

    // Cash Deposit Display
    // Call the cash withdraw display function.
    withdraw_cash_disp(); 

    clear_disp();

    float amnt_deposit = 0.0;

    // Takes in user input.
    input_gettor_fl( amnt_deposit );

    // credit amnt into from bank.
   
    // update cash reserve.
    clir.top().incrs_cash_reserve(amnt_deposit);

    // Print receipt later. Gotcha.
    // Print receipt later. Gotcha.
    print_receipt(clir.top(),2,amnt_deposit);

    over_ridefile( clir );

}

// Performs cash transfer proesses.
void cash_transfer( std::stack <Client> & clir) {

    // Cash Deposit Display
    // Call the cash withdraw display function.
    withdraw_cash_disp(); 

    clear_disp();

    float amnt_deposit = 0.0;

    // Takes in user input.
    input_gettor_fl( amnt_deposit );

    // update cash reserve.
    clir.top().dcrs_cash_reserve(amnt_deposit);

    // Print receipt later. Gotcha.
    // Print receipt later. Gotcha.
    print_receipt(clir.top(),1,amnt_deposit);

    // Overwrite file with new Data.
    over_ridefile( clir );

}


void over_ridefile( std::stack <Client> & clie ) {

    // instantiate fstream class
    std::fstream file_1;
    
    file_1.open("Vault.dat", std::ios::in | std::ios::out);

    // Check if file is opened
    if(file_1.fail()) {
        std::cout << " Can't open file" << std::endl;
        return;
    }

    std::string line_vault; // get's line content of file.
    std::string line_tempvault;
    std::vector <std::string> file_content;

    // keeps track if there's still content in file.
    bool _content_done = true;

    // Push All contents of Vault to vector
    // clie.top().incrs_cash_reserve(5.00); // for testing.

    // Case :: compare string lines.
    while ( !file_1.eof() ) {

        // Get's line from data.
        getline(file_1, line_vault);

        // Case : get_file content's of Client 
        std::string client_data = clie.top().to_file();

        // Case : Compare client_data of type string with line_vault.
        // Compares some lines of two strings to see if they are equal.
        bool equal = compr_line( line_vault, client_data );

        // When the two string lines  are similar
        if ( equal ) {
            // Push overidden content  to file vector.
            file_content.push_back(client_data);

        } else { // if not


            // Push existing file content to file vector.
            file_content.push_back(line_vault);
        }
    }

    // release file to os.
    file_1.close(); 

    // Write Content to File again, including the updated line.
    file_1.open("Vault.dat", std::ios::out | std::ios::trunc);


    int file_vec_size = file_content.size();

    int i=0;

    // Case : write updated content to file.
    while ( i < file_content.size() ) {
        file_1 << file_content[i] << std::endl;;
        i++;
    }   
}

bool compr_line(std::string & line_1, std::string & cli_2) {


    for ( int i=0; i < 25; i++ ) {

        if ( !(line_1[i] == cli_2[i]) ) {
            return false;
        }

    }


    return true;
}







