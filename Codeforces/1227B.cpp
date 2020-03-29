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
    set<int>S;
     vi a;
     vi b;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        b.clear();
        b.resize(n);
        S.clear();
        REP(i,0,n){
            cin>>a[i];
            S.insert(i+1);
        }
        // vi b(n);
        for(int i=0;i<n;i++){
            b[i]=-1;
        }
        b[0]=a[0];
        S.erase(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                b[i]=a[i];
                S.erase(a[i]);
            }
        }
        int f=1;
        for(int i=0;i<n;i++){
            if(b[i]==-1){
                auto g=S.lower_bound(a[i]);
                // if(g==(S.end())){
                //     g--;
                // }
                // else{
                //     g--
                // }
                if(g==S.begin()){
                    f=0;
                    break;
                }
                else{
                    g--;
                }
                b[i]=*(g);

                S.erase(g);
            }
        }
        if(f==0){
            cout<<-1<<"\n";
        }
        else{
            for(auto g:b){
                cout<<g<<" ";
            }
            cout<<"\n";
        }



    }

    return 0;
}