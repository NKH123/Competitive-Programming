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


class Solution{
public:
    int maxProfit(vector<int> &price){
        int prevMax=-price[0];
        int maxProfit=0;
        for(int i=1;i<price.size();i++){
            int curProfit=price[i]+prevMax;
            prevMax=max(prevMax,-price[i]+maxProfit);
            maxProfit=max(maxProfit,curProfit);

        }   
        return maxProfit;
    }
};
class Solution1{
public:
    int maxProfit(vector<int> &price){
        vector<vector<int> >ans;
        vector<int>minMax;
        int Ans=0;
        for(int i=0;i<price.size();i++){
            if(i==0){
                if(price[1]>=price[0]){
                    minMax.push_back(0);
                }
            }   
            else if(i==(price.size()-1)){
                if(price[price.size()-1]>=price[price.size()-2]){
                    if(minMax.size()==1){
                        minMax.push_back(i);
                    }
                }
            }
            else{
    //maxima
                if(price[i]>=price[i-1] && price[i]>=price[i+1]){
                    if(minMax.size()==1){
                        minMax.push_back(i);
                    }

                }
//minima
                else if(price[i]<=price[i-1] && price[i]<=price[i+1])
                    if(minMax.size()==0){
                        minMax.push_back(i);
                    }
                }
                if(minMax.size()==2){
                    ans.push_back(minMax);
                    Ans+=(price[minMax[1]]-price[minMax[0]]);
                    minMax.clear();
                }
            }
            deb(ans);
            // return ans;
            return Ans;
        }
    };

    int32_t main(){
        ios::sync_with_stdio(false);
        int n;
        cin>>n;
        vi a(n);
        REP(i,0,n){
            cin>>a[i];
        }
        Solution S;
        Solution1 S1;
        deb(S.maxProfit(a));
        deb(S1.maxProfit(a));

        return 0;
    }