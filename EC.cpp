#include "EC.hpp"

using namespace std;
using namespace NTL;

Point EC::point_addition_doubling(Point P, Point Q)
{
    Point R;
    ZZ_p lambda;
    // P!=Q
    if (P.x != Q.x || P.y != Q.y)
        lambda = (Q.y - P.y) * inv(Q.x - P.x);
    // P=Q
    else if (P.x == Q.x && P.y == Q.y)
    {
        int a = 1;
        lambda = (3 * P.x * P.x + a) * inv(2 * P.y);
    }

    if (lambda == 0)
    {
        R.x = 0, R.y = 1;
        // cout << "Lines are parallel!" << endl;
        return R;
    }
    R.x = (lambda * lambda) - P.x - Q.x;
    R.y = lambda * (P.x - R.x) - P.y;

    return R;
}

Point EC::scalar_multiplication(ZZ_p m, Point P)
{
    Point Q = P;
    ZZ temp = conv<ZZ>(m);

    long num_bits = NumBits(temp); // number of bits
    // cout << "Q :: (" << Q.x << "," << Q.y << ")" << endl;

    for (long i = num_bits - 2; i >= 0; --i) // from msb to lsb
    {
        // cout << "bit at " << i << "th position :: " << bit(temp, i) << endl;
        // Double the  Q
        Q = point_addition_doubling(Q, Q);
        // cout << "Q :: (" << Q.x << "," << Q.y << ")" << endl;
        // Check the ith bit
        if (bit(temp, i) == 1)
        {
            // If the bit is 1, add the point P to Q
            Q = point_addition_doubling(Q, P);
            // cout << "Q :: (" << Q.x << "," << Q.y << ")" << endl;
        }
    }

    return Q;
}
