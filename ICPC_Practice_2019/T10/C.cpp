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


vector<pair<pair<int,int>, int> >ab;
vector<pair<pair<int,int>, int> >even;
vector<pair<pair<int,int>, int> >odd;
bool comp1(pair<pair<int, int>, int>A, pair<pair<int, int>, int>B){
    if(A.F.S>B.F.S){
        return true;
    }
    else{
        return false;
    }
}
bool comp2(pair<pair<int, int>, int>A, pair<pair<int, int>, int>B){
    if(A.F.S<B.F.S){
        return true;
    }
    else{
        return false;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int A, B;
        cin>>A>>B;
        // ab.PB({A,B,i+1});
        if(A<B){
            even.PB({{A,B},i+1});
        }
        else{
            odd.PB({{A,B},i+1});
        }
    }
    if(even.size()!=0){
        sort(even.begin(),even.end(),comp1);
    }
    if(odd.size()!=0){
        sort(odd.begin(),odd.end(),comp2);
    }
    int ans=max(even.size(),odd.size());
    // deb(odd);
    // deb(even);
    cout<<ans<<"\n";
    if(even.size()>odd.size()){
        for(int i=0;i<even.size();i++){
            cout<<even[i].S<<" ";
        }
        cout<<"\n";
    }
    else{
        for(int i=0;i<odd.size();i++){
            cout<<odd[i].S<<" ";
        }
        cout<<"\n";
    }





    return 0;
}