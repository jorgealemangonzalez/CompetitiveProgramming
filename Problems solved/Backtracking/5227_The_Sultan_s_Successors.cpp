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

#define Y second
#define X first
#define MP make_pair
#define SZ size()
#define PB push_back
#define VI vector<int>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define CUBE(a) ((a)*(a)*(a))
#define SQ(a) ((a)*(a))
#define FOR(i,N) for(int i = 0 ; i < N ; ++i)


int values[8][8];

bool attack(int q1,int q2){
    //cout<<q1<<" "<<q2<<endl;
    int q1x = int(q1 / 8), q1y = int(q1 % 8);
    int q2x = int(q2 / 8), q2y = int(q2 % 8);
    //cout<<q1x<<" "<<q1y<<endl<<q2x<<" "<<q2y<<endl;
    //Same column or row
    if(q1x == q2x || q1y == q2y)
        return true;
    //Diagonal
    if(abs(q1x - q2x) == abs(q1y-q2y))
        return true;
    return false;
}
void printvector(vector<int>& v){
    FOR(i,v.size()){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int maxQueensValue = 0;

void maxOrdered(vector<int>& queens){
    if(queens.size() == 8){
        int value = 0;
        FOR(q,queens.size()){
            value += values[int(queens[q] / 8)][int(queens[q] % 8)];
        }
        //cout<<value<<endl;
        maxQueensValue = MAX(maxQueensValue,value);
        //printvector(queens);
        return;
    }
    //TODO max of all iterations
    int queen = 0;
    if(queens.size())
        queen = queens[queens.size()-1]+1;
    for(; queen < 64 ; ++queen){  //Fila
        if(!queens.size()){
            queens.push_back(queen);
            maxOrdered(queens);
            queens.pop_back();
        }else{
            int no_attack = 0;

            FOR(q,queens.size()){
                if(!attack(queens[q],queen)){
                    no_attack++;
                }else break;
            }
            //cout<<"no_attack "<<no_attack<<endl;
            if(no_attack == queens.size()){
                queens.push_back(queen);
                maxOrdered(queens);
                queens.pop_back();
            }

        }
    }
}

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
        maxQueensValue= 0;
        FOR(i,8){
            FOR(j,8){
                cin>>values[i][j];
            }
        }
        vector<int> quuu;
        maxOrdered(quuu);
        printf("%5d\n",maxQueensValue);

    }

}
