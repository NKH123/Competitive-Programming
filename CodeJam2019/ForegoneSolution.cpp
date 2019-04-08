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

vi no;
vi A,B;
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    while(t--){

        string s;
        int n;
        cin>>s;
        no.resize(s.size());
        REP(i,0,s.size()){
            no[i]=s[i]-'0';
        }
        A.resize(s.size());
        B.resize(s.size());
        REP(i,0,s.size()){
            A[i]=no[i]/2;
            B[i]=no[i]-no[i]/2;
            if(A[i]==4 && B[i]==4){
                A[i]=3;
                B[i]=5;
            }
            else if(A[i]==3 && B[i]==4){
                A[i]=2;
                B[i]=5;
            }
            else if(A[i]==4 && B[i]==5){
                A[i]=3;
                B[i]=6;
            }
        }
        cout<<"Case #"<<T-t<<": ";
        REP(i,0,A.size()){
            cout<<A[i];
        }
        cout<<" ";
        REP(i,0,B.size()){
            cout<<B[i];
        }
        cout<<"\n";



    }



	return 0;
}