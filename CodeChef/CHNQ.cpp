#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
//#define int ll
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

vi a;
vector<pair<int, pair<int,int > > >pre[100005];
vector<pair<int, pair<int,int > > >dum;
set<int>vals;
void pre1(){
    REP(i,0,100005){
        //deb(i);
        int inc;
        for(int j=1;j<=i;j=inc+1){
            //deb("****");
            //deb(j);
            inc=i/(i/j);
            pre[i].PB({i/j,{j,inc}});
        }
    }
}
vi sum;
int32_t main(){
    ios::sync_with_stdio(false);
    
    //cin>>t;
     pre1();
    // for(int i=0;i<10;i++){
    //     deb(i);
    //    deb(pre[i]);
    // }
    // deb(pre[100]);
    // deb(pre[3]);
    // deb(pre[5]);
    int t;
   // deb("Input t");
    cin>>t;
    while(t--){
       // deb(t);
       // deb("I'm here");
        int n,k;
        cin>>n>>k;
        sum.clear();
        a.resize(n+1);
        sum.resize(n+5);
        REP(i,1,n+1)cin>>a[i];
        int ans=0;
        
        for(int i=1;i<n+1;i++){
            // deb(a[i]);
            for(int j=0;j<pre[a[i]].size();j++){
                // deb(j);
                int l=pre[a[i]][j].S.F;
                int r=pre[a[i]][j].S.S;
                int val=pre[a[i]][j].F;
                sum[i+1-l+1]-=val;
                sum[max(1,i+1-r)]+=val;
                // deb(sum);
             

            }
        }
        // deb("before");
        // deb(sum);
        for(int i=1;i<n+1;i++){
            sum[i]=sum[i-1]+sum[i];
        }
        // deb("after");
        // deb(sum);
        int pos=1;
        for(int i=1;i<=n;i++){
            if(sum[i]<=k){
                break;
            }
            else{
                pos++;
            }
        }
        cout<<pos<<"\n";
   

    }


    return 0;
}