#include<bits/stdc++.h>

using namespace std;

int main(){
    int sums[101];
    sums[0] = 0;
    sums[1] = 1;
    for(int i = 2 ; i <= 100 ; ++i){
        sums[i] = sums[i-1] + int(i%2)*i;
    }

    int c;
    cin>>c;
    for(int i = 0 ; i < c ; ++i){
        int x , y;
        cin>>x>>y;
        cout<<"Case "<<i+1<<": "<<sums[y]-sums[x-1];
        if(i+1 < c)cout<<endl;
    }

}
