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


int32_t main(){
	ios::sync_with_stdio(false);
    int a,b,c;
    cin>>a>>b>>c;
    int A=0,B=0;
    int f=0;
    //deb(a);deb(b);deb(c);
    for(int i=0;i<=61;i++){
        int aa=a&(1LL<<i);
        int bb=b&(1LL<<i);
        int cc=c&(1LL<<i);
        //deb(i);
        //deb(aa);deb(bb);deb(cc);
        if(aa==0 && bb==0 && cc==0){
            //deb("1");
        }
        else if(aa!=0 && bb!=0 && cc==0){
           //deb("2");
            B=B|((1LL)<<i);
        }
        else if(aa!=0 && bb==0 && cc!=0){
             //deb("3");
             B=B|((1LL)<<i);
              A=A|((1LL)<<i);
        }
        else{
            //deb("4");
            f=1;
            break;
        }


    }
    if(f){
        cout<<-1<<"\n";
    }
    else{
        cout<<A<<" "<<B<<"\n";
    }



	return 0;
}