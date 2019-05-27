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
vector<pair<int, int> >AA;
bool nequal(pair<int, int>A, pair<int, int>B){
    set<int>s;
    s.insert(A.F);
    s.insert(A.S);
    s.insert(B.F);
    s.insert(B.S);
    return s.size()==4;
}
bool check(pair<int, int>A,pair<int, int>B){
    // deb(A);
    // deb(B);
    set<int>s;
    s.insert(A.F);
    s.insert(A.S);
    s.insert(B.F);
    s.insert(B.S);
    vector<int>a;
    for(auto g:s){
        a.PB(g);
    }
    // deb(a);
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            int f=1;
            for(int k=0;k<AA.size();k++){
                if(AA[k].F==a[i] || AA[k].F==a[j] || AA[k].S==a[i] || AA[k].S==a[j]){

                }
                else{
                    // cout<<"failed at "<<i<<" "<<j<<" "<<k<<"\n";
                    // deb(AA[k]);
                    // return false;
                    f=0;
                    break;
                }
            }
            if(f==1)
            return true;
        }
    }
    return false;
}

int32_t main(){
	ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vector<pair<int, int> >a;
    set<pair<int, int> >aa;
    // a.resize(m);
    REP(i,0,m){
        int A, B;
        cin>>A>>B;
        if(A>B){
            swap(A,B);
        }
        a.PB({A,B});
        aa.insert({A,B});
    }
    sort(a.begin(),a.end());
    
    // AA.resize(aa.size());
    for(auto g:aa){
        AA.PB(g);
    }
   // deb(AA);
    if(AA.size()==1){
        if(AA[0].F==AA[1].F){
            cout<<"NO\n";
            return 0;
        }
        else{
            cout<<"YES\n";
            return 0;
        }
    }
    for(int i=0;i<AA.size();i++)
    {
        for(int j=i+1;j<AA.size();j++){
            // deb(i);
            // deb(j);
            if(nequal(AA[i],AA[j])){
                if(check(AA[i],AA[j])){
                    // deb("nequal yes");
                    cout<<"YES\n";
                    return 0;
                }
                else{
                    // deb("nequal no");
                    cout<<"NO\n";
                    return 0;
                }
            }
            else{
                if(check(AA[i],AA[j])){
                    // deb("eual yes");
                    cout<<"YES\n";
                    return 0;
                }
            }
        }
    }   
    cout<<"NO\n";

	return 0;
}