#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    bool left = true;
    while(getline(cin,s)){
        for(int i = 0 ; i < s.length() ; ++i){
            if(s[i] == '"'){
                if(left)
                    cout<<"``";
                else cout<<"''";
                left = !left;
            }else cout<<s[i];
            
        }
        cout<<endl;
    }
}
