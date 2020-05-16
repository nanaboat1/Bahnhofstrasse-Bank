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
// Purpose: Final Project- Makes the client to login, header file.
//
////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string> // the standard string library 
#include "../headers/Biodata.h" // the header file Biodata class
#include "../headers/Client.h" // the header file for Client class
#include <vector> // the standard vector library
#include <stack> // the standard stack library.
#include <fstream> // for handling files.
#include <typeinfo> // for type info
#include "../headers/Transaction.h"
// More include libraries 
#include "../headers/Logindisplay.h" // for display handling.


// function prototypes
bool line_to_seprt(std::string & _line, std::vector <std::string> & data_vec );
bool search_vault( std::vector <std::string> & search_client_data , std::stack <Client> & user );
void read_file( std::vector <std::string> & usr_details, std::stack <Client> & user );

/////////////////////

// Case: Removes unneccessary data. 
// 
void cv_str( std::string & str_float ) {

  std::string str = "";

  
  for ( int i =0; i < str_float.length(); i++ ) {

    if( static_cast<int>(str_float[i]) >= 32 && static_cast<int>(str_float[i]) <= 126 ) {

      str += str_float[i];
    }
  }


  str_float = str;
  
}


void read_file( std::vector <std::string> & usr_details, std::stack <Client> & user ) {

  // Case: Instantiate ifstream class
  std::ifstream fin;

  fin.open("Vault.dat"); // open file

  // Case: Error checking of file.
  if ( fin.fail()) {
    std::cout << "File not found" << std::endl;
  }

  // Case:  Loop Reads the file breaks file line into portions
  // 
  std::string chk_data; // to check if there's more line to read
  std::string file_line; // get line of data.
  std::vector <std::string> client_info;//get's info from file
  bool reading = true;
  bool _data_exst = false; // to prevent memory access error
    
  while( !fin.eof()) {

    // Case: get that specific line of data
    getline(fin, file_line);

    cv_str( file_line);
    
    // Case: Send string to a function that breaks it up 
    // to get the details of the account and push it to vector.
    _data_exst = line_to_seprt( file_line, client_info);

    // Case: Check if the login details are correct
    if ( _data_exst ) {

      if ( (client_info[2] == usr_details[0]) && (client_info[3] == usr_details[1])) {

        // Case : When login details are equal 
        // dynamically create a Client class with it.
        Biodata *bio_ptr = nullptr;// pointer to hold biodata
        Client *client_ptr = nullptr;// pointer to hold client

        // Case: Create a Biodata class
        bio_ptr = new Biodata(client_info[0], client_info[1]);

        // Case: Create a temporary Client class.
        client_ptr = new Client( *bio_ptr, client_info[2], client_info[3]);

        // Case: Push Client object to stack
        user.push(*client_ptr);

        // Case: set access to bank account to true.
        user.top().set_access(client_info[3]);

        // for memory safety
        delete bio_ptr;
        bio_ptr =nullptr;

        delete client_ptr;
        client_ptr = nullptr;

        reading = false;// signalling data has been gotten
        return; // so that it doesnt read the files again.

      } else {
        
        // Empty the client_info vector .
        // to prepare it to get data on next line.
        client_info.clear();
        
      }
    }

  } 

  // After reading file then the user's data doesnt exist.
  if ( !_data_exst) { 
    std::cout << " Account Not found !!!!!! " << std::endl;
  }

   
  return;
}

// Situation : this function separates line contents of file of type string 
// It utilises ASCII to detect a separator.
bool line_to_seprt(std::string & _line, std::vector <std::string> & data_vec ) {

  // use the comma as a clue here to break the code 
  int num_comma = 0;
  std::string data_collector = ""; // get's data from _line
  int track_cur_comma =0; // the position of current comma.
  

  // Case: This loop checks line of type string and get's 
  // specific data from it and stores them in temp_baby_name & tem_baby_gender &
  // temp_baby_count respectively.
  
  for ( int i=0; i < _line.size(); i++) {

    // Case: iterate meets 1st comma
    if ((_line[i] == ',' )  && (num_comma == 0)) { 

      // Case : get name from string _line 
      for (int n=0; n < i; n++) {
        data_collector += _line[n];
      }
      data_vec.push_back(data_collector); 
      num_comma =1;  
      data_collector = ""; 
      track_cur_comma = i;
    }

    // Case: iterate meets 2nd comma
    if ((_line[i]== ',' && num_comma == 1) && (i != track_cur_comma)) {

      // Case : get address from _line
      for( int j= track_cur_comma + 1; j < i; j++){ 
        data_collector += _line[j];
      }
      data_vec.push_back(data_collector);
      num_comma = 2;
      data_collector = "";
      track_cur_comma = i; 
    } 

    // Case: iterate meets 3rd comma.
    if((_line[i] == ',' && num_comma == 2) && (i != track_cur_comma) ) {

      // get Acct number from  _line
      for (int c = track_cur_comma + 1; c < i; c++){
        data_collector += _line[c]; // get's count
      }
      data_vec.push_back( data_collector);
      num_comma =3; 
      data_collector = "";
      track_cur_comma = i;
    }

    // Case: iterate meets 4th comma.
    if(( _line[i] == ',' && num_comma == 3) && (i != track_cur_comma) ) {

      for( int e= track_cur_comma + 1; e < i; e++){
        //get pin from _line 
        data_collector += _line[e];
      }
        data_vec.push_back(data_collector);
        data_collector = "";

        // Case: iterate gets any data after 4th comma.
        for ( int o=i + 1; o < _line.length(); o++) {
            // get cash reserve from _line
           data_collector += _line[o];
        }
        data_vec.push_back(data_collector);

    }
    
  }

  // Case : Incase no data is pushed to vector
  if ( data_collector.size() == 0) {
    return false; // signalling no data exists
  }



    return true;
}

// Case : Sub-function that searches through file to get User Data.
// function returns bool to indicate that data is existent in file. of login details.
bool search_vault( std::vector <std::string> & search_client_data , std::stack <Client> & user ) {


  // Searches Vault, by reading file.
  read_file( search_client_data, user) ;

  if ( user.top().get_pin() == search_client_data[1]) {
    return true;
  } else {
    return false;
  }
  
}


// Case : Sub-function that creates a temporary customer class from data from file.

// Case : Mother function for user to log into bank.
void login_bank( ) {

    // Case: Welcome display 
    login_welcome_display();

    // Instantiate a vector
    std::vector <std::string> from_file;  // Vector get's Customer data from file.
    std::vector <std::string> user_login_info; // stores user's input 
    std::stack <Client> user; // get's Client object.


    // Nice Login Page. to Get user's data // arb_vector <==> arbitrary vector
    login_form(user_login_info); // arb_vector[0] == Accnt_num. arb_vector[1] == PIN.

    // Case : Search the Vault for User details and if gotten, load into
    // stack.
    search_vault( user_login_info, user);
    clear_disp();

    int delay =0;
    // tell User that Account has been logged in Successfully.
    std::cout << "------------------------------------------------------------- \n" << std::endl;
    std::cout << " WELCOME BACK,   " << user.top().get_bio_name( )  <<  std::endl;
    std::cout << "\n-------------------------------------------------------------" << std::endl;
    std::cout << " Press 1 to contiune ";
    std::cin >> delay;
    clear_disp();

    // Now: Let's Play with User

    // Performs Transactions on User.

    // Use a loop for mother function.
    mother_func( user); 

  return;
}