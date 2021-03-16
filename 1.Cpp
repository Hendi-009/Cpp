#include <iostream>
#include <string>  

using namespace std;

int getShift(char c); // helper function that converts chars into their place in the alphabet as an int 
char shiftChar(char c, int rshift); // this function handles the character value shifting part of the problem
string encryptVigenere(string plaintext, string keyword); //implemntation of Vigenere cypher  , needs to loop around keyword

int main()
{ 
    string text, key, debug; 
    cout << "Masukkan Plaintext: ";
    getline(cin, text); 
    cout << "Kata Kunci: "; 
    getline(cin, key); 

    debug = encryptVigenere(text, key);
    cout << "Ciphertext     : " << debug;  

    return 0; 
}

int getShift(char c) 
{ 
    if (isupper(c)) 
    { 
        return (int)c-(int)'A';
    }
    else 
    { 
        return (int)c-(int)'a';
    }
}  

char shiftChar(char c, int rshift) 
{ 
    char shifted;
    if (isalpha(c)) { //if it is a letter

        if (isupper(c)){

            shifted = ((int)c + rshift - 'A')%26 + 'A';        //65-90 for uppercase , 97-122 for lowercase
        } 
        else { //dont have to put condition since if its not uppercase its obviously lowercase  

            shifted = ((int)c + rshift - 'a')%26 + 'a'; 

        } 

        return shifted;
    } 
    else { 

        return c; 

    } 

} 

string encryptVigenere(string plaintext, string keyword){ 

    char encrypted;
    string vigenere; 
    int ciphercount = 0;

        for(int i = 0; i < plaintext.length(); ++i) {

            if(isalpha(plaintext[i])) {
                encrypted = shiftChar(plaintext[i], getShift(keyword[ciphercount])); 
                vigenere += encrypted; 
                ciphercount ++;
            } 
            else { 
                //ciphercount -= keyword.length();
                vigenere += plaintext[i]; 
            }
            ciphercount = ciphercount % keyword.length();
        }  

    return vigenere;    

}