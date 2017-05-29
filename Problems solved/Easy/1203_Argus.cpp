#include <iostream>
#include<cctype>
#include<ctype.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<fstream>
#include<map>
#include<set>
#include<queue>
#include<stdio.h>
#include<cstring>
#include<sstream>
#include<locale>
#include<utility>
#include<list>
using namespace std;

#ifdef _DEBUG

   #include <fstream>

   istream * in;
   ostream * out;
#endif

#define MP make_pair
#define VI vector<int>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define CUBE(a) ((a)*(a)*(a))
#define SQ(a) ((a)*(a))

typedef unsigned int UI ;
typedef pair<UI,pair< UI,UI > > ppUI;

class mycomparison
{

public:

  bool operator() (const ppUI& lhs, const ppUI&rhs) const
  {
    if(lhs.second.second == rhs.second.second)
        return lhs.first > rhs.first;
    else
        return lhs.second.second > rhs.second.second;
  }

};

int main()
{
    #ifdef _DEBUG

     in  = new ifstream("entrada.txt");
     out = new ofstream("salida.txt");
     cin.rdbuf(in->rdbuf());
     cout.rdbuf(out->rdbuf());
    #endif


    string  action;
    priority_queue< ppUI,vector<ppUI>,mycomparison > tasks; //identifier , period, next call
    while(cin>>action){
        if(action == "#" && !tasks.empty()){
            UI prints;
            cin>>prints;
            while(prints--){
                ppUI p = tasks.top(); tasks.pop();
                cout<<p.first<<"\n";
                tasks.push(MP(p.first,MP(p.second.first,p.second.second+p.second.first)));
            }
            tasks = priority_queue< ppUI,vector<ppUI>,mycomparison >(); //Clear container
            continue;
        }
        if(action == "Register"){
            UI id, period;
            cin>>id>>period;
            tasks.push(MP(id,MP(period,period)));
        }
    }
}
