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
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
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
    ll s1,s2,s3,s4,s5,s6;
    ll c1,c2,c3,c4,c5,c6;
    ll x1,x2,y1,y2;
    cout.flush();
    ll lar=1000000000;
    while(t--){
        cout<<"Q 0 0"<<"\n";
        cin>>c1;
        cout<<"Q "<<lar<<" 0"<<"\n";
        cin>>c2;
        cout<<"Q "<<lar<<" "<<lar<<"\n";
        cin>>c3;
        cout<<"Q "<<0<<" "<<lar<<"\n";
        cin>>c4;
        s1=c1;
        s2=c2-lar;
        s3=2*lar-c3;
        s4=c4-lar;
        ll mid=s1-s2;
        mid=mid/2;
        cout<<"Q "<<mid<<" "<<0<<"\n";
        cin>>c5;
        y1=c5;
        cout<<"Q "<<mid<<" "<<lar<<"\n";
        cin>>c6;
        y2=lar-c6;
        /*s5=c5-mid;
        s6=c6-lar+mid;

        y1=(s1+s5)/2;
        x2=(s3+s6)/2;
        y2=x2-s6;
        x1=y1-s5;*/
        x1=s1-y1;
        x2=s3-y2;
        cout<<"A "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
        int x;
        cin>>x;
    }



	return 0;
}