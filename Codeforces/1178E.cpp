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
    string s;
    cin>>s;
    int n=s.size();
    vi a,b,c;
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            a.PB(i);
        }
        else if(s[i]=='b'){
            b.PB(i);
        }
        else if(s[i]=='c'){
            c.PB(i);
        }
    }
    vi ar=a;
    vi br=b;
    vi cr=c;
    reverse(ar.begin(),ar.end());
    reverse(br.begin(),br.end());
    reverse(cr.begin(),cr.end());
    int l=0, r=n-1;
    vector<pair<char,int> >ans;
    int La=a[0], Lb=b[0], Lc=c[0], Ra=ar[0], Rb=br[0], Rc=cr[0];
    int sum=0;
    deb(a);
    deb(b);
    deb(c);
    deb(ar);
    deb(br);
    deb(cr);
    while(l<=r){
        if(a[l]==a[r]){
            int ct=1;
            if(l!=r){
                ct++;
            }
            ans.PB({a[l],ct} );
            sum+=ct;
        }
        else{
            int L,R;
            if(a[l]=='a'){
                while(a[Ra]>r){
                    Ra++;
                }
                R=a[Ra];
            }
            else if(a[l]=='b'){
                while(Rb>r){
                    Rb--;
                }
                R=Rb;
            }
            else if(a[l]=='c'){
                while(Rc>r){
                    Rc--;
                }
                R=Rc;
            }
            int len=(R-l+1);
            if(a[r]=='a'){
                while(La<l){
                    La++;
                }
                L=La;
            }
            else if(a[r]=='b'){
                while(Lb<l){
                    Lb--;
                }
                L=Lb;
            }
            else if(a[l]=='c'){
                while(Lc<l){
                    Lc--;
                }
                L=Lc;
            }
            int len1=(r-L+1);
            if(len>len1){
                r=R;

            }
            else{
                l=L;
            }
        }
    }
    int pos=(s.size())/2;
    if(pos>sum){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].F;
        }
        for(int i=(int)ans.size()-1;i>=0;i--){
            if(ans[i].second!=1){
                cout<<ans[i].F;
            }
        }
        cout<<"\n";
    }

    return 0;
}