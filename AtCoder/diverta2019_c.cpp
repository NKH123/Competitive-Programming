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

vector<string>a;
int Alast[10005];
int Bfirst[10005];
int32_t main(){
	ios::sync_with_stdio(false);
    memset(Alast,0,sizeof(Alast));
    memset(Bfirst,0,sizeof(Bfirst));
    int n;
    cin>>n;
    a.resize(n);
    int ans=0;
    REP(i,0,n){
        cin>>a[i];
        if(a[i][0]=='B'){
            Bfirst[i]=1;
        }
        if(a[i][a[i].size()-1]=='A'){
            Alast[i]=1;
        }
        for(int j=0;j<a[i].size()-1;j++){

            if(a[i][j]=='A' && a[i][j+1]=='B'){
                ans++;
            }
            
        }
    }
    // deb(ans);
    // for(int i=0;i<n;i++){
    //     deb(i);
    //     deb(Alast[i]);
    //     deb(Bfirst[i]);

    // }
    for(int i=0;i<n;i++){
        if(Alast[i]==1 && Bfirst[i]==1){
            for(int j=0;j<n;j++){
                if(i==j || !Bfirst[j])continue;
                else{
                    ans++;
                    Alast[i]=0;
                    Bfirst[i]=0;
                    Bfirst[j]=1;
                    j=n+1;
                }

            }
        }
    }
    for(int i=0;i<n;i++){
        if(Alast[i]){
            for(int j=0;j<n;j++){
                if(i==j || !Bfirst[j])continue;
                else{
                    ans++;
                    Alast[i]=0;
                    Bfirst[j]=0;
                    j=n+1;
                }

            }
        }
    }
    cout<<ans<<"\n";
    





    return 0;
}