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


// map< pair<int, int > , int>Count;
int Count[10][10];
set<int>used;
vector<int>vis(10,0);
int foo(int from, int to, int x, int y){
    vis.clear();
    vis.resize(10,0);
    queue<int>Q=queue<int>();
    vector<int>dis(10,1e18);
    dis[from]=0;
    Q.push(from);
    while(Q.size()!=0){
        auto ele=Q.front();
        Q.pop();
        vis[ele]=1;
        int x1=(ele+x)%10;
        int y1=(ele+y)%10;
        dis[x1]=min(dis[x1],dis[ele]+1);
        dis[y1]=min(dis[y1],dis[ele]+1);
        if(!vis[x1]){
            Q.push(x1);
        }
        if(!vis[y1]){
            Q.push(y1);
        }
    }
    return dis[to];

}
int fun(int from, int to, int x, int y){
    int ans=1+foo((from+x)%10,to,x,y);
    ans=min(ans,1+foo((from+y)%10,to,x,y));
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    vector<int>A(s.size());
    for(int i=0;i<s.size();i++){
        int aa=s[i]-'0';
        A[i]=aa;
    }
   vector<vector<int> >Ans(10,vector<int>(10));
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            int ans=0;
            for(int I=0;I<10;I++){
                for(int J=0;J<10;J++){
                    Count[I][J]=fun(I,J,i,j);
                }
            }

            // deb("here");
            for(int k=1;k<s.size();k++){
                // deb(k);
                ans+=(Count[A[k-1]][A[k]]-1);
                if(Count[A[k-1]][A[k]]>=1e18){
                    ans=-1;
                    break;
                }
            }
            
            

            // cout<<ans<<" ";
            Ans[i][j]=ans;
            Ans[j][i]=ans;
        }
        // cout<<"\n";
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<Ans[i][j]<<" ";
        }
        cout<<"\n";
    }



    return 0;
}