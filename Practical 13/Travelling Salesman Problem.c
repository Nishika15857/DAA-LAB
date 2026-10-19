#include <stdio.h>
#include <limits.h>

#define INF 1000000000
#define MAXN 15

int n;
int cost[MAXN][MAXN];
int dp[1<<MAXN][MAXN];

int min(int a, int b) { return a < b ? a : b; }

int tsp() {
    // Initialize DP table
    for (int mask = 0; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            dp[mask][i] = INF;
        }
    }
    dp[1][0] = 0; // Start at city 0

    // Iterate over all subsets of cities
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1<<u))) continue; // city u not visited
            for (int v = 0; v < n; v++) {
                if (mask & (1<<v)) continue; // city v already visited
                if (cost[u][v] == INF) continue; // no edge
                int newMask = mask | (1<<v);
                dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + cost[u][v]);
            }
        }
    }

    // Return to starting city (0)
    int ans = INF;
    for (int i = 1; i < n; i++) {
        if (cost[i][0] != INF) {
            ans = min(ans, dp[(1<<n)-1][i] + cost[i][0]);
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if (x == -1) cost[i][j] = INF;
            else cost[i][j] = x;
        }
    }
    printf("%d\n", tsp());
    return 0;
}

