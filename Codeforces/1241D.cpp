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



int32_t main(){
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    vi a;
    vector<int>mleft;
    vector<int>mright;
    vector<int>pleft; //strores the maximum of prefix from mright
    vector<int>pright;  //stores the minimum of the suffix from mleft 
    vector<int>dp1;
    vector<int>dp2;
    vector<int>flag1;
    vector<int>flag2;
    vector<vector<int> >dp;
    map<int, int>Red;
    while(q--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        
        dp1.clear();
        dp1.resize(n+2);
        dp2.clear();
        dp2.resize(n+2);
        mleft.clear();
        mright.clear();
        mleft.resize(n+2);
        mright.resize(n+2);
        pleft.clear();
        pright.clear();
        pleft.resize(n+2);
        pright.resize(n+2);
        int Mini=1e18;
        int Maxi=-1;
        Red.clear();
        REP(i,0,n+1){
            mleft[i]=1e18;
            mright[i]=-1;
            pright[i]=1e18;
            pleft[i]=-1;
        }
        // deb(1);







        REP(i,0,n){
            cin>>a[i];
            Red[a[i]]=1;
            
        }
        // deb(2);
        int number=0;
        map<int, int>red;
        red.clear();
        for(auto g:Red){
            g.S=(number+1);
            number++;
            red[g.F]=g.S;
            // deb(g);

        }
        // deb(Red);
        // deb(3);
        for(int i=0;i<n;i++){
            a[i]=red[a[i]];
            Mini=min(Mini,a[i]);
            Maxi=max(a[i],Maxi);
            mleft[a[i]]=min(mleft[a[i]],i+1);
            mright[a[i]]=max(mright[a[i]],i+1);
        }
        n=number;
        for(int i=n;i>=1;i--){
            if(i==n)
            pright[i]=mleft[i];
            else{
                pright[i]=min(mleft[i],pright[i+1]);
            }
        }
        // deb(4);
        for(int i=1;i<=n;i++){
            if(i==1){
                pleft[i]=mright[i];
            }
            else{
                pleft[i]=max(pleft[i-1],mright[i]);
            }
        }
        dp.clear();
        // deb(a);
        // deb(n);
        dp.resize(n+2,vector<int>(3,0));
        // The DP states are
        // dp[i][0]  number of moves to make 1 to i be sorted if ith element moves to left
        // dp[i][1]  number of moves to make 1 to i be sorted if ith element stays there
        // dp[i][2]  number of moves to make 1 to i be sorted if ith element moves to the back
        // mleft[i] is the minimum index of i in the array
        // mright[i] is the maximum index of i in the array
        for(int i=1;i<=n;i++){
            if(i==1){
                dp[i][0]=1;
                dp[i][1]=0;
                dp[i][2]=1;
            }
            else{
                if(mleft[i]>mright[i-1]){
                    dp[i][0]=i;
                    dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
                    dp[i][2]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;
                }
                else{
                    dp[i][0]=i;
                    dp[i][1]=dp[i-1][0];
                    dp[i][2]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;
                }
            }

        }
        int ans=min({dp[n][0],dp[n][1],dp[n][2]});
        // //calculate dp1
        // //initialize dp1 for 1 
        // // if(mright[Mini]>pright[Mini+1]){
        // //     dp1[Mini]=1;
        // // }

        // // //initialize dp2 for n
        // // if(mleft[Maxi]<pleft[Maxi-1]){
        // //     dp2[Maxi]=1;
        // // }
        // // for(int i=Mini+1;i<=Maxi;i++){

        // //     if(mleft[i]<pleft[i-1]){
        // //         dp1[i]=1+dp1[i-1];
        // //     }
        // //     else{
        // //         dp1[i]=dp1[i-1];
        // //     }
        // // }

        // // //calculate dp2
        // // for(int i=Maxi-1;i>=Mini;i--){
        // //     if(mright[i]>pright[i+1]){
        // //         dp2[i]=dp2[i+1]+1;
        // //     }
        // //     else{
        // //         dp2[i]=dp2[i+1];
        // //     }
        // // }
        // for(int i=Mini;i<=Maxi;i++){
        //     if(mright[i]>pright[i+1]){
        //         dp1[i]=1+dp1[i-1];
        //     }
        //     else{
        //         dp1[i]=dp1[i-1];
        //     }
        // }
        // for(int i=Maxi;i>=1;i--){
        //     if(mleft[i]<pleft[i-1]){
        //         dp2[i]=1+dp2[i+1];
        //     }
        //     else{
        //         dp2[i]=dp2[i+1];
        //     }
        // }
        // int ans=1e18;
        // deb(mleft);
        // deb(mright);
        // deb(pleft);
        // deb(pright);
        // deb(dp1);
        // deb(dp2);
        // // for(int i=Mini-1;i<=Maxi;i++){
        // //     ans=min(ans,dp1[i]+dp2[i+1]);
        // // }
        // ans=min(dp1[Maxi],dp2[Mini]);
        // dp.clear();
        
        // for(int i=1;i<=n;i++){

        // }
        cout<<ans<<"\n";

    }



    return 0;
}