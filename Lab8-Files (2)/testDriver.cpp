/*
 * testDriver.cpp
 * 
 * Description: Drives the testing of the BST, the BSTNode, 
 *              the WordPair and all the exceptions classes. 
 *
 * Author: AL
 * Last Modification Date: Feb. 2022
 */


// Yet to be adapted to the new data structure.
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BinaryHeap.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"


void display(const WordPair& anElement) {
  cout << anElement << endl;
} // end of display


// As you discover what main() does, record your discoveries by commenting the code.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[]) {

  // Initialize the BST
  BST<WordPair>* testing = new BST<WordPair>();
    
  
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "dataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
 
  
  ifstream myfile (filename);
  // Check if dataFile.txt can be read
  if (myfile.is_open()) {
  	cout << "Reading from a file:" << endl; 


    while ( getline (myfile,aLine) )
    { // read a line from the file
      
      // Returns the location of the delimiter ":" and stores it in pos
      pos = aLine.find(delimiter);

      // Parse the first word before the delimiter and store it in englishW
      englishW = aLine.substr(0, pos);


      // Parse the second word after the delimiter and store it in translationW
      aLine.erase(0, pos + delimiter.length());
      translationW = aLine;

      // Create a WordPair object pairing the english and translation words
      WordPair aWordPair(englishW, translationW);


	   // insert aWordPair into "testing" using a try/catch block
     try {
        testing->insert(aWordPair);
      }
      catch (ElementAlreadyExistsException& e) {
        cout << "ElementAlreadyExistsException: " << e.what() << endl;
      }
      catch (EmptyDataCollectionException& e) {
        cout << "EmptyDataCollectionException: " << e.what() << endl;
     }
    }
    myfile.close();

    // If user entered "Display" at the command line ...
    if ( ( argc > 1 ) && ( strcmp(argv[1], "Display") == 0) ) { // if user entered "Display" at the command line ...
        // ... then display the content of the BST.

        // FIXME: BRO........ I wasted a lot of time on this. FUCK ME
        // void (*display)(const WordPair&) = display;

        cout << "Displaying the content of the BST:" << endl;
        testing->traverseInOrder(&display);
        cout << endl;
    }
    else if (argc == 1) {
       // while user has not entered CTRL+D
       while ( getline(cin, aWord) ) { //get a word from the user

          // FIXME: DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
          // FIXME: DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
          // FIXME: DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
          if(aWord == "Fuck") {
            break;
          }

          WordPair aWordPair(aWord);
          // retrieve aWordPair from "testing" using a try/catch block
          try {
            cout << "Retrieving: " << aWordPair << endl;
            translated = testing->retrieve(aWordPair);
          }
          catch (ElementDoesNotExistException& e) { // if the element does not exist
            cout << "Element does not exist: " << e.what() << endl;
          }
          catch (EmptyDataCollectionException& e) { // if the collection is empty
            cout << "Empty data collection: " << e.what() << endl;
          }
          cout << "Translation successful. " << translated << endl;
          cout << "English: " << aWordPair.getEnglish() << endl;
          cout << "Translation: " << translated.getTranslation() << endl;
          cout << endl;
       }
    }
  }
  else 
    cout << "Unable to open file"; 

  delete testing;
  return 0;
}
