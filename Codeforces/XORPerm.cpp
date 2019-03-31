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
    int t;
    cin>>t;
    while(t--){
        string s[3];
        cin>>s[0]>>s[1]>>s[2];
        // deb(s[0]);
        // deb(s[1]);
        // deb(s[2]);
        int ct[3];
        memset(ct,0,sizeof(ct));
        REP(j,0,3)
        REP(i,0,s[j].size()){
            if(s[j][i]=='1'){
                ct[j]++;
            }
        }
        sort(ct,ct+3);
        // deb(ct[0]);
        // deb(ct[1]);
        // deb(ct[2]);
        int sum=0;
        sum=ct[0]+ct[1]+ct[2];
        // deb(sum);
        if(sum<=10){
            // deb(sum);
            for(int i=0;i<sum;i++){
                cout<<1;
            }
            for(int i=0;i<(10-sum);i++){
                cout<<0;
            }
            cout<<"\n";
            continue;
        }
        int mini=ct[0];//min(ct[0],min(ct[1],ct[2]));
        int olap=ct[2]+ct[1]-10;
        olap=max(0LL,olap);
        int gaps=olap;
        if(gaps==0){
            gaps=10-ct[2]-ct[1];
        }
        int cur=10-gaps;
        if(gaps>=ct[0]){
            gaps-=ct[0];
        }
        else{
            gaps=ct[0]-gaps;
        }
        cur=10-gaps;
        // deb(gaps);
        // deb(gaps);
        REP(i,0,cur){
            cout<<1;
        }
        REP(i,0,gaps){
            cout<<0;
        }

        cout<<"\n";

    }



	return 0;
}