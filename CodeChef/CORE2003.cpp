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
int n, m;
char a[100][100];
// int ct[n][m];
int fun(int n, int m){
    if(n==0){
        return 0;
    }
    int ans=0;
    if(m%3==0){
        ans=(m/3)*2*n;
    }
    if(m%3==1){
        ans=(m/3)*2*n;
        
        if(n%3==0){
            ans+=(n/3)*2;
        }
        if(n%3==1){
            ans+=(n/3)*2;
        }
        if(n%3==2){
            ans+=(n/3)*2;
            ans++;
        }
    }
    if(m%3==2){
        ans=(m/3)*2*n;
        int temp=0;
        if(n%3==0){
            temp+=(n/3)*2;
            temp+=(n/3)*2;
        }
        if(n%3==1){
            temp+=(n/3)*2;
            temp+=(n/3)*2;
        }
        if(n%3==2){
            temp+=(n/3)*2;
            temp++;
            temp+=(n/3)*2;
            temp++;
        }
        ans+=max(temp,n);
    }
    return ans;
}
int Cans=0;
void brute(int I, int J){
    if(I==(n)){
        //process
        // memset(ct,0,sizeof(ct));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='L'){
                    if(j>0){
                        if(a[i][j-1]=='*'){
                            // ct[i][j]
                            ans++;
                        }
                    }
                }
                if(a[i][j]=='R'){
                    if(j<(m-1)){
                        if(a[i][j+1]=='*'){
                            ans++;
                        }
                    }
                }
                if(a[i][j]=='U'){
                    if(i>0){
                        if(a[i-1][j]=='*'){
                            ans++;
                        }
                    }
                }
                if(a[i][j]=='D'){
                    if(i<(n-1)){
                        if(a[i+1][j]=='*'){
                            ans++;
                        }
                    }
                }
            }
        }
        Cans=max(ans,Cans);
        // if(ans==7){
        //     deb("ans3");
        //     REP(i,0,n){
        //         REP(j,0,m){
        //             cout<<a[i][j]<<" ";
        //         }
        //         cout<<"\n";
        //     }
        // }
        return;

    }
    int nextJ=J+1;
    int nextI=I;
    if(nextJ==(m)){
        nextI++;
        nextJ=0;
    }
    // deb(I);
    // deb(J);
    a[I][J]='L';
    brute(nextI,nextJ);
    a[I][J]='R';
    brute(nextI,nextJ);
    a[I][J]='U';
    brute(nextI,nextJ);
    a[I][J]='D';
    brute(nextI,nextJ);
    a[I][J]='*';
    brute(nextI,nextJ);
}

int32_t main(){
    ios::sync_with_stdio(false);
    // n=3;
    // m=5;
    // brute(0,0);
    // deb(Cans);
    // for(int i=1;i<=5;i++){
    //     for(int j=1;j<=5;j++){

    //         // cin>>n>>m;
    //         n=i;
    //         m=j;
    //         if((n==2&& m==5 || m==2 && n==5 )){
    //             continue;
    //         }
    //         deb(n);
    //         deb(m);
    //         int ans=max(fun(n,m),fun(m,n));
    //         cout<<ans<<"\n";

    //         brute(0,0);

    //         deb(Cans);
    //         deb(ans);
    //         if(Cans!=ans){
    //             // if(ans==3){
    //             REP(i,0,n){
    //                 REP(j,0,m){
    //                     cout<<a[i][j]<<" ";
    //                 }
    //                 cout<<"\n";
    //         // }
    //             }
    //             exit(0);
    //         }
    //         Cans=0;
    //     }
    // }
   
    cin>>n>>m;
    if((n*m)<=12){
        brute(0,0);
        cout<<Cans<<"\n";
    }
    else
    {
        int ans=max(fun(n,m),fun(m,n));
        // cout<<ans<<"\n";

        //2 5 shit
            int count;
            //n m
            count=(m/5)*(n/2)*7;
            // deb(count);
                //taking corner to up
                // ans=max(ans,count+(n%2==1)?fun(1,5*(m/5)):0+fun(n,m%5));
                if(n%2==1){
                    ans=max(ans,count+fun(1,5*(m/5))+fun(n,m%5));
                }
                else{
                    ans=max(ans,count+fun(n,m%5));
                }
                // deb(ans);
                //taking corner to down
                // ans=max(ans,count+(n%2==1)?(fun(1,m)+fun(n-1,m%5)):(fun(n,m%5)) );
                if(n%2==1){
                    ans=max(ans,count+fun(1,m)+fun(n-1,m%5));
                }
                else{
                    ans=max(ans,count+fun(n,m%5));
                }
                // deb(ans);
            swap(n,m);
             count=(m/5)*(n/2)*7;
            //taking corner to up
                // ans=max(ans,count+(n%2==1)?fun(1,5*(m/5)):0+fun(n,m%5));
                if(n%2==1){
                    ans=max(ans,count+fun(1,5*(m/5))+fun(n,m%5));
                }
                else{
                    ans=max(ans,count+fun(n,m%5));
                }
                // deb(ans);
                //taking corner to down
                // ans=max(ans,count+(n%2==1)?(fun(1,m)+fun(n-1,m%5)):(fun(n,m%5)) );
                if(n%2==1){
                    ans=max(ans,count+fun(1,m)+fun(n-1,m%5));
                }
                
                else{
                    ans=max(ans,count+fun(n,m%5));
                }
                // deb(ans);
            cout<<ans<<"\n";

    }
    


    return 0;
}
