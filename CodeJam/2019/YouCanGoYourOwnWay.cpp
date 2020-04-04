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
typedef pair<int,int> pii;
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
map<pii, pii>m;
map<pii,pii>par;
set< pii >vis;
int n;
int f=0;
void dfs(pii v){
    vis.insert(v);
    pii V;
    if(m.find(v)!=m.end())
        V=m[v];
    else{
        V={-10,-10};
    }
    if(!(V.F==(v.F+1) && V.S==(v.S)) && f==0){
        if(v.F+1<n && vis.find({v.F+1,v.S})==vis.end()){
            par[{v.F+1,v.S}]=v;
            dfs({v.F+1,v.S});
        }
    }
    if(!(V.F==(v.F) && V.S==(v.S+1)) && f==0){
        if(v.S+1 <n && vis.find({v.F,v.S+1})==vis.end()){
            par[{v.F,v.S+1}]=v;
            dfs({v.F,v.S+1});
        }
    }
    if(v.F==n-1 && v.S==n-1){
        //goto Label;
        f=1;
    }


}


int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    while(t--){
        f=0;
        cin>>n;
        string s;
        cin>>s;
        vis.clear();
        m.clear();
        par.clear();
        pii initi={0,0};
        // deb(s);
        for(int i=0;i<s.size();i++){
            // deb(i);
            pii next=initi;
            if(s[i]=='E'){
                next.F+=1;
            }
            else{
                next.S+=1;
            }
            // deb(initi);
            // deb(next);
            // deb(m);
            m[initi]=next;
            initi=next;
        }
        // deb("outside");
        // deb(m);
        dfs({0,0});

        pii cur={n-1,n-1};
        vector<char>ans;
        // deb(par);
        // deb(m);
        while(!(cur.F==0 && cur.S==0) ){
            pii parent=par[cur];
            // deb(cur);
            // deb(parent);
            if(parent.F==cur.F){
                ans.PB('S');
            }
            else{
                ans.PB('E');
            }
            cur=parent;
        }
        cout<<"Case #"<<T-t<<": ";
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
        }
        cout<<"\n";

    }



    return 0;
}