#include <bits/stdc++.h>
using namespace std;

int main()
{
    int S[256], T[256], keyStream[256];
    string ptString, keyString, dtString = "";
    int pt[256], ct[256], dt[256];

    cout << "Enter message : "; cin >> ptString;
    cout << "Enter key     : "; cin >> keyString;
    int n = ptString.length();

    cout << "\nPlain text \t: " ;
    for(int i=0; i<n; i++)
    {
        pt[i] = ptString[i];
        cout << pt[i] << " ";
    }

    // Initialization
    for(int i=0; i<256; i++)
    {
        S[i] = i;
        T[i] = (int)keyString[i%keyString.length()];
    }

    // Initial permutation
    int j=0;
    for(int i=0; i<256; i++)
    {
        j = (j + S[i] + T[i]) % 256;
        swap(S[i], S[j]);
    }

    // Stream Generation
    cout << "\nKey Stream \t: ";
    j=0;
    for(int i=0; i<n; i++) // generate keystream of same length as plaintext
    {
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % 256;
        keyStream[i] = S[t];
        cout << keyStream[i] << " ";
    }

    // Encryption
    cout << "\nCipher Text \t: ";
    for(int i=0; i<n; i++)
    {
        ct[i] = pt[i] ^ keyStream[i];
        cout << ct[i] << " ";
    }

    // Decryption
    cout << "\nDecrypted text \t: " ;
    for(int i=0; i<n; i++)
    {
        dt[i] = ct[i] ^ keyStream[i];
        cout << dt[i] << " ";
        dtString += (char)dt[i];
    }
    cout << "\nDecrypted text \t: " << dtString << endl;
}

/******************* output-1 ************************
Enter message : Siddaganga
Enter key     : Institute

Plain text      : 83 105 100 100 97 103 97 110 103 97
Key Stream      : 236 34 53 234 27 158 64 219 222 102
Cipher Text     : 191 75 81 142 122 249 33 181 185 7
Decrypted text  : 83 105 100 100 97 103 97 110 103 97
Decrypted text  : Siddaganga
******************************************************/

/******************* output-2 ************************
Enter message : Washington
Enter key     : DC

Plain text      : 87 97 115 104 105 110 103 116 111 110
Key Stream      : 116 117 178 145 231 124 255 200 240 115
Cipher Text     : 35 20 193 249 142 18 152 188 159 29
Decrypted text  : 87 97 115 104 105 110 103 116 111 110
Decrypted text  : Washington
******************************************************/
