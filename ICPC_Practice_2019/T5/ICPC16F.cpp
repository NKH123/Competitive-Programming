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
    vector<set<int> >neigh[2];
    // vector<vector<int> >adj[2];
    while(t--){
        int n, m, d, D;
        cin>>n>>m>>d>>D;
        int low=n*d;
        int high=n*D;
        if(m<low || m>high || m>(n*n)){
            cout<<"-1\n";
            continue;
        }
        neigh[0].clear();
        neigh[1].clear();
        neigh[0].resize(n+1);
        neigh[1].resize(n+1);
        // int times=n/d;
        int rem=m;
        int ff=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<d;j++){
                int I=i-1;
                int J=(I+j)%n;
                neigh[0][I+1].insert(J+1);
                neigh[1][J+1].insert(I+1);
                rem--;
                if(rem<0){
                    ff=0;
                }
            }
        }
        if(rem>0){
            for(int i=1;i<=n;i++){
                if(rem==0){
                    break;
                }
                if(neigh[0][i].size()==D){
                    continue;
                }
                for(int j=1;j<=n;j++){
                    if( neigh[1][j].size()==0|| neigh[1][j].find(i)==neigh[1][j].end()){
                        if(neigh[1][j].size()==D){
                            continue;
                        }
                        neigh[1][j].insert(i);
                        neigh[0][i].insert(j);
                        rem--;
                        if(rem<0){
                            ff=0;
                        }   
                        if(neigh[0][i].size()==D){
                            break;
                        }
                    }
                    if(rem==0){
                        break;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(rem==0){
                    break;
                }
                if(neigh[1][i].size()==D){
                    continue;
                }
                for(int j=1;j<=n;j++){
                    if( neigh[0][j].size()==0|| neigh[0][j].find(i)==neigh[0][j].end()){
                        if(neigh[0][j].size()==D){
                            continue;
                        }
                        neigh[0][j].insert(i);
                        neigh[1][i].insert(j);
                        rem--;
                        if(rem<0){
                            ff=0;
                        }   
                        if(neigh[1][i].size()==D){
                            break;
                        }
                    }
                    if(rem==0){
                        break;
                    }
                }
            }

        }
        if(ff==0){
            cout<<"-1\n";
        }
        else if(rem>0){
            cout<<"-1\n";
        }

        else if(rem==0){
            int f=1;
            for(int i=1;i<=n;i++){
                if(neigh[0][i].size()>D || neigh[0][i].size()<d || neigh[1][i].size()>D || neigh[1][i].size()<d){

                    f=0;
                }
            }
            if(f==0){
                cout<<"-1\n";
                // deb(3);
            }
            else{
                for(int i=1;i<=n;i++){
                    for(auto g:neigh[0][i]){
                        cout<<i<<" "<<g<<"\n";
                    }
                }
            }
        }


    }


    return 0;
}