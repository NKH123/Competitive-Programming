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

int n;
vi a;
vi pos;
vector<pair<int, int> > ans;
int ct=0;
void _swap(int A, int B){
    int go=a[A];
    int come=a[B];
    swap(a[A],a[B]);
    swap(pos[go],pos[come]);
    // cout<<A<<" "<<B<<"\n";
    ans.PB({A,B});
}

int32_t main(){
	ios::sync_with_stdio(false);

    cin>>n;
    a.resize(n+1);
    pos.resize(n+1);
    REP(i,1,n+1){
        cin>>a[i];
        pos[a[i]]=i;
    }
    // if(a[1]!=1){
    //     _swap(1,pos[1]);
    // }
    for(int i=1;i<=(n/2);i++){
        // deb("***************");
        // deb(i);
        // deb(a);
        if(a[i]!=i){
            if(pos[i]>n/2){
                // deb(pos[i]);
                int go=pos[i];
                // if(go!=n){
                // _swap(go,1);
                // _swap(1,n);
                // _swap(n,i);
                
                // _swap(1,go);
                if(2*abs(go-i)>=(n)){
                    _swap(i,go);
                }
                else{
                    _swap(1,go);
                    _swap(1,n);
                    _swap(n,i);
                    _swap(go,1);
                }

            }
            else{
                int go=pos[i];
                _swap(go,n);
                _swap(n,i);

            }
        }
        // deb(i);
        // deb(a);
        // deb(pos);
    }
    for(int i=(n/2)+1;i<=n;i++){
        if(a[i]!=i){
            if(pos[i]<=(n/2)){

                int go=pos[i];
                if(2*abs(go-i)>=(n)){
                    _swap(i,go);
                }
                else{
                    _swap(go,n);
                    _swap(1,n);
                    _swap(1,i);
                    _swap(1,n);
                }
            }
            else{
                int go=pos[i];
                _swap(1,go);
                _swap(1,i);
                _swap(1,go);
            }
        }
        // deb(i);
        // deb(a);
        // deb(pos);
    }
    // deb(a);
    cout<<ans.size()<<"\n";
    REP(i,0,ans.size()){
        if(ans[i].F>ans[i].S)swap(ans[i].F,ans[i].S);
        cout<<ans[i].F<<" "<<ans[i].S<<"\n";
    }


    return 0;
}