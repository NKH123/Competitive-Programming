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

vi a;
vector<pair<int, pair<int,int > > >pre[100005];
vector<pair<int, pair<int,int > > >dum;
set<int>vals;
void pre1(){
    for(int i=1;i<=100;i++){
        dum.clear();
        vals.clear();
        for(int j=1;j<=sqrt(i);j++){
            int val=i/j;
            pre[i].PB({val,{j,j}});
            dum.PB({val,{j,j}});
            vals.insert(val);
        }
       // deb("before");

      //  deb(pre[i]);
     //   deb("after");
        for(int j=0;j<dum.size();j++){

            int val=i/dum[j].F;
           // deb(val);
            if(vals.find(val)==vals.end()){
                int r=dum[j].F;
               // deb(r);
            //handle case of sqrt here
                int l;
                if(j==dum.size()-1)
                     l=r;
                     
                else
                    l=dum[j+1].F+1;
                   
                   // deb(l);
                pre[i].PB({val,{l,r}});
                //deb({val,{l,r}});
            }
        }
        sort(pre[i].begin(),pre[i].end());
        //deb("final");
       // deb(pre[i]);

    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    //cin>>t;
    pre1();
    for(int i=0;i<10;i++){
        deb(i);
       deb(pre[i]);
    }
    deb(pre[100]);
    deb(pre[3]);
    deb(pre[5]);
    while(t--){
        int n,k;
        cin>>n>>k;
        a.resize(n);
        REP(i,0,n)cin>>a[i];
        int ans=0;
        int pos=1;
        for(int i=0;i<n;i++){
            ans=0;
            for(int j=i;j<n;j++){
                ans+=a[j]/(j-i+1);
            }
            if(ans<=k){
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