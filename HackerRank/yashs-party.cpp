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
int t;
int n, m;
vector<set<int> >adj;
vector<int>mark;
vector<int>Ans;
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        int n;
        int m;
        cin>>n>>m;
        adj.clear();
        adj.resize(n+1);
        Ans.clear();
        mark.clear();
        mark.resize(n+1,0);
        mark[2]=1;
        for(int i=1;i<=m;i++){
            int A, B;
            cin>>A>>B;
            if(A==B){
                continue;
            }
            if(A>B){
                swap(A,B);
            }

            adj[A].insert(B);
            adj[B].insert(A);
            if(A==2){
                mark[B]=1;
            }   
        }
        int ans=adj[1].size();
        mark[1]=0;
        for(auto g:adj[1]){
            int f=1;
            if(mark[g]==1){
                ans--;
                f=0;
            }
            else{
                for(auto h:adj[g]){
                    if(mark[h]==1){
                        ans--;
                        f=0;
                        break;
                    }
                }
            }
            if(f==1){
                Ans.PB(g);
            }
        }
        if(Ans.size()==0){
            cout<<-1<<"\n";
        }
        else{
            sort(Ans.begin(),Ans.end());
            for(auto g:Ans){
                cout<<g<<" ";
            }
            cout<<"\n";
        }

    }

    return 0;
}