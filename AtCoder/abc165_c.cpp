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
vector<vector<int> >qq;
int n, m, q;
bool comp(vector<int>A, vector<int>B){
    return A[3]>B[3];
}

int ans=0;

void cal(mask){
    vector<vector<int> >A;
    A.clear();
    for(int i=0;i<q;i++){
        if(((1LL<<i)&(mask))!=0){
            A.PB(qq[i]);
        }
    }
    sort(A.begin(),A.end(),comp);
    vector<int>aa;
    aa.clear();
    aa.resize(n+1,-1);
    int Ans=0;
    for(int i=0;i<A.size();i++){
        int a, b, c, d;
        a=A[0];
        b=A[1];
        c=A[2];
        d=A[3];
        //both empty
        if(aa[a]==-1 && aa[b]==-1){
            
        }
        //one empty


        //both not empty
    }
    ans=max(ans,Ans);
}
int32_t main(){
    ios::sync_with_stdio(false);
    
    cin>>n>>m>>q;
    qq.resize(q);
    for(int I=0;i<q;I++){
        for(int i=0;i<4;i++){
            int A;
            cin>>A;
            qq[I].PB(A);
        }
    }
    sort(qq.begin(),qq.end(),comp);
    for(int i=1;i<(1<<q);i++){

    }
    cout<<ans<<"\n";
    return 0;
}