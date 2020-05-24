#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define sz(x) (int)(x.size())
#define mod 1000000007

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



int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n+1);
    map<int, int>M;
    map<int, int>dp;
    // map<int
    REP(i,1,n+1){
        cin>>a[i];
        if(M.count(a[i]-1)!=0){
            dp[a[i]]=dp[a[i]-1]+1;
        }
        else{
            dp[a[i]]=1;
        }
        M[a[i]]=i;
    }
    int ans=0;
    for(auto g:dp){
        ans=max(ans,g.S);
    }
    cout<<ans<<"\n";
    int last=0;
    for(auto g:dp){
        if(g.S==ans){
            last=g.F;
            break;
        }
    }
    int ele=last;
    vector<int>Ans;
    // while(M[ele]!=0){
    //     Ans.push_back(M[ele]);
    //     ele--;
    //     if(M[ele]>M[ele+1]){
    //         break;
    //     }
    // }
    // reverse(Ans.begin(),Ans.end());
    // for(int i=0;i<Ans.size();i++){
    //     cout<<Ans[i]<<" ";
    // }
    int ind=M[ele];
    int cur=ele-1;
    Ans.push_back(ind);
    for(int i=ind;i>=1;i--){
        if(a[i]==cur){
            // cout<<(i)<<" ";
            Ans.push_back(i);
            cur--;
        }
    }
    reverse(Ans.begin(),Ans.end());
    for(int i=0;i<Ans.size();i++){
        cout<<Ans[i]<<" ";
    }
    cout<<"\n";



    return 0;
}