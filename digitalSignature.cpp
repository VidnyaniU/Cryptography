#include "DLP.hpp"
using namespace std;
using namespace NTL;
Vec<ZZ_p> DLP::elGamal_digital_signature(ZZ_p g, long x, long m)
{

    // here we need everything as mod(p-1)

    // choose y coprime with (p-1)

    // get y inverse

    // find gamma = g^y

    // del = (m - x*gamma)(y inverse)

    // return gamma , del
}

bool DLP::digital_signal_verification(Vec<ZZ_p> gamma_del, ZZ_p g, long m, long x)
{
    ZZ_p rhs = power(g, m);
    ZZ_p h = power(g, x);
    ZZ_p lhs = power(h, conv<long>(gamma_del[0])) * power(gamma_del[0], conv<long>(gamma_del[1]));

    return lhs == rhs;
}