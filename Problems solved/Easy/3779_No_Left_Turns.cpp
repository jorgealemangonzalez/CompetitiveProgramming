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

    int cases;
    cin>>cases;
    while(cases--){
        int lines, col;
        cin>>lines>>col;
        cin.ignore();
        char tab[lines][col];
        pair<int,int> s;
        string line;
        FOR(i,lines){
            getline(cin,line);
            FOR(j,col){
                tab[i][j] = line[j];
                if(tab[i][j] == 'S')
                    s = MP(i,j);
            }
        }

        queue<P> q;
        q.push(MP(MP(1,RIGHT),MP(s.X+1,s.Y)));
        q.push(MP(MP(1,LEFT),MP(s.X-1,s.Y)));
        q.push(MP(MP(1,UP),MP(s.X,s.Y+1)));
        q.push(MP(MP(1,DOWN),MP(s.X,s.Y-1)));
        P sol;
        set< pair<int,pair<int,int> > > visited;
        while(!q.empty()){
            P actual = q.front(); q.pop();
            pair<int,pair<int,int> > actual_visit = MP(actual.I.Y,actual.O);
            if(tab[actual.O.X][actual.O.Y] == 'F'){
                sol = actual;
                break;
            }
            if(tab[actual.O.X][actual.O.Y] == 'X' || visited.find(actual_visit) != visited.end())
                continue;
            pair<int,int> s = actual.O;
            int moves = actual.I.X+1;
            switch(actual.I.Y){
                case RIGHT:
                    q.push(MP(MP(moves,DOWN),MP(s.X,s.Y-1)));
                    q.push(MP(MP(moves,RIGHT),MP(s.X+1,s.Y)));
                    break;
                case LEFT:
                    q.push(MP(MP(moves,UP),MP(s.X,s.Y+1)));
                    q.push(MP(MP(moves,LEFT),MP(s.X-1,s.Y)));
                    break;
                case UP:
                    q.push(MP(MP(moves,RIGHT),MP(s.X+1,s.Y)));
                    q.push(MP(MP(moves,UP),MP(s.X,s.Y+1)));
                    break;
                case DOWN:
                    q.push(MP(MP(moves,LEFT),MP(s.X-1,s.Y)));
                    q.push(MP(MP(moves,DOWN),MP(s.X,s.Y-1)));
                    break;

            }
            visited.insert(actual_visit);
        }
        cout<<sol.I.X<<endl;
    }
}
