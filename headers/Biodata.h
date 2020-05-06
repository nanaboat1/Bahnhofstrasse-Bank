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
// Purpose: Final Project- Biodata, header file.
//
////////////////////////////////////////////////////////////////////////////////////////
#ifndef BIODATA_H
#define BIODATA_H

#include <string> // the standard string library


class  Biodata {

    public : 

        // Default constructor for the class. 
        Biodata( );

        // Parameterized constructor.
        Biodata ( std::string _name, std::string _addrs );

    public : 

        // member variable access is made public, 
        // because it will be accessed in protected mode by the Client class.


        // stores name of client.
        std::string name_client; 

        // stores address of client.
        std::string addrss_client;
    // 

};

#endif