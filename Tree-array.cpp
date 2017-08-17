#ifndef __bit__
#define __bit__
#define n 10005
struct bit
{
	int c[n];
	int lowbit(int x)
	{
		return x & (-x);
	}

	void modify(int x,int y)
	{
		while(x <= n)
		{
			c[x] += y;
			x += lowbit(x);
		}
	}

	int query(int x)
	{
		int ans = 0;
		while(x > 0)
		{
			ans += c[x];
			x -= lowbit(x);
		}
		return ans;
	}
};
#undef n
#endif
