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

bool bisiesto[2101];
set<string> dates;

string addZero(string n){
    if(n.length() == 1)
        return "0"+n;
    return n;
}

void generate(){
    FOR(i,1900,2101)
        bisiesto[i] = (i%4==0 && !i%100==0) || (i%400 == 0);

    int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; // 1 index
    int d=1,m=1,y=1900;
    while( y != 2101){
        string ins;
        string yy=addZero(to_string(y)),mm=addZero(to_string(m)),dd=addZero(to_string(d));
        ins = yy+mm+dd;
        dates.insert(ins);

        if(bisiesto[y])
            months[2] = 29;
        else
            months[2] = 28;

        d++;
        if(d>months[m]){
            d = 1;
            m++;
            if(m>12){
                m = 1;
                y++;
            }
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
    int N;
    generate();
    while(cin>>N){
        if(N==0)break;
        int dias=0, gasto=0;
        string lastDay = "";
        int lastPay=0;
        FOR(i,0,N){
            string d,m,y, mapIx;
            int g;
            cin>>d>>m>>y>>g;

            string yy=addZero(y), mm = addZero(m),dd = addZero(d);
            mapIx = yy+mm+dd;
            if(lastDay == mapIx) {
                dias++;
                gasto+=g-lastPay;
            }

            if(mapIx == "21001231"){
                lastDay = "";
                continue;
            }

            auto it = dates.find(mapIx);
            it++;
            lastDay = (*it);
            lastPay = g;
        }
        cout<<dias<<" "<<gasto<<endl;
    }
}