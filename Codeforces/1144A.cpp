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
    while(n--){
        string s;
        cin>>s;
        int a[26];
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        int f=1;
        for(int i=0;i<26;i++){
            if(a[i]>1){
                cout<<"No\n";
                f=0;
                break;
            }
        }
        if(f==0){
            continue;
        }
        int fi=-1;
        int la=-1;
        for(int i=0;i<26;i++){
            if(a[i]>0){
                fi=i;
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(a[i]>0){
                la=i;
            }
        }
        f=1;
        for(int i=fi;i<=la;i++){
            if(a[i]==0){
                cout<<"No\n";
                f=0;
                break;
            }
        }
        if(f==0)continue;
        cout<<"Yes\n";

    }
    



    return 0;
}