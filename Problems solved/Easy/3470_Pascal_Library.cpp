#include <bits/stdc++.h>
using namespace std;


void checkAssist(int N, int D) {
	vector<int> v(N);
	bool flag = false;
	for(int i = 0; i < D; ++i) {
		for(int j = 0; j < N; ++j) {
			int x;
			cin >> x;
			if(!flag) {
				v[j] += x;
				if(v[j] == D) {
					cout << "yes" << endl;
					flag = true;
				}
			}
		}
	}
	if(!flag) cout << "no" << endl;
}

	int main() {
		int N,D;
		while(cin >> N >> D and N != 0 and D != 0) {
			checkAssist(N,D);
		}
	}