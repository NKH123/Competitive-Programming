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
vi p;
int x,y, a, b;
int q;
int n;
int k;
int lcm(int A, int B){
    int ans=A*B;
    ans=ans/__gcd(A,B);
    return ans;
}
bool comp(int A, int B){
    return A>B;
}
bool check(int No){
    int nox, noy, noxy;
    nox=No/a;
    noy=No/b;
    int L=lcm(a,b);
    noxy=No/(L);
    nox-=noxy;
    noy-=noxy;
    int ans=0;
    int ini=0;
    if(noxy>0){
        int ct=0;
        for(int i=ini;i<(ini+noxy);i++){
             ans=(ans+(x+y)*(p[i]/100));
             ct++;
             if(ct==(noxy)){
                ini=i+1;
                break;
             }
        }
    }
    if(x>y){
        int ct=0;
        for(int i=ini;i<(ini+nox);i++){
             ans=(ans+(x)*(p[i]/100));
             ct++;
             if(ct==(nox)){
                ini=i+1;
                break;
             }
        }
        ct=0;
        for(int i=ini;i<(ini+noy);i++){
             ans=(ans+(y)*(p[i]/100));
             ct++;
             if(ct==(noy)){
                ini=i+1;
                break;
             }
        }

    }
    else{
        int ct=0;
        for(int i=ini;i<(ini+noy);i++){
             ans=(ans+(y)*(p[i]/100));
             ct++;
             if(ct==(noy)){
                ini=i+1;
                break;
             }
        }
        ct=0;
        for(int i=ini;i<(ini+nox);i++){
             ans=(ans+(x)*(p[i]/100));
             ct++;
             if(ct==(nox)){
                ini=i+1;
                break;
             }
        }
    }
    if(ans>=k){
        return true;
    }
    else{
        return false;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    
    cin>>q;

    while(q--){

        cin>>n;
        p.clear();
        p.resize(n);
        REP(i,0,n){
            cin>>p[i];
        }
        sort(p.begin(),p.end(), comp);
        cin>>x>>a;
        cin>>y>>b;
        cin>>k;
        int l=1, r=n;
        int ans=1e18;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(ans==(1e18)){
            cout<<"-1"<<"\n";
        }
        else{
            cout<<ans<<"\n";
        }
    }   



    return 0;
}
