#include "DLP.hpp"

using namespace std;
using namespace NTL;

int main()
{
    // string _p = "11";
    ZZ p = conv<ZZ>("467"); // all instances of the ZZ_p will have the fixed p value now
    ZZ_p::init(p);
    ZZ_p g = conv<ZZ_p>("2");
    DLP obj1;

    /*

    long a = 3, b = 2; // a and b are secret keys of Alice and Bob
    ZZ_p Alice = obj1.diffie_hellman_encryption(g, a);
    ZZ_p Bob = obj1.diffie_hellman_encryption(g, b);

    cout << "Encrypted message of Alice :: " << Alice << endl;
    cout << "Encrypted message of Bob :: " << Bob << endl;

    ZZ_p Alice_dash = obj1.diffie_hellman_decryption(Bob, a);
    ZZ_p Bob_dash = obj1.diffie_hellman_decryption(Alice, b);

    if (Alice_dash == Bob_dash)
        cout << "Decryption Successful!" << endl;

*/
    // Alice sends message m to Bob
    long m = 100;
    long x = 127;
    /*

        Vec<ZZ_p> encrypted_message = obj1.elGamal_encryption(g, x, m);
        cout << "\nC1 :: " << encrypted_message[0] << "\nC2 :: " << encrypted_message[1] << endl;

        // Decryption of message at Bob's end
        ZZ_p decrypted_message = obj1.elGamal_decryption(encrypted_message, x);
        cout << "Decrypted message :: " << decrypted_message << endl;
    */
    Vec<ZZ_p> sign = obj1.elGamal_digital_signature(g, x, m);
    cout << "gamma :: " << sign[0] << "delta :: " << sign[1] << endl;
    if (obj1.digital_signal_verification(sign, g, x, m) == 1)
        cout << "Digital signature verified!!" << endl;
    return 0;
}