#include <bits/stdc++.h>
using namespace std;


vector<int> getPrimosSuma (int c) {
    int z = 2;
    vector<int> primeFactors;
    // Se obtiene la factorizacion de c.
    while (z * z <= c) {
        if (c % z == 0) {
            primeFactors.push_back(z);
            c /= z;
        }
        else z++;
    }

    if (c > 1) primeFactors.push_back(c);
    return primeFactors;
}

int main() {
    vector<int> res = getPrimosSuma(4937775);
    for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
    cout << endl;
}