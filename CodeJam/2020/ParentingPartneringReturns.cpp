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
    int T=t;
    vector<pair<pair<int,int>,int> >se;
    vi ct;
    while(t--){
        int f=1;
        int n;
        cin>>n;
        ct.clear();
        ct.resize(24*60+1);
        se.resize(n);
        for(int i=0;i<n;i++){
            cin>>se[i].first.first>>se[i].first.second;
            se[i].second=i;
            for(int j=se[i].first.first;j<se[i].first.second;j++){
                ct[j]++;
            }
        }
        for(int i=0;i<(24*60);i++){
            if(ct[i]>2){
                f=0;
            }
        }
        if(f==0){
            cout<<"Case #"<<T-t<<": "<<"IMPOSSIBLE\n";
        }
        else{
            int C=0;
            int J=0;
            sort(se.begin(),se.end());
            vi ans(n);
            for(int i=0;i<n;i++){
                if(C<=se[i].first.first){
                    C=se[i].first.second;
                    ans[se[i].second]=0;
                }
                else if(J<=se[i].first.first){
                    J=se[i].first.second;
                    ans[se[i].second]=1;
                }
            }
            cout<<"Case #"<<T-t<<": ";
            for(int i=0;i<n;i++){
                if(ans[i]==0){
                    cout<<"C";
                }
                else{
                    cout<<"J";
                }
            }
            cout<<"\n";
        }

    }

    return 0;
}