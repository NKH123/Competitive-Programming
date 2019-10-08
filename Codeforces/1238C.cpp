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
    vi p;
    while(q--){
        int h, n;
        cin>>h>>n;
        p.clear();
        p.resize(n);
        set<int>S;
        S.clear();
        map<int, int>ind;
        ind.clear();
        REP(i,0,n){
            cin>>p[i];
            ind[p[i]]=i;
            S.insert(p[i]);
        }
        int ans=0;
        int cur=p[0];
        // S.insert(1);
        S.insert(0);
        // for(int i=1;i<n;i++){
        //     if(S.find(p[i]-1)==S.end()){
        //         ans++;
        //     }
        // }
        int I=0;
        p.PB(0);
        ind[0]=n;
        while(cur>0){
           if(cur==1 || cur==2){
                cur=0;
                break;
            }
            if(S.find(cur-1)!=S.end()){
                if(S.find(cur-2)!=S.end()){
                    cur=cur-2;
                    I=ind[cur];
                }
                else{
                    ans++;
                    cur=cur-2;
                }
            }
            else{
                // cur=p[I+1]+1;

                // cur=p[I]
                int l=0, r=n;
                int ind=-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(p[mid]>cur){
                        l=mid+1;
                    }
                    else{
                        if(p[mid]<cur){
                            ind=mid;
                            r=mid-1;
                        }
                        else{
                            l=mid+1;
                        }
                    }
                }
                cur=p[ind]+1;
            }
            //  deb(cur);
            // deb(ans);
            if(cur==1 || cur==2){
                cur=0;
                break;
            }
        }
        cout<<ans<<"\n";
        // for(int i=0;i<(n-1);i++){
        //     if(p[i+1]==(cur-1)){
        //         if(p[i+2]==(cur-2)){
        //             cur=cur-2;
        //         }
        //         else{
        //             ans++;
        //             cur=cur-2;
        //         }
        //     }
        //     else{
        //         if(p[i+1]==cur){
        //             continue;
        //         }
        //         else{
        //             cur=p[i]+1;
        //         }
        //     }
        // }

        // cout<<ans<<"\n";
    }



    return 0;
}