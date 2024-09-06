#include <bits/stdc++.h>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

using namespace NTL;
using namespace std;
// void fun()
// {
//     ZZ_p c, d;
// }
int main()
{
    // ulong num = 18446744073709551615; // largest integer in 64 bit machine 2^64 -1
    // cout << "num :: " << num << endl;
    // ZZ a = conv<ZZ>("18446744073709551615");
    // cout << "a :: " << a << endl;
    // ZZ a_sqr = a*a;
    // cout << "a square:: " << a*a << endl;

    // for (int i = 1; i <= 50; i++)
    // {
    //     a *= a;
    //     cout << "a^" << i << " :: " << a << endl;
    // }

    ZZ p = conv<ZZ>("11"); // all instances of the ZZ_p will have the fixed p value now

    ZZ_p::init(p);
    ZZ_p a, b;

    // a = conv<ZZ_p>("5");

    // G
    ZZ_p g = conv<ZZ_p>("2");
    long x = 5;
    ZZ_p h;

    power(h, g, x); // h = g^x

    cout << "g :: " << g << "x :: " << x << "h :: " << h << endl;

    // brute force attack on DLP
    bool flag = false;
    for (int i = 1; i <= p; i++)
    {
        ZZ_p h2;
        power(h2, g, i);
        if (h2 == h)
        {
            cout << "DLP SOLVED!! \n  x :: " << i << endl;
            flag = true;
            break;
        }
    }

    if (!flag)
        cout << "DLP NOT SOLVED!!" << endl;
    return 0;
}