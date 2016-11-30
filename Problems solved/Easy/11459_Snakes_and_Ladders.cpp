#include<bits/stdc++.h>
using namespace std;

#define FOR(a,b) for(int a = 0 ; a < b ; ++a)

int main(){
	int games ;
	cin>>games;
	while(games--){
		int players , snakes , rolls;
		unsigned jumps[101] = {0};
		
		
		cin>>players>>snakes>>rolls;
		//cout<<"p: "<<players<<"s: "<<snakes<<"r: "<<rolls<<endl;
		unsigned playerpos[players+1] = {0};
		
		FOR(i,players)
			playerpos[i+1] = 1;
			
		unsigned initjump,endjump;
		FOR(i,snakes){
			cin>>initjump;
			cin>>endjump;
			jumps[initjump] = endjump;
		}
		
		int roll,player = 1;
		FOR(i,rolls){
			cin>>roll;
			playerpos[player] = min((playerpos[player] + roll),(unsigned int)100) ;
			
			if(jumps[playerpos[player]] != 0)
				playerpos[player] = jumps[playerpos[player]];
			
			if(playerpos[player] == 100){
				for(int j = i+1 ; j < rolls ; ++j){
					cin>>roll;//Garbage
				}
				break;
			}
			
			player = (player % players ) +1;
		}
		
		FOR(i,players){
			cout<<"Position of player "<<i+1<<" is "<< playerpos[i+1] <<"."<<endl;
		}
	}
}