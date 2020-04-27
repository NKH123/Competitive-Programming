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
    while(t--){
        string s;
        cin>>s;
        int f=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){

            }
            else{
                f=0;
            }
        }
        if(f==1){
            cout<<s<<"\n";
        }
        else{
            // f=1;
            // for(int i=2;i<s.size();i++){

            // }
            int cur=s[0]-'0';
            cout<<s[0];
            for(int i=1;i<s.size();i++){
                if((s[i]-'0')==(cur)){
                    if(s[i]=='0'){
                        cout<<1;
                        cout<<s[i];
                        cur=s[i]-'0';
                    }
                    else{
                        cout<<0;
                        cout<<s[i];
                        cur=s[i]-'0';
                    }
                }
                else{
                    cout<<s[i];
                    cur=s[i]-'0';
                }
            }
            cout<<"\n";
        }
    }

    return 0;
}