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
#define RFOR(i,x,y) for(int i=(int)y-1; i>=(int)x; i--)
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define IN(a,pos,c) insert(a.begin()+pos,1,c)
#define DEL(a,pos,cant) erase(a.begin()+pos,cant)

int exponential[11];

void rec(int multiplic, int pos) {
    // base case
    string s;
    while(cin >> s) {
        if(s == "END") {
            return;
        }

        if(s == "LOOP") {
            cin >> s;
            if(s == "n") {
                rec(multiplic, pos+1);
            }
            else {
                int n = stoi(s);
                rec(multiplic*n, pos);
            }
        }
        if(s == "OP") {
            int n;
            cin >> n;
            exponential[pos] += n*multiplic;
        }
    }
}



int main() {
#ifdef _DEBUG
    in  = new ifstream("entrada.txt");
    out = new ofstream("salida.txt");
    cin.rdbuf(in->rdbuf());
    cout.rdbuf(out->rdbuf());
#endif

    int cases;
    cin >> cases;
    int num = 1;
    while(cases--) {
        FOR(i,0,11) exponential[i] = 0;
        string s;
        cin >> s;
        rec(1,0);
        bool notfirst = false;
        cout << "Program #" << num++ << endl;
        cout << "Runtime = ";
        RFOR(i,0,11) {

            if(exponential[i] == 0)
                continue;
            switch(i) {
                case 0:
                    if(notfirst)
                        cout<<"+";
                    cout << exponential[i];
                    break;
                case 1:
                    if(notfirst)
                        cout<<"+";
                    if(exponential[i] > 1)
                        cout << exponential[i] << "*";
                    cout << "n";
                    break;
                default:
                    if(notfirst)
                        cout<<"+";
                    if(exponential[i] > 1)
                        cout << exponential[i]<< "*";
                    cout << "n^" << i;
                    break;
            }
            notfirst =true;
        }
        if(!notfirst) cout << 0;
        cout << endl;
        cout << endl;
    }
}
