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
    vi a, b;
    vi dp;
    map<int, pair<int, int> >M;
    set<pair<int, int> >S;
    vi done;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        b.clear();
        a.resize(n);
        b.resize(n);
        M.clear();
        int W=0;
        S.clear();
        done.clear();
        done.resize(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            M[i]={a[i],b[i]};
            S.insert({a[i],i});
        }
        int ans=0;
        while(S.size()>0){
            deb(S);
            auto g=*(S.begin());
            ans+=g.F;
            int next=(g.S+1)%n;
            deb(next);
            deb(g);
            deb("***************");
            S.erase(S.find(g));
            done[g.S]=1;
            int prev=g.S;
            while(done[next]==0){

                deb("inside nested while loop");
                deb(S);
                deb("yo");
                S.erase(S.find({M[next].first,next}));
                M[next].first=max(0LL,M[next].first-b[prev]);
                if(M[next].first>0){
                    S.insert({M[next].first,next});
                    deb("not killed so break");
                    break;
                }
                else{
                    done[next]=1;
                    deb("killed so continue;")
                    prev=next;
                    next=(next+1)%n;
                }

            }
            deb(S);
            deb(ans);
            deb("##################################");

            
        }
        cout<<ans<<"\n";

        
        

    }

    return 0;
}