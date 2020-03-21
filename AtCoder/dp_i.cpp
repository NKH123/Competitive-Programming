
vector<double>a;
double dp[3005][3005];
double fun(int i, int k){
    if(k<0){
        return 0;
    }
    if(k>i){
        return 0;
    }
    if(i==1){
        if(k==1){
            return a[i];
        }
        if(k==0){
            double ans=1-a[i];
            return ans;
        }
    }
    if(dp[i][k]!=-1){
        return dp[i][k];
    }
    dp[i][k]=a[i]*fun(i-1,k-1)+(1-a[i])*fun(i-1,k);
    return dp[i][k];
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    a.resize(n+1);
    for(int i=0;i<3005;i++){
        for(int j=0;j<3005;j++){
            dp[i][j]=-1;
        }
    }

    REP(i,1,n+1){
        cin>>a[i];
    }
    double ans=0;
    for(int i=(n/2)+1;i<=n;i++){
        ans+=fun(n,i);
    }
    printf("%0.12lf\n",ans);
    return 0;
}