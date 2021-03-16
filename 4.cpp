#include<iostream>
using namespace std;
 
int main()
{
	char kalimat[100], c;//100 = jumlah karakter
	int i, geser;
	
	cout << "Masukkan Chiphertext: ";
	cin.getline(kalimat, 100);
	cout << "Penggeseran: ";
	cin >> geser;
	
	for(i = 0; kalimat[i] != '\0'; ++i){
		c = kalimat[i];
		
		if(c >= 'a' && c <= 'z'){ //Huruf kecil
			c = c - geser;//alphabet digeser kesemula
			
			if(c < 'a'){//antisipasi keluar dari ASCII
				c = c + 'z' - 'a' + 1;
			}
			
			kalimat[i] = c;//pesan ditulis ulang
		}
		else if(c >= 'A' && c <= 'Z'){ //Huruf besar
			c = c - geser;
			
			if(c < 'A'){
				c = c + 'Z' - 'A' + 1;
			}
			
			kalimat[i] = c;
		}
	}
	
	cout << "Plaintext : " << kalimat;
	
	return 0;
}