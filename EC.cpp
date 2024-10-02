#include "EC.hpp"

using namespace std;
using namespace NTL;

Point EC::point_addition(Point P, Point Q)
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
        cout << "Lines are parallel!" << endl;
    }
    R.x = (lambda * lambda) - P.x - Q.x;
    R.y = lambda * (P.x - R.x) - P.y;

    return R;
}

Point EC::scalar_multiplication(ZZ_p m, Point P)
{
    Point Q;

    // initialize Q at infinity
    Q.x = 0, Q.y = 1;
    Point Pt = P;
    ZZ temp = conv<ZZ>(m);
    /*
    while (temp > 0)
    {
        if (temp % 2 == 1)
        {
            cout << "For " << temp % 2 << " :: " << endl;
            Q = point_addition(Pt, Q); // Add
            cout << "Add :: Q = (" << Q.x << "," << Q.y << ")" << endl;
        }
        // double
        Q = point_addition(Pt, Pt);
        cout << "Double :: Q = (" << Q.x << "," << Q.y << ")" << endl;

        temp /= 2;
    }*/
    long num_bits = NumBits(temp); // Get the number of bits in k

    // Iterate from the most significant bit to the least significant bit
    for (long i = num_bits - 1; i >= 0; --i)
    {
        Q = point_addition(Q, Q); // Always double the Q

        if (bit(temp, i) == 1)
        { // If the ith bit is 1, add the point P
            Q = point_addition(Q, Pt);
        }
    }
    return Q;
}
