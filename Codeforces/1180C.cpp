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

int n, q;
vi a;
vi m;
map<int,pair<int,int> >M;
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    int maxi=-1;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
        if(maxi<a[i]){
            maxi=a[i];
        }
    }
    deque<int>dq;
    for(int i=0;i<n;i++){
        dq.PB(a[i]);
    }
    int mvs=0;
    while(dq.front()!=maxi){
        mvs++;
        int A,B;
        A=dq.front();
        dq.pop_front();
        B=dq.front();
        dq.pop_front();
        M[mvs]={A,B};

        if(A<B){
            swap(A,B);
        }
        dq.push_front(A);
        dq.push_back(B);
    }
    vi b;
    for(int i=0;i<n;i++){
        int A=dq.front();
        dq.pop_front();
        b.push_back(A);
    }
    m.resize(q);
    REP(i,0,q){
        cin>>m[i];
        if(m[i]<=mvs){
            auto P=M[m[i]];
            cout<<P.F<<" "<<P.S<<"\n";
        }
        else{
            cout<<maxi<<" ";
            int Q=(m[i]-mvs)%(n-1);
            if(Q==0)Q=n-1;
            cout<<b[Q]<<"\n";

        }
    }




    return 0;
}