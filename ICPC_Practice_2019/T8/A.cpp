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
vi a;
map<int, int>edj;
int n, m;
vector<int>used;
// int mine(int prev){
//     if(prev==-1){
//         int maxi=-1;
//         int ind=-1;
//         for(int i=1;i<=2*n;i++){
//             if(used[i]==0){
//                 if(maxi<a[i]){
//                     maxi=a[i];
//                     ind=i;
//                 }
//             }
//         }
//         used[ind]=1;
//         return ind;
//     }
//     else{
//         if(edj[prev]!=0){
//             int to=edj[prev];
//             if(used[to]==1){
//                 int maxi=-1;
//                 int ind=-1;
//                 for(int i=1;i<=2*n;i++){
//                     if(used[i]==0){
//                         if(maxi<a[i]){
//                             maxi=a[i];
//                             ind=i;
//                         }
//                     }
//                 }
//                 used[ind]=1;
//                 return ind;
//             }
//             else{
//                 used[edj[prev]]=1;
//                 return edj[prev];
//             }
//         }
//         else{
//          int maxi=-1;
//          int ind=-1;
//          for(int i=1;i<=2*n;i++){
//             if(used[i]==0){
//                 if(maxi<a[i]){
//                     maxi=a[i];
//                     ind=i;
//                 }
//             }
//         }
//         used[ind]=1;
//         return ind;
//     }
// }
// }
int ct=0;
set<pair<int, int> >sss;
int comp(){
   int p;
   cin>>p;
   used[p]=1;
   // ct++;
   return p;

}
void mine(){
    for(auto g:sss){
        int A=g.F;
        int B=g.S;
        if(a[A]<a[B]){
            swap(A,B);
        }
        cout<<A<<"\n";
        ct++;
        int b;
        cin>>b;
        used[A]=1;
        used[B]=1;
        ct++;
    }
    // deb(ct);
    sss.clear();
    for(int i=1;i<=(2*n);i++){
        if(used[i]==0){
            sss.insert({-a[i],i});
        }
    }
    while(ct<(2*n)){
        // deb(ct);
        auto A=*(sss.begin());
        sss.erase(sss.begin());
        cout<<A.S<<"\n";
        ct++;
        // deb(1);
        // deb(ct);
        // deb(1);
        if(ct==(2*n)){
            break;
        }
        int p;
        cin>>p;
        int val=a[p];
        sss.erase(sss.find({-val,p}));

        ct++;
        // deb(2);
        // deb(ct);
        // deb(2);
        // deb("*");
        // deb(ct);
    }

}
int32_t main(){
    ios::sync_with_stdio(false);
    cout.flush();
    cin>>n>>m;
    a.resize(2*n+1);
    used.clear();
    used.resize(2*n+1,0);
    REP(i,1,2*n+1){
        cin>>a[i];
    }
    set<pair<int, int> >SS;
    for(int i=0;i<m;i++){
        int A, B;
        cin>>A>>B;
        edj[A]=B;
        edj[B]=A;
        SS.insert({A,B});
    }
    int t;
    cin>>t;
    if(t==1){
        ct=0;
        for(auto g:SS){
            int A=g.F;
            int B=g.S;
            if(a[A]<a[B]){
                swap(A,B);
            }
            cout<<A<<"\n";
            ct++;
            int b;
            cin>>b;
            used[A]=1;
            used[B]=1;
            ct++;
        }
        sss.clear();
        for(int i=1;i<=(2*n);i++){
            if(used[i]==0){
                sss.insert({-a[i],i});
            }
        }
        while(ct<(2*n)){
            auto A=*(sss.begin());
            sss.erase(sss.begin());
            cout<<A.S<<"\n";
            ct++;
            int p;
            cin>>p;
            int val=a[p];
            sss.erase(sss.find({-val,p}));
            ct++;
        }
    }
    else{
        ct=0;
        while(ct<(2*n)){
            int p=comp();
            ct++;
            if(edj[p]!=0){
                cout<<edj[p]<<"\n";
                used[edj[p]]=1;
                ct++;
            }
            else{
                for(int i=1;i<=(2*n);i++){
                    if(edj[i]!=0){
                        if(used[i]==0){
                            sss.insert({min(i,edj[i]),max(i,edj[i])});
                        }
                    }
                }
                // deb(ct);
                // deb("before mine");

                mine();
                // deb("after mine")
                break;
            }
        }
    }    



    return 0;
}