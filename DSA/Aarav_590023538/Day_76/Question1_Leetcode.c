#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

pp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr long long MOD = 1000000007LL;

    vector<vector<int>> tree;
    vector<long long> fact, invFact;

    long long modPow(long long a, long long e) {
        long long ans = 1;
        while (e > 0) {
            if (e & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return ans;
    }

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    // Returns {subtree_size, number_of_valid_orders}
    pair<int, long long> dfs(int u) {
        int totalSize = 1;
        long long ways = 1;

        for (int v : tree[u]) {
            auto [childSize, childWays] = dfs(v);

            ways = ways * childWays % MOD;
            ways = ways * C(totalSize + childSize - 1, childSize) % MOD;

            totalSize += childSize;
        }

        return {totalSize, ways};
    }

public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        tree.assign(n, {});

        for (int i = 1; i < n; i++)
            tree[prevRoom[i]].push_back(i);

        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n; i >= 1; i--)
            invFact[i - 1] = invFact[i] * i % MOD;

        return (int)dfs(0).second;
    }
};

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
