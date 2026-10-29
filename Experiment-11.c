
#include <stdio.h>

int main() {
	int N, W;
	int value[1000], weight[1000];
	int dp[1001][1001];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &value[i]);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &weight[i]);
	}

	scanf("%d", &W);

	for (int i = 0; i <= N; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;
			} else if (weight[i - 1] <= w) {
				int include = value[i - 1] + dp[i - 1][w - weight[i - 1]];
				int exclude = dp[i - 1][w];

				dp[i][w] = (include > exclude) ? include : exclude;
			} else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	printf("%d\n", dp[N][W]);
