#include <NTL/ZZ.h>
#include <NTL/EllipticCurve.h>
#include <iostream>
#include <random>

using namespace NTL;
using namespace std;

// Function to generate random numbers in a range
ZZ randomZZ(const ZZ& limit) {
    static random_device rd;
    static mt19937_64 gen(rd());
    uniform_int_distribution<long long> dis(0, to_long(limit) - 1);
    return ZZ(dis(gen));
}

// Struct for an elliptic curve point with coefficients
struct ECPoint {
    ZZ x, y;
    ZZ a, b; // Coefficients of the linear combination Q = aP + bG
};

