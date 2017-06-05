#include <bits/stdc++.h>
using namespace std;


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


unsigned long long A[10001][10001];
void resetMatrix(unsigned int n){
    FOR(i,0,n){
        FOR(j,0,n){
            if(i == j)
                A[i][j]= 0;
            else
                A[i][j] = 120000;
        }
    }
}

void floydWarshal(unsigned int n){

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] = MIN(A[i][j], A[i][k] + A[k][j]);
}

int main() {
    unsigned int cases;
    cin>>cases;
    FOR(_case,0,cases){

        unsigned int N,R;
        cin>>N>>R;
        resetMatrix(N);

        unsigned long long a,b;
        FOR(i,0,R){
            cin>>a>>b;
            A[a][b] = 1;
            A[b][a] = 1;
        }

        floydWarshal(N);
        unsigned int source, dest;
        cin>>source>>dest;
        unsigned long long  maxdest= 0;
        FOR(i,0,N){
            maxdest = MAX(maxdest,A[source][i]+A[i][dest]);

        }
        cout<<"Case "<<_case+1<<": "<<maxdest<<endl;
    }
    return 0;
}