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



int32_t main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vi a(m);
    REP(i,0,m){
        cin>>a[i];
    }
    vi can(m);
    int f=1;
    for(int i=0;i<m;i++){
        if(a[i]>(n-i)){
            f=0;
        }
    }
    if(f==0){
        cout<<-1<<"\n";
        return 0;
    }
    else{
        int gap=n;
        for(int i=0;i<m;i++){
            gap=min(gap,n-1-(i+(a[i])-1));
        }
        if(gap==0){
            for(int i=0;i<m;i++){
                cout<<i+1<<" ";
            }cout<<"\n";

        }
        else{
            vi shift(m);
            for(int i=1;i<m;i++){
                can[i]=min(a[i-1]-1,gap);
            }
            for(int i=1;i<m;i++){
                shift[i]=min(gap,can[i]);
                gap-=shift[i];  
            }
            if(gap!=0){
                cout<<-1<<"\n";
            }
            else{
                int ss=0;
                for(int i=0;i<m;i++){
                    ss+=shift[i];
                    cout<<(i+1+ss)<<" ";
                }
                cout<<"\n";
            }
        }
    }

    return 0;
}