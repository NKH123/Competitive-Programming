
int compute(int A,int B){
	return a+b;
}






void build(int a[], int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
        t[v] = compute(t[v*2] , t[v*2+1]);// t[v*2] + t[v*2+1];
    }
}


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

