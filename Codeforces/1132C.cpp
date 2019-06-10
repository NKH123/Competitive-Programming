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
int n, q;
vi l,r;
vi wall;
vi zeros, ones, twos;
void paint(int L, int R){
    for(int i=L;i<=R;i++){
        wall[i]++;
    }
}
int cost(int I, int J){

    if(l[I]>l[J]){
        swap(I,J);
    }
    int ol1, or1,ol2, or2;
    int tl1, tr1;
    ol1=l[I];
    or1=min(l[J],r[I]);
    if(l[J]<=r[I]){
        tl1=or1;
        or1--;
        tr1=min(r[I],r[J]);
        if(r[J]<=r[I]){
            if(r[J]==r[I]){
                ol2=3;
                or2=2;
            }
            else{
                ol2=tr1+1;
                or2=r[I];
            }
        }
        else{
            tr1=r[I];
            ol2=r[I]+1;
            or2=r[J];
        }

    }
    else{
        tl1=3;
        tr1=2;
        ol2=l[J];
        or2=r[J];

    } 
    int tot=0;
    if(ol1<=or1){
        tot+=ones[or1];
        if(ol1!=0){
            tot-=ones[ol1-1];
        }
    }
    if(tl1<=tr1){
        tot+=twos[tr1];
        if(tl1!=0){
            tot-=twos[tl1-1];
        }
    }
    if(ol2<=or2){
        tot+=ones[or2];
        if(ol2!=0){
            tot-=ones[ol2-1];
        }
    }
    return tot;


}

int32_t main(){
	ios::sync_with_stdio(false);
    cin>>n>>q;
    l.resize(q),r.resize(q);
    wall.resize(n,0);
    REP(i,0,q){
        cin>>l[i]>>r[i];
        l[i]--;
        r[i]--;
        paint(l[i],r[i]);
    }
    int ans=1e18;
    int ind1, ind2;
    zeros.resize(n); ones.resize(n),twos.resize(n);
    for(int i=0;i<n;i++){
        if(i==0){
            if(wall[i]==0){
                zeros[i]=1;
            }
        }
        else{
            zeros[i]=zeros[i-1];
            if(wall[i]==0){
                zeros[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i==0){
            if(wall[i]==1){
                ones[i]=1;
            }
        }
        else{
            ones[i]=ones[i-1];
            if(wall[i]==1){
                ones[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i==0){
            if(wall[i]==2){
                twos[i]=1;
            }
        }
        else{
            twos[i]=twos[i-1];
            if(wall[i]==2){
                twos[i]++;
            }
        }
    }
    int ac=0;
    for(int i=0;i<n;i++){
        if(wall[i]>0){
            tot++;
        }
    }
    for(int i=0;i<q;i++){
        for(int j=i+1;j<q;j++){
            int C=cost(i,j);
            if(C<ans){
                ans=C;
                ind1=i;
                ind2=j;
                ac=max(ac,tot-C);
            }
        }
    }
    cout<<ac<<"\n";



	return 0;
}
