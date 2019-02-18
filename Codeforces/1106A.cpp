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
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
#define llp 1000000007
#define mod 1000000007
char a[505][505];
int main()
{   ios::sync_with_stdio(false);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		char A;
    		cin>>A;
    		a[i][j]=A;
    	}
    }
    int ct=0;
    for(int i=2;i<n;i++){
    	for(int j=2;j<n;j++){
    		/*char A;
    		cin>>A;
    		a[i][j]=A;*/
    		if(a[i][j]=='X' && a[i-1][j-1]=='X' && a[i-1][j+1]=='X' && a[i+1][j-1]=='X' && a[i+1][j+1]=='X'){
    			ct++;
    		}
    	}
    }
    cout<<ct<<"\n";
    return 0;
}