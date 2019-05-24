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

map<int, int >M;
int32_t main(){
	ios::sync_with_stdio(false);
    int n, x;
    cin>>n>>x;
    vi a(n);
    REP(i,0,n){
        cin>>a[i];
    }
    vi b(n);
    if(n==1){
        cout<<max(a[0],x*a[0])<<"\n";
        return 0;
    }
    REP(i,0,n){
        b[i]=x*a[i];
    }
    vi pref(n);

    REP(i,0,n){
        if(i==0){
            pref[i]=b[i];
        }
        else{
            pref[i]=pref[i-1]+b[i];
        }
        M[pref[i]]=i;
    }
    vi maxa(n);
    vi maxb(n);
    maxa[n-1]=max(0LL,a[n-1]);
    maxb[0]=max(0LL,b[0]);
    

    int ans=maxa[n-1];
    for(int i=n-2;i>=0;i--){
        if(maxa[i+1]+a[i]>=0){
            maxa[i]=maxa[i+1]+a[i];
            ans=max(maxa[i],ans);
        }
        else{
            maxa[i]=0;
        }
    }
    ans=max(ans,maxb[0]+maxa[1]);
    vi Maxa(n);
    Maxa[0]=max(0LL,a[0]);
    for(int i=1;i<n;i++){
        if(Maxa[i-1]+a[i]>=0){
            Maxa[i]=Maxa[i-1]+a[i];

        }else{
            Maxa[i]=0;
        }
    }
    for(int i=1;i<n;i++){

        if((maxb[i-1]+b[i])>=0){
            maxb[i]=maxb[i-1]+b[i];
            ans=max(ans,maxb[i]);
        }
        else{
            maxb[i]=0;
        }

    }
    for(int i=0;i<n;i++){
        if(i==0){
            ans=max(ans,maxb[0]+maxa[1]);
        }
        else if(i==n-1){
            if(M.find(pref[n-1]-maxb[n-1])==M.end()){
                ans=max(ans,maxb[n-1]);

            }
            else{
                int L=M[pref[n-1]-maxb[n-1]];
            // L--;
            // L++;
                ans=max(ans,maxb[n-1]+Maxa[L]);
            }
        }
        else{
            if(M.find(pref[i]-maxb[i])==M.end()){
                ans=max(ans,maxb[i]+maxa[i+1]);

            }
            else{
                int L=M[pref[i]-maxb[i]];
            // L--;
            // L++;
                ans=max(ans,maxb[i]+maxa[i+1]+Maxa[L]);
            }
           
        }
    }
    cout<<ans<<"\n";


    return 0;
}