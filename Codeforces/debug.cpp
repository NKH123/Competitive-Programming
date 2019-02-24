#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define llp 1000000007
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


int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    REP(i,0,n)cin>>a[i];
    vi b(n);
    sort(a.begin(),a.end());
    deb(a);
    b[0]=a[0];
    b[1]=a[1];
   /* if(n>2){
        b[n-1]=a[2];
    }
    int I=3;
    for(int i=2;i<(n-1);i++){
        b[i]=a[I];
        I++;
    }*/
    if(n==2){
        REP(i,0,2){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        return 0;
    }
    int final;
    int init=max(a[2]-a[0],a[n-1]-a[2]);
    int I=2;
    for(int i=2;i<(n-1);i++){
        int init1=max(a[i]-a[0],a[n-1]-a[i]);

        if(init>init1){
            init=init1;
            I=i;
        }
    }
    int i2=max(a[n-1]-a[0],a[n-1]-a[n-2]);
    int f=0;
    if(i2<init){
        I=n-1;
        init=i2;
    }
    if(!f){
        int II=0;
        deb(I);
        b[n-1]=a[I];
        for(int i=0;i<n;i++){
            if(i==I)continue;
            b[II]=a[i];
            II++;
        }
        deb(b);
    }








    REP(i,0,n){
        cout<<b[i]<<" ";
    }
    cout<<"\n";



    return 0;
}