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
// int f=0;
int n;
int m;
int ans=0;
vector<int>col;
vector<pair<int, int> >edj;
set<pair<int, int> >S;
map<int, int> M;
// map<int, int>req;
void fun(int I){
    if(I==(n+1)){
        // check
        map<int, int>M;
        // deb(col);        
        S.clear();
        // M.clear();
        int temp=0;
        int f=1;
        for(int i=0;i<edj.size();i++){
            int A=edj[i].F;
            int B=edj[i].S;
            int colA=col[A];
            int colB=col[B];
            if(colA==0 || colB==0){
                continue;
            }
            if(colA>colB){
                swap(colA,colB);
            }
           if(S.find({colA,colB})==S.end()){
                S.insert({colA,colB});
                temp++;
            }

        }
        if(f==1){
            ans=max(ans,temp);
        }
    }
    else{
        for(int i=0;i<=6;i++){
            col[I]=i;
            fun(I+1);
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    col.resize(n+1);
    cin>>m;

    for(int i=0;i<m;i++){
        int A, B;
        cin>>A>>B;
        edj.PB({A,B});
    }
    if(n<7){
        fun(1);
        cout<<ans<<"\n";
        // c

    }
    else{
        fun(1);
        cout<<ans<<"\n";
    }
    




    return 0;
}