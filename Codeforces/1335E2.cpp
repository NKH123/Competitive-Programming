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
vector<vector<int> >ct;
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ct.clear();
        ct.resize(201,vector<int>(n,0));
        a.clear();
        a.resize(n);
        
        REP(i,0,n){
            cin>>a[i];
            ct[a[i]][i]=1;
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
        for(int i=1;i<=200;i++){
            for(int j=0;j<n;j++){
                if(j==0){

                }
                else{
                    ct[i][j]+=ct[i][j-1];
                }
            }
        }
        int ans=0;
        for(int i=1;i<=200;i++){
            int cl=0;
            int cr=0;
            int l=-1, r=n;
            // deb(i);
            int fl=0;
            int fr=0;
            while(l<r){
                // deb("*****************");
                // deb(l);
                // deb(r);
                if(l>-1 && a[l]==i && fl==0){
                    cl++;
                    fl=1;
                }
                if(r<n &&a[r]==i && fr==0){
                    cr++;
                    fr=1;
                }

                // deb(cl);
                // deb(cr);
                if(cl==cr){
                    // deb(cl);
                    // deb(cr);
                    // deb(l);
                    // deb(r);

                    int maxi=0;
                    if(l!=-1 && r!=n){
                        for(int I=1;I<=200;I++){
                            maxi=max(maxi,ct[I][r-1]-ct[I][l]);
                        }
                        // deb(maxi);
                        ans=max(ans,2*cl+maxi);
                        // deb(ans);
                    }
                    l++;
                    fl=0;
                    
                }
                else{
                    r--;
                    fr=0;
                }
            }

        }
        cout<<ans<<"\n";
    }

    return 0;
}