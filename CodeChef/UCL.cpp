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
map<string,int>mm;
map<string,int>gd;
bool comp(pair<string,int> A,pair<string,int> B){
    if(A.S!=B.S)
    return A.S>B.S;
    else{
        return gd[A.F]>gd[B.F];
    }
}

int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        mm.clear();
        gd.clear();

        for(int i=0;i<12;i++){
            string ss,tt,vs;
            int g1, g2;
            cin>>ss>>g1>>vs>>g2>>tt;
            gd[ss]+=g1-g2;
            gd[tt]+=g2-g1;
            if(g1>g2){
                mm[ss]+=3;
                mm[tt]+=0;

            }
            else if(g1<g2){
                mm[tt]+=3;
                mm[ss]+=0;
            }
            else{
                //equal case
               mm[tt]+=1;
               mm[ss]+=1;
           }
       }
       vector<pair<string, int > > MM;
       MM.clear();
       vector<pair<string, int > > GD;
       GD.clear();
       for(auto g:mm){
        MM.PB({g.F,g.S});
       }
       // deb(MM);
       for(auto g:gd){
        GD.PB({g.F,g.S});
       }
       // deb(GD);
       sort(MM.begin(),MM.end(),comp);
       // deb(MM);
       string FFF=MM[0].F;
       string SSS=MM[1].F;
       // if(MM[0].S==MM[1].S){
       //  if(gd[MM[0].F]<gd[MM[1].F]){
       //      swap(FFF,SSS);
       //  }
       // }
       cout<<FFF<<" "<<SSS<<"\n";
   }



   return 0;
}