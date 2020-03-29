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
    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        int L=0, R=0, U=0, D=0;
        REP(i,0,s.size()){
            if(s[i]=='L'){
                L++;
            }
            if(s[i]=='R'){
                R++;
            }
            if(s[i]=='U'){
                U++;
            }
            if(s[i]=='D'){
                D++;
            }
        }
        int lr=min(L,R);
        int ud=min(U,D);
        if(lr==0 || ud==0){
            if(lr!=0){
                cout<<2<<"\n";
                cout<<"LR\n";
            }
            else if(ud!=0){
                cout<<2<<"\n";
                cout<<"UD\n";
            }
            else{
                cout<<0<<"\n\n";
            }
            continue;
        }
        int ans=(lr+ud)*2;
        // deb(lr);
        // deb(ud);
        // exit(0);
        cout<<ans<<"\n";
        REP(i,0,lr){
            cout<<"L";
        }
        REP(i,0,ud){
            cout<<"U";
        }
        REP(i,0,lr){
            cout<<"R";
        }
        REP(i,0,ud){
            cout<<"D";
        }
        cout<<"\n";
    }

    return 0;
}