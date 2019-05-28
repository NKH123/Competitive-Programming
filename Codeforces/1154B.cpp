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
#define llp 1000000007
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
    vi a(n);
    set<int>s;
    REP(i,0,n){
        cin>>a[i];
        s.insert(a[i]);
    }
    vi SS;
    for(auto g:s){
        SS.PB(g);
    }
    if(s.size()>=4){
        cout<<-1<<"\n";
        return 0;
    }
    else{
        if(s.size()==1){
            cout<<0<<"\n";
            return 0;
        }
        if(s.size()==2){
            if((SS[0]%2)==(SS[1]%2)){
                int ans=(SS[0]+SS[1])/2;
                ans=ans-SS[0];
                cout<<ans<<"\n";
                return 0;
            }
            else{
                int ans=SS[1]-SS[0];
                cout<<ans<<"\n";
                return 0;
            }
        }
        if(s.size()==3){
            if((SS[1]-SS[0])==(SS[2]-SS[1])){
                cout<<(SS[1]-SS[0])<<"\n";
                return 0;
            }
            else{
                cout<<-1<<"\n";
                return 0;
            }
        }
    }



	return 0;
}