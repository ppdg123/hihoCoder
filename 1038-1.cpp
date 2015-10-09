#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[100005];
int need[502], value[502];

int main()
{
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d %d", &need[i], &value[i]);
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++)
			for(int j=m; j>=need[i]; j--)
				dp[j] = max(dp[j], dp[j-need[i]] + value[i]);
		printf("%d\n", dp[m]);
	}
	return 0;
}