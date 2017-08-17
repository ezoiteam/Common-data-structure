#ifndef __zkw__
#define __zkw__
#define MAX_N 100005
#define ll long long
int x;
struct zkw
{
	int M,T;
	int tr[MAX_N];
	int min(int x,int y){return x < y ? x : y;}
	int max(int x,int y){return x > y ? x : y;}
	void build(int x)
	{
		for (T = 1;T <= x + 1;T <<= 1);
		for (int i = T + 1;i <= T + x;++i) //--read;
		for (int i = T - 1;i >= 1;--i){
			tr[i] = min(tr[i << 1],tr[i << 1 | 1]);
			tr[i << 1] -= tr[i];
			tr[i << 1 | 1] -= tr[i];
		}
	}
	int Querynum(int l)//-单点查询
	{
		int res = 0;
		while(l){
			res += tr[l];
			x >>= 1;
		}
		return res;
	}
	int Querysum(int l,int r)//--区间求和
	{
		int ans = 0;
		l += M - 1,r += M - 1;
		ans += tr[l] + tr[r];
		if (l == r) return ans - tr[l];
		for (;l ^ r ^ 1;l >>= 1,r >>= 1)
		{
			if (~l&1) ans += tr[l ^ 1];
			if (r&1) ans += tr[r ^ 1];
		}
		return ans;
	}
	int Querymax(int l,int r)//--区间最大值
	{
		int L,R;
		int ans = 0;
		for (l = l + M - 1,r = r + M + 1;l ^ r ^ 1;l >>= 1,r >>= 1){
			L += tr[l],R += tr[r];
			if (~l&1) L = max(L,tr[l ^ 1]);
			if (r&1)  R = max(R,tr[r ^ 1]);
		}
		ans = max(L,R);
		while(l) ans += tr[l >>= 1];
	}
	void change(int x,int v)
	{
		tr[x = M + x - 1] += v;
		while(x) tr[x >>= 1] = tr[x << 1] + tr[x << 1 | 1];
	}
};

#undef MAX_N
#undef ll
#endif
