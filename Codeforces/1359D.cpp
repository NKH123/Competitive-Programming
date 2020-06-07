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


vi a;
int t[4*(100005)];
int t1[4*(100005)];
vector<vector<int> >ind;
vector<int>pref;
vector<int>suff;
vi ans;
//compute function
int compute(int A,int B){
    return max(A,B);
}



int n;

//call build(1,0,n-1) 
void build( int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = pref[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] = compute(t[v*2] , t[v*2+1]);// t[v*2] + t[v*2+1];
    }
}
void build1( int v, int tl, int tr) {
    if (tl == tr) {
        t1[v] = suff[tl];
    } else {
        int tm = (tl + tr) / 2;
        build1( v*2, tl, tm);
        build1( v*2+1, tm+1, tr);
        t1[v] = compute(t1[v*2] , t1[v*2+1]);// t[v*2] + t[v*2+1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return -(1e18);
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return compute(sum(v*2, tl, tm, l, min(r, tm)),sum(v*2+1, tm+1, tr, max(l, tm+1), r));/*sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);*/
}
int sum1(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return -(1e18);
    if (l == tl && r == tr) {
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    return compute(sum1(v*2, tl, tm, l, min(r, tm)),sum1(v*2+1, tm+1, tr, max(l, tm+1), r));/*sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);*/
}
int getright(int I){
    int no=a[I];
    int ans=n;
    for(int i=(a[I]+30+1);i<=(60);i++){
        int l=0, r=ind[i].size()-1;
        int tans=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(ind[i][mid]>I){
                tans=min(tans,ind[i][mid]-1);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=min(ans,tans);
    }
    return ans;
}
int getleft(int I){
    int no=a[I];
    int ans=-1;
    for(int i=(a[I]+30+1);i<=(60);i++){
        int l=0, r=ind[i].size()-1;
        int tans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(ind[i][mid]<I){
                tans=max(tans,ind[i][mid]+1);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ans=max(ans,tans);
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    memset(t,0,sizeof(t));
    memset(t1,0,sizeof(t1));
    a.clear();
    ind.clear();
    ind.resize(61);
    a.resize(n);
    for(int i=0;i<=60;i++){
        ind[i].PB(-1);
    }
    REP(i,0,n){
        cin>>a[i];
        ind[a[i]+30].PB(i);
    }
    for(int i=0;i<=60;i++){
        ind[i].PB(n);
    }
    pref.clear();
    suff.clear();
    pref.resize(n);
    REP(i,0,n){
        if(i==0){
            pref[i]=a[i];
        }
        else{
            pref[i]=pref[i-1]+a[i];
        }
    }
    suff.resize(n);
    for(int i=(n-1);i>=0;i--){
        if(i==(n-1)){
            suff[i]=a[i];
        }
        else{
            suff[i]=suff[i+1]+a[i];
        }
    }
    build(1,0,n-1);
    build1(1,0,n-1);
    ans.clear();
    ans.resize(n);
    for(int i=0;i<n;i++){
        int I=getright(i);
        if(I==(n)){
            I--;
        }
        if((I)>=(i+1)){
            int maxi= sum(1,0,n-1,i+1,I);
            ans[i]+=max(maxi-pref[i],0LL);
        }
        I=getleft(i);
        if(I==-1){
            I++;
        }
        if((i-1)>=I){
            int Mini=sum1(1,0,n-1,I,i-1);
            ans[i]+=max(Mini-suff[i],0LL);
        }
    }
    int Ans=0;
    for(int i=0;i<n;i++){
        Ans=max(Ans,ans[i]);
    }
    cout<<Ans<<"\n";


    return 0;
}