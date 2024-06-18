#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;
/*
	This code accepts the input file name and passes it to the function words. It also passes it a
	pointer for the total number of words in the file. When it returns from the function, it displays
	the total number of words. It runs based on the assumption the file exists and is spelled correctly.

	Written by Betsy Kamas
	March 2022
	Written in C++
	g++ compiler

*/
int main(void)
{
  void words(string file, int &word_count); // Function Prototype

  string filename; // Input file name
  cout<<"Please enter the name of the file ";
  cin>>filename; // Read in file name
  cout<<endl; //Aesthetics

  int WC=0; // Sets number of words in the file to 0 by default before analyzing the file
  words(filename,WC); // Passing the user input and word count to function

  cout<<endl<<"The total number of words in this file is "<<WC<<endl; // Back from function and displays the
								// total number of words in the file

  return 0;
}

/*
	This code's purpose is to read in a user defined file and search it for all the words that start
	with either 'D' or 'd' and report the number of letters each of the words that start with d and
	have a max length of 10 letters. It also reports the total number of words in the file.

	This function is adapted from Ron Sarner's code for Reading a File of Words handout from class.

	It is passed two things, one being the file name and the other a pointer to the total number of
	words in the file.

	Adapted by Betsy Kamas
	March 2022
	Written in C++
	g++ compiler
*/

void words(string file, int &word_count)
{

  int lengthoword[10]={0}; // Array that has 10 positions and has been initialized to 0. Each spot in the
			   // array corresponds to the length of the word

  string s;		   // This is the placeholder for each of the words read in from the file in order
			   // to be analyzed

  ifstream fileIn;	   // This opens the file

  fileIn.open(file.data());// This pulls the data in from the external file
  assert(fileIn.is_open());
  while (fileIn>>s)	   // Loop to go through every word in the file
      {
	word_count++;	   // This holds the value for the total number of words in the file, and is a pointer
			   // to WC in main
//	cout<<s<<endl;	   // This displays every word to the screen, and was used for troubleshooting

	if(s[0]=='d' || s[0]=='D') // This checks if the word that was just pulled from the file starts with the letter d
	{
//	  cout<<s<<endl;   // Also used for troubleshooting and displays all words that start with d
	  int x=s.length(); // This calculates the number of characters in the string
//	  cout<<x<<endl;    // Used for troubleshooting, displayed the total length of the word

	  int z=ispunct(s[x-1]); // This checks if the last character of the word is a punctuation mark. This makes
				 // the length of the word more accurate

	  if(z!=0)		 // If it did equal 0, then it would not be a punctuation mark. Since it does not equal 0
		x=x-1;		 // the last character is a punctuation mark, so the length is decreased by 1.

//	  cout<<x<<endl;	 // This was used for troubleshooting and if the ispunct command was working correctly

	  int spot=x-1;		 // This correlates the length of the word to the array so that position 0 would equal 1
				 // letter, 1 would equal 2 letters, etc.

	  lengthoword[spot]=(lengthoword[spot])+1; // Increases the value in the array location
	}


      }

  int y; // Loop counter variable
  int len=1; // Length of word to be displayed in the loop below

  for(y=0; y<10; y++) // Displays content of array and how many words of each length there are
  {
	cout<<"The number of words starting with either 'd' or 'D' and has a length of "<<len++<<" is "<<lengthoword[y]<<endl;
  }
}














