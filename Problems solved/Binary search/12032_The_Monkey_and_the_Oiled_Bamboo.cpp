#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG

   #include <fstream>

   istream * in;
   ostream * out;
#endif

#define Y second
#define X first
#define O second
#define I first
#define MP make_pair
#define SZ size()
#define PB push_back
#define VI vector<int>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define CUBE(a) ((a)*(a)*(a))
#define SQ(a) ((a)*(a))
#define FOR(i,N) for(int i = 0 ; i < N ; ++i)
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int N;
unsigned int rugs[1000000];


bool posible(int k){
    int difer;
    for(int i = 1;i < N; ++i){
        difer = rugs[i] - rugs[i-1];
        if(difer > k)
            return false;
        if(difer == k)
            k--;
    }
    return true;
}

int main()
{
    #ifdef _DEBUG

     in  = new ifstream("entrada.txt");
     out = new ofstream("salida.txt");
     cin.rdbuf(in->rdbuf());
     cout.rdbuf(out->rdbuf());
    #endif

    int cases, c = 1;
    cin>>cases;
    rugs[0] = 0;
    while(c++ <= cases){
        cin>>N;
        N++;
        for(int i = 1 ; i < N ; ++i)
            cin>>rugs[i];

        int low = 0 , up = 1000000000, med;
        while(low+1 != up){
            med = (up-low)/2 + low;
            if(posible(med)){
                up = med;
            }else
                low = med;
        }
        cout<<"Case "<<c-1<<": "<<(posible(low)? low : up)<<endl;
    }
}
