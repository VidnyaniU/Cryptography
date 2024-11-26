#include <bits/stdc++.h>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

using namespace std;

void rho(ZZ_p h, ZZ_p g, ZZ_p r, ZZ_p a, ZZ_p b)
{
    if (r % 3 == 1)
    {
        r = pow(h, r);
        b = b + 1;
    }

    else if (r % 3 == 0)
    {
        r = pow(r, r);
        a = 2 * a;
        b = 2 * b;
    }
    else if (r % 3 == 2)
    {
        r = g * r;
        a = a + 1;
    }
}

tuple<ZZ_p, ZZ_p> pollardRho(ZZ_p g, ZZ_p h, ZZ_p r0, ZZ_p a0, ZZ_p b0)
{
    unordered_map<ZZ_p, pair<ZZ_p, ZZ_p>> r_map;
    r_map[r0] = {a0, b0}; // Store the initial state

    while (true)
    {
        // Update r0, a0, b0 using the rho function
        rho(h, g, r0, a0, b0);

        // Check if r0 has been seen before
        if (r_map.find(r0) != r_map.end())
        {
            // Found a cycle, return r0, a0, b0
            return make_tuple(a0, b0);
        }

        r_map[r0] = {a0, b0};
    }
}
int main()
{
    ZZ p = conv<ZZ>("29"); // all instances of the ZZ_p will have the fixed p value now
    ZZ_p::init(p);

    ZZ_p g = 3, h = 4, r0 = 1, a0 = 0, b0 = 0;
    ZZ_p[a, b] = pollardRho(g, h, r0, a0, b0);
    ZZ_p x = ()

        return 0;
}