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
bool comp1(pii A, pii B){
    return A.F<B.F;
}
bool comp2(pii A, pii B){
    return A.S<B.S;
}

bool comp3(pii A, pii B){
    return A.S>B.S;
}
// bool comp3(pii A, pii B){
//     return a
// }
int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pair<int, int> >ab;
    REP(i,0,n){
        int A, B;
        cin>>A>>B;
        ab.PB({A,B});

    }
    vector<pair<int, int> >Lf;
    vector<pair<int, int> >Ls;
    vector<pair<int, int> >Rf;
    vector<pair<int, int> >Rs;
    REP(i,0,n){
        if(ab[i].F<ab[i].S){
            Lf.PB(ab[i]);
            Ls.PB(ab[i]);
        }
        else{
            Rf.PB(ab[i]);
            Rs.PB(ab[i]);
        }
    }
    sort(Lf.begin(),Lf.end(),comp1);
    sort(Ls.begin(),Ls.end(),comp2);
    sort(Rf.begin(),Rf.end(),comp1);
    sort(Rs.begin(),Rs.end(),comp2);
    //first type
    // int fis=Lf[0];
    vi seq;
    seq.PB(0);
    while(1){
        auto g=lower_bound(Lf.begin(),Lf.end(),{0,Lf[seq[seq.size()-1]].S},comp3);
        if(g==Lf.end()){
            break;
        }
        else{
            seq.PB(g-Lf.begin());

        }
    }


    //second type
    vi seq1;
    seq1.PB(0);
    while(1){
        auto g=lower_bound(Lf.begin(),Lf.end(),{0,Lf[seq[seq.size()-1]].S},comp2);
    }



    return 0;
}