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
    vector<pair<int, int > >a;
  //  unordered_set<pair<int, int > >aa;
    a.PB({0,0});
    //aa.insert({A,B});
    REP(i,0,n){
        int A,B;
        cin>>A>>B;
        a.PB({A,B});
      //  aa.insert({A,B});
    }
    ll ans=0;

    for(int i=0;i<a.size()-1;i++){
        int ff=a[i].F,fs=a[i].S,sf=a[i+1].F,ss=a[i+1].S;
        // inside
       /* int linc=sf-ff;
        int rinc=ss-fs;
        if(fs<=sf){

        }
        else{

        }
        */
        //deb(i);
        //deb(a[i]);
        //deb(a[i+1]);
        int f=0;
        if(ff<fs){
            f=0;
          
        }
        else{
            f=1;
         
        }
        //deb(f);
        if(a[i]==a[i+1])continue;
        if(f==0){
            if(fs<=sf){
                ll inc=min(sf,ss)-fs+1;
              //  deb(inc);
                ans+=inc;
            }
            else{
                continue;
            }
        }
        else{
            if(ff<=ss){
                ll inc=min(ss,sf)-ff+1;
              //  deb(inc);
                ans+=inc;
            }

        }

    }
    if(!ans)ans++;



    cout<<ans<<"\n";
	return 0;
}