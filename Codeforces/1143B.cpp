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
int dig=0;
int ans=0;
bool check(){
    int num=0;
    int f=0;
    for(int i=dig-1;i>=0;i--){

        num=num*10+a[i];
    }
    if(num>n){
        return false;
    }
    return true;
}
int getans(){
    // // deb("#################");
    // deb(a);
    int ans=1;
    int f=0;
    for(int i=dig-1;i>=0;i--){
        if(f==0 && a[i]==0){
            continue;
        }
        if(f==0 && a[i]!=0){
            f=1;
        }
        ans=ans*a[i];
    }
    // deb(ans);
    return ans;
}
bool check1(int ind){
    // deb("**************");
    // deb(a);
    // deb(ind);
    int ans=0;
    for(int i=dig-1;i>=ind;i--){
        ans=ans*10+a[i];
    }
    for(int i=0;i<ind;i++){
        ans=ans*10;
    }
    // deb(ans);
    // deb("*************");
    if(ans>n){
        return false;
    }
    return true;
}
void fun(int ct){
    if(ct==-1){
        if(check()){
            // deb(a);
            ans=max(ans,getans());
        }
    }
    else{
        for(int i=9;i>=0;i--){
            a[ct]=i;
            if(check1(ct))
                fun(ct-1);
        }
    }
}
int power(int a, int b){
    if(b==0)return 1;
    if(b==1)return a;
    ans=power(a,b/2);
    ans=ans*ans;
    if(b%2==1){
        ans=a*ans;
    }
    return ans;
}
int32_t main(){
	ios::sync_with_stdio(false);
    cin>>n;
    
    int N=n;
    while(N>0){
        N=N/10;
        dig++;
    }
    a.resize(dig);
    // fun(dig-1);    
    // cout<<ans<<"\n";
    N=n;
    for(int i=dig-1;i>=0;i--){
        a[i]=(N%10);
        N=N/10;
    }
    // deb(a);
    vi prod(dig);
    prod[0]=a[0];
    for(int i=1;i<dig;i++){
        prod[i]=prod[i-1]*a[i];
    }
    int ans=prod[dig-1];
    // deb(prod);
    for(int i=dig-1;i>=0;i--){
       // deb(i);
       if(a[i]!=0 && i!=0){
        ans=max(ans,prod[i-1]*(a[i]-1)*(power(9,dig-1-i)));
        // deb(prod[i-1]*(a[i]-1)*(power(9,dig-1-i)));
    }
    if(i==0 && a[i]!=0){
        ans=max(ans,power(9,dig-1)*(max(1LL,a[i]-1)));
        // deb(power(9,dig-1)*(max(1LL,a[i]-1)));
    }


}
cout<<ans<<"\n";


return 0;
}