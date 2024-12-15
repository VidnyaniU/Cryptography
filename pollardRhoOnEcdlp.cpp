#include <NTL/ZZ.h>
#include <iostream>
#include <stdexcept>
#include <random>
#include <cryptography.hpp>

using namespace NTL;
using namespace std;

// Function to generate random numbers in a range
ZZ randomZZ(const ZZ &limit)
{
    static random_device rd;
    static mt19937_64 gen(rd());
    uniform_int_distribution<long long> dis(0, to_long(limit) - 1);
    return ZZ(dis(gen));
}

// Class for an elliptic curve over a prime field
class EllipticCurve
{
public:
    ZZ a, b, p; // Curve parameters: y^2 = x^3 + ax + b (mod p)

    EllipticCurve(const ZZ &a, const ZZ &b, const ZZ &p) : a(a), b(b), p(p) {}

    // Add two points on the curve
   

    // Double a point on the curve
  
};

// Pseudo-random partitioning function
int partition(const ZZ &x, int numPartitions)
{
    return to_long(x % numPartitions);
}

// Pollard Rho Algorithm for ECDLP
ZZ pollardsRhoECDLP(const EllipticCurve &E, const Point &G, const Point &Q, const ZZ &n)
{
    int numPartitions = 3; // Number of partitions
    Point Tortoise = G, Hare = G;

    // Initialize random coefficients a, b for Tortoise and Hare
    Tortoise.a = randomZZ(n);
    Tortoise.b = randomZZ(n);
    Hare.a = randomZZ(n);
    Hare.b = randomZZ(n);

  //randon walk generation

    while (true)
    {
        // Tortoise once, Hare twice
        step(Tortoise);
        step(Hare);
        step(Hare);

        if (Tortoise.x == Hare.x && Tortoise.y == Hare.y)
        {
            // Found a collision
            ZZ deltaA = (Hare.a - Tortoise.a) % n;
            ZZ deltaB = (Tortoise.b - Hare.b) % n;

            if (deltaB == 0)
            {
                throw runtime_error("Collision with zero difference in coefficients!");
            }

            // Solve deltaA = k * deltaB mod n
            ZZ k;
            InvMod(k, deltaB, n); // Inverse of deltaB mod n
            k = (deltaA * k) % n;

            return (k + n) % n;
        }
    }
}

int main()
{
    ZZ a = conv<ZZ>("2");
    ZZ b = conv<ZZ>("3");
    ZZ p = conv<ZZ>("97"); // Prime field
    EllipticCurve E(a, b, p);

    // Generator point G
    Point G{conv<ZZ>("3"), conv<ZZ>("6"), ZZ(0), ZZ(0)};

    // Target point Q
    Point Q{conv<ZZ>("80"), conv<ZZ>("10"), ZZ(0), ZZ(0)};

    ZZ n = conv<ZZ>("19"); // Order of the subgroup

    try
    {
        ZZ result = pollardsRhoECDLP(E, G, Q, n);
        cout << "Discrete log: " << result << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
