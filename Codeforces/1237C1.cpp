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

bool comp(pair< pair<int, int>, pair<int, int> >A,pair< pair<int, int>, pair<int, int> >B){
    if(A.F.F==B.F.F){
        if(A.F.S==B.F.S){
            return A.S.F<B.S.F;
        }
        else{
            return A.F.S<B.F.S;
        }
    }
    else{
        return A.F.F<B.F.F;
    }

}
int dist(pair< pair<int, int>, pair<int, int> >A,pair< pair<int, int>, pair<int, int> >B){
    int ans=0;
    ans=(A.F.F-B.F.F)*(A.F.F-B.F.F)+(B.F.S-A.F.S)*(B.F.S-A.F.S)+(B.S.F-A.S.F)*(B.S.F-A.S.F);
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair< pair<int, int>, pair<int, int> > > xyz;
    for(int i=0;i<n;i++){
        int X, Y, Z;
        cin>>X>>Y>>Z;
        xyz.PB({{X,Y},{Z,i+1}});
    }
    vector<int>used(n,0);
    for(int i=0;i<n;i++){
        int Mini=-1;
        int Dist=1e18;
        if(used[i]==1){
            continue;
        }
        else{
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(used[j]==1){
                    continue;
                }
                int cur=dist(xyz[i],xyz[j]);
                if(cur<Dist){
                    Dist=cur;
                    Mini=j;
                }
            }
            cout<<i+1<<" "<<Mini+1<<"\n";
            used[i]=1;
            used[Mini]=1;
            
        }
    }



    return 0;
}