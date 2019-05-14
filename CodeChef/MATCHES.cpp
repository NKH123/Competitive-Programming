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
int dp[105][105];
// int win(int a,int b){
//     // deb(a);
//     // deb(b);
//     if(a>b){
//         swap(a,b);
//     }
//     if(dp[a][b]!=-1){
//         return dp[a][b];
//     }
//     if(a==0 || b==0){
//        // deb("lose");
//      return dp[a][b]=0;
//  }
//  else if(b%a==0){
//     return dp[a][b]=1;
// }
// else if(a==b){
//     // deb("win");
//     return dp[a][b]=1;
// }
// int times=b/a;
// int f=0;
// for(int i=0;i<times;i++){
//     b=b-a;
//     if(!win(a,b)){
//         f=1;
//         break;
//     }
// }
// if(f==1){
//     // deb("win");
//     return dp[a][b]=1;
// }
// else{
//     // deb("lose");
//     return dp[a][b]=0;
// }
// }
int win(int a,int b){
    // deb(a);
    // deb(b);
    if(a>b){
        swap(a,b);
    }
    
    if(a==0 || b==0){
       // deb("lose");
     return 0;
 }
 else if(b%a==0){
    return 1;
}
else if(a==b){
    // deb("win");
    return 1;
}
int times=b/a;
int f=0;
for(int i=0;i<times;i++){
    b=b-a;
    if(!win(a,b)){
        f=1;
        break;
    }
}
if(f==1){
    // deb("win");
    return 1;
}
else{
    // deb("lose");
    return 0;
}
}

int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    // cin>>t;
    t=1;
    memset(dp,-1,sizeof(dp));
    while(t--){
        // deb("here");
        int n, m;
        //cin>>n>>m;
        // deb("init");
        // for(int i=0;i<=10;i++){
        //     for(int j=0;j<=10;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        // int i=4,j=6;
        
        // deb(i);
        // deb(j);
        // n=i;
        // m=j;
        // if(win(n,m)==1){
        //     cout<<"Ari\n";
        // }
        // else if(win(n,m)==0){
        //     cout<<"Rich\n";
        // }
        vi loss(21);
        for(int i=0;i<=50;i++){
            for(int j=i;j<=100;j++){
                /*if(i%j!=0 && j%i!=0)*/{
                    // deb(i);
                    // deb(j);
                n=i;
                m=j;
                if(win(n,m)==1){

                 // cout<<"Ari\n";  
                }
                else if(win(n,m)==0){
                    if(win(n,m+1)==1){
                        deb(i);
                        deb(j);

                        cout<<"Rich\n";
                    }
                    loss[i]++;
                }
            }
        }
    }
    deb(loss);
        // i=4,j=6;
        // deb("afterwards");
        // for(int i=0;i<=10;i++){
        //     for(int j=0;j<=10;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // deb(i);
        // deb(j);
        // n=i;
        // m=j;
        // if(win(n,m)==1){
        //     cout<<"Ari\n";
        // }
        // else if(win(n,m)==0){
        //     cout<<"Rich\n";
        // }

}



return 0;
}