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
    int n;
    cin>>n;
    vector<pair<double, double> >AB;
    REP(i,0,n){
        double A, B;
        cin>>A>>B;
        AB.PB({A,B});
    }
    vector<pair<double, double> >BB;
    for(int i=0;i<n;i++){
        if(i==(n-1)){
            BB.PB({((AB[i].F+AB[0].F)/2.0),(AB[i].S+AB[0].S)/2.0});
        }   
        else{
            BB.PB({((AB[i].F+AB[i+1].F)/2.0),(AB[i].S+AB[i+1].S)/2.0});
        }
    }
    double ar=0;
    REP(i,0,BB.size()){
        int I=i;
        int J=(i+1)%(BB.size());
        ar+=(BB[I].F-BB[J].F)*(BB[I].S+BB[J].S)/2.0;
    }
    ar=abs(ar);
    printf("%.10lf\n",ar);

    return 0;
}