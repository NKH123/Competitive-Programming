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
    int T;
    T=t;
    vector<int>a;
    map<int, int>M;
    while(t--){
        int n, d;
        cin>>n>>d;
        a.clear();
        cout<<"Case #"<<(T-t)<<": ";
        a.resize(n);
        M.clear();
        REP(i,0,n){
            cin>>a[i];
            M[a[i]]++;
        }
        sort(a.begin(),a.end());
        int ans=1e18;
        for(int i=0;i<a.size();i++){
            if(M[a[i]]>=d){
                ans=0;
            }
        }
        if(ans==0){
            cout<<ans<<"\n";
        }
        else{
            set<int>S;
            S.clear();
            for(auto g:a){
                S.insert(g);
            }
            vi b;
            b.clear();
            int total=0;
            for(auto g:S){
                b.PB(g);
                total+=M[g];
            }
            if(d==2){
                cout<<1<<"\n";
            }
            else if(d==3){
                int ans=2;
                for(int i=0;i<b.size();i++){
                    int cuts=0;
                    int cur=M[b[i]];

                    for(int j=i+1;j<b.size();j++){
                        if(cur==2){
                            ans=1;
                        }
                        if((b[j]%b[i])==(0) && (b[j]/b[i])==2){
                                ans=min(ans,1LL);
                        }
                    }
                    
                }
                cout<<ans<<"\n";
            }
            else{
                if(ans==(1e18)){
                    //deb("here");
                    ans=(d-1);
                }
                cout<<ans<<"\n";
            }
        }
        // cout<<"\n";if()
    }

    return 0;
}