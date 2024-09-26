#include <bits/stdc++.h>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

using namespace std;
using namespace NTL;
class DLP
{
public:
    DLP(); // pass the prime as a string
    ZZ_p dlp(ZZ_p g, long x);
    void diffie_hellman(ZZ_p g);
    ZZ_p diffie_hellman_encryption(ZZ_p g, long a);
    ZZ_p diffie_hellman_decryption(ZZ_p A, long b);
    ZZ_p elGamal_encryption();
    ZZ_p elGamal_decryption();
};