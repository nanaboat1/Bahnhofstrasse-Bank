
#include "../headers/Accdisplay.h"
#include "../headers/Createacct.h"
#include "../headers/Logindisplay.h"
#include "../headers/Login.h"
#include "../headers/Transactdisplay.h"

#include "../headers/Transaction.h"
#include "../headers/Home.h"

#include <iostream>


void tester( ) {

    std::vector <std::string> vec;

    std::string test = "Nana Boateng Amoah,wer34,Cu09309,4704,0.0000";

    line_to_seprt( test, vec );


   // std::cout << vec[4] << std::endl;
    
   // if ( vec[2] == "Cu09309") {
       //std::cout << "Good to go" << std::endl;
   //}

    // login_bank();

    // Client clo;

    // std::stack <Client> cli;
    //cli.push(clo);

    // over_ridefile( cli );

    // cash_withraw( cli );

    // print_receipt( clo , 1, 0.0);

   // mother_func( cli );
   
}

void main_test() {
   Home();
}


int main() {

   // tester();
    main_test();

   return 0;
}