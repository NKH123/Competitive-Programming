
#define MAXN 100005
int  t[4*MAXN], lazy[4*MAXN];  //n is size of array, t is the segment tree
vector<int>a;    //a is the input array from which segtree is built


//compute function
int compute(int A,int B){
	return A+B;
}





//call build(1,0,n-1) 
void build( int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build( v*2, tl, tm);
		build( v*2+1, tm+1, tr);
        t[v] = compute(t[v*2] , t[v*2+1]);// t[v*2] + t[v*2+1];
    }
}

//call sum(1,0,n-1,l, r)  l and r are range boundaries in 0 based indexing
int sum(int v, int tl, int tr, int l, int r) {
	if (l > r) 
		return 0;
	if (l == tl && r == tr) {
		return t[v];
	}
	int tm = (tl + tr) / 2;
    return compute(sum(v*2, tl, tm, l, min(r, tm)),sum(v*2+1, tm+1, tr, max(l, tm+1), r));/*sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);*/
}

//updating one value of the array and rebuilding the path in the segtree above it
//call update(1,0,n-1,pos,new_val) pos is pos in array a and new_val is the new value that replaces the old value
void update(int v, int tl, int tr, int pos, int new_val) {
	if (tl == tr) {
		t[v] = new_val;
	} else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v*2, tl, tm, pos, new_val);
		else
			update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = compute(t[v*2] , t[v*2+1]);// t[v*2] + t[v*2+1];
    }
}
//lazy propagation push values to children
void Push(int v, int tl, int tr){
	if(tl!=tr){
		lazy[(v<<1)]+=lazy[v];
		lazy[((v<<1)^1)]+=lazy[v];
	}
	t[v]+=lazy[v];
	lazy[v]=0;
}

//range updates lazy propagation
//adds to range l to r x
void add(int v, int tl, int tr, int l, int r, int x){
	Push(v,tl,tr);
	if(l>tr || tl>r){
		return;
	}
	if(l<=tl && tr<=r){
		lazy[v]+=x;
		Push(v,tl, tr);
	}
	else{
		int tm=(tl+tr)>>1;
		add(v<<1,tl, tm,l, r, x);
		add(v<<1^1,tm+1,tr,l,r, x);
		t[v]=compute(t[v<<1],t[v<<1^1]);
	}
}





//SegTree class

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector< vll >
#define vld vector< ld >
#define vvld vector< vld >
#define pll pair<ll ,ll >
#define vpll vector< pll >
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define endl "\n"
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;read(t);while(t--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define scd second

#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

using namespace std;

class SegmentTree {
public:
	int n;
	vll tree;
	vll lazy;
	vll A;
	SegmentTree(){}
	SegmentTree(vector<int> &_A) {
		sort(all(_A));
		n = _A.size();
		tree.resize(4 * n + 1 , 0);
		lazy.resize(4 * n + 1 , 0);
		A.resize(n);
		for(int i = 0 ; i < n ; ++i) {
			A[i] = _A[i];
		}
	}

	void _update(int node , int s , int e , int l , int r) {
		if(lazy[node] == 1) {
			tree[node] = (e-s+1) - tree[node];
			if(s != e) {
				lazy[node << 1] ^= 1;
				lazy[node << 1 | 1] ^= 1;
			}
			lazy[node] = 0;
		}
		if(s > r || e < l) {
			return;
		}
		if(s >= l && e <= r) {
			tree[node] = (e-s+1)-tree[node];
			if(s != e) {
				lazy[node << 1] ^= 1;
				lazy[node << 1 | 1] ^= 1;
			}
			return;
		}
		int m = s + e >> 1;
		_update(node << 1 , s , m , l , r);
		_update(node << 1 | 1, m + 1 , e , l , r);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	void update(int inTime , int outTime) {
		int l = lower_bound(all(A) , inTime) - A.begin();
		int r = lower_bound(all(A) , outTime) - A.begin() - 1;
		_update(1 , 0 , n - 1 , l , r);
	}

	int _query(int node , int s , int e , int l , int r) {
		if(lazy[node] == 1) {
			tree[node] = (e-s+1) - tree[node];
			if(s != e) {
				lazy[node << 1] ^= 1;
				lazy[node << 1 | 1] ^= 1;
			}
			lazy[node] = 0;
		}
		if(s > r || e < l) {
			return 0;
		}
		if(s >= l && e <= r) {
			return tree[node];
		}

		int m = s + e >> 1;
		return _query(node << 1 , s , m , l , r) + _query(node << 1 | 1 , m + 1 , e , l , r);
	}

	int query(int inTime , int outTime) {
		int l = lower_bound(all(A) , inTime) - A.begin();
		int r = lower_bound(all(A) , outTime) - A.begin() - 1;
		return _query(1 , 0 , n - 1 , l , r);
	}

	void display(){
		for(int i = 0 ; i < n ; ++i) {
			cout << _query(1 , 0 , n-1 , i , i) << " ";
		}
		cout << "\n";
	}
} linear[26];
