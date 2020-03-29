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
#define MAXN 200005
int  t[4*MAXN], lazy[4*MAXN];  //n is size of array, t is the segment tree
vector<int>A;    //a is the input array from which segtree is built

#define INF 200005
//compute function
int compute(int A,int B){
    return A+B;
}





//call build(1,0,n-1) 
void build( int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = A[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = compute(t[v*2] , t[v*2+1]);// t[v*2] + t[v*2+1];
    }
}

//call sum(1,0,n-1,l, r)  l and r are range boundaries in 0 based indexing
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return compute(sum(v*2, tl, tm, l, min(r, tm)),sum(v*2+1, tm+1, tr, max(l, tm+1), r));/*sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);*/
}

//updating one value of the array and rebuilding the path in the segtree above it
//call update(1,0,n-1,pos,new_val) pos is pos in array a and new_val is the new value that replaces the old value
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] += new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = compute(t[v*2] , t[v*2+1]);// t[v*2] + t[v*2+1];
    }
}
//lazy propagation push values to children
void Push(int v, int tl, int tr){
    if(tl!=tr){
        lazy[(v<<1)]+=lazy[v];
        lazy[((v<<1)^1)]+=lazy[v];
    }
    t[v]+=lazy[v];
    lazy[v]=0;
}

//range updates lazy propagation
//adds to range l to r x
void add(int v, int tl, int tr, int l, int r, int x){
    Push(v,tl,tr);
    if(l>tr || tl>r){
        return;
    }
    if(l<=tl && tr<=r){
        lazy[v]+=x;
        Push(v,tl, tr);
    }
    else{
        int tm=(tl+tr)>>1;
        add(v<<1,tl, tm,l, r, x);
        add(v<<1^1,tm+1,tr,l,r, x);
        t[v]=compute(t[v<<1],t[v<<1^1]);
    }
}
vi a;

vector<int>adj[210000];
int ans=0;
void dfs(int x, int p){
    int Sum=sum(1,0,INF,a[x]+1,INF);
    ans+=(Sum*a[x]);
    update(1,0,INF,a[x],1);
    for(auto g:adj[x]){
        if(g==p){
            continue;
        }
        else{
            dfs(g,x);
        }
    }
    update(1,0,INF,a[x],-1);
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    a.resize(n+1);
    A.resize(INF+1,0);
    build(1,0,INF);
    for(int i=0;i<(n-1);i++){
        int A, B;
        cin>>A>>B;
        adj[A].PB(B);
        adj[B].PB(A);
    }
    REP(i,1,n+1){
        cin>>a[i];
    }
    dfs(1,0);

    cout<<ans<<"\n";

    return 0;
}