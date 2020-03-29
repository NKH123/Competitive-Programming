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
#define endl "\n"
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
    int t;
    cin>>t;
    vi ans,ans1;
    vi q;
    vector<int>x;
    while(t--){
        // int x;
        int n;
        cin>>n;
        // cin>>x;
        x.clear();
        REP(i,0,n){
            char A;
            cin>>A;
            x.PB(A-'0');
        }
        ans.clear();
        ans.resize(n);
        ans1.clear();
        ans1.resize(n);
        ans[0]=1;
        ans1[0]=1;
        int f=0;
        for(int i=1;i<n;i++){
            if(f==0){
                if(x[i]==1){
                    ans[i]=1;
                    ans1[i]=0;
                    f=2;
                }
                else if(x[i]==2){
                    ans[i]=1;
                    ans1[i]=1;
                }
                else if(x[i]==0){
                    ans[i]=0;
                    ans1[i]=0;
                    // f=2;
                }   

            }
            else if(f==1){

            }
            else if(f==2){
                if(x[i]==1){
                    ans[i]=0;
                    ans1[i]=1;
                    f=2;
                }
                else if(x[i]==2){
                    ans[i]=0;
                    ans1[i]=2;
                }
                else if(x[i]==0){
                    ans[i]=0;
                    ans1[i]=0;
                    // f=2;
                }   
            }
        }
        REP(i,0,n){
            cout<<ans[i];
        }
        cout<<"\n";
        REP(i,0,n){
            cout<<ans1[i];
        }
        cout<<"\n";

    }

    return 0;
}