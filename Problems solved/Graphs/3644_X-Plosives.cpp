#include <bits/stdc++.h>
using namespace std;



int refuses, N, mf[1000002]; // numero de nodos N <= 10000002

int mapaFind(int n) { // conjunto conexo de n
    if (mf[n] == n) return n;
    else mf[n] = mapaFind(mf[n]); return mf[n];
}

bool mapaMerge(int n, int m) {
	int pN, pM;
	pN = mapaFind(n);
	pM = mapaFind(m);
	if(pN != pM) {
		mf[pM] = pN;
		return false;
	}
	else return true;
}

void inicializar() {
	for(int i = 0; i < 1000002; ++i) {
		mf[i] = i;
	}
	refuses = 0;
}

int main() {

	string s;
	inicializar();
	int n,m;
	while(cin >> n) {
		if(n == -1) {
			cout << refuses << endl;
			inicializar();
			continue;			
		}
		cin >> m;

		refuses += mapaMerge(n,m);
	}	
}