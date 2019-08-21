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

bool comp(pair<int, int>A, pair<int, int> B){
    if(A.F==B.F){
        return A.S>B.S;
    }
    else{
        return A.F<B.F;
    }
}
bool comp1(pair<int, int>A, pair<int, int> B){
    if(A.F==B.F){
        return A.S>B.S;
    }
    else{
        return A.F>B.F;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n, r;
    cin>>n>>r;
    vector<pair<int, int> >AB;
    AB.resize(n);
    vector<pair<int,int> >pos;
    vector<pair<int,int> >neg;
    REP(i,0,n){
        int A, B;
        cin>>A>>B;
        AB.PB({A,B});
        if(B>=0){
            pos.PB({A,B});
        }
        else{
            neg.PB({A+B,B});
        }
    }
    if(pos.size()!=0)
    sort(pos.begin(),pos.end(), comp);
    deb(pos);
    int cur=r;
    int f=1;
    for(int i=0;i<pos.size();i++){
        if(cur>=pos[i].F){
            cur+=pos[i].S;
        }
        else{
            f=0;
            break;
        }
    }
    if(f==0){
        cout<<"NO\n";
        return 0;
    }
    if(neg.size()!=0)
    sort(neg.begin(),neg.end(),comp1);
    deb(neg);
    f=1;
    deb(cur);
    for(int i=0;i<neg.size();i++){
        if(cur>=neg[i].F){
            cur=cur+neg[i].S;
            if(cur<0){
                f=0;
                break;
            }
        }
        else{
            f=0;
            break;
        }
    }
    if(f==1){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }



    return 0;
}