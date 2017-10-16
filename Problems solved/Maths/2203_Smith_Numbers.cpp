#include <bits/stdc++.h>
using namespace std;

int MAXLEN = 78498;
//int v[] = {1,2}; // primes
int v[100000];
int sumaDigitos(int n) {
    int r = 0;
    while(n!=0) {
        r += n%10;
        n /= 10;
    }
    return r;
}

void savePrimes()
{
    int k = 0;
    v[k++] = 2;
    for (int i = 3; i < 1000000; i += 2) {
        bool b = true;
        for (int j = 0; b && v[j] * v[j] <= i; j++)
            b = i%v[j] > 0;
        if (b)
            v[k++] = i;
    }
    
}

bool isPrime(int x){
	bool prime = true;
	for (int j = 0; prime && v[j] * v[j] <= x; j++)
		prime = x%v[j] > 0;
	return prime;
}

int getPrimosSuma (int c) {
    int suma = 0;
    int z = 2;

    while (z * z <= c) {
        if (c % z == 0) {
            suma += sumaDigitos(z);
            c /= z;
        }
        else z++;
    }

    if (c > 1) suma += sumaDigitos(c);

    return suma;
}

int nextSmith(int c) {
    int sumaNumeros = sumaDigitos(c);
    int sumaPrimo = getPrimosSuma(c);

    if(sumaNumeros == sumaPrimo && !isPrime(c)) return c;
    else return 0;
}

int main()
{
    savePrimes();
    int n;
    cin >> n;

    while(n--) {
        int c;
        cin >> c;
        int res = 0;

        while (res == 0) {
            res = nextSmith(++c);
        }
        cout << res << endl;
    }
}
