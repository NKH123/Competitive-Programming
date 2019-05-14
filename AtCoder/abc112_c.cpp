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
    int n;
    cin>>n;
    vi x(n),y(n), h(n);
    REP(i,0,n){
        cin>>x[i]>>y[i]>>h[i];
    }
    for(int i=0;i<=100;i++){
        
        for(int j=0;j<=100;j++){
            // int f=0;
            int H=-1;
     
                for(int k=0;k<n;k++){
                    if(H==-1){
                        H=h[k]+abs(i-x[k])+abs(j-y[k]);
                        break;
                    }

                }
            
            
            // deb(f);
            int F=1;
            // deb(i);
            // deb(j);
            // deb(H);
            for(int k=0;k<n;k++){

                // deb(k);
                // deb(h[k]+abs(i-x[k])+abs(j-y[k]));
                if( H!=(h[k]+abs(i-x[k])+abs(j-y[k])) && h[k]!=0){
                    F=0;
                    break;
                }
            }
            if(F==1){
                cout<<i<<" "<<j<<" "<<H<<"\n";
                return 0;
            }
        }
    }



	return 0;
}