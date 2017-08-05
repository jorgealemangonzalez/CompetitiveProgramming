//Ir sumando el trozo que le falta a cada todo el rato , cuando des una vuelta entera que todos sean verdes
//entonces has encontrado el momento

#include<bits/stdc++.h>

using namespace std;

#define FOR(a,b) for(int a = 0 ; a < b ; ++a)
#define PB(a) push_back(a)

bool inGreen(int acttime , int period){
	int abstime = acttime%(period *2);
	return abstime < (period - 5);
}

unsigned restTime(int acttime , int period){
	int abstime = acttime%(period*2);
	return (period * 2) - abstime;
}

int main(){
	
	while(1){
		vector<int> light;
		int input;
		
		int minimun = 100000;
		
		while(cin>>input){
			
			if(input == 0)
				break;
			light.PB(input);
			minimun = min(minimun,input);
		}
		
		if(light.size() == 0)
			break;
		
		int i = -1;
		int acttime = minimun*2;//At list the minimun Tlight must go green another time
		int maxtime = 60*60*5;
		unsigned lights = light.size() , greens = 0; 
		
		while(1){
			if(greens == lights || acttime > maxtime)break;
			i = (i+1)%lights;
			
			if(inGreen(acttime,light[i])){
				greens++;
			}else{
				greens = 1;
				acttime += restTime(acttime,light[i]);
			}
		}
		//cout<<"actime: "<<acttime<<endl;
		if(acttime <= maxtime)
			printf("%02d:%02d:%02d\n",acttime/(60*60), (acttime/60)%60 , acttime%60 );
		else
			cout<<"Signals fail to synchronise in.txt 5 hours"<<endl;
		
	}
	return 0;
}