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
vector<pair<int, int> >range;
vector<string>m;
vector<string>r;
set<char>dig;
vector<char>Dig;
vector<char>ans;
vector<char>Ans;
int FF=0;
void fun(int I){
    if(I==10){
        int f=0;
        for(int i=0;i<10;i++){
            if(ans[i]=='i'){
                f=1;
            }
        }
        if(f==0){
            //deb("lmao");
            FF=1;
            Ans=ans;
        }

    }
    else{
        // auto g=*(dig.begin()+I);
        char g=Dig[I];
        for(int i=range[I].F;i<=range[I].S;i++){
            if(ans[i]=='i'){
                ans[i]=g;
                fun(I+1);
                if(FF==1){
                    break;
                }
                ans[i]='i';
            }
        }
    }
}


int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    
    while(t--){
        int u;
        cin>>u;
        ans.clear();
        range.clear();
        range.resize(10,{0,9});
        m.clear();
        FF=0;
        r.clear();
        m.resize(10000);
        r.resize(10000);
        ans.resize(10);
        Dig.clear();dig.clear();
        Ans.clear();

        REP(i,0,10){
            ans[i]='i';
        }
        int I=0;
        for(int i=0;i<(10);i++){
            cin>>m[i]>>r[i];
            if(m[i]=="-1"){
                // continue;
            }
            
                for(auto g:r[i]){
                    dig.insert(g);
                }
            
        }
        while(dig.size()!=10){
            char A='A'+I;
            dig.insert(A);
            I++;
        }
        
        map<char, int >ind;
        ind.clear();
        for(auto g:dig){
            Dig.push_back(g);
            ind[g]=Dig.size()-1;
        }

        for(int i=0;i<(10);i++){
            // cin>>m[i]>>r[i];
            if(m[i]=="-1"){
                // if(r[i].size()>1){
                    range[ind[r[i][0]]].first=max(range[ind[r[i][0]]].first,1LL);
                // }
                // continue;
            }
            else{
                if(m[i].size()==r[i].size()){
                    //deb("**************");
                    //deb(m[i]);
                    //deb(r[i]);
                    //deb("************");
                    // range[m[i][0]-'0']={max(range[m[i][0]-'0'].first,1LL),min(range[m[i][0]-'0'].second,r[i][0]-'0')};
                    if(m[i].size()>1)
                    range[ind[r[i][0]]].first=max(range[ind[r[i][0]]].first,1LL);
                    range[ind[r[i][0]]].second=min(range[ind[r[i][0]]].second,(int)(m[i][0]-'0'));
                }
                else{

                }
            }
        }
        
        
        fun(0);
        cout<<"Case #"<<(T-t)<<": ";
        //deb(Dig);
        //deb(range);
        //deb(ind);
        for(int i=0;i<10;i++){
            cout<<Ans[i];
        }
        cout<<"\n";


    }

    return 0;
}