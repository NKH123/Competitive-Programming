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
int w, h, l, u, r, d;
bool near(int i, int j){
    if(j==(r)&&(i>=(u-1) && i<=(d-1))){
        return true;
    }
    if(i==(d) && (j>=(l-1)) && j<=(r-1)){
        return true;
    }
    if(i==(u-2) && (j>=(l-1)) && j<=(r-1)){
        return true;
    }
    if(j==(l-2)&&(i>=(u-1) && i<=(d-1))){
        return true;
    }

    return false;
}
bool n1(int i, int j){
    // if(j==(r)&&(i>=(u-1) && i<=(d-1))){
    //     return true;
    // }
    // if(i==(d) && (j>=(l-1)) && j<=(r-1)){
    //     return true;
    // }
    if(i==(u-2) && (j>=(l-1)) && j<=(r-1)){
        return true;
    }
    if(j==(l-2)&&(i>=(u-1) && i<=(d-1))){
        return true;
    }

    return false;
}

int32_t main(){
    // ios::sync_with_stdio(false);
    int t;
    cin>>t;
    // double dp[305][305];
    vector<vector<double> >dp;
    vector<vector<double> >contri;
    
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        
        
        
        cin>>w>>h>>l>>u>>r>>d;
        dp.clear();
        contri.clear();
        dp.resize(h,vector<double>(w));
        contri.resize(h,vector<double>(w));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                dp[i][j]=0;
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(n1(i,j)){
                    contri[i][j]=0.5;
                }
                else if(i>=(u-1) && i<=(d-1) && j>=(l-1) && j<=(r-1)){
                    contri[i][j]=0;
                }
                else{
                    if(i==(h-1) || j==(w-1)){
                        contri[i][j]=1;
                    }
                    else{
                        contri[i][j]=0.5;
                    }
                }
            }
        }
        dp[0][0]=1;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(i==0 && j==0){
                    continue;
                }

                    // if(i==(h-1)){
                    //     if(j!=0)
                    //     dp[i][j]=dp[i][j-1];
                    // }
                    // if(j==(w-1)){
                    //     if(i!=0){
                    //         dp[i][j]=dp[i-1][j];
                    //     }
                    // }
                // if(!near(i,j)){
                //     if(i==u-1 && j==l){
                //         dp[i][j]=dp[i][j-1]+0.5*
                //     }
                //     else{
                //         dp[i][j]=0;
                //     // dp[i][j]=0.5*dp[i-1][j]+0.5*dp[i][j-1];
                //         if(i==0){
                //             dp[i][j]=0.5*dp[i][j-1];
                //         }
                //         else if(j==0){
                //             dp[i][j]=0.5*dp[i][j-1];   
                //         }
                //         else{
                //             dp[i][j]=0.5*dp[i-1][j]+0.5*dp[i][j-1];
                //         }
                //     }
                // }
                // else{
                //     //deb("near");
                //     //deb(i);
                //     //deb(j);
                //     //if right
                //     if(j==(r)&&(i>=(u-1) && i<=(d-1))){
                //         // return true;
                //         dp[i][j]=dp[i-1][j];
                //     }

                    

                //     //if bottom
                //     if(i==(d) && (j>=(l-1)) && j<=(r-1)){
                //         // return true;
                //         dp[i][j]=dp[i][j-1];
                //     }
                //     //if up
                //     if(i==(u-2) && (j>=(l-1)) && j<=(r-1)){
                //         if(j>l-1){
                //             if(i!=0)
                //                 dp[i][j]=dp[i][j-1]+0.5*(dp[i-1][j]);
                //             else{
                //                 dp[i][j]=dp[i][j-1];
                //             }   
                //         }
                //         else{
                //             if(i==0){
                //                 dp[i][j]=0.5*dp[i][j-1];
                //             }
                //             else if(j==0){
                //                 dp[i][j]=0.5*dp[i][j-1];   
                //             }
                //             else{
                //                 dp[i][j]=0.5*dp[i-1][j]+0.5*dp[i][j-1];
                //             }
                //         }
                //     }
                //     //if left
                //     if(j==(l-2)&&(i>=(u-1) && i<=(d-1))){
                //         if(i>(u-1)){
                //             if(j!=0){
                //                 dp[i][j]=dp[i-1][j]+0.5*dp[i][j-1];
                //             }
                //             else{
                //                 dp[i][j]=dp[i-1][j];
                //             }
                //         }
                //         else{
                //             if(i==0){
                //                 dp[i][j]=0.5*dp[i][j-1];
                //             }
                //             else if(j==0){
                //                 dp[i][j]=0.5*dp[i][j-1];   
                //             }
                //             else{
                //                 dp[i][j]=0.5*dp[i-1][j]+0.5*dp[i][j-1];
                //             }
                //         }
                //     }

                    
                // }  
                dp[i][j]=0;
                if(i>0){
                    dp[i][j]+=contri[i-1][j]*dp[i-1][j];
                }
                if(j>0){
                    dp[i][j]+=contri[i][j-1]*dp[i][j-1];
                }
                

            }
        }
        //deb(contri);
        //deb(dp);
        // cout<<setprecision(12)<<dp[h-1][w-1]<<"\n";
        printf("%.9lf\n",dp[h-1][w-1]);
    }
    

    return 0;
}