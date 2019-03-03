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
    int t;
    cin>>t;
    vl a;
    vl b;
    while(t--){
        int n;
        cin>>n;
        ll p;
        cin>>p;
        a.resize(n);
        b.clear();
        b.resize(max(n,1+int(log2(p))));
        REP(i,0,n)cin>>a[i];
        ll cost=0;
      
        int last=a.size()-1;
      deb(n);
      deb(p);
      deb(a);

        ll ans=1L<<(57);
        int pp=1+int(log2(p));
        deb(pp);
        REP(i,0,pp){
            if((1L<<i)&p){
                b[i]=1;
            }
        }
        deb("before");
        deb(b);
        if(b.size()<=a.size()){
            for(int i=0;i<n;i++){
                if((1L<<i)>=p){
                    ans=min(ans,a[i]);
                }
            }
        }
        else{
          
           for(int i=last+1;i<b.size();i++){
            if(b[i]){
                b[last]+=(1*(1L<<i)/(1L<<last));
            }
        }
       
        for(int i=0;i<=last;i++){
            if(b[i]){
                cost=cost+a[i]*b[i];
            }
        }
        ans=min(cost,ans);
    }
    deb("after resizeing b");
    deb(b);
    deb("before reduce");
    deb(ans);
    deb(last);
    for(int i=last;i>=0;i--){
        if(b[i]){
            for(int j=i-1;j>=0;j--){
                ll cleft=b[i]*((1L<<i)/(1L<<j))*a[j];
                ll act=b[i]*a[i];
                if(act>cleft){
                    b[j]+=b[i]*((1L<<i)/(1L<<j));
                    b[i]=0;
                }
            }
        }
    }
     deb("afterwards");
        deb(b);

    cost=0;
    for(int i=0;i<=last;i++){
        if(b[i]){
            cost=cost+a[i]*b[i];
        }
    }

    ans=min(cost,ans);
       deb("after reduce");
    deb(ans);
    cout<<ans<<"\n";

}



return 0;
}