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
vi a;
map<int,int>m;
vi b;
vector<pair<int, int > > pp;
int n;
void sswap(int st, int se, int len){
    int j=(se+1)%n;
    // deb(st);
    // deb(se);
    // deb(len);
    // deb(j);
    for(int i=st;i<=se;i++){
        // deb(i);
        // deb(j);
        swap(a[pp[i].S],a[pp[j].S]);
        j=(j+1)%n;
    }
    // deb(a);
}


int32_t main(){
	ios::sync_with_stdio(false);   
    int t;
    cin>>t;
    while(t--){
        
        cin>>n;
        m.clear();
        a.resize(n);
        pp.clear();
        REP(i,0,n){
            cin>>a[i];
            m[a[i]]++;
            pp.PB({a[i],i});
        }
        int f=1;
        for(auto g:m){
            int rem=n-g.S;
            if(rem<g.S){
                f=0;
            }
        }
        if(f==0){
            cout<<"No\n";
            continue;
        }
        else{
            sort(pp.begin(),pp.end());
            // for(int i=0;i<)
            b.resize(n);
            // int I=-1;
            // int J=-1;
            // deb(pp);
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    if(pp[j].F!=pp[i].F){

                        sswap(i,j-1,j-1-i+1);
                        i=j+j-1-i;
                        j=n;
                        // deb("aaaaaaf");
                        // deb(i);
                        // deb(j);
                        // deb("aaaaaaf end");
                    }
                    else if(j==n-1){
                         // deb("here");
                        sswap(i,j,j-i+1);
                        i=n;
                        j=n;
                    }
                }
            }
            cout<<"Yes\n";
            REP(i,0,n){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }

    }




	return 0;
}