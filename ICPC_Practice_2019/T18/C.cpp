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
    vi x(n);
    map<int, int>M;
    set<int>SS;
    REP(i,0,n){
        cin>>x[i];
        // M[x[i]]++;
        SS.insert(x[i]);
    }
    int ans=1;
    vi two;
    vi three;
    for(int i=0;i<n;i++){
        //check for two
        int mul=1LL;
        while((x[i]+mul)<=(1e9)/* && (x[i]+mul)>=(-(1e9))*/){
            if(SS.find(x[i]+mul)!=SS.end()){
                ans=max(ans,2LL);
                two.clear();
                two.PB(x[i]);
                two.PB(x[i]+mul);
                break;
            }
            mul=mul*2LL;
            if(mul>(2*(1e9)+10)){
                break;
            }
        }

        //check for three
        mul=1LL;
        int f=0;
        while((x[i]+mul)<=1e9 || (x[i]+mul+mul)<=1e9){
            // ans=max(ans,3);
            // three.clear();
            if(SS.find(x[i]+mul)!=SS.end() &SS.find(x[i]+mul+mul)!=SS.end()){
                ans=max(ans,3LL);
                three.clear();
                three.PB(x[i]);
                three.PB(x[i]+mul);
                three.PB(x[i]+mul+mul);
                f=1;
                break;
            }
            mul=mul*2LL;
            if(mul>(2*(1e9)+10)){
                break;
            }
        }
        if(f==1){
            break;
        }
    }


    if(ans==1){
        cout<<1<<"\n";
        cout<<x[0]<<"\n";
    }
    else{
        cout<<ans<<"\n";
        if(ans==2){
            cout<<two[0]<<" "<<two[1]<<"\n";
        }
        else{
            cout<<three[0]<<" "<<three[1]<<" "<<three[2]<<"\n";
        }
    }

    return 0;
}