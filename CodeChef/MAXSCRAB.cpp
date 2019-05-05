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
    int t;
    cin>>t;
    vi a(8);
    while(t--){
        int n;cin>>n;
        string s;
        cin>>s;
        REP(i,0,8){
            cin>>a[i];
        }
        int D=0,T=0;
        int score=0;
        int ans=0;
        for(int i=0;i<(n-8+1);i++){
            D=0;
            T=0;
            score=0;
            for(int j=i;j<i+8;j++){
                score+=a[j-i];
                if(s[j]=='d'){
                    score+=a[j-i];
                }
                else if(s[j]=='t'){
                     score+=2*a[j-i];
                }
                else if(s[j]=='D'){
                    D++;
                }
                else if(s[j]=='T'){
                    T++;
                }

            }
            // deb(i);
            // deb(score);
            for(int I=0;I<D;I++){
                score=score*2;
            }
            for(int I=0;I<T;I++){
                score=score*3;
            }
            ans=max(score,ans);


        }
        cout<<ans<<"\n";


    }



	return 0;
}