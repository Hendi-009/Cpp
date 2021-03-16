#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;
void menu();
void balik_menu(){
    cout << "Tekan enter untuk kembali..."; getch();
    cout << endl;
    menu();
}

void caesar_plaintext(){
	char kalimat[100], c;
	int i, geser;
	cout << "Plaintext  : "; cin >> kalimat;
	cout << "Penggeseran: "; cin >> geser;
	for(i = 0; kalimat[i] != '\0'; ++i)    {
		c = kalimat[i];
		if (c >= 'a' && c <= 'z'){ //Huruf kecil
			c = c + geser; //alfabet digeser
			if (c > 'z'){ //antisipasi keluar dari ASCII
				c = c - 'z' + 'a' - 1;
			}
			kalimat[i] = c; //kata ditulis ulang
		}
		else if (c >= 'A' && c <= 'Z'){ //Huruf besar
			c = c + geser; //alfabet digeser
			if (c > 'Z'){ //antisipasi keluar dari ASCII
				c = c - 'Z' + 'A' - 1;
			}
			kalimat[i] = c; //kata ditulis ulang
		}
	}
	cout << "Ciphertext : " << kalimat << endl;
    balik_menu();
}

void caesar_ciphertext(){
	char kalimat[100], c;
	int i, geser;
	cout << "Ciphertext : "; cin >> kalimat;
	cout << "Penggeseran: "; cin >> geser;
	for(i = 0; kalimat[i] != '\0'; ++i)    {
		c = kalimat[i];
		if (c >= 'a' && c <= 'z'){ //Huruf kecil
			c = c - geser; //alfabet digeser
			if (c < 'a'){ //antisipasi keluar dari ASCII
				c = c + 'z' - 'a' + 1;
			}
			kalimat[i] = c; //kata ditulis ulang
		}
		else if (c >= 'A' && c <= 'Z'){ //Huruf besar
			c = c - geser; //alfabet digeser
			if (c < 'A'){ //antisipasi keluar dari ASCII
				c = c + 'Z' - 'A' + 1;
			}
			kalimat[i] = c; //kata ditulis ulang
		}
	}
	cout << "Plaintext  : " << kalimat << endl;
    balik_menu();
}

void vigenere_plaintext(){
	int i,j,k,n;
	string kata, kunci;
    vector< vector<char> > arr(26, vector<char>(26));
    k = 0;
    n = 26;
    for (i = 0; i < n; i++){
        k = i;
        for (j = 0; j < n; j++){
            arr[i][j] = 'A' + k;
            k++;
            if (k == 26)
                k = 0;
        }
    }
    cout << "Plaintext : "; cin >> kata;
    cout << "Kunci     : "; cin >> kunci;
    k = 0;
    int jumlah = kunci.size();
    for (i = kunci.size(); i < kata.size(); i++){
        kunci += kunci[k % jumlah];
        k++;
    }
    string hasilvigenere;
    for(i = 0; i < kata.size(); i++){
        hasilvigenere += arr[kata[i]-'A'][kunci[i]-'A'];
    }
    cout << "Ciphertext: " << hasilvigenere << '\n';
	balik_menu();
}

char shiftChar(char c, int rshift) { 
	char shifted;
	if (isalpha(c)) { 
		if (isupper(c)){
			shifted = ((int)c - rshift + 'A') % 26 + 'A';
		}
		else {  
			shifted =  (((int)c - 32) - (rshift + 65) + 26) % 26 + 'a'; 
		} 
		return shifted;
	} 
	else { 
		return c; 
	} 
}

void vigenere_ciphertext(){
	string text, key, hasilcipher; 
	cout << "Ciphertext: "; cin >> text;
	cout << "Kunci     : "; cin >> key;
	char encrypted, c;
	int ciphercount = 0;
		for(int i = 0; i < text.length(); ++i) {
			if (isalpha(text[i])) {
				if (isupper(key[ciphercount])){
					c = (int)key[ciphercount] - (int)'A';
					}
				else {
					c = (int)key[ciphercount] - (int)'a';
					}
				encrypted = shiftChar(text[i], c); 
				hasilcipher += encrypted; 
				ciphercount++;
			} 
			else {
				hasilcipher += text[i];
			}
			ciphercount = ciphercount % key.length();
		}
	cout << "Plaintext : " << hasilcipher << endl;
	balik_menu();
}

void menu(){
	string input;
	system("cls");
	cout << "\nSelamat Datang" << endl;
    cout << "Projek ini dibuat oleh" << endl;
    cout << "Giovani Chadavi Hidayat       2009106001" << endl;
    cout << "Hendi                         2009106009" << endl;
    cout << "Fazri Rahmad Nor Gading       2009106031" << endl;
    cout << "Muhammad Rifky Cahyadi Sukri  2009106043" << endl;
    cout << "Fathan Ghoji Adzikra          2009106044" << endl;
	cout << "==============================" << endl;
	cout << "1. Metode Caesar Plaintext ke Ciphertext" << endl;
	cout << "2. Metode Caesar Ciphertext ke Plaintext" << endl;
	cout << "3. Metode Vigenere Plaintext ke Ciphertext" << endl;
	cout << "4. Metode Vigenere Ciphertext ke Plaintext" << endl;
	cout << "0. Keluar" << endl;
	cout << "==============================" << endl;
	cout << "Pilihan: "; cin >> input;
    if(input == "1"){
		caesar_plaintext();
		}
	else if(input == "2"){
		caesar_ciphertext();
		}
	else if (input == "3"){
		vigenere_plaintext();
		}
	else if (input == "4"){
		vigenere_ciphertext();
		}
	else if (input == "0"){
		cout << "Keluar dari program...";
		}
    else{cout << "Pilihan tidak ditemukan." << endl;}
}

int main(){
	menu();
}