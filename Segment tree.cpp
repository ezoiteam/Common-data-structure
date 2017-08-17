#ifndef __SEG__
#define __SEG__
#define MAX_N 100005
#define ll long long 
int a[MAX_N];
struct SEG
{
	struct node{
		ll num,sum,size,lazy;
	}tr[MAX_N << 1];
	void pushup(int k){
		tr[k].sum = tr[k << 1].sum + tr[k << 1 | 1].sum; 
		tr[k].size = tr[k << 1].size + tr[k << 1 | 1].size;
	}

	void pushdown(int k,int l,int r){
		tr[k << 1].lazy += tr[k].lazy;
		tr[k << 1 | 1].lazy += tr[k].lazy;
		tr[k << 1].sum += tr[k << 1].size * tr[k].lazy;
		tr[k << 1 | 1].sum += tr[k << 1 | 1].size * tr[k].lazy;
		tr[k].lazy = 0;
	}

	void build(int k,int l,int r){
		if (l == r){
			tr[k].num = tr[k].sum = a[l];
			tr[k].lazy = 0;tr[k].size = 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(k << 1,l,mid);
		build(k << 1 | 1,mid + 1,r);
		pushup(k);
	}

	void modify(int k,int L,int R,int l,int r,int v){
		if (l <= L && R <= r){
			tr[k].lazy += v;
			tr[k].sum += v * tr[k].size;
			return;
		}
		int mid = (L + R) >> 1;
		if (tr[k].lazy) pushdown(k,L,R);
		if (l <= mid) modify(k << 1,L,mid,l,r,v);
		if (r > mid) modify(k << 1 | 1,mid + 1,R,l,r,v);
		pushup(k);
	 }

	ll Query(int k,int L,int R,int l,int r){
		if (l <= L && R <= r) return tr[k].sum;
	
		int mid = (L + R) >> 1;
		ll ans = 0;
	
		if (tr[k].lazy) pushdown(k,L,R);
	
		if (l <= mid) ans += Query(k << 1,L,mid,l,r);
		if (r > mid) ans += Query(k << 1 | 1,mid + 1,R,l,r);
		return ans;
	}
};
#undef ll 
#undef MAX_N
#endif
