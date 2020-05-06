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
// Purpose: Final Project- Client, header file.
//
////////////////////////////////////////////////////////////////////////////////////////

#ifndef ClIENT_H
#define CLIENT_H

#include <string> // the standard string library
#include "./Biodata.h" // the header file for Biodata.


// This class abstracts and implements the functions of a customer in a bank.

class Client {


    public :

        // gettor's

        // get's name 
        std::string get_bio_name( );

        // get's addrs
        std::string get_bio_addrs( );

        // get's accNumber
        std::string get_accNum( );

        //get's pin
        std::string get_pin( );

        // set's the access to true ,after data is evaluated.
        bool set_access( );

        // get's cash reserve 
        float get_cash_resrv( );


    protected :

        // Member variables of Client class.

        // stores the bio data of the client
        Biodata bio;

        // stores the account number of client
        std::string accnt_num;

        // stores the personal pin of client user.
        std::string pin;

        // stores the amount of money client has in bank.
        float cash_resrv;

        // enables client to have access to data.
        bool access;

    public :

        // updates's cash reserve()
        void update_cash_reserve( );

        // Constructors for the Class

        // default constructor
        Client( ); 

        // parameterized constructor
        Client( Biodata bio, std::string _accntNum, std::string _pin );

        // Destructor
        ~Client( );

        // send's data to file. 
        void to_file( );

        // read data from file.
        void from_file( );

        // operator overloads for the class

        // increment's the cash reserve , when amount is deposited.
        int operator+( int _amnt );

        // deduct's the cash reserve when amount is withdrawn.
        int operator-( int _amnt );
    // 


};
#endif