/*
Author: Arjuna Herbst
Class: CPSC 122 Section 2
Date: January 26, 2022
Assignment: Project 3
Description: This program takes in 2 ints and a file name as command line inputs and then multiplies the two ints and outputs the product to the text file
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int myAtoi(char str[]);

int main(int argc, char* argv[]){

    fstream outFile;
    
    int x = myAtoi(argv[1]);
    int y = myAtoi(argv[2]);

    outFile.open(argv[3], ios::app);

    outFile << x * y << endl;

    return 0;
}

int myAtoi(char str[]){

    int ans;

    for(int i = 0; str[i] != '\0'; ++i){
        ans = ans*10 + str[i] - '0';
    }

    return ans;
}