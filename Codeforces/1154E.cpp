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


int32_t main(){
	ios::sync_with_stdio(false);
    int n, k;
     cin>>n>>k;
    vi a(n);

    set<int>s;
    map<int, pair<int,int> >M;
    REP(i,0,n){
        cin>>a[i];
        s.insert(-a[i]);
        M[a[i]]={(i-1),(i+1)};
    }
    
    vi b(n+1);
    int f=1;
    while(s.size()!=0){
        int ele=-(*(s.begin()));
        int cur=ele;
        s.erase(s.begin());
        b[ele]=f;
        if(M[ele].F!=-1){
            int l=M[ele].F;
            M[a[l]].S=M[ele].S;
        }
        int least=M[ele].F;
        int ff=0;
        for(int i=0;i<k;i++){
            int l=M[cur].F;
            least=l;
            
            if(l!=-1){
                
                if(M[a[l]].F!=-1){
                    M[a[M[a[l]].F]].S=M[a[l]].S;

                }
                s.erase(s.find(-a[l]));
                cur=a[l];
                b[cur]=f;
            }
            else{
                ff=1;
                break;
            }
        }
        if(ff==0){
            least=M[a[least]].F;
        }
        M[ele].F=least;
        if(least!=-1)
        M[a[least]].S=M[ele].S;
        if(M[ele].S!=n){
            M[a[M[ele].S]].F=M[ele].F;

        }
        cur=ele;
        int far=M[ele].S;
        ff=0;
        for(int i=0;i<k;i++){
            int l=M[cur].S;
            far=l;
            if(l!=n){
                if(M[a[l]].S!=n){
                    M[a[M[a[l]].S]].F=M[a[l]].F;
                }
                s.erase(s.find(-a[l]));
                cur=a[l];
                b[cur]=f;

            }
            else{
                ff=1;
                break;
            }
        }
        if(ff!=1){
            far=M[a[far]].S;
        }
        if(far!=n){
            M[a[far]].F=least;
        }
        if(least!=-1)
        M[a[least]].S=far;
        if(f==1){
            f=2;
        }
        else{
            f=1;
        }
    }
    REP(i,0,n){
        cout<<b[a[i]];
    }
    cout<<"\n";




	return 0;
}