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

#define // deb(x) cerr << #x << " = " << x << endl;

class TapeMeasure {
public:
    vector <string> draw(int l, int r) {
        // string s = "";
        vector<string>ans(5);
        ans.clear();
        ans.resize(5);
        // deb("1");
        for(int i=0; i<=2000; i++) {
            ans[0]+= "#";
            if(i%2==0) {
                ans[1] +="#";
            } else {
                ans[1] +=" ";
            }
            if(i%10==0) {
                ans[2] +="#";
            } else {
                ans[2] +=" ";
            }
            if(i%(20)==0) {
                ans[3] +="#";
                string num = "";
                int I = i/2;
                while(I>0) {
                    int dig  = I%10;
                    I=I/10;
                    char aa = '0' + dig;
                    num += aa;
                }

                if(num.size()==0) {
                    num = "0";
                }
                reverse(num.begin(), num.end());
                int len = 19 - (num.size() - 1);
                ans[4] += num;
                for(int j=0; j<len;j++) {
                    ans[4]+=" ";
                }
            } else {
                ans[3] +=" ";
            }

        }
        // deb(2);
        int  L = l*2;
        int R  = r*2;
        vector<string>Ans(5);
        Ans.clear();
        Ans.resize(5);
        for(int i=L; i<=R; i++) {
            for(int j=0; j<5; j++) {
                if(ans[j][i]!=' ') {
                    Ans[j] += ans[j][i];
                } else  {
                    if(Ans[j].size() != 0) {
                        if(Ans[j][Ans[j].size() - 1]!= ' ') {
                            Ans[j] += ans[j][i];
                        }
                    } else {
                        Ans[j] += ans[j][i];
                    }
                }
            }
        }
        // deb("3");
        return Ans;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    TapeMeasure S;
    int l, r;
    cin>>l>>r;
    vector<string> Ans =S.draw(l, r);
    // deb(Ans);
    return 0;
}