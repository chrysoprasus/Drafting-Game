#include <fstream>
#include <iostream>
#include <string> 
#include <vector>
using namespace std;

class Draft{

  //vars 
  private: int picks = 6;
  private: vector<string> names;
  private: vector<string> drafted;

  public:

    // Draft constructor
    Draft(string file){

        
        //vars
        string myText;
        ifstream MyReadFile(file);

        //check is file is open
        if(!MyReadFile.is_open()){
          cerr << "error opening file!";
          return;
        }
        //read file
        while(getline(MyReadFile, myText)){
          names.push_back(myText);
        }
        //close file
        MyReadFile.close();

      
    }// draft constructor

    
    //do the drafting
    void drafting(int picks, int input){

      int picksTemp = picks;
      
      for(size_t i = 0; i < (picks + 1); i++){

        if (input < 1 || input > names.size()) {
            cout << "Invalid input, try again: ";
            cin >> input;
            --i; 
            continue; 
        }
        
        drafted.push_back(names[input - 1]);
        names.erase(names.begin() + (input - 1));

        if(picksTemp == 1){
          cout << "\nYou have drafted " << drafted[i] << endl;
          
          cout << "\nDraft is over!" << endl;

          cout << "You have drafted: " << endl;
          for (size_t i = 0; i < drafted.size(); ++i) {
              
              cout << (i + 1) << ". " << drafted[i] << "\n";
          }// for loop

          break;
        }else{
  
          getNames();
          
          cout << "\nYou have drafted " << drafted[i] << endl;
          cout << "You have " << picksTemp << " picks left!" << endl;
          cout << "Enter a number to draft another player: ";
          cin >> input;
          picksTemp--;
        }
        
      }// for loop
      
    }// for drafting

    void getNames(){
      cout << "\n-2024 Draft Class-\n" << endl;
      
      for (size_t i = 0; i < names.size(); ++i) {
          // print index + 1 and name
          cout << (i + 1) << ". " << names[i] << "\n";
      }// for loop
    }//get names

    void create(){
      int input = 0;
      
      cout << "Welcome to the 2024 draft!\n";
      cout << "You Have " << picks << " picks!\n";

      while(true){
        cout << "Press 1 to start: ";
        
        cin >> input;
        
        if(input == 1){
          
          getNames();
          
          break;
          
        }else{
           cout << "i said press 1";
        }// if statment
      }//while

      cout << "Pick the number of player you want to draft: ";
      cin >> input;
      drafting(picks, input);

      
    }//create
};
