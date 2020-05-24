#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vd(T) vector<vector<T>>
#define v(T) vector<T>
#define mod (ll)(1e9+7)
#define pp(T) pair<T,T>
#define pb push_back
#define read1(x) scanf("%d",&x)
#define read2(x,y) scanf("%d%d",&x,&y)
#define read3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define read4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define mp make_pair
#define NN 200005
#define IO ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define DEBUG cout<<"***********DEBUGGING***********"<<endl
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define PB push_back
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;


typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
ll power(ll a,ll b){ if(b==0) return 1; ll s=power(a,b/2); s*=s;if(b&1) return s*a; return s;}
ll powermod(ll a,ll b,ll m){ if(b==0) return 1; ll s=power(a,b/2);s*=s; s%=m; if(b&1) return (s*a)%m; return s;}
inline int add(ll a,ll b,ll m=0){
    if(m==0) return a+b;
    return (a%m+b%m)%m;
}

inline int sub(ll a,ll b ,ll m=0){
    if(m==0) return a-b;
    return ((a%m-b%m)%m+m)%m;
}

inline int mul(ll a,ll b,ll m=0){
    if(m==0)return (a*b);
    return ((a%m)*(b%m))%m;
}

inline int div(ll a,ll b,ll m=0){
    if(m==0) return a/b;
    return ((a%m)*(powermod(a,b,m-2)%m))%m;
}


ll setup_k(ll *a,ll k){
  ordered_set x;
  // Now , insert and then check number of integers less than k by just using x.order_of_key(k+1)
  return 0;
}

int main() {

    IO; 

    string s;
    cin>>s;
    int n=s.length();
    int pal[n][n];
    vector<int>ans;
    memset(pal,0,sizeof(pal));
    int dp[n][n]{0};
    memset(dp,0,sizeof(dp));
    int tmp=0;
     for(int i=0;i<n;i++){
      dp[i][i]=1;
      tmp++;
      if(i!=(n-1)){
        if(s[i]==s[i+1]){
          dp[i][i+1]=1;
          tmp++;
        }
      }
    }
    // for(int i=0;i<n;i++){
    //   for(int j=i+2;j<n;j++){
    //     if(pal[i+1][j-1]==1 && s[i]==s[j]){
    //       pal[i][j]=1;
    //     }
    //   }
    // }
      
    
    for(int len=3;len<=n;len++){
    	for(int i=0;i<n;i++){
    		if((i+len-1)>=n)continue;
    		int j=i+len-1;
    		if(dp[i+1][j-1]==1 && s[i]==s[j]){
    			dp[i][j]=1;
    			tmp++;
    		}
    	}
    }
    
  
    // for(int i=0;i<n;i++){
    //   for(int j=0;j<n;j++){
    //     if(pal[i][j]){
    //     	deb("pal");
    //     	cout<<i<<" "<<j<<"\n";
    //     	deb("pal");
    //       dp[i][j]=1;   
    //       tmp++;   
    //     }
    //     else{
    //     	dp[i][j]=0;
    //     }
    //   }
    // }
    // deb("dp");
    // for(int i=0;i<n;i++){
    // 	for(int j=0;j<n;j++){
    // 		cout<<dp[i][j]<<" ";
    // 	}
    // 	cout<<"\n";
    // }
    // deb("dp");
    // cout<<tmp<< " ";
    ans.PB(tmp);
    int k=2;
    while(k<=n){
       int dp1[n][n]{0};
    	memset(dp1,0,sizeof(dp1));
       int cnt=0;
        for(int i=0;i<n;i++){
          for(int j=i+1;j<n;j++){
            if(dp[i][j]==0){
            	continue;
            }
            int mid=(i+j)/2;
            int len=(j-i+1);
            if(len%2==0){
            	if(dp[i][mid]==1 && dp[mid+1][j]==1 ){
            		dp1[i][j]=1;
            		cnt++;
            	}
            }
            else{
            	if(dp[i][mid-1]==1 && dp[mid+1][j]==1){
            		dp1[i][j]=1;
            		cnt++;
            	}
            }


          }
        }

        // cout<<cnt<<" ";
        ans.PB(cnt);
        // for(int i=0;i<n;i++){
        // 	for(int j=0;j<n;j++){
        // 		cout<<dp1[i][j]<<" ";
        // 	}
        // 	cout<<"\n";
        // }
        if(cnt==0){
        	break;
        }
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          dp[i][j]=dp1[i][j];
        }
       }
       k++;
    }
    // deb(ans);
    int rem=n-(int)ans.size();
    while(rem--){
    	ans.PB(0);
    }
    for(int i=0;i<n;i++){
    	cout<<ans[i]<<" ";
    }
    cout<<"\n";

}



Given an integer n. n is till 10^5.
Consider a clique of size n.
For every edge (i,j) add the value integer part of i/j to node j.
Find the sum of all nodes in the end.