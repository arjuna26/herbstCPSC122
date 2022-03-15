#include <iostream>
using namespace std;

char encrypt(char ch, int key);

int main(){
cout << encrypt('A', 1);
}

char encrypt(char ch, int key){
    char x = ch - 65; 
    char encrypted = ((x + key) % 26) + 65;
    return encrypted;
}
