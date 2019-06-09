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

int n;
vi a;
int ans=0;
vi b[6];
vi c{4,8,15,16,23,42};
int32_t main(){
	ios::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
        int f=0;
        for(int j=0;j<6;j++){
            if(a[i]==c[j]){
                f=1;
                b[j].PB(i);
            }
        }
        if(f==0){
            ans++;
        }
    }
    int i, j;
    int I[6]{0};
    if(b[0].size()==0){
        cout<<n<<"\n";
        return 0;
    }
    // int prev=b[0][0];
    vi cc;
    for(int i=0;i<6;i++){
        // deb(i);
        // deb(b[i]);
        reverse(b[i].begin(),b[i].end());
    }
    int prev=-1;
    int rel=0;
    i=0;
    while(1){
        int f=0;
        while(b[i].size()!=0){
            if(b[i][b[i].size()-1]>prev){
                prev=b[i][b[i].size()-1];
                f=1;
                b[i].pop_back();
                rel++;
                break;
            }
            else{
                b[i].pop_back();
            }
        }
        if(f==0){
            break;
        }
        i=(i+1)%6;
        if(i==0){
            prev=-1;
        }
    }
    rel=rel-(rel%6);
    ans=n-rel;
    cout<<ans<<"\n";



	return 0;
}