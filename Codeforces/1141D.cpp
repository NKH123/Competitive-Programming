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

    vector<int>a1[27];
    vector<int>a2[27];
    int32_t main(){
    	ios::sync_with_stdio(false);
        int n;
        cin>>n;
        string s;
        string t;
        cin>>s;
        cin>>t;
        for(int i=0;i<n;i++){
            if(s[i]!='?')
                a1[s[i]-'a'].PB(i+1);
            else{
                a1[26].PB(i+1);
            }
        }
        for(int i=0;i<n;i++){
            if(t[i]!='?')
                a2[t[i]-'a'].PB(i+1);
            else{
                a2[26].PB(i+1);
            }
        }
        // deb(s);
        // deb(t);
        vector<pair<int,int > >ans;
        for(int i=0;i<26;i++){
            if(a1[i].size()>0){
                int mini=min(a1[i].size(),a2[i].size());
                for(int j=0;j<mini;j++){
                    ans.PB({a1[i][a1[i].size()-1],a2[i][a2[i].size()-1]});
                    a1[i].pop_back();
                    a2[i].pop_back();
                }
            }
        }
        if(a1[26].size()>0){
            for(int i=0;i<27;i++){
                if(a2[i].size()>0){
                    int mini=min(a1[26].size(),a2[i].size());
                    for(int j=0;j<mini;j++){
                        ans.PB({a1[26][a1[26].size()-1],a2[i][a2[i].size()-1]});
                        a1[26].pop_back();
                        a2[i].pop_back();
                    }
                }
            }
        }
        if(a2[26].size()>0){
            for(int i=0;i<27;i++){
                if(a1[i].size()>0){
                    int mini=min(a2[26].size(),a1[i].size());
                    for(int j=0;j<mini;j++){
                        ans.PB({a1[i][a1[i].size()-1],a2[26][a2[26].size()-1]});
                        a2[26].pop_back();
                        a1[i].pop_back();
                    }
                }
            }
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].F<<" "<<ans[i].S<<"\n";
        }



        return 0;
    }