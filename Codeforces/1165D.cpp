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
int gcd(int a, int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n;
    // cin>>n;
    set<int>s;
    vi a;
    while(t--){
        cin>>n;
        a.resize(n);
        s.clear();
        s.insert(1);
        REP(i,0,n){
            cin>>a[i];
            s.insert(a[i]);
        }
        sort(a.begin(),a.end());
        if(n==1){
            cout<<a[0]*a[0]<<"\n";
            continue;
        }
        int f=1;
        for(int i=0;i<n;i++){
            
            for(int j=1;j*j<=a[i];j++){
                if(a[i]%j==0){
                    if(s.find(j)==s.end()){
                        f=0;
                        break;
                    }
                }
                int J=a[i]/j;
                if(a[i]%J==0){
                    if(s.find(J)==s.end()){
                        f=0;
                        break;
                    }
                }
            }
            if(f==0){
                cout<<-1<<"\n";
                continue;
            }
        }
        if(f==0){
            continue;
        }
        else{
            int ans=1;
            for(int i=0;i<n;i++){
                int mul=ans*a[i];
                int div=gcd(ans,a[i]);
                mul=mul/div;
                ans=mul;
            }
            int f=0;
            for(int i=0;i<n;i++){
                if(ans==a[i])f=1;
            }
            if(f==1){
                ans=ans*a[0];
            }
            cout<<ans<<"\n";
            // else{
            //     cout<<ans*ans<<"\n";
            // }

        }
    }



	return 0;
}