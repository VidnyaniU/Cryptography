#include "DLP.hpp"

using namespace std;
using namespace NTL;



// void DLP::diffie_hellman(ZZ_p g)
// {
//     // select a or b randomly
//     long p = conv<long>(ZZ_p::modulus());
//     long a = RandomBnd(p);
//     cout << "a :: " << a << endl;
//     long b = RandomBnd(p);
//     cout << "b :: " << b << endl;

//     // calculate and return dlp (A, g ,a) and dlp(B , g , b)
//     ZZ_p A = dlp(g, a);
//     cout << "A :: " << A << endl;

//     ZZ_p B = dlp(g, b);
//     cout << "B :: " << B << endl;

//     ZZ_p A_dash = dlp(B, a);
//     ZZ_p B_dash = dlp(A, b);

//     if (A_dash == B_dash)
//         cout << "A_dash == B_dash == " << A_dash << endl;
// }

ZZ_p DLP::diffie_hellman_encryption(ZZ_p g, long a)
{
    // long p = conv<long>(ZZ_p::modulus());
    // long a = RandomBnd(p);
    ZZ_p A = dlp(g, a);
    return A;
}

ZZ_p DLP::diffie_hellman_decryption(ZZ_p A, long b)
{
    // long p = conv<long>(ZZ_p::modulus());
    ZZ_p B_dash = dlp(A, b);
    return B_dash;
}
// int main()
// {
//     ZZ p = conv<ZZ>("11"); // all instances of the ZZ_p will have the fixed p value now
//     ZZ_p::init(p);
//     ZZ_p g = conv<ZZ_p>("2");

//     diffie_hellman(g);

//     return 0;
// }