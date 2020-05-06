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
// Purpose: Final Project- Biodata, cpp file.
//
////////////////////////////////////////////////////////////////////////////////////////
#include "../headers/Biodata.h" // the header file for biodata.
#include <string> // the standard string library


// The cpp file only contains constructors
// data will only be accessed from Client class.


// Default Constructor
Biodata::Biodata( ) : Biodata("undefined", "undefined") {}

// Parameterized constructor 
Biodata::Biodata( std::string _name, std::string _addrs ) : name_client(_name), addrss_client(_addrs) {}