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

vector<vector<int> >dt;
vector<int>md,mp;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        dt.clear();
        dt.resize(n);
        md.clear();
        mp.clear();
        mp.resize(n);
        md.resize(n);
        REP(i,0,n){
            int k;
            cin>>k;
            dt[i].resize(k);
            REP(j,0,k){
                cin>>dt[i][j];
                if(md[i]==0 && mp[dt[i][j]-1]==0){
                    md[i]=dt[i][j];
                    mp[dt[i][j]-1]=i+1;
                }
            }


        }
        int f=0, f1=0;
            int dd, pp;
            for(int i=0;i<n;i++){
                if(md[i]==0){
                    f++;
                    dd=i+1;
                }
                if(mp[i]==0){
                    f1++;
                    pp=i+1;
                }
            }
            if(f>0 && f1>0){
                cout<<"IMPROVE\n";
                cout<<dd<<" "<<pp<<"\n";
            }
            else{
                cout<<"OPTIMAL\n";
            
            }

    }

    return 0;
}