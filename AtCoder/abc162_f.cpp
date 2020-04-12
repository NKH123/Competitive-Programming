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
#define MAXN 100005
int  t[4*MAXN], lazy[4*MAXN];  //n is size of array, t is the segment tree
vector<int>preodd,preeven;    //a is the input array from which segtree is built


//compute function
int compute(int A,int B){
    // return A+B;
    return min(A,B);
}





//call build(1,0,n-1) 
void build( int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = preodd[tl];
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


int  t1[4*MAXN], lazy1[4*MAXN];  //n is size of array, t is the segment tree
// vector<int>preodd,preeven;    //a is the input array from which segtree is built


//compute function
int compute1(int A,int B){
    // return A+B;
    return min(A,B);
}





//call build(1,0,n-1) 
void build1( int v, int tl, int tr) {
    if (tl == tr) {
        t1[v] = preeven[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t1[v] = compute(t1[v*2] , t1[v*2+1]);// t[v*2] + t[v*2+1];
    }
}

//call sum(1,0,n-1,l, r)  l and r are range boundaries in 0 based indexing
int sum1(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 1e18;
    if (l == tl && r == tr) {
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    return compute(sum(v*2, tl, tm, l, min(r, tm)),sum(v*2+1, tm+1, tr, max(l, tm+1), r));/*sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);*/
}

//updating one value of the array and rebuilding the path in the segtree above it
//call update(1,0,n-1,pos,new_val) pos is pos in array a and new_val is the new value that replaces the old value



int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    // vi preodd((n)/2);
    preodd.resize(n/2);
    preeven.resize((n+1)/2);

    // vi preeven((n+1)/2);
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(i==0){
                preeven[0]=a[0];
            }
            else{
                preeven[i/2]=a[i]+preeven[i/2-1];
            }
        }
        else{
            if(i==1){
                preodd[i/2]=a[i];
            }
            else{
                preodd[i/2]=preodd[i/2-1]+a[i];
            }
        }
    }
    deb(preeven);
    deb(preodd);
    build(1,0,preodd.size()-1);
    build1(1,0,preeven.size()-1);
    int ans=-(1e18);
    int I=-1;
    for(int i=(floor(n*1.0/2)-1);i<preeven.size();i++){
        deb("even");
        deb(i);
        int temp=0;
        if(I!=-1){
            // temp=preeven[I];
            temp=sum1(1,0,preeven.size()-1,0,I);
        }
        deb(temp);
        ans=max(ans,preeven[i]-temp);
        deb(ans);
        I++;
    }
    I=-1;
    
    for(int i=(floor(n*1.0/2)-1);i<preodd.size();i++){
        deb("odd");
        deb(i);
        int temp=0;
        if(I!=-1){
            // temp=preodd[I];
            temp=sum(1,0,preodd.size()-1,0,I);
        }
        deb(temp);
        ans=max(ans,preodd[i]-temp);
        deb(ans);
        I++;
    }
    cout<<ans<<"\n";
    return 0;
}