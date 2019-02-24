#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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


int main(){
	ios::sync_with_stdio(false);
    int A,B,Q;
    cin>>A>>B>>Q;
    vl s(A),t(B),x(Q);
    REP(i,0,A){
        cin>>s[i];
    }
    REP(i,0,B){
        cin>>t[i];
    }
    REP(i,0,Q){
        cin>>x[i];
    }
    //deb(s);
    //deb(t);
    //deb(x);
    ll maxi=max(s[A-1],t[B-1]);
    ll mini=min(s[0],t[0]);
    REP(i,0,Q){
        ll ans;
       // deb(x[i]);
        if(x[i]>=maxi){
           // deb("Greater than maxi");
            ans=max(x[i]-s[A-1],x[i]-t[B-1]);
           // deb(ans);
        }
        else if(x[i]<=mini){
            //deb("Smaller than maxi");
            ans=max(s[0]-x[i],t[0]-x[i]);
            //deb(ans);
        }
        else{
            auto ss=lower_bound(s.begin(),s.end(),x[i])-s.begin();
            auto tt=lower_bound(t.begin(),t.end(),x[i])-t.begin();
            auto ssi=ss-1;
            auto tti=tt-1;
           /* deb(ss);
            deb(tt);
            deb(ssi);
            deb(tti);*/
            ans=1e18;
            ll sl,sr,tl,tr;
            if(ssi!=-1)
            sl=x[i]-s[ssi];
            else sl=1e18;
            if(tti!=-1)
            tl=x[i]-t[tti];
            else tl=1e18;
            if(ss!=A)
            sr=s[ss]-x[i];
            else sr=1e18;
            if(tt!=B)
            tr=t[tt]-x[i];
            else tr=1e18;
            /*deb(sl);
            deb(sr);
            deb(tl);
            deb(tr);*/
            //both left
            /*deb("both left");
            deb(max(sl,tl));*/

            ans=min(ans,max(sl,tl));
            //both right
           // deb("both right");
            //deb(max(sr,tr));
            ans=min(ans,max(sr,tr));

            //left and right
            //deb("left and right");
            int le,ri;
            ans=min(ans,2*sl+tr);
            ans=min(ans,2*tl+sr);
            ans=min(ans,2*tr+sl);
            ans=min(ans,2*sr+tl);
            //deb(ans);

        }

        cout<<ans<<"\n";

    }



	return 0;
}