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

    ZZ RSA_Encrypt(ZZ message);

    ZZ RSA_Decrypt(ZZ ciphertext);
    // digital signature
};