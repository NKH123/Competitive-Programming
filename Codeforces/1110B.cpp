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
int n, m , k;
vi a;
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    a.resize(n);
    vector<pair<int, int> > br;
    REP(i,0,n){
        cin>>a[i];
        if(i==0){
            br.PB({a[i],a[i]});
        }
        else{
            if(a[i]==(a[i-1]+1)){
                br[br.size()-1].S=a[i];
            }
            else{
                br.PB({a[i],a[i]});
            }
        }
    }
    int dis=0;
    if(br.size()<=k){
        cout<<n<<"\n";
    }
    else{
        vi pec;
        for(int i=0;i<(sz(br)-1);i++){
            pec.PB(br[i+1].F-br[i].S);
        }
        sort(pec.begin(),pec.end());
        int cur=br.size();
        int tot=n;
        int I=0;
        while(cur>k){
            tot+=pec[I]-1;
            I++;
            cur--;
        }
        cout<<tot<<"\n";
    }
    return 0;
}