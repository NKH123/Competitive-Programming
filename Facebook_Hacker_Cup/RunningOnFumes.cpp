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
#define MAXN 100005
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

vi c;

int  t[4*MAXN]; //n is size of array, t is the segment tree
vector<int>a;    //a is the input array from which segtree is built


//compute function
int compute(int A,int B){
    return min(A,B);
}





//call build(1,0,n-1) 
void build( int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
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
        return 1e18;
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
        t[v] = new_val;
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

//range updates lazy propagation
//adds to range l to r x

// vi vis;
multiset<int>M;

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    while(t--){
        M.clear();
        int n, m;
        // deb(n);
        // deb(m);
        cin>>n>>m;
        c.clear();
        c.resize(n);
        a.clear();
        a.resize(n);
        REP(i,0,n){
            cin>>c[i];
            if(c[i]!=0){
                a[i] = c[i];

            }
            else{
                a[i] = 1e18;
                c[i] = 1e18;
            }
        }
        if(n==m || m==(n-1)){
            cout<<"Case #"<<(T-t)<<": 0\n";
            continue;
        }
        // deb(c);
        // deb("A before build");
        // deb(a);
        // deb("here");
        // build(1,0,n-1);
        for(int i=1;i<=m;i++){
            M.insert(a[i]);
        }
        // deb("dsfsd");
        for(int i=m+1;i<n;i++){

            // deb("**************");
            // deb(i);
            int l=max(0LL,i-m);
            // int r=i-1;
            // deb(l);
            // deb(r);
            // int min_cost=sum(1,0,n-1,l,r);
            // update(1,0,n-1,i, min_cost + c[i]);
            // a[i]=min_cost + c[i];
            // deb(min_cost);
            // deb("///////////////");
            int min_cost = *(M.begin());
            M.insert(c[i]+min_cost);
            a[i]=min_cost + c[i];
            M.erase(M.find(a[l]));
        }
        // deb(c);
        // deb(a);
        cout<<"Case #"<<(T-t)<<": ";
        a[n-1]-=c[n-1];
        if(a[n-1]<1e18){
            cout<<a[n-1]<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }

    }

    return 0;
}