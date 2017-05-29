#include<bits/stdc++.h>

using namespace std;

int main(){
    int c;
    cin>>c;
    while(c--){
        int x,y;
        cin>>x>>y;
        cout<< int((float(x-1)/3.0)+0.9) * int((float(y-1)/3.0)+0.9) <<endl;
    }
    return 0;
}
