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
string B;
bool inn(int j){
    char A=j+'a';
    REP(i,0,B.size()){
        if(B[i]==A){
            return true;
        }
    }
    return false;
}

int main(){
	ios::sync_with_stdio(false);

    int t;
    cin>>t;
    string A;

    int a[26];
    vector<vector <int> > b;
    while(t--){
        REP(i,0,26)a[i]=0;
        b.clear();
        B="";
        int n;
        cin>>n;
        cin>>A;
        for(int i=0;i<A.size();i++){
            if(a[A[i]-'a']==0){
                B=B+A[i];
                a[A[i]-'a']++;
            }
            else{
                a[A[i]-'a']++;
            }
        }
        //deb(B);
        char first=B[0];
        b.resize(n);
        for(int i=0;i<n;i++){
            b[i].resize(26);
        }
        b[0][A[0]-'a']++;
        for(int i=1;i<n;i++){
            for(int j=0;j<26;j++){
                b[i][j]=b[i-1][j];
            }
            b[i][A[i]-'a']++;
        }
        //deb(b);
        ll ans=0;

        for(int i=0;i<n;i++){
            if(A[i]==B[0]){
                 ll tans=1;
                for(int j=0;j<26;j++){
                   
                    if(j!=(B[0]-'a')){
                        if(inn(j)){
                            //deb(j);
                            //deb('a'+j);
                            tans=((tans%mod)*((b[n-1][j]-b[i][j])%mod))%mod;
                        }
                    }
                }
                ans+=tans;
                ans=ans%mod;
            }
        }
        cout<<ans<<"\n";

    }


    return 0;
}