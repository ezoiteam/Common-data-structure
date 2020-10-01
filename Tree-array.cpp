#ifndef __bit__
#define __bit__
#define n 10005
struct bit    // Binary Indexed Tree(or fenwick tree) 1 based index implementation
{
	int c[n];    // array of size n
	int lowbit(int x)   // returns smallest set bit
	{
		return x & (-x); 
	}

	void modify(int x,int y)     // Add value y at index x if array
	{
		while(x <= n)
		{
			c[x] += y;
			x += lowbit(x);
		}
	}

	int query(int x)   // prefix sum of array upto index x
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
