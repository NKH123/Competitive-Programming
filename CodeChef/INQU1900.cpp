#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define FAST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DECIMAL(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define hell 1000000007
#define narak 998244353
#define PI 3.14159265358979323844
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fi first 
#define se second
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
#define REVERSE(v) reverse(ALL(v))
#define endl "\n"
#define maxc(v) *max_element(ALL(v))
#define minc(v) *min_element(ALL(v))
#define sqr(a) (a)*(a)
#define GCD(m,n) __gcd(m,n)
#define LCM(m,n) m*(n/GCD(m,n))
#define inputarr(a,n) for(int xxx=0;xxx<n;++xxx) cin>>a[xxx]
#define initarr(a,n,x) for (int xxx=0;xxx<n;++xxx) a[xxx]=x
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define sz(a) (int)a.size()
#define sl(a) (int)a.length()
#define invect(data,n,commands) for(int xxx = 0;xxx<n;xxx++){int tmp;cin>>tmp;data.pb(tmp);commands}
#define inset(data,n,commands) for(int xxx = 0;xxx<n;xxx++){int tmp;cin>>tmp;data.insert(tmp);commands}
#define display(x) trav(a,x) cout<<a<<" ";cout<<endl
#define debug cerr<<"bhau"<<endl
#define between(n,a,b) (a<=n&&n<=b)
#define clamp(n,a,b) (((n)<(a))?(a):(((n)>(b))?(b):(n))) 

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

template<typename T, typename U> static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
}
template<typename T, typename U> static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define ll int
#define ld long double 
#define pii std::pair<int, int> 
#define pll std::pair<ll, ll>  
#define vi vector<int>  
#define vvi vector<vi > 
#define vii vector<pii >
#define point complex<ll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

//primes for hashing 937,991,1013,1409,1741


using namespace std;
using namespace __gnu_pbds;

    ll ps[2005][2005];
    ll pt[2005][2005];
void meowmeow321()
{
    string s;
    cin>>s;
    int n=sl(s);
    //preprocess
    ll ispal[n+1][n+1];
    for (int i = 0; i < n+1; ++i)
    {
        initarr(ispal[i],n+1,0);
        ispal[i][i]=1;
    }
    ispal[0][0]=0;
    for (int i = 1; i < n; ++i)
    {
        if(s[i-1]==s[i])
            ispal[i][i+1]=1;
        else ispal[i][i+1]=0;
    }
    for (int len = 3; len <= n; ++len)
    {
        for (int st = 1; st <= n-len+1; ++st)
        {
            ispal[st][st+len-1]=(ispal[st+1][st+len-2]&&(s[st-1]==s[st+len-2]));
        }
    }
    memset(ps,0,sizeof(ps));
    memset(pt,0,sizeof(pt));
    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < n+1; ++j)
        {
            if(ispal[i][j]){
                int l,r,k;
                l=i,r=j,k=(r-l+1);
                ps[k][r]++;
                pt[k][l]++;
            }
        }
    }
    
    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < n+1; ++j)
        {
            ps[j][i]+=ps[j-1][i];
            pt[j][i]+=pt[j-1][i];
            // if(i==7)trace(i,j,ps[j][i],pt[j][i]);

        }
    }
    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < n+1; ++j)
        {
            ps[i][j]+=ps[i][j-1];
            pt[i][j]+=pt[i][j-1];
        }
    }
    //query answer
    int q,l,r,x,y,M;
    cin>>q>>l>>r>>x>>y>>M;
    int ans=0;
    long long printshit=0;
    for (int i = 0; i < q; ++i)
    {
        l=1+(l+ans)%n;
        r=1+(r+ans)%n;
        if(l>r)swap(l,r);
        x=1+(x+ans)%M;
        y=1+(y+ans)%n;
        if(x>y)swap(x,y);
        ll yy=y;
        yy=min(y,r-l+1);
        ll xx=x;
        if(xx>yy){ans=0;continue;}
        ans=ps[yy][r]-ps[xx-1][r] - (pt[yy][l-1] - pt[xx-1][l-1]);
        printshit+=ans;
        // trace(ps[yy][r],ps[xx-1][r],(pt[yy][l-1]),(pt[xx-1][l-1]));
    }
    cout<<printshit<<endl;
}
int main()
{
    FAST;
    int testcases=1;
    cin>>testcases;
    for(int i=0;i<testcases;++i)
    {
        meowmeow321();
    }
    return 0;
}