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

int a[1005][1005];
int ct=0;
queue<pair<int, int > > qq;
int h,w;
int X[4]{0,1,0,-1};
int Y[4]{1,0,-1,0};
int Count[1005][1005];
void pq(){
    queue<pair<int, int> > q=qq;
    while (!q.empty())
    {
       cout << q.front() << " ";
        q.pop();
    }
    cout << std::endl;
    cout<<"\n";
}
void bfs(){
    // deb(qq);
    while(!qq.empty()){
        auto G=qq.front();
        qq.pop();
        int f=0;
        // deb(G);
        for(int i=0;i<4;i++){
         int j=i;
                //if(i==0 && j==0)continue;
         if(G.F+X[i] >=h || G.F+X[i] <0)continue;
         else if(G.S+Y[j] >=w || G.S+Y[j] <0)continue;
         else if(a[G.F+X[i]][G.S+Y[j]]==0){
            f=1;
            break;
        }


    }
    if(f==1){
        // ct++;
        for(int i=0;i<4;i++){
         int j=i;
                     //if(i==0 && j==0)continue;
         if(G.F+X[i] >=h || G.F+X[i] <0)continue;
         else if(G.S+Y[j] >=w || G.S+Y[j] <0)continue;
         else if(a[G.F+X[i]][G.S+Y[j]]==0){
            a[G.F+X[i]][G.S+Y[j]]=1;
            qq.push({G.F+X[i],G.S+Y[i]});
            Count[G.F+X[i]][G.S+Y[j]]=Count[G.F][G.S]+1;
            ct =max(ct,Count[G.F+X[i]][G.S+Y[j]]);
        }

    }
}
// for(int i=0;i<h;i++){
//     for(int j=0;j<w;j++){
//         cout<<a[i][j]<<" ";
//     }
//     cout<<"\n";
// }
// cout<<"Queue is \n";
// pq();
}
}


int32_t main(){
   ios::sync_with_stdio(false);

   memset(Count,0,sizeof(Count));
   cin>>h>>w;
 // for(int i=0;i<4;i++){
 //   {   int j=i;
 //        cout<<X[i]<<","<<Y[j]<<" ";
 //    }
 //    cout<<"\n";
 // }
   for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        char c;
        cin>>c;
        if(c=='.'){
            a[i][j]=0;
        }
        else{
            qq.push({i,j});
            a[i][j]=1;
            Count[i][j]=0;
        }
    }
}
// for(int i=0;i<h;i++){
//     for(int j=0;j<w;j++){
//         cout<<a[i][j]<<" ";
//     }
//     cout<<"\n";
// }
// pq();
bfs();
//ct=-1;

cout<<ct<<"\n";



return 0;
}