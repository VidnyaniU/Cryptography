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
};