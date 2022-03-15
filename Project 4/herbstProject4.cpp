/*
Author: Arjuna Herbst
Class: CPSC 122 Section 2
Date: February 2, 2022
Assignment: Project 4
Description: This program first generates a an encryption key by generating a number 1-25, and then uses that key to encrypt the text from one text file
and puts the encrypted text into another text file.

PTfile = Plain text file: file that contains the text to be encrypted
CTfile = Cipher text file: file that contains the encrypted text
PTEfile = Decrypted cipher text file: file that contains the decrypted encrypted text
Keyfile = File that stores the rand num 1-25 to create the encryption key
*/

#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;

int keyGen();
void fileOpen(fstream&, string, char);
char encrypt(char ch, int key);
char decrypt(char ch, int key);

int main(int argc, char* argv[]){

fstream fileIn, fileOut;
int randNum = keyGen();

switch(atoi(argv[1])){

case 0:
fileOpen(fileOut, "project4key.txt", 'w');
fileOut << randNum;
fileOut.close();
break;

case 1: 
{
int i = 0;
char eArr[200];
fileOpen(fileIn, "project4PT.txt", 'r');
fileOpen(fileOut, "project4CT.txt", 'w');
while(fileIn){
    eArr[i] = fileIn.get();
    eArr[i] = toupper(eArr[i]);
    i++;
}
for(int n = 0; n < i - 2; n++){
    char a =  encrypt(eArr[n], randNum);
    fileOut << a;
}
fileOut.close();
fileIn.close();
break;
}
case 2:
{
int i = 0;
char dArr[200];
fileOpen(fileIn, "project4CT.txt", 'r');
fileOpen(fileOut, "project4PTE.txt", 'w');
while(fileIn){
    dArr[i] = fileIn.get();
    dArr[i] = toupper(dArr[i]);
    i++;
}
for(int n = 0; n < i - 2; n++){
    char a =  decrypt(dArr[n], randNum);
    fileOut << a;
}
fileOut.close();
fileIn.close();



break;
}
default:
return 0;
}

return 0;
}

/*
Description: creates a random number 1-25 and returns it
Input: no input
Output: random int 1-25
*/
int keyGen(){
    int x = rand() % 25 + 1;
    return x;
}

/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name. 
*/ 
void fileOpen(fstream& file, string name, char mode)
//void fileOpen(fstream& file, char name[], char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " file" << endl; 
  exit(EXIT_FAILURE);
 }
}

/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int key){
    char x = ch - 65; 
    char encrypted = ((x + key) % 26) + 65;
    return encrypted;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt (char ch, int key){
    char x = ch + 65; 
    char decrypted = ((x - key) % 26) - 65;
    return decrypted;
}


