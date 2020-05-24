 #include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define fast ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0)
typedef long double ld;
typedef pair<int, int> pt;

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
inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }
// int f[(1<<20)+100];
    // int F[(1<<20)];
int pen[(1<<20)+100];
signed main(){
    
    fast;
    // memset(F,0,sizeof(F));
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        string s;
        cin>>s;
        
        // vector<int> K;
        memset(pen,-1,sizeof(pen));
        // memset(f,0,sizeof(f));
        for(int i=0;i<k;i++){
            string l;
            cin>>l;
            int tt=0;
            for(int j=0;l[j];j++){
                tt|=(1<<(l[j]-'a'));
            }
            // K.push_back(tt);
            // f[tt]++;
            pen[tt]=i+1;
        }
        // deb(K);
        for(int i=(1LL<<20)-1;i>=0;i--){
            if(pen[i]!=-1){
                for(int j=0;j<20;j++){
                    if((1<<j)&i){
                        pen[i^(1<<j)]=pen[i];
                        // f[i^(1<<j)]=1;
                    }
                }
            }
        }
            int mask=0;
            int p=-1;
            bool run=0;
            // for(int i=0;i<n;i++){
            //     mask|=(1<<(s[i]-'a'));
            //     if(pen[mask]!=-1){
            //         if(run){
            //             cout<<p<<" ";
            //             continue;
            //         }
            //         p=pen[mask];
            //         cout<<pen[mask]<<" ";
            //         run=1;
            //     }
            //     else{
            //         run=0;
            //         mask=(1<<(s[i]-'a'));
            //         run=1;
            //         cout<<pen[mask]<<" ";
            //         p=pen[mask];
            //     }
            // }
            // cout<<endl;
            int curMask=0;
            int prev=0;
            for(int i=0;i<n;i++){
                int M=curMask;
                // deb(i);
                curMask=(curMask)|((1LL<<(s[i]-'a')));
                // deb(curMask);
                // deb(pen[curMask]);
                if(pen[curMask]==-1){
                    for(int j=prev;j<=(i-1);j++){
                        cout<<pen[M]<<" ";
                        prev=j+1;
                    }
                    prev=i;
                    curMask=((1LL<<(s[i]-'a')));
                }
                else{

                }
            }
            if(prev!=n){
                for(int i=prev;i<n;i++){
                    cout<<pen[curMask]<<" ";
                }
            }
            cout<<"\n";
        }
        return 0;
    }



