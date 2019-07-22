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
// bool prime[1100];
vector<bool>prime(2100,true);
vi primes;
void seive(){
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<2100;i++){
        if(prime[i]==false)continue;
        for(int j=i*i;j<2100;j=j+i){
            prime[j]=false;
        }
    }
    for(int i=0;i<2100;i++){
        if(prime[i]){
            primes.PB(i);
        }
    }
}
int deg[1100];

int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int three=(n/3);
    if(n%3!=0){
        three--;
    }
    seive();
    int M=three*3;
    int start=1;
    vector<pair<int, int> >edj;
    // if((n%3)==1){
    //     start=5;
    //     edj.PB({1,2});
    //     edj.PB({1,3});
    //     edj.PB({2,3});
    //     edj.PB({3,4});
    //     edj.PB({2,4});
    // }
    // else if((n%3)==2){
    //     start=6;
    //     edj.PB({1,2});
    //     edj.PB({1,3});
    //     edj.PB({2,3});
    //     edj.PB({3,4});
    //     edj.PB({2,4});
    //     edj.PB({1,5});
    //     edj.PB({4,5});
    // }
    // for(int i=start;i<=n;i=i+3){
    //     edj.PB({i,i+1});
    //     edj.PB({i+1,i+2});
    //     edj.PB({i,i+2});
    // }
    // int P=*(lower_bound(primes.begin(),primes.end(),edj.size()));
    // // deb(primes);
    // deb(P);
    // if(edj.size()<P){
    //     // deb("h2");
    //     // int I=start;
    //     // deb(I);
    //     // while(edj.size()!=P && (I)<=n){

    //     //     if((I+3)>n )break;
    //     //     edj.PB({I,I+3});
    //     //     I+=1;
    //     // }
    //     if((n%3)==2){
    //         edj.PB({5,6});
    //     }
    //     if((n%3)==1){
    //         edj.PB({})
    //     }

    // }
    memset(deg,0,sizeof(deg));
    for(int i=1;i<n;i++){
        edj.PB({i,i+1});
        deg[i]++;
        deg[i+1]++;
    }
    edj.PB({n,1});
    deg[n]++;
    deg[1]++;
    int P=*(lower_bound(primes.begin(),primes.end(),edj.size()));
    // deb(P);
    // for(int i=1;i<=n;i++){
        // cout<<deg[i]<<" ";
    // }
    // cout<<"\n";
    if(P>edj.size()){
        for(int i=1;i<=(n-2);i++){
            if(deg[i]==2 && deg[i+2]==2){
                edj.PB({i,i+2});
                deg[i]++;
                deg[i+2]++;
            }
            if(P==edj.size()){
                break;
            }
        }
        
    }
    cout<<edj.size()<<"\n";
    for(int i=0;i<edj.size();i++){
        cout<<edj[i].F<<" "<<edj[i].S<<"\n";
    }

    return 0;
}