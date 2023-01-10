//
//  main.cpp
//  Cryptography
//
//  Created by Armine Meseldzhyan on 6/15/22.
//

//Diffie-Hellman Key exchange algorithm
//Step 1: Vicky and Dylan get public numbers V = 23, D= 9
//
//Step 2: Vicky selected a private key v = 4 and
//        Dylan selected a private key d = 3
//
//Step 3: Vicky and Dylan compute public values
//Vicky:    x =(9^4 mod 23) = (6561 mod 23) = 6
//Dylan:    y = (9^3 mod 23) = (729 mod 23)  = 16
//
//Step 4: Vicky and Dylan exchange public numbers
//
//Step 5: Vicky receives public key y =16 and
//        Dylan receives public key x = 6
//
//Step 6: Vicky and Dylan compute symmetric keys
//        Vicky:  ka = y^v mod p = 65536 mod 23 = 9
//        Dylan:  kb = x^d mod p = 216 mod 23 = 9
//
//Step 7: 9 is the shared secret.
#include <iostream>
#include <cmath>
using namespace std;
 
// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b,
                    long long int P)
{
    if (b == 1)
        return a;
 
    else
        return (((long long int)pow(a, b)) % P);
}
 

int main()
{
    long long int P, G, x, v, y, d, kv, kd;
 
    
    P = 23; // A prime number P is taken
    cout << "The value of P : " << P << endl;
 
    G = 9; // A primitive root for P, G is taken
    cout << "The value of G : " << G << endl;
 
    
    v = 4; // v is the chosen private key
    cout << "The private key v for Vicky : " << v << endl;
 
    x = power(G, v, P); // gets the generated key
 
   
    d = 3; // d is the chosen private key
    cout << "The private key d for Dylan : " << d << endl;
     
        y = power(G, d, P); // gets the generated key
     
        // Generating the secret key after the exchange
        // of keys
        kv = power(y, v, P); // Secret key for Vicky
        kd = power(x, d, P); // Secret key for Dylan
        cout << "Secret key for the Vicky is : " << kv << endl;
     
        cout << "Secret key for the Dylan is : " << kd << endl;
     
        return 0;
    }
