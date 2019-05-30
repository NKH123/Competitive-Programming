
#define MAXN 100005
int  n, t[4*MAXN];  //n is size of array, t is the segment tree
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

