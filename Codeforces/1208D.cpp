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
pi  t[4*MAXN], lazy[4*MAXN];  //n is size of array, t is the segment tree
vector<int>a;    //a is the input array from which segtree is built


//compute function
pi compute(pi A,pi B){
    // return A+B;
    if(A.F!=B.F){
        if(A.F<B.F){
            return A;
        }
        else{
            return B;
        }
    }
    else{
        if(A.S<B.S){
            return B;
        }
        else{
            return A;
        }
    }
}





//call build(1,0,n-1) 
void build( int v, int tl, int tr) {
    if (tl == tr) {
        t[v].F = a[tl];
        t[v].S = tl;
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = compute(t[v*2] , t[v*2+1]);// t[v*2] + t[v*2+1];
    }
}

//updating one value of the array and rebuilding the path in the segtree above it
//call update(1,0,n-1,pos,new_val) pos is pos in array a and new_val is the new value that replaces the old value
//don't call this if you are using lazy updates
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v].F = new_val;
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
        lazy[(v<<1)].F+=lazy[v].F;
        lazy[(v<<1^1)].F+=lazy[v].F;
    }
    t[v].F+=lazy[v].F;
    lazy[v].F=0;
}

//range updates lazy propagation
//adds to range l to r x
void add(int v, int tl, int tr, int l, int r, int x){
    Push(v,tl,tr);
    if(l>tr || tl>r){
        return;
    }
    if(l<=tl && tr<=r){
        lazy[v].F+=x;
        Push(v,tl, tr);
    }
    else{
        int tm=(tl+tr)>>1;
        add(v<<1,tl, tm,l, r, x);
        add(v<<1^1,tm+1,tr,l,r, x);
        t[v]=compute(t[v<<1],t[v<<1^1]);
    }
}



int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
    }
    build(1,0,n-1);
    vector<int>b(n);
    int II=1;
    for(int i=1;i<=n;i++){
            int I=t[1].S;
            b[I]=II;
            add(1,0,n-1,I,n-1,(-II)); 
            add(1,0,n-1,I,I,1e18);
            II++;
    }
    REP(i,0,n){
        cout<<b[i]<<" ";
    }
    cout<<"\n";




    return 0;
}