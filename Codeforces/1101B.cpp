#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define llp 1000000007
#define mod 1000000007




int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
	string s;
	cin>>s;
	int count=0;
	int i;
	int f=1;
	for(i=0;i<s.size();i++){
		if(s[i]!='['){
			count++;
		}
		else{
			f=0;
			break;
		}
	}
	if(f==1){
		cout<<-1<<"\n";
		return 0;
	}
	i++;
	//trace(count);
	f=1;
	for(;i<s.size();i++){
		if(s[i]!=':'){
			count++;
		}
		else{
			f=0;
			break;
		}
	}
	if(f==1){
		cout<<-1<<"\n";
		return 0;
	}
	i++;
	f=1;
	int j=i;
	int k=-1;
	for(;j<s.size();j++){
		if(s[j]==':'){
			k=j;
		}
	}
	if(k==-1){
		cout<<-1<<"\n";
		return 0;
	}

	else{
	//	trace(k);
		for(;i<=k;i++){
			if(s[i]!='|' && i!=k){
				count++;
			}
		}
	}

	f=1;
	//trace(i);
	for(;i<s.size();i++){
		if(s[i]!=']'){
			count++;
		}
		else{
			f=0;
			break;
		}
	}
	if(f==1){
		cout<<"I'm here\n";
		cout<<-1<<"\n";
		return 0;
	}
	f=1;
	i++;
	//trace(count);
	for(;i<s.size();i++){
		count++;
	}
	cout<<s.size()-count<<"\n";
	return 0;
}