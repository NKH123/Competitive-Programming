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

vi dis;
vi a;
int n;
vi vis;
void bfs(){
    // queue<int>q=queue<int>();   
    // vis.clear();
    // vis.resize(a.size(),0);
    // dis.clear();
    // dis.resize(n+2,1e18);
    // for(int i=0;i<a.size();i++){
    //     if(a[i]==1){
    //         q.push(i);
    //         dis[i]=0;
    //     }
    // }
    // while(!q.empty()){
    //     int cur=q.front();
    //     q.pop();
    //     vis[cur]=1;
    //     if(cur>0){
    //         dis[cur-1]=min(dis[cur]+1,dis[cur-1]);
    //         if(vis[cur-1]==0){
    //             q.push(cur-1);
    //         }
    //     }
    //     if((cur+1)<a.size()){
    //         dis[cur+1]=min(dis[cur+1],dis[cur]+1);
    //         if(vis[cur+1]==0){
    //             q.push(cur+1);
    //         }
    //     }



    // }
    for(int i=0;i<a.size();i++){
        if(a[i]==1)continue;
        for(int j=0;j<a.size();j++){
            if(a[j]==0)continue;
            dis[i]=min(dis[i],abs(i-j));
        }
    }
}
void print(){
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            cout<<"*";
        }
        else{
            cout<<"#";
        }
    }
    cout<<"\n";
}
int32_t main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    a.resize(n+2,0);
    dis.resize(n+2,1e18);
    dis[0]=0;
    dis[n+1]=0;
    a[0]=1;
    a[n+1]=1;
    for(int i=1;i<=n;i++){
        bfs();
        int ind=0;
         for(int i=0;i<a.size();i++){
            if(dis[ind]<=dis[i]){
                ind=i;
            }
        }
        int ct=0;
        for(int i=0;i<a.size();i++){
            if(dis[i]==dis[ind]){
                ct++;
            }
        }
        int mid=ct/2;
        mid++;
        ct=0;
        for(int i=0;i<a.size();i++){
            if(dis[i]==dis[ind]){
                ct++;
                if(ct==mid){
                    ind=i;
                    break;
                }
            }
        }
        // deb(dis);
        a[ind]=1;
        dis[ind]=0;
        print();
    }



    return 0;
}