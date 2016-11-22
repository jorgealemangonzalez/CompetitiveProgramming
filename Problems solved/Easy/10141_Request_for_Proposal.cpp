/* 
 * File created by
 * Jorge Aleman Gonzalez
 * on 21-nov-2016 
 */

#include<bits/stdc++.h>
#define FOR(i,n) for(int i = 0 ; i < n ; ++i)
using namespace std;

int main(){
    int n , p , id = 1;
    while(cin>>n>>p){
        if(n == 0 && p == 0)break;
        else if(id != 1)cout<<endl;
        string garbage;
        cin.ignore();
        FOR(i,n){
            getline(cin,garbage);
            //cout<<"gar: "<<garbage<<endl;
        }
        
        double mincost=-1.0;
        double price  , minprice = 9999999999999.9;
        string minname , name;
        unsigned metreq;
        FOR(i,p){
            getline(cin,name);
            cin>>price>>metreq;
            cin.ignore();
            FOR(j,metreq)getline(cin,garbage);
            
            double cost = (double)( metreq )/(double)(n);
            //cout<<"name"<<name<<"cost "<<cost<<" mincost "<<mincost<<endl;
            if(cost == mincost){
                if(price < minprice){
                    mincost = cost;
                    minname = name;
                    minprice = price;
                }
            }else if(cost > mincost){
                mincost = cost;
                minname = name;
                minprice = price;
            }
            //if(i != p-1)cin.ignore();
        }
        
        cout<<"RFP #"<<id++<<endl;
        cout<<minname<<endl;
        
    }
}
