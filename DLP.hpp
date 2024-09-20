#include <bits/stdc++.h>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

using namespace std;
using namespace NTL;
class DLP
{
public:
    DLP(string _p); //pass the prime as a string
    ZZ_p dlp(ZZ_p g, long x);
    void diffie_hellman(ZZ_p g);
};