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



int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> d1;
    vector<int> d2;
    while(n--){
        string s;
        cin>>s;
        int n=s.size();
        int l=0, r=n-1;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                break;
            }
        }
        if(l>r){
            cout<<s<<"\n";
            continue;
        }
        d1.clear();
        d1.resize(n);
        d2.clear();
        d2.resize(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }

        }
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
        int lans=l;
        int rans=r;
        for(int i=l;i<r;i++){
            int maxd=i-l+1;
            if(d1[i]>=maxd){
                if((i+maxd-1)<r)
                    lans=max(lans,i+maxd-1);
            }
            if(d2[i]>=(maxd-1)){
                if( (i+maxd-2)<r){
                    lans=max(lans,i+maxd-2);
                }
            }


        }
        for(int i=r;i>l;i--){
            int maxd=r-i+1;
            if(d1[i]>=maxd){
                if((i-maxd+1)>l)
                    rans=min(rans,i-maxd+1);
            }
            if(d2[i]>=(maxd)){
                if( (i-maxd)>l){
                    rans=min(rans,i-maxd);
                }
            }
        }
        for(int i=0;i<l;i++){
            
            cout<<s[i];
        }
        if(lans-l>(r-rans)){
            for(int i=l;i<=lans;i++){
                cout<<s[i];
            }
        }
        else{
            for(int i=rans;i<=r;i++){
                cout<<s[i];
            }
        }
        for(int i=r+1;i<n;i++){
            cout<<s[i];
        }
        cout<<"\n";



    }


    return 0;
}