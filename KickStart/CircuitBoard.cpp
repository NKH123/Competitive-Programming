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

int a[305][305];
int ax[305][305];
//x y min max;
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;

    while(t--){
        int r, c, K;
        cin>>r>>c>>K;
        memset(a,0,sizeof(a));
        memset(ax,0,sizeof(ax));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ax[i][j]=j;
                int mini=a[i][j];
                int maxi=a[i][j];

                for(int k=j-1;k>=0;k--){
                    if(a[i][k]<mini){
                        if(abs(maxi-a[i][k])>K){
                            break;
                        }
                        else{
                            mini=a[i][k];
                            ax[i][j]=k;
                        }
                    }
                    else if(a[i][k]>maxi){
                        if(abs(a[i][k]-mini)>K){
                            break;
                        }
                        else{
                            maxi=a[i][k];
                            ax[i][j]=k;
                        }
                    }
                    else{
                        ax[i][j]=k;
                    }
                }
            }
        }
        int ans=1;
        int temp=1;
        int cur=0;
        for(int i=0;i<r;i++){
            for(int j=c-1;j>=0;j--){
                temp=j-ax[i][j]+1;
                cur=j-ax[i][j]+1;
                for(int k=i+1;k<r;k++){
                    cur=min(cur,j-ax[k][j]+1);
                    temp=max(temp,(k-i+1)*cur);
                }
                ans=max(temp,ans);
            }
        }
    cout<<"Case #"<<T-t<<": "<<ans<<"\n";


}



return 0;
}