
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

typedef pair< pair<int,int>, pair<int,int> > P;
int main()
{
    #ifdef _DEBUG

     in  = new ifstream("entrada.txt");
     out = new ofstream("salida.txt");
     cin.rdbuf(in->rdbuf());
     cout.rdbuf(out->rdbuf());
    #endif

    int slept , connections;
    while(cin>>slept){
        cin>>connections;
        map<char,vector<char> > con;
        map<char,int> stimuled; //3 = stimuled

        char direct1,direct2,direct3;
        cin>>direct1>>direct2>>direct3;
        stimuled[direct1] = 3;
        stimuled[direct2] = 3;
        stimuled[direct3] = 3;

        char conx,cony;
        FOR(i,connections){
            cin>>conx>>cony;
            stimuled[conx];
            con[conx].push_back(cony);
            con[cony].push_back(conx);
        }

        queue<pair<int,char> > bfs;
        bfs.push(MP(0,direct1));
        bfs.push(MP(0,direct2));
        bfs.push(MP(0,direct3));
        set<char> visited;
        visited.insert(direct1);
        visited.insert(direct2);
        visited.insert(direct3);
        int years = 0, waked_up = 3;
        while(!bfs.empty()){
            pair<int,char> p = bfs.front(); bfs.pop();
            years = MAX(years,p.X);
            vector<char> &connected = con[p.Y];
            FOR(i,connected.SZ){
                char next = connected[i];
                stimuled[next]++;
                if(stimuled[next] >= 3 && visited.find(next) == visited.end()){
                    bfs.push(MP(p.X+1,next));
                    visited.insert(next);
                    waked_up++;
                }
            }
        }
        if(waked_up == slept){
            cout<<"WAKE UP IN, "<<years<<", YEARS"<<endl;
        }else
            cout<<"THIS BRAIN NEVER WAKES UP"<<endl;

    }
}
