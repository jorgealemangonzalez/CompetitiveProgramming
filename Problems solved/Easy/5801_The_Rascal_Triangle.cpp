#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG

#include <fstream>

istream * in;
ostream * out;
#endif


#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define FOR(i,x,y) for(int i=(int)x; i<(int)y; i++)
#define RFOR(i,x,y) for(int i=(int)x; i>(int)y; i--)
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define IN(a,pos,c) insert(a.begin()+pos,1,c)
#define DEL(a,pos,cant) erase(a.begin()+pos,cant)

#define INDEX first
#define NUM second

int main() {
#ifdef _DEBUG
    in  = new ifstream("entrada.txt");
    out = new ofstream("salida.txt");
    cin.rdbuf(in->rdbuf());
    cout.rdbuf(out->rdbuf());
#endif
    int P;
    cin >> P;
    while(P--) {
        unsigned LI d,n,m;
        cin >> d >> n >> m;
        cout << d << " " << 1+(n-m)*m;
        if(P) cout << endl;
    }

}