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

set<unsigned long long> squares;

bool isSquare(unsigned long long s){
    //cout<<s<<" "<<(squares.find(s) != squares.end() ? "true" : "false");
    return squares.find(s) != squares.end();
}

bool isDigitSquare(unsigned long long s){
    stringstream ss;
    ss << s*s;
    string number = ss.str();
    unsigned long long sum = 0;
    for(int i =0 ; i< number.length() ; ++i){
        //cout<<number[i]<<".";
        sum += number[i] - '0';
    }
    //cout<<s<< " + "<<ss.str() <<" - "<<sum<<endl;
    return isSquare(sum);
}

unsigned long long nextSquaredNum(unsigned long long n){
    while(!isDigitSquare(n))
        n++;
    return n;
}

int main() {
#ifdef _DEBUG
    in  = new ifstream("entrada.txt");
    out = new ofstream("salida.txt");
    cin.rdbuf(in->rdbuf());
    cout.rdbuf(out->rdbuf());
#endif
    //INIT SQUARES
    for(unsigned long long i = 1 ; i <= 100 ; ++i)
        squares.insert(i*i);

    unsigned long long num[7];
    num[0] = 18;
    num[6] = 0;
    int i = 1 ;
    while(i < 7){
        num[i] = num[i-1] +1 ;
        if(isDigitSquare(num[i]))
            i++;
        else
            num[0] = nextSquaredNum(num[i] +1),
                    i = 1;
        /*
        if( i >= 5) {
            cout << i << endl;
            for (int i = 0; i < 7; ++i)
                cout << num[i] << " " << num[i] * num[i] << endl;
        }*/
    }

    for(int i = 0 ; i< 7 ; ++i)
        cout<<num[i]<<" "<<num[i]*num[i]<<endl;

}