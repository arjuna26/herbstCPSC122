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
int decryptGen();
int key[26];
void fileOpen(fstream&, string, char);
char encrypt(char ch, int key[26]);
char decryptC(char ch, int decrypt[][26]);
void command(int decrypt[][26]);

int main(int argc, char* argv[]){

    srand(time(0));
    command();       
}
/*
Description: creates an array that stores the encryption values
Input: no input
Output: returns the array containing the encryption values
*/
int keyGen(){

    bool validate[26] = {false, false, false, false, false, false, false, false, false, false, false, false, false,
                         false, false, false, false, false, false, false, false, false, false, false, false, false,};
    int key[26];
    int posi = 0;
    while(posi < 26){
        while(true){
        int k = rand() % 25;
            if(validate[k] == false){
                key[posi] = k;
                validate[k] = true;
                posi++;
            }
          } 
        }
    return key[26];
    }

/*
Description: creates an array that stores the decryption values
Input: no input
Output: array containing decryption values
*/
int decryptGen(){
    int decrypt[26][2];
        for(int j = 0; j < 26; j++){
            decrypt[0][j] == key[j];
        }
        for(int i = 0; i < 26; i++){
            decrypt[1][i] == i;
        }
        return decrypt[1][26];
}

/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name. 
*/ 
void fileOpen(fstream& file, string name, char mode){
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
Description: encrypts a char from PT file
Input: char and encryption key array
Output: encrypted char
*/
char encrypt(char ch, int key[26]){
    char cha = toupper(ch);
    for(int i = 0; i < 26; i++){
        if(cha - 65 == key[i]){
            cha = key[i] + 65;
        }
    }
    return cha;
}

/*
Description: decrypts a char from CT file
Input: char and decrypt array
Output: decrypted char
*/
char decryptC(char ch, int decrypt[][26]){
    char cha = toupper(ch);
    for(int i = 0; i < 26; i++){
        if(cha - 65 == decrypt[0][i]){
            cha = decrypt[1][i] + 65;
        }
    }
    return cha;
}
/*
Description: Opens files, encrypts, closes files. Opens new files, decrypts, closes files
Input: decryption array
Output: no output
*/
void command(int decrypt[][26]){
    fstream fileIn, fileOut;
    keyGen();
    decryptGen();

    fileOpen(fileIn, "project6PT.txt", 'r');
    fileOpen(fileOut, "project6CT.txt", 'w');
    while(fileIn){
        char a = fileIn.get();
        char b = encrypt(a, key[26]);
        fileOut << b;
    }
    fileIn.close();
    fileOut.close();

    fileOpen(fileIn, "project6CT.txt", 'r');
    fileOpen(fileOut, "project6PTE.txt", 'w');
    while(fileIn){
        char c = fileIn.get();
        char d = decryptC(c, decrypt[][26]);
        fileOut << d;
    }
    fileIn.close();
    fileOut.close();
}
