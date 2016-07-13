int cal(int n, int m)
{
	int res;
	res = S2(n, m) * fac[m] % p;
	return res;
}
