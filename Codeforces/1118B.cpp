#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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


int main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vl a(n);
    ll sum=0;
    REP(i,0,n){
        cin>>a[i];
        sum+=a[i];
    }
    vl oddf(n);
    vl oddr(n);
    vl evef(n);
    vl ever(n);
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
   

    int I=0;
    for(int i=0;i<n;i=i+2){
        if(i==0){
            oddf[0]=a[0];
        }
        else{
            oddf[I]=oddf[I-1]+a[i];
        }
        I++;
    }
    I=0;
    for(int i=1;i<n;i=i+2){
        if(i==1){
            evef[0]=a[1];

        }


        else{
            evef[I]=evef[I-1]+a[i];

        }
        I++;
    }

    
    if(n%2){
        I=0;
        for(int i=n-1;i>=0;i=i-2){
            if(i==(n-1)){
                oddr[0]=a[i];
            }
            else{
                oddr[I]=oddr[I-1]+a[i];
            }
            I++;
        }
        I=0;
        for(int i=n-2;i>=0;i=i-2){
            if(i==(n-2)){
                ever[0]=a[i];
            }
            else{
                ever[I]=ever[I-1]+a[i];
            }
            I++;
        }
    }
    else{
        I=0;
        for(int i=n-2;i>=0;i=i-2){
            if(i==(n-2)){
                oddr[0]=a[i];
            }
            else{
                oddr[I]=oddr[I-1]+a[i];
            }
            I++;
        }
        I=0;
        for(int i=n-1;i>=0;i=i-2){
            if(i==(n-1)){
                ever[0]=a[i];
            }
            else{
                ever[I]=ever[I-1]+a[i];
            }
            I++;
        }
    }

    int f=0;
    if(sum%2){
        f=1;
    }
    vl ODD(n);
    vl EVEN(n);
    int pt;
    pt=n/2;
    if(n%2){

        pt++;
    }
    REP(i,0,pt){
        ODD[i]=oddr[pt-1-i];
    }
    if(n%2){

        pt--;
    }
    REP(i,0,pt){
        EVEN[i]=ever[pt-1-i];
    }
    REP(i,0,n){
        oddr[i]=ODD[i];
    }
    REP(i,0,n){
        ever[i]=EVEN[i];
    }

    ll ans=0;
    for(int i=0;i<n;i++){
     /*   if(f==1){
            if(a[i]%2){*/
        int ind=i/2;
       
        if(i%2){
            ll pre1=0;
            if(ind-1 >=0)
             pre1=evef[ind-1];
         ll pre2=0;
         pre2=oddf[ind];
         pre1+=oddr[ind+1];
         pre2+=ever[ind+1];
        
         if(pre1==pre2){
            ans++;
        }
    }
    else{
        ll pre1=0;
        ll pre2=0;
        if(ind-1>=0){
            pre1=oddf[ind-1];
            pre2=evef[ind-1];

        }
        pre1+=ever[ind];
        pre2+=oddr[ind+1];
          if(pre1==pre2){
            ans++;
        }

    }
}

cout<<ans<<"\n";





return 0;
}