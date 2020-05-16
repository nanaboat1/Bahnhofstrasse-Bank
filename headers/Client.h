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

#ifndef CLIENT_H
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
        void set_access( std::string arb_pin );

        // get's cash reserve 
        float get_cash_resrv( );

        // public settor's

        void set_pin(std::string _pin);

        void set_accnt_number(std::string _accnum);


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
        void incrs_cash_reserve( float update_cash );

        // decrease cash reserve
        void dcrs_cash_reserve( float update_cash );

        // Constructors for the Class

        // default constructor
        Client( ); 

        // parameterized constructor
        Client( Biodata _bio, std::string _accntNum, std::string _pin );

        // Destructor
        ~Client( );

        // send's data to file. 
        std::string to_file( );


        // operator overloads for the class

        // increment's the cash reserve , when amount is deposited.
        float operator+( float _amnt );

        // deduct's the cash reserve when amount is withdrawn.
        float operator-( float _amnt );


        // Find a way to implement to_string in Display : NOTE 1.a
        friend std::ostream& operator<<( std::ostream & out, Client & cli ); 


        
      
    // 

};
#endif