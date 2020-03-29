#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
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
ostream &operator << ( ostream & os, const multiset< T > &v ) {
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

const int N = 1e5 + 10, inf = 1e9 + 42;
 
int sa[N], sb[N], ea[N], eb[N];
 
bool solve(int n);
 
int main() {
    fast_cin();
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }
    if (!solve(n)) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        swap(sa[i], sb[i]);
        swap(ea[i], eb[i]);
    }
    if (!solve(n)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
}
 
bool solve(int n) {
    vector<pii> events;
    for (int i = 1; i <= n; ++i) {
        events.pb({sa[i], i});
        events.pb({ea[i] + 1, -i});
    }
    sort(events.begin(), events.end());
    multiset<int> lvals, rvals;
    lvals.insert(-inf);
    rvals.insert(inf);
    deb(events);
    for (auto& e : events) {
        deb(lvals);
        deb(rvals);
        if (e.second > 0) {
            int i = e.second;
            int l = max(*lvals.rbegin(), sb[i]);
            int r = min(*rvals.begin(), eb[i]);
            if (l > r) {
                return false;
            }
            lvals.insert(sb[i]);
            rvals.insert(eb[i]);
        } else {
            int i = -e.second;
            lvals.erase(lvals.find(sb[i]));
            rvals.erase(rvals.find(eb[i]));
        }
    }
    return true;
}