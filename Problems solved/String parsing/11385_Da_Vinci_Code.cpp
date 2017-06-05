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

map<unsigned long long,unsigned long long> fibo;

#define INDEX first
#define NUM second

void init(){
    unsigned long long i = 3, maxi = pow(2,31),a = 1, b = 2,c;
    fibo[a] = 1;
    fibo[b] = 2;
    while(true){
        fibo[a+b] = i++;
        c = a;
        a=b;
        b=c+b;
        if(b > maxi)
            break;
    }
}

int main() {
    int cases;
    init();
    cin>>cases;
    while(cases--){
        int N;
        cin>> N;
        unsigned long long numbers[N];
        FOR(i,0,N){
            cin>>numbers[i];
        }

        string lin;
        getline(cin,lin);
        getline(cin,lin);
        char sol[105];  //El primer char no cuenta
        FOR(i,0,105)
            sol[i] = '#';

        priority_queue<pair<unsigned long long, unsigned long long> > pq;
        int j=0;
        FOR(i,0,lin.length()){
            if(lin[i] >= 'A' && lin[i] <= 'Z'){
                unsigned long long f = fibo[numbers[j]];
                sol[f] = lin[i];
                pq.push(MP(f,numbers[j]));
                j++;
            }
            if(j >= N) {
                break;
            }
        }

        unsigned long long prev = 0;

        if(pq.size() > 1)
            while(!pq.empty()){
                pair<unsigned long long, unsigned long long> p = pq.top();  //El mas grande esta arriba
                pq.pop();
                if(prev == 0){
                    prev = p.INDEX;
                }else{
                    prev--;
                    if(prev != p.INDEX){
                        while(prev != p.INDEX){
                            sol[prev--] = ' ';
                        }
                    }
                }
            }
        else{
            prev = pq.top().INDEX;
        }
        prev--;
        while(prev >= 1){
            sol[prev--] = ' ';
        }

        FOR(i,1,101){
            if(sol[i] == '#')
                break;
            else cout<<sol[i];
        }
        cout<<endl;

    }
    return 0;
}