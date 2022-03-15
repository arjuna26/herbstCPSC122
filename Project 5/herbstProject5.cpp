/*
Author: Arjuna Herbst
Class: CPSC 122 Section 2
Date: February 2, 2022
Assignment: Project 5
Description: This program uses the affine cipher to encrypt the text from one text file and puts the encrypted text into another text file.
*/

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int keyGen();
void fileOpen(fstream&, string, char);
char encrypt(char ch, int key, int alphaKey);
char decrypt(char ch, int key, int alphaKey);
int alphaKeyGen();

int main(int argc, char* argv[]){

fstream fileIn, fileOut;
int randNum = keyGen();
int alphaKey = alphaKeyGen();

switch(atoi(argv[1])){

case 0:
fileOpen(fileOut, "project4key.txt", 'w');
fileOut << randNum;
fileOut.close();
break;

case 1:
{
char a;
int i = 0;
char eArr[200];
fileOpen(fileIn, "project5PT.txt", 'r');
fileOpen(fileOut, "project5CT.txt", 'w');
while(fileIn){
    eArr[i] = fileIn.get();
    eArr[i] = toupper(eArr[i]);
    i++;
}
for(int n = 0; n < i - 2; n++){
    char a =  encrypt(eArr[n], randNum, alphaKey);
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
fileOpen(fileIn, "project5CT.txt", 'r');
fileOpen(fileOut, "project5PTE.txt", 'w');
while(fileIn){
    dArr[i] = fileIn.get();
    dArr[i] = toupper(dArr[i]);
    i++;
}
for(int n = 0; n < i - 2; n++){
    char a =  decrypt(dArr[n], randNum, alphaKey);
    fileOut << a;
}
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
int alphaKeyGen(){
    int arr[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    int y = rand() % 12;
    int alphaKey = arr[y];
    return alphaKey; 
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
Description: Encrypts an upper case alphabetic character using the Affine cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int key, int alphaKey){
    char x = ch - 65; 
    char encrypted = ((alphaKey * x + key) % 26) + 65;
    return encrypted;
}


/*
Description: Decrypts an upper case alphabetic character using the Affine cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt (char ch, int key, int alphaKey){
    char y = ch + 65;
    char decrypted = ((alphaKey * y - alphaKey *  key + 650 * 26) %  26) - 65;
    return decrypted; 

}

