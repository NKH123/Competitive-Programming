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
    int H,n;
    cin>>H>>n;
    vi a(n);
    int sum=0;
    int great=1e18;
    REP(i,0,n){
        cin>>a[i];
        sum+=a[i];
        great=min(great,sum);
    }
    int hh=H;
    int f=0;
    for(int i=0;i<n;i++){
        hh+=a[i];
        if(hh<=0){
            f=1;
            cout<<(i+1)<<"\n";
            return 0;
        }
    }
    // deb(sum);
    if(sum>=0){
        cout<<-1<<"\n";
    }
    else{
        int moves=H/abs(sum);
        int comp=great/sum;
        moves-=comp;
        int ans=moves;
        int rem=H+ans*sum;
        // deb(rem);
        // deb(moves);
        moves=moves*n;
        int add=0;
        if(rem==0){
            cout<<ans<<"\n";
        }
        else{
            // deb(a);
            int f=0;
            /*deb(comp);
            comp++;*/
            while(f==0){
                for(int i=0;i<n;i++){
                // deb(i);

                    moves++;
                    rem=rem+a[i];
                // deb(rem);
                    if(rem<=0){
                        cout<<moves<<"\n";
                        f=1;
                        break;
                    }

                }
                if(f==1){
                    break;
                }
            }
        }
    }





    return 0;
}