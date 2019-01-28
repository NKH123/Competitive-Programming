// CPP program to find the 
// blocks for given number. 
#include <bits/stdc++.h>
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



int block(long int x) 
{ //cout<<"block\n";
	vector<long int> v; 
	
	// Converting the decimal number 
	// into its binary equivalent. 
	//cout << "Blocks for " << x << " : "; 
	while (x > 0) 
	{ 
		v.push_back(x % 2); 
		x = x / 2; 
	} 

	// Displaying the output when 
	// the bit is '1' in binary 
	// equivalent of number. 
	int ret=0;
	for (int i = 0; i < v.size(); i++) 
	{ 
		if (v[i] == 1) 
		{ 
			ret++;
			//cout << i; 
			//if (i != v.size() - 1) 
			//	cout << ", "; 
		} 
	} 
	return ret;
	//cout << endl; 
} 


void pprint(long int x) 
{ //cout<<"pprint\n";
	vector<long int> v; 
	
	// Converting the decimal number 
	// into its binary equivalent. 
	//cout << "Blocks for " << x << " : "; 
	while (x > 0) 
	{ 
		v.push_back(x % 2); 
		x = x / 2; 
	} 

	// Displaying the output when 
	// the bit is '1' in binary 
	// equivalent of number. 
	cout<<"YES\n";
	int ret=0;
	for (int i = 0; i < v.size(); i++) 
	{ 
		if (v[i] == 1) 
		{ 
			ret++;
			int A=1<<i;
			cout<<A<<" ";
			//cout << i; 
			//if (i != v.size() - 1) 
			//	cout << ", "; 
		} 
	} 
	//return ret;
	cout << endl; 
} 

void solve(long int x, ll k, ll mini) 
{ 
	//cout<<"solve\n";
	vector<long int> v; 
	ll rem=k-mini;
	// Converting the decimal number 
	// into its binary equivalent. 
	//cout << "Blocks for " << x << " : "; 
	while (x > 0) 
	{ 
		v.push_back(x % 2); 
		x = x / 2; 
	} 

	// Displaying the output when 
	// the bit is '1' in binary 
	// equivalent of number. 
	int ret=0;
	/*for (int i = 0; i < v.size(); i++) 
	{ 
		if (v[i] == 1) 
		{ 
			ret++;
			int A=1<<i;
			cout<<A<<" ";
			//cout << i; 
			//if (i != v.size() - 1) 
			//	cout << ", "; 
		} 
	} */
	cout<<"YES\n";
	int i=v.size()-1;
	while(rem>0){
		v[i]--;
		v[i-1]+=2;
		if(v[i]==0){
			i--;
		}
		rem--;
	}
	for (int i = 0; i < v.size(); i++) 
	{ 
		while (v[i] >0) 
		{ 
			ret++;
			int A=1<<i;
			cout<<A<<" ";
			v[i]--;
			//cout << i; 
			//if (i != v.size() - 1) 
			//	cout << ", "; 
		} 
	} 
	//return ret;
	cout << endl; 
} 

// Driver Function 
int main() 
{ 
	ll x;
	ll n,k;
	cin>>n>>k;
	if(k>n){
		cout<<"NO\n";
		return 0;
	}
	if(k==n){
		cout<<"YES\n";
		REP(i,0,n){
			cout<<1<<" ";
		}
		return 0;
	}

	int mini=block(n);
	if(k<mini){
		cout<<"NO\n";
		return 0;
	}
	if(k==mini){
		pprint(n);
	}
	else{
		solve(n,k,mini);
	}
	//block(71307); 
	//block(1213); 
	//block(29); 
	//block(100); 
	return 0; 
} 
