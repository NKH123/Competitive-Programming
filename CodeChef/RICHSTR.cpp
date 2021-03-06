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
    int t;
    cin>>t;
    string s;
    set<int>ind;
    while(t--){
        int n, q;
        cin>>n>>q;
        cin>>s;
        ind.clear();
        int f=0;
        if(n<=2){
            f=1;
        }
        if(f==0){
            for(int i=0;i<(s.size()-2);i++){
                if(s[i]==s[i+1] || s[i]==s[i+2] || s[i+1]==s[i+2]){
                    ind.insert(i);
                }
            }
        }
        // deb(ind);
        while(q--){
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            if(f==0){
                if(ind.size()==0){
                    cout<<"NO\n";
                    continue;
                }
                auto L=(ind.lower_bound(l));
            // deb((*L));
                if(L==ind.end()){
                    cout<<"NO\n";
                    continue;
                }
                else{
                    int LL=(*L);
                    if((LL+2)<=r){
                        cout<<"YES\n";
                    }
                    else{
                        cout<<"NO\n";
                    }
                }
            }
            else{
                cout<<"NO\n";
            }
            
        }
    }



    return 0;
}