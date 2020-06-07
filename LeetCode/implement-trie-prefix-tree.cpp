#include<bits/stdc++.h>
using namespace std;
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

#define deb(x) cout << #x << " = " << x << endl;
class Trie {
public:
    /** Initialize your data structure here. */
    struct Vertex{
        int next[26];
        bool flag;
        Vertex(){
            memset(next,26,-1);
            flag=false;
        }
    };
    vector<Vertex>T;
    Trie() {
        T.clear();
        T.resize(1);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int cur=0;
        for(auto g:word){
            if(T[cur].next[g-'a']!=-1){
                cur=T[cur].next[g-'a'];
            }
            else{
                T[cur].next[g-'a']=T.size();
                T.emplace_back();
                cur=T[cur].next[g-'a'];
            }
        }
        T[cur].flag=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int cur=0;
        for(auto g:word){
            if(T[cur].next[g-'a']!=-1){
                cur=T[cur].next[g-'a'];
            }
            else{
                return false;
            }
        }
        return T[cur].flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int cur=0;
        for(auto g:prefix){
            if(T[cur].next[g-'a']!=-1){
                cur=T[cur].next[g-'a'];
            }
            else{
                return false;
            }
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int32_t main(){
    Trie* obj=new Trie();
    obj->insert("apple");
    deb(1);
    deb(obj->search("apple"));
    deb(2);
    deb(obj->search("app"));
    deb(3);
    deb(obj->startsWith("app"));
    deb(4);
    obj->insert("app");
    deb(5);
    deb(obj->search("app"));
    deb(6);
    return 0;
}