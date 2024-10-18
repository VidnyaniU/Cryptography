#include <bits/stdc++.h>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

using namespace std;
using namespace NTL;
// point struct
struct Point
{
    ZZ_p x, y;
};
class EC
{
public:
    Point point_addition_doubling(Point P, Point Q);
    Point scalar_multiplication(ZZ_p m, Point P);
    // encryption-decryption
    Point *elGamal_encryption_over_EC(Point P, long x, Point msg);
    Point elGamal_decryption_over_EC(Point C1_C2[2], long x);
    // ECDSA
    ZZ_p *signature_generation(Point P, ZZ q, long x, ZZ m);
    bool verification(Point P, Point Q, ZZ_p signature[2], ZZ_p m, ZZ q);
};