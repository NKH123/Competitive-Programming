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
#define endl "\n"
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
// vector<vector<int> >ct;
vector<int>ctl;
vector<int>ctr;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ctl.clear();
        // ct.resize(201,vector<int>(n,0));
        ctl.resize(3,0);
        ctr.clear();
        ctr.resize(3,0);
        a.clear();
        a.resize(n);
        
        REP(i,0,n){
            cin>>a[i];
            // ct[a[i]][i]=1;
        }
        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        else if(n==2){
            if(a[0]==a[1]){
                cout<<2<<"\n";
            }
            else{
                cout<<1<<"\n";
            }
            continue;
        }
        // for(int i=1;i<=200;i++){
        //     for(int j=0;j<n;j++){
        //         if(j==0){

        //         }
        //         else{
        //             ct[i][j]+=ct[i][j-1];
        //         }
        //     }
        // }
        for(int i=0;i<n;i++){
            ctr[a[i]]++;
        }
        // for(int i=1;i<n;i++){
        //     ctr[i]+=ctr[i-1];
        // }
        int ans=0;
        for(int i=1;i<=1;i++){
            int cl=0;
            int cr=0;
            int l=-1, r=n;
            int fl=0;
            int fr=0;
            while(l<r){
                deb(l);
                deb(r);
                deb(ctl);
                deb(ctr);
                
                if(l>-1 && a[l]==i && fl==0){
                    cl++;
                    fl=1;
                }
                if(r<n &&a[r]==i && fr==0){
                    cr++;
                    fr=1;
                }
                deb(cl);
                deb(cr);
                if(cl==cr){
                    deb("equal");
                    int maxi=0;
                    if(l!=-1 && r!=n){
                        for(int I=1;I<=1;I++){
                            maxi=max(maxi,ctr[I]-ctl[I]);

                        }
                        ans=max(ans,2*cl+maxi);
                    }
                    l++;
                    if(l<n){
                        ctl[a[l]]++;
                    }
                    fl=0;
                    
                }
                else{
                    r--;
                    if((r+1)>=0 && (r+1)<n){
                        ctr[a[r+1]]--;
                    }
                    // if((r>=0) && (r)<n){
                    //     ctr[a[r]]--;
                    // }
                    fr=0;
                }
            }

        }
        ans=max(1LL,ans);
        cout<<ans<<"\n";
    }

    return 0;
}