#include "DLP.hpp"

using namespace std;
using namespace NTL;

Vec<ZZ_p> DLP::elGamal_encryption(ZZ_p g, long x, long m)
{

    Vec<ZZ_p> C1_C2;
    C1_C2.SetLength(2);

    // choose y from {0,1,2,..,p-1}
    ZZ_p y = random_ZZ_p();
    // compute s = h^y
    ZZ_p h = dlp(g, x);
    ZZ_p s = dlp(h, conv<long>(y));

    // compute C1 = g^y
    ZZ_p C1_C2[0] = dlp(g, conv<long>(y));

    // compute C2 = m.s
    ZZ_p C1_C2[1] = m * s;
    return C1_C2;
}

long elGamal_decryption(Vec<ZZ_p> C1_C2, long x)
{

    long ans = conv<long>(C1_C2[1]) * conv<long>(inv(power(C1_C2[0], x)));
    return ans;
}
