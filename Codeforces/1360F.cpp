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
    int t;
    cin>>t;
    vector<string>a;
    while(t--){
        int n, m;
        cin>>n>>m;
        a.clear();
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            a.push_back(s);
        }
        string ans="-1";
        for(int i=0;i<m;i++){
            int f=0;
            string temp=a[0];
            for(int j=0;j<26;j++){
                char A='a'+j;
                temp[i]=A;
                int FF=1;
                for(int k=0;k<n;k++){
                    int ct=0;
                    for(int l=0;l<m;l++){
                        if(temp[l]!=a[k][l]){
                            ct++;
                        }

                    }
                    if(ct>1){
                        FF=0;
                    }
                }
                if(FF==1){
                    f=1;
                    ans=temp;
                }
            }
            
        }

        cout<<ans<<"\n";
    }

    return 0;
}