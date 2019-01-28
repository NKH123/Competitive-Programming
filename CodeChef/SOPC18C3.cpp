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


ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}


bool isP(int x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 
  
int getno(int n) 
{ 
    // Sum of divisors
    if(n==1)return 1;
    int f; 
    int result;
    int sq=0;
    if(isP(n)){
     result = 1+n;
    	sq=1;
 	f=1;}
	else{
		result=-1+n;
		f=0;
	}
     
   
    // find all divisors which divides 'num' 
    if(sq==0){
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        // if 'i' is divisor of 'n' 
        if (n % i == 0) 
        { 
            // if both divisors are same 
            // then add it once else add 
            // both 
            f=f^1;
            if(f==0){
result -= (i); 
result+=n/i;
            }
            else{
                result += (i); 
result-=n/i;
            }
            
        } 
    } 
}
    if(sq==1){

    	// find all divisors which divides 'num' 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        // if 'i' is divisor of 'n' 
        if (n % i == 0) 
        { 
            // if both divisors are same 
            // then add it once else add 
            // both 
            f=f^1;
            if(f==0 && i!=(n/i)){
            	result-=i;
            	result-=(n/i);

            }
            if(f==1 && i==(n/i)){
            	result+=i;
            	//resut-=(n/i);

            }
            if(f==0 && i==(n/i)){
            	result-=i;
            	//resut-=(n/i);

            }
            if(f==1 && i!=(n/i)){
            	result+=i;
            	result+=(n/i);

            }
           // trace(result);
            
        } 
    } 

    }
   
    // Add 1 and n to result as above loop 
    // considers proper divisors greater  
    // than 1. 
    return result; 
} 

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
    	int a,b;
    	cin>>a>>b;
    	//int A=getno(a);
    	//int B=getno(b);
    	//trace(A);
    	//trace(B);

    	cout<<getno(a)-getno(b)<<"\n";
    }
    
    return 0;
}