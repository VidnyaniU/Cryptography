#include "RSA.hpp"

using namespace std;

RSA::RSA(long keySize)
{
    GenerateKeys(keySize);
}

void RSA::GenerateKeys(long keySize)
{

    // Step 1: Generate two random primes p and q
    // p = RandomPrime_ZZ(keySize);
    // q = RandomPrime_ZZ(keySize);
    p = 3;
    q = 7;

    // n = p * q
    n = p * q;

    // phi = (p-1) * (q-1)
    phi = (p - 1) * (q - 1);

    a = ZZ(1);
    while (GCD(a, phi) != 1)
    {
        a++;
    }

    b = InvMod(a, phi);
}

ZZ RSA::RSA_Encrypt(ZZ message)
{
    return PowerMod(message, b, n);
}
ZZ RSA::RSA_Decrypt(ZZ ciphertext)
{
    return PowerMod(ciphertext, a, n);
}
ZZ RSA::RSA_Sign(ZZ message)
{
    return PowerMod(message, a, n);
}
bool RSA::RSA_Verify(ZZ message, ZZ signature)
{
    return PowerMod(message, b, n) == signature;
}