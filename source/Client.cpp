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
// Purpose: Final Project- Client, cpp file.
//
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>  // the standard io stream library
#include <string> // the standard string library
#include "../headers/Client.h" // the header file for client class
#include "../headers/Biodata.h" // the header file for biodata class


// Implementing methods

// // gettors of the class

    // get's name
    std::string Client::get_bio_name() { return this->bio.name_client; }

    // get's address
    std::string Client::get_bio_addrs() { return this->bio.addrss_client; }

    // get's account Number
    std::string Client::get_accNum() { return this->accnt_num; }

    // get's pin
    std::string Client::get_pin() { return this->pin; }

    // get's cash reserve
    float Client::get_cash_resrv() { return this->cash_resrv; }


// //  Constructors

    // default constructor 
    Biodata _temp( "John Doe", "undef"); // to pass it to default constructor
    Client::Client() : Client::Client( _temp , "wRtzas", "1234" ) { }

    // parameterized constructor
    Client::Client( Biodata _bio, std::string _accntNum, std::string _pin ) :
        bio(_bio), accnt_num(_accntNum), pin(_pin) {}

    // destructor
    Client::~Client() {}

// 
    // manipulates the amount of money in reserve
    void Client::update_cash_reserve( float update_cash ) {

        // Case: update cash reserve when accesss is true.
        if ( Client::access) {
            // Enables System to manipulate the Customers cash
            this->cash_resrv = update_cash;
        }

    }

    // send's data to file. 
    std::string Client::to_file( ) {
        std::string str; 

        // Case: Append data to string in a standardized way
        // to be stores on file. 
        char stnd_sprtr = ','; // used to detect and manipulate strings

        str += this->get_bio_name() + stnd_sprtr + // name is added to string & stndrd separated.
        this->get_bio_addrs() + stnd_sprtr + // addrs is added to string & stndrd separated
        this->get_accNum() + stnd_sprtr + // accnt number is added to string & stndrd separated
        this->get_pin() + stnd_sprtr + // pin is added to string & stndrd separated
        std::to_string(this->get_cash_resrv()); // cash is added to string & stndrd separated

        return str;
    }

// 
    // increments the cash reserve
    float Client::operator+( float _amnt ) {

        // This operator overload increments the 
        // amount of cash in store when access is set to true.
        if ( this->access ) {
            this->cash_resrv += _amnt;

        } else {
            this->cash_resrv += 0.0;
        }

        return this->cash_resrv;
    }

    // decrements the cash reserve when amount is withdrawn
    float Client::operator-( float _amnt ) {

        // This operator overload decreases the 
        // amount of cash in store when access is set to true.

        if ( this->access ) {
            this->cash_resrv -= _amnt;

        } else {
            this->cash_resrv -= 0.0;
        }

        return this->cash_resrv;
    }

// 

