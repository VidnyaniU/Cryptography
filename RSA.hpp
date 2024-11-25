#include <bits/stdc++.h>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

using namespace std;
using namespace NTL;

class RSA
{
public:
    ZZ p, q, n, phi, a, b;

    RSA(long keySize);

    void GenerateKeys(long keySize);

    // encryption and decryption
    ZZ RSA_Encrypt(ZZ message);

    ZZ RSA_Decrypt(ZZ ciphertext);

    // digital signature and verification
    ZZ RSA_Sign(ZZ message);
    bool RSA_Verify(ZZ message, ZZ signature);
};