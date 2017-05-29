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
#define FOR(i,N) for(int i = 0 ; i < N ; ++i)

typedef unsigned int UI ;
typedef pair<UI,pair< UI,UI > > ppUI;

int main()
{
    #ifdef _DEBUG

     in  = new ifstream("entrada.txt");
     out = new ofstream("salida.txt");
     cin.rdbuf(in->rdbuf());
     cout.rdbuf(out->rdbuf());
    #endif

    int employees;
    while(cin>>employees){
        cin.ignore();
        vector<vector<UI> > emp(employees,vector<UI>());

        for(UI i = 0 ; i < employees ; ++i){
            int n_conn;
            cin>>n_conn;
            int conexion;
            while(n_conn--){
                cin>>conexion;
                emp[i].push_back(conexion);
            }
        }
        /* Test
        FOR(i,emp.size()){
            cout<<"Emp "<<i<<":";
            FOR(j,emp[i].size()){
                cout<<emp[i][j]<<" ";
            }
            cout<<endl;
        }
         */

        UI test_cases;
        cin>>test_cases;
        while(test_cases--){
            bool visited[employees]; //All false
            FOR(vi,employees)
                visited[vi] = false;
            queue<pair<UI,UI> > que; // empID , layer
            UI start_e;
            cin>>start_e;

            que.push(MP(start_e,0));
            UI max_dialy = 0 , first_max_dialy = 0, actual_layer = 0, accum_layer = 0;
            visited[start_e] = true;
            while(!que.empty()){

                //cout<<"max_dialy "<< max_dialy <<" first_max_dialy "<<first_max_dialy<<" actual_layer "<<actual_layer<<" accum_layer "<<accum_layer<<endl;
                pair<UI,UI> employe = que.front();
                que.pop();
                if(actual_layer != employe.second){
                    if(accum_layer > max_dialy && actual_layer != 0){
                        max_dialy = accum_layer;
                        first_max_dialy = actual_layer;
                    }
                    actual_layer = employe.second;
                    accum_layer = 0;
                }
                FOR(i,emp[employe.first].size()){
                    if(!visited[emp[employe.first][i]]){
                        que.push(MP(emp[employe.first][i],employe.second+1));

                        visited[emp[employe.first][i]] = true;
                    }
                }
                accum_layer++;
            }

            if(accum_layer > max_dialy && actual_layer != 0){
                max_dialy = accum_layer;
                first_max_dialy = actual_layer;
            }

            if(max_dialy == 0)
                cout<<"0"<<endl;
            else
                cout<<max_dialy<<" "<<first_max_dialy<<endl;
        }
    }
}
