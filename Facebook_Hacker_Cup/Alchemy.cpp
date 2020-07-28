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
    vector<char> a;
    vector<char> b;
    int T=t;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        b.clear();
        b.PB(a[0]);
        b.PB(a[1]);
        int ct[2];
        for(int i=2;i<n;i++){
            ct[0]=0;
            ct[1]=0;
            if(b.size()>=2){
                char ele1 = b[b.size()-1];
                char ele2 = b[b.size()-2];
                ct[ele1 - 'A']++;
                ct[ele2 - 'A']++;
                ct[a[i]-'A']++;
                if(ct[0]>0 && ct[1]>0){
                    b.pop_back();
                    b.pop_back();
                    if(ct[0]==2){
                        b.PB('A');
                    }
                    else{
                        b.PB('B');
                    }
                }
                else{
                    b.PB(a[i]);
                }
            }
            else{
                b.PB(a[i]);
            }
        }
        cout<<"Case #"<<(T-t)<<": ";
        if(b.size() == 1){
            cout<<"Y";
        }
        else{
            cout<<"N";
        }
        cout<<"\n";
    }

    return 0;
}