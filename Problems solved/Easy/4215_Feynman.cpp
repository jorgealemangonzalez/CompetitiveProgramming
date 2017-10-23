#include <bits/stdc++.h>
using namespace std;

int v[101];

void generarNumeros() {
	v[0] = 0;
	v[1] = 1;
	for(int i = 2; i < 101; ++i) {
		v[i] = v[i-1] + i*i;
	}
}

int main() {
	int n;
	generarNumeros();

	while(cin >> n and n != 0) {
		cout << v[n];
		cout << endl; 
	}
}