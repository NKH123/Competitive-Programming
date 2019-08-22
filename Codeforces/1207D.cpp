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
#define mod 998244353

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

int fact[300005];
bool comp1(pair<int, int>A, pair<int, int> B){
    return (A.F<B.F);
}
bool comp2(pair<int, int>A, pair<int, int> B){
    return (A.S<B.S);
}
bool comp(pair<int, int>A, pair<int, int> B){
    if(A.F==B.F){
        return A.S<B.S;
    }
    else{
        return A.F<B.F;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<int, int> >ab;
    REP(i,0,n){
        int A, B;
        cin>>A>>B;
        ab.PB({A,B});
    }
    fact[0]=1;
    for(int i=1;i<300005;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    sort(ab.begin(),ab.end(),comp1);
    int ans=fact[n];
    int cur=1;
    int ans1=1;
    for(int i=1;i<n;i++){
        if(ab[i].F!=ab[i-1].F){
            ans1=(ans1*(fact[cur]))%mod;
            cur=1;
        }
        else{
            cur++;
        }
    }
    if(cur!=1){
        ans1=(ans1*(fact[cur]))%mod;
        cur=1;
    }
    sort(ab.begin(),ab.end(),comp2);
    int ans2=1;
    cur=1;
    for(int i=1;i<n;i++){
        if(ab[i].S!=ab[i-1].S){
            ans2=(ans2*(fact[cur]))%mod;
            cur=1;
        }
        else{
            cur++;
        }
    }
    if(cur!=1){
        ans2=(ans2*(fact[cur]))%mod;
        cur=1;
    }
    sort(ab.begin(),ab.end(),comp);
    int f=1;
    for(int i=1;i<n;i++){
        if(ab[i].F>=ab[i-1].F && ab[i].S>=ab[i-1].S){

        }
        else{
            f=0;
            break;
        }
    }
    int ans3=0;
    if(f==1){
        ans3=1;
        cur=1;
        for(int i=1;i<n;i++){
            if(ab[i].F!=ab[i-1].F || ab[i].S!=ab[i-1].S){
                ans3=(ans3*fact[cur])%mod;
                cur=1;
            }
            else{
                cur++;
            }
        }
        if(cur!=1){
            ans3=(ans3*fact[cur])%mod;
            cur=1;
        }
    }
    int fans=ans;
    fans=(ans-ans1+2*mod)%mod;
    fans=(fans-ans2+2*mod)%mod;
    fans=(fans+ans3)%mod;
    cout<<fans<<"\n";


    return 0;
}