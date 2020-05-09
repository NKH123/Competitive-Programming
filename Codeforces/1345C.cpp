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
    vi a;
    // set<int>emp,two;
    set<int>To;
    // map<int, int>M;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        // emp.clear();
        // one.clear();
        // two.clear();
        // M.clear();
        REP(i,0,n){
            cin>>a[i];
            // M[a[i]]=1;
        }
        To.clear();
        for(int i=0;i<n;i++){
            int from=i;
            int to=(from)+(a[i%n]);
            // if(emp.find(to)!=emp.end()){
            //     // two.insert(to);
            //     emp.erase(emp.find(to));

            // }
            // else{
            //     two.insert(to);
            // }
            // M[from]--;
            // M[to]++;
            To.insert(to);
        }
        vi b;
        b.clear();
        b.resize(n);
        for(auto g:To){
            // deb((g%n));
            int A=g%n;
            A=(A+n)%n;
            b[A]=1;
        }

        int f=1;
        for(int i=0;i<n;i++){
            if(b[i]==0){
                f=0;
            }
        }
        // deb(M);
        // for(auto g:M){
        //     if(g.second==-1){
        //         f=1;
        //     }
        // }
        if(f==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }

    }

    return 0;
}