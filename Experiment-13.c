
#include <stdio.h>

#define MAX 15
#define INF 99999999

int n;
int cost[MAX][MAX];
int dp[1 << MAX][MAX];

int min(int a, int b) {
	return (a < b) ? a : b;
}

int tsp(int mask, int pos) {
	if (mask == (1 << n) - 1) {
		if (cost[pos][0] == -1)
			return INF;
		return cost[pos][0];
	}

	if (dp[mask][pos] != -1)
		return dp[mask][pos];

	int ans = INF;

	for (int city = 0; city < n; city++) {
		if (!(mask & (1 << city)) && cost[pos][city] != -1) {
			int next = tsp(mask | (1 << city), city);

			if (next != INF)
				ans = min(ans, cost[pos][city] + next);
		}
	}

	return dp[mask][pos] = ans;
