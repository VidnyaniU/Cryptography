#include "DLP.hpp"

using namespace std;
using namespace NTL;

DLP::DLP()
{
    // ZZ p = conv<ZZ>(); // all instances of the ZZ_p will have the fixed p value now
    // ZZ_p::init(p);
    // ZZ_p g = conv<ZZ_p>("2");
}

ZZ_p DLP ::dlp(ZZ_p g, long x)
{
    ZZ_p h;
    power(h, g, x);
    return h;
}