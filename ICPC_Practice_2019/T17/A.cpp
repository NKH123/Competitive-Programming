#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007
//vector <int>
// push_back
// char ice[n][m]
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


ll logg(ll num, ll base){
    if(num==0){
        return 1; 
    }
    ll count = 0;
    while(num){
        count++;
        num/=base;
    }

    return count;
}

ll getval(string s){
    ll val=0;
    for(int i=0; i<s.size(); i++){
        val = val*7+(s[i]-'0');
    }

    return val;
}

bool valid(string s, ll n, ll m, ll digh, ll digm){
    string hours = s.substr(0, digh);
    string minutes = s.substr(digh, digm);

    ll h = getval(hours);
    ll mm = getval(minutes);

    if(h<=n-1 && mm<=m-1){
        // cout<<s<<" "<<h<<" "<<mm<<"\n";
        return true;
    }

    return false;
}


int main(){
    
    ll n, m;
    cin>>n>>m;
    ll digh=logg(n-1, 7);
    ll digm=logg(m-1, 7);
    // deb(digh);
    // deb(digm);
    if((digm+digh)>7)
        cout<<0<<"\n";

    else{
        ll count = 0;
        string perm = "0123456";

        // map<string, bool> mp;
        set<string>mp;
        do{
            string temp = perm.substr(0, digh+digm);
            if(valid(temp, n, m, digh, digm)==true){
                // mp[temp]=1;
                mp.insert(temp);
            }

        }
        while(next_permutation(perm.begin(), perm.end()));

        cout<<mp.size()<<"\n";
    }


    
}
