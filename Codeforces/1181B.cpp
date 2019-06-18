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
int l;
string s;
vi a;
vector<int>sum(int x){
    int L=x;int R=l-1;
    vector<int>b;
    int car=0;
    int Sum=0;
    while(L>=0 || R>x){
        if(L>=0 && R>x){
            Sum=(a[L]+a[R]+car)%10;
            car=((a[L]+a[R]+car))/10;
            L--;
            R--;
            b.PB(Sum);
        }
        else{
            if(L>=0){
                Sum=(a[L]+car)%10;
                car=(a[L]+car)/10;
                L--;
                b.PB(Sum);
            }
            else{
                Sum=(a[R]+car)%10;
                car=(a[R]+car)/10;
                R--;
                b.PB(Sum);
            }
        }

    }
    if(car!=0){
        b.PB(car);
        car=0;
    }
    reverse(b.begin(),b.end());
    return b;
}
bool small(vi A, vi B){
    if(A.size()> B.size()) return false;
    if(A.size()<B.size()) return true;
    for(int i=0;i<A.size();i++){
        if(A[i]>B[i]){
            return false;
        }
        if(A[i]<B[i]){
            return true;
        }
    }
    return true;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>l;
    cin>>s;
    a.resize(l);
    REP(i,0,l){
        a[i]=s[i]-'0';
    }
    vi ans;
    ans.resize(l+l);
    REP(i,0,ans.size()){
        ans[i]=1e18;
    }

    int mid=l/2;
    int L=mid;
    while(L>=1){
        if(a[L]>0){
            vi B=sum(L-1);
            if(!small(ans,B)){
                ans.clear();
                ans=B;
            }
            break;
        }
        L--;
    }
    L=mid;
    while(L<(l-1)){
        if(a[L+1]!=0){
            vi B=sum(L);
            if(!small(ans,B)){
                ans.clear();
                ans=B;
            }
            break;
        }
        L++;
    }
    REP(i,0,ans.size()){
        cout<<ans[i];
    }
    cout<<"\n";


    return 0;
}