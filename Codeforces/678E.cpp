#include <bits/stdc++.h>
using namespace std;
 
int n;
 
double tab[27][27];
 
double dp[19][300007];
 
double wyn;
 
int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%lf", &tab[i][j]);
        }
    }
    dp[0][1]=1.0;
    for (int mask=1; mask<(1<<n); mask++)
    {
        if(__builtin_popcount(mask)==1){
            continue;
        }
        for (int j=0; j<n; j++)
        {   //j must me set
            if ((mask&(1<<j))==0)
            continue;
            double s=0;
            for (int k=0; k<n; k++)
            {   //k must also be set and is different from j
                if ((mask&(1<<k))==0 || k==j)
                continue;
                dp[j][mask]=max(dp[j][mask], dp[k][mask^(1<<j)]*tab[k][j]+dp[j][mask^(1<<k)]*tab[j][k]);
                //printf("%d %d    %lf %lf\n", j, k, dp[k][i^(1<<j)], tab[j][k]);
            }
            //printf("%d %d   %lf\n", j, i, dp[j][i]);
        }
    }
    for (int i=0; i<n; i++)
    wyn=max(wyn, dp[i][(1<<n)-1]);
    printf("%.9lf\n", wyn);
    return 0;
}