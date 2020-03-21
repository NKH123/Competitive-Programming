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
 int n;
 void dd(){
    vi AA=a;
    vi b(n-1);
    while(AA.size()!=1){
        b.clear();
        b.resize(AA.size()-1);
        REP(i,0,n-1){
            b[i]=abs(AA[i]-AA[i+1]);
        }
        AA=b;
    }
    // deb(a);
    int ans=AA[0];
        int A=a[0];
        for(int i=1;i<n;i++){
            if(i==(n-1)){
                A=abs(A-a[i]);
            }
            else if((a[i]>=A && a[i]>=a[i+1]) || (a[i]<=A && a[i]<=a[i+1])){
                continue;
            }
            else{
                if((i+1)==(n-1)){
                    A=0;
                    i=i+3;
                }
                else{
                    if(a[i+2]==1){
                        A=1;
                    }
                    else if(a[i+2]==2){
                        A=0;
                    }
                    else if(a[i+2]==3){
                        A=1;
                    }
                    i=i+4;
                }
            }
        }
    // deb(A);
        // deb(ans);
        // deb(A);
        if(ans!=A){
            // exit(0);
            deb(a);
            deb(ans);
            deb(A);
        }
 }


 void fun(int I){
    if(I==n){
        // return;
        dd();

    }
    else{
        a[I]=1;
        fun(I+1);
        a[I]=2;
        fun(I+1);
        a[I]=3;
        fun(I+1);
    }
 }
int32_t main(){
    ios::sync_with_stdio(false);
    for(int i=4;i<=5;i++){
       
        // cin>>n;
        n=i;
        a.clear();
        a.resize(n);
        fun(0);    
    //     REP(i,0,n){
    //         char aa;
    //         cin>>aa;
    //         a[i]=aa-'0';
    //     }
    // vi AA=a;
    // vi b(n-1);
    // while(AA.size()!=1){
    //     b.clear();
    //     b.resize(AA.size()-1);
    //     REP(i,0,n-1){
    //         b[i]=abs(AA[i]-AA[i+1]);
    //     }
    //     AA=b;
    // }
    // deb(a);
    // int ans=AA[0];
    //     int A=a[0];
    //     for(int i=1;i<n;i++){
    //         if(i==(n-1)){
    //             A=abs(A-a[i]);
    //         }
    //         else if((a[i]>=A && a[i]>=a[i+1]) || (a[i]<=A && a[i]<=a[i+1])){
    //             continue;
    //         }
    //         else{
    //             if((i+1)==(n-1)){
    //                 A=0;
    //                 i=i+3;
    //             }
    //             else{
    //                 if(a[i+2]==1){
    //                     A=1;
    //                 }
    //                 else if(a[i+2]==2){
    //                     A=0;
    //                 }
    //                 else if(a[i+2]==3){
    //                     A=1;
    //                 }
    //                 i=i+4;
    //             }
    //         }
    //     }
    // // deb(A);
    //     deb(ans);
    //     deb(A);
    //     if(ans!=A){
    //         exit(0);
    //     }
        // cout<<A<<"\n";
    }

    return 0;
}