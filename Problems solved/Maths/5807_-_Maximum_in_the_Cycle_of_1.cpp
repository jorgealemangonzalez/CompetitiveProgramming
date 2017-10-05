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
unsigned long long binomial[21][21] = {0};


void create_binom(){
    binomial[0][0] = 1;
    binomial[1][1] = 1;
    binomial[1][0] = 1;
    for(int i = 2 ; i < 21 ; ++i){
        binomial[i][0] = 1;
        binomial[i][i] = 1;
        for(int j = 1 ; j < i; ++j){
            binomial[i][j] = binomial[i-1][j-1] + binomial[i-1][j];
        }
    }
}

unsigned long long getBinom(int n , int k){
    // (n , k) binom value
    if(n <= k || min(n,k) <= 0)
        return 1;
    return binomial[n][k];
}

unsigned long long factorial(int i){
    if( i <= 1 )
        return 1;
    return i * factorial( i-1 );
}

unsigned long long Lvalue(unsigned int L, unsigned int n , unsigned int k){
    if(k == 1)
        return factorial(n-1);
    if( L == 1 )    //Just if k = 1 lenght could be 1
        return 0;
    return getBinom(k-2,L-2)*factorial(L-1)*factorial(n-L);

}

int main() {
#ifdef _DEBUG
    in  = new ifstream("entrada.txt");
    out = new ofstream("salida.txt");
    cin.rdbuf(in->rdbuf());
    cout.rdbuf(out->rdbuf());
#endif
    create_binom();
    /*
    for(int i = 0 ; i < 21 ; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << binomial[i][j] << " ";
        cout<< endl;
    }
     */
    unsigned int c;
    cin>>c;
    while(c--){
        unsigned int nc;
        cin>>nc;
        cout<<nc<<" ";
        unsigned int n , k ;
        cin>>n>>k;

        unsigned long long acum = 0;
        for(unsigned l = 1; l <= k ; ++l ){
            acum += Lvalue(l,n,k);
        }
        cout<<acum<<endl;
    }
}