#include<bits/stdc++.h>
using namespace std;

class PokerRound{
public:
	int amount(int final){
		long long y=0;
		y=final+70000;
		if(y%8!=0){
			return -1;
		}
		else{
			return y/8;
		}


		//return y;
	}
};