#include <iostream>
#include <vector>

int coinChange(int amount, const std::vector<int> &coins)
{
    int n = coins.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            // If current coin value is less than the current amount
            // then we have two options: either exclude the coin or include it
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j]; // exclude the coin
        }
    }

    return dp[n][amount];
}

int main()
{
    int amount = 10;
    std::vector<int> coins = {1, 2, 5};

    int numWays = coinChange(amount, coins);
    std::cout << "Number of ways to make change: " << numWays << std::endl;

    return 0;
}
