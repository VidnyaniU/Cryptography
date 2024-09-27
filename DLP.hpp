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

    Vec<ZZ_p> elGamal_encryption(ZZ_p g, long x, long m); // m is message
    ZZ_p elGamal_decryption(Vec<ZZ_p> C1_C2, long x);     // x is the extra info alice knows

    // signing
    Vec<ZZ_p> elGamal_digital_signature(ZZ_p g, long x, long m);
    // verification
    bool digital_signal_verification(Vec<ZZ_p>, ZZ_p g, long x, long m);
};