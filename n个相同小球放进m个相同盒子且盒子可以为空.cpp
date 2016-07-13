int cal(int n, int m)
{
	for(int i = 1; i <= N; i++) dp[i][1] = 1;
	for(int i = 1; i <= N; i++)
	for(int j = 2; j <= i; j++)
	{
		dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
	}
	int res = 0;
	for(int i = 1; i <= m; i++) res += dp[n][i];
	return res;
}
