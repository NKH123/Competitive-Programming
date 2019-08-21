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



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<string>s;
     vector<int>Left,Right;
    while(t--){
        int n;
        cin>>n;
        s.clear();
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            s.PB(S);
        }
        Left.clear();
        Right.clear();
        Left.resize(n);
        Right.resize(n);
        int LSum=0;
        int RSum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<(n/2);j++){
                if(s[i][j]=='1'){
                    Left[i]++;
                }
            }
            for(int j=n/2;j<n;j++){
                if(s[i][j]=='1'){
                    Right[i]++;
                }
            }
            LSum+=Left[i];
            RSum+=Right[i];
        }
        int ans=abs(LSum-RSum);
        for(int i=0;i<n;i++){
            int tl=LSum;
            int tr=RSum;
            tl=tl-Left[i]+Right[i];
            tr=tr-Right[i]+Left[i];
            ans=min(ans,abs(tl-tr));
        }
        cout<<ans<<"\n";

    }



    return 0;
}