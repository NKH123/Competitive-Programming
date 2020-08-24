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


int mul(int a, int b) {
    int ans = ((a%mod)*(b%mod))%mod;
    return ans;
} 
int add(int a, int b){
    int ans = ((a%mod) + (b%mod) )%mod;
    return ans;
}
int sub(int a, int b) {
    int ans = ((a%mod) - (b%mod) + 2*mod)%mod;
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi l;
    vi h;
    vi val;
    int T = t;
    vector<pair<pair<int, int>, int> >st;
    while(t--){
        val.clear();
        int n, k, w;
        cin>>n>>k>>w;
        val.resize(n);
        l.clear();
        h.clear();
        l.resize(k);
        h.resize(k);
        REP(i,0,k){
            cin>>l[i];
        }
        int al, bl, cl, dl;
        cin>>al>>bl>>cl>>dl;
        REP(i,0,k){
            cin>>h[i];
        }
        int ah, bh, ch, dh;
        cin>>ah>>bh>>ch>>dh;
        int sum =0;
        for (int i = 0; i < k; i++) {
            if(i==0){
                int peri = ((2)*(((w%mod) + (h[0]%mod) )%mod)%mod)%mod;
                val[0] =  peri;
                st.push_back({{l[0], l[0]+w}, 0}); 
                sum = peri;
            }
            else{
                int L = l[i];
                int H = h[i];
                int peri = sum;
                int prevL = -(1e18);
                if(st.size()!=0){
                    prevL = st[st.size()-1].first.second
                } 
                // If current rectangle is taller
                if (h[i] >= h[st[st.size() - 1].second]) {
                    // If left of current does not overlap
                    if (L > prevL){
                        peri = (peri + ((2)*(((w%mod) + (h[i]%mod))%mod ))%mod)%mod;
                        st.push_back({{l[i], l[i] + w}, i});
                    }
                    else{
                    // If left of current overlaps
                        // Remove comp[letes overlaps and update perimeter]
                         while(st.size()!=0 && st[st.size() - 1].first.first > L) {
                            peri =  peri - (2*(st[st.size()-1].first.second - st[st.size()-1].first.second));
                            st.pop_back(); 
                         }
                         // Update partial overlap if any
                        int prevL = -(1e18);
                        if(st.size()!=0){
                            prevL = st[st.size()-1].first.second
                        }
                        if (L > prevL) {
                            peri = add(peri, add(mul(2,w), mul(2,h[i])));
                            st.push_back({{L, L+w}, i});
                        } 
                        else{
                            auto topp = st[st.size() - 1];
                            st.pop_back();
                            int before = topp.first.second;
                            topp.first.second = L;
                            st.push_back(topp);
                            peri = (peri - (2*(L - before + mod)%mod)%mod + mod)%mod;
                            peri = peri - h[topp.second];
                            peri = peri + h[i] - h[topp.second];
                            peri = peri + 2*(w);
                            peri = peri + h[i];
                            st.push_back({{L,L+w},i});
                        }
                         
                    }  
                }

                 // If current rectangle is smaller
                else  {
                    // If left of current does not overlap
                    if (L > prevL){
                        peri = (peri + ((2)*(((w%mod) + (h[i]%mod))%mod ))%mod)%mod;
                        st.push_back({{l[i], l[i] + w}, i});
                    }
                    else {
                        
                    }
                }
                sum = peri;
                val[i] = peri;
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++){
            ans = (ans * (val[i]%mod) )%mod;
        }
        cout<<"Case #"<<T-t<<": "<<ans<<"\n";
    }

    return 0;
}