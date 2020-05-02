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
    vi a;set<int>S;
    while(t--){
        int n,k;
        cin>>n>>k;
        a.resize(n);
        S.clear();
        REP(i,0,n){
            cin>>a[i];
            S.insert(a[i]);
        }
        if(S.size()>k){
            cout<<-1<<"\n";
        }
        else{
            vector<int>ans;
            ans.clear();
            ans.resize(S.size());
            int I=0;
            for(auto g:S){
                ans[I]=g;
                I++;
            }

            while(ans.size()<k){
                ans.PB(*(S.begin()));
            }
            I=ans.size();
            int pos=0;
            while(pos<n){
                //deb(pos);
                //deb(ans);
                if(a[pos]!=ans[(ans.size())%k]){
                    while(a[pos]!=ans[(ans.size())%k]){
                        int I=ans.size();
                        ans.PB(ans[I%k]);
                        //deb("PB");
                        //deb(a[I%k]);
                    I++;
                    }
                    ans.PB(a[pos]);
                }
                else{
                    ans.PB(a[pos]);
                }
                //deb(ans);
                //deb("******");
                // I++;
                pos++;
            }
            cout<<ans.size()<<"\n";
            REP(i,0,ans.size()){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}