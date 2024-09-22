#include "DLP.hpp"

using namespace std;
using namespace NTL;

int main()
{
    // string _p = "11";
    ZZ p = conv<ZZ>("11"); // all instances of the ZZ_p will have the fixed p value now
    ZZ_p::init(p);
    ZZ_p g = conv<ZZ_p>("2");
    DLP obj1;

    long a = 3, b = 2; // a and b are secret keys of Alice and Bob
    ZZ_p Alice = obj1.diffie_hellman_encryption(g, a);
    ZZ_p Bob = obj1.diffie_hellman_encryption(g, b);

    cout << "Encrypted message of Alice :: " << Alice << endl;
    cout << "Encrypted message of Bob :: " << Bob << endl;

    ZZ_p Alice_dash = obj1.diffie_hellman_decryption(Bob, a);
    ZZ_p Bob_dash = obj1.diffie_hellman_decryption(Alice, b);

    if (Alice_dash == Bob_dash)
        cout << "Decryption Successful!" << endl;

    return 0;
}