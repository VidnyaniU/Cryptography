#include "DLP.hpp"
using namespace std;
using namespace NTL;
Vec<ZZ_p> DLP::elGamal_digital_signature(ZZ_p g, long x, long m)
{
    ZZ p_minus_1 = ZZ_p::modulus() - 1;
    // ZZ p = conv<ZZ>("17"); // all instances of the ZZ_p will have the fixed p value now
    ZZ_p::init(p_minus_1);

    Vec<ZZ_p> signature;

    // Choose y coprime with (p-1)
    ZZ_p y = random_ZZ_p();
    while (true)
    {
        ZZ yp = conv<ZZ>(y);
        if (GCD(yp, p_minus_1) == 1)
            break;
        y = random_ZZ_p(); // Random y in [0, p-2]
    }

    // Compute y inverse modulo (p-1)
    ZZ_p y_inv = inv(y);

    // Compute gamma = g^y mod p-1
    ZZ_p gamma = dlp(g, conv<long>(y));

    // Compute delta = (m - x*gamma) * y_inv mod (p-1)
    ZZ_p delta = (m - x * gamma) * y_inv;

    // ZZ m_zz = conv<ZZ>(m);
    // ZZ x_zz = conv<ZZ>(x);
    // ZZ temp = (m_zz - x_zz * gamma) % p_minus_1; // (m - x*gamma) mod (p-1)
    // ZZ delta = (temp * y_inv) % p_minus_1;
    // ZZ_p delta = conv<ZZ_p>((m_zz - x_zz * rep(gamma)) * y_inv % p-1);

    signature.append(gamma);
    signature.append(delta);

    return signature;
}
bool DLP::digital_signal_verification(Vec<ZZ_p> gamma_del, ZZ_p g, long m, long x)
{
    ZZ_p rhs = power(g, m);
    ZZ_p h = power(g, x);
    ZZ_p lhs = power(h, conv<long>(gamma_del[0])) * power(gamma_del[0], conv<long>(gamma_del[1]));

    return lhs == rhs;
}