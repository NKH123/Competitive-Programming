#include<bits/stdc++.h>
using namespace std;

class LiteratureOptimal{
public:
	int minTurns(int N, vector <int> Teja, vector <int> history){
		vector<int>a(3*N+5);
		int ct[3];
		memset(ct,0,sizeof(ct));
		ct[0]=N;
		for(int i=0;i<Teja.size();i++){
			a[Teja[i]]=1;
		}
		for(int i=0;i<history.size();i++){
			if(i%3==1){
				if(a[Teja[i]]!=1 /*|| a[Teja[i]]!=0*/){
				a[Teja[i]]=3;
				ct[2]++;
			}
		}
		if(i%3==2){
				if(a[Teja[i]]!=1 /*|| a[Teja[i]]!=0*/){
			a[Teja[i]]=2;
			ct[1]++;
		}

	}
}
int un=0;
for(int i=1;i<=3*N;i++){
	if(a[i]==0){
		un++;
	}
}
int maxi=max(ct[1],ct[2]);
int rem=N-maxi;

int f=0;
if(ct[2]>ct[1]){
	f=1;
}
int ret=0;
if(f==0){
	ret+=(rem-1)*3;
	if(history.size()%3==0){
		ret+=3;
	}
	if(history.size()%3==1){
		ret+=2;
	}
	if(history.size()%3==2){
		ret+=4;
	}
}
else{
	ret+=(rem-1)*3;
	if(history.size()%3==0){
		ret+=3;
	}
	if(history.size()%3==1){
		ret+=2;
	}
	if(history.size()%3==2){
		ret+=1;
	}

}
	return ret;

}
};