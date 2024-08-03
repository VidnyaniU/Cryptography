#include <bits/stdc++.h>

using namespace std;

class HillCipher
{

public:
    string message;
    int n = message.length();
    vector<vector<int>> key(n, vector<int>(n));

    vector<int> matrix_multiplication(vector<vector<int>> key, vector<int> M);
    vector<vector<int>> get_inverse_matrix(vector<vector<int>> key);

    string encrypt(string message, vector<vector<int>> key);
    string decrypt(string cipher_text, vector<vector<int>> key);
}