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
    vi sum(200001);
    vi xorr(200001);
    vi prod(200001);
    vi orr(200001);
    vi andd(200001);
    sum[1]=1;
    xorr[1]=1;
    prod[1]=1;
    orr[1]=1;
    andd[1]=1;
    for(int i=2;i<200001;i++){
        sum[i]=sum[i-1]+i;
        prod[i]=(prod[i-1]*i)%mod;
        xorr[i]=(xorr[i-1]^i);
        andd[i]=(andd[i-1]&i);
        orr[i]=(orr[i-1]|i);

    }
    set<int>S;
    vi a;
    vector<pair<int, int> >ans;
    while(t--){
        S.clear();
        ans.clear();
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        int Sum=0, Xor=0, Prod=1, Orr=0, And=(1LL<<62)-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            Sum+=a[i];
            Xor^=a[i];
            Prod=(Prod*a[i])%mod;
            Orr|=a[i];
            And&=a[i];
            if(Sum==sum[i+1] && Xor==xorr[i+1] && Prod==prod[i+1] &&Orr==orr[i+1] && And==andd[i+1] ){
                S.insert(i+1);
            }
        }
        Sum=0, Xor=0, Prod=1, Orr=0, And=(1LL<<62)-1;
        for(int i=n-1;i>=0;i--){
            // cin>>a[i];
            Sum+=a[i];
            Xor^=a[i];
            Prod=(Prod*a[i])%mod;
            Orr|=a[i];
            And&=a[i];

            if(Sum==sum[n-i] && Xor==xorr[n-i] && Prod==prod[n-i] &&Orr==orr[n-i] && And==andd[n-i] ){
                if(S.find(i)!=S.end()){
                    ans.push_back({i,n-i});
                }
                // S.insert(i+1);
            }
        }
        cout<<ans.size()<<"\n";
        REP(i,0,ans.size()){
            cout<<ans[i].F<<" "<<ans[i].S<<"\n";
        }


    }

    return 0;
}