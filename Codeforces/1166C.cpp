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


int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    vi pos;
    vi neg;
    REP(i,0,n){
        cin>>a[i];
        if(a[i]<0){
            neg.PB(-1*a[i]);
        }
        else{
            pos.PB(a[i]);
        }
    }
    int ans=0;
    sort(neg.begin(),neg.end());
    sort(pos.begin(),pos.end());
    for(int i=0;i<n;i++){
        // deb(i);
        int temp=0;
        if(a[i]<0){
            auto g=upper_bound(pos.begin(),pos.end(),-2*a[i]);
            auto h=upper_bound(pos.begin(),pos.end(),-1*a[i]);
            // g--;
            if(!(g==pos.end() && h==pos.end())){
              // deb("pos");
              temp+=(g-h+1);
              // deb(g-h+1);
              ans+=(g-h)+1;
              if(g==pos.end() || *g>(-2*a[i])){
                temp--;
                ans--;
            }
            if(*h==-1*a[i]){
                ans--;
                temp--;
            }
        }
        g=upper_bound(neg.begin(),neg.end(),-2*a[i]);
        h=upper_bound(neg.begin(),neg.end(),-1*a[i]);


            // g--;
        if(!(g==neg.end() && h==neg.end())){
            // deb("neg");
            // deb(g-h+1);
            temp+=(g-h+1);
            ans+=(g-h)+1;
            if(g==neg.end() || *g>(-2*a[i])){
                temp--;
                ans--;
            }
            if(*h==-1*a[i]){
                ans--;
                temp--;
            }
        }
            // if(*h==(-1*a[i])){
            //     ans--;
            //     temp--;
            //     deb("dec");
            //  }

    }
    else{
        auto g=upper_bound(pos.begin(),pos.end(),2*a[i]);
            // g--;
        auto h=upper_bound(pos.begin(),pos.end(),a[i]);
        if(!(g==pos.end() && h==pos.end())){
            // deb("pos");
            temp+=(g-h+1);
            // deb(g-h+1);
            ans+=(g-h)+1;
            if(g==pos.end() || *g>2*a[i]){
                temp--;
                ans--;
            }
            if(*h==a[i]){
                deb("here");
                ans--;
                temp--;
            }
        }
            // if(*h==a[i]){
            //     temp--;
            //     ans--;
            //     deb("dec");
            // }
        g=upper_bound(neg.begin(),neg.end(),2*a[i]);
        h=upper_bound(neg.begin(),neg.end(),a[i]);
            // g--;
        if(!(g==neg.end() && h==neg.end())){
            // deb("neg");
            // deb(g-h+1);
            temp+=(g-h+1);
            ans+=(g-h)+1;
            if(g==neg.end() || *g>2*a[i]){
                temp--;
                ans--;
            }
            if(*h==a[i]){
                ans--;
                temp--;
            }
        }
    }
    // deb(temp);
}
// ans-=n;
vi b(n);
REP(i,0,n){
    if(a[i]<0){
        b[i]=-1*a[i];
    }
    else{
        b[i]=a[i];
    }
}
int ct=1;
// deb(b);
for(int i=1;i<n;i++){
    if(b[i]!=b[i-1]){
        if(ct>1){
            ans+=(ct)*(ct-1)/2;
        }
        ct=1;
    }
    else{
        ct++;
    }
}
ans+=(ct*(ct-1))/2;
cout<<ans<<"\n";


return 0;
}