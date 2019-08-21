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
    int n;
    cin>>n;
    vector<string>s(3);
    for(int i=0;i<3;i++){
        cin>>s[i];
    }
    map<char,int>freq;
    vi Ans(3,-1);
    for(int i=0;i<3;i++){
        freq.clear();

        for(int j=0;j<s[i].size();j++){
            freq[s[i][j]]++;
        }
        int maxi=-1;
        int Maxi=-1;
        for(auto g:freq){
            maxi=g.second;
            Maxi=max(Maxi,g.second);
            int remchar=s[i].size()-maxi;
            if(n<remchar){
                Ans[i]=max(Ans[i],maxi+n);
            }
            else{
                int temp=s[i].size();
                int remmoves=n-remchar;
                // if((remmoves%2)==0){

                // }
                // else{
                //     temp--;
                // }
                Ans[i]=max(Ans[i],temp);
            }
            //0 case
            maxi=0;
            remchar=s[i].size()-maxi;
            if(n<remchar){
                Ans[i]=max(Ans[i],maxi+n);
            }
            else{
                int temp=s[i].size();
                int remmoves=n-remchar;
                // if((remmoves%2)==0){

                // }
                // else{
                //     temp--;
                // }
                Ans[i]=max(Ans[i],temp);

            }
        }
        if(Maxi==s[i].size()){
            if(n==1){
                Ans[i]=max(1LL,(int)(s[i].size()-1) );

            }
            
        }
    }

    // deb(Ans);
    int ans=max({Ans[0],Ans[1],Ans[2]});
    int ct=0;
    for(int i=0;i<3;i++){
        if(Ans[i]==ans){
            ct++;
        }
    }

    if(ct!=1){
        cout<<"Draw\n";
    }
    else{

        if(ans==Ans[0]){
            cout<<"Kuro\n";
        }
        else if(ans==Ans[1]){
            cout<<"Shiro\n";
        }
        else{
            cout<<"Katie\n";
        }
    }



    return 0;
}