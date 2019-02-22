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
    string s;
    cin>>s;
    vi a(26);
    //memset(a,0,sizeof(a));
    a.clear();
    a.resize(26);
    ll ans=0;
    int ct=0;
    ll init=0;
    int f=0;
    for(int i=0;i<n;i++){
        int A=s[i]-'a';
      //  deb(i);
      //  deb(s[i]);
      //  deb(A);

        if(a[A]==0){
         //   deb("first occur*********************");
            init++;
            a[A]=1;
           // deb(a);
        }
        else{
         //   deb("repeat***************************");

            ans+=(init)*(init+1)/2;
        //    deb(ans);
            int len=0;
            for(int j=i-1;j>=0;j--){
      //          deb(j);
     //           deb(s[j]);
                if(s[j]!=s[i]){
                    len++;
                }
                else{
                    break;
                }

            }
           // deb(len);
            ans+=len;
           // deb(ans);
            a.clear();
            a.resize(26);
            a[A]=1;
            init=1;
            //deb(a);
            if(i==(n-1))ans++;

            if(i==(n-1))f=1;
        }

    }
    if(!f)
    
        ans+=init*(init+1)/2;
    
    cout<<ans<<"\n";


    return 0;
}