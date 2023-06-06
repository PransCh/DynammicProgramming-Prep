#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int longestCommonSubsequence(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    // Create a 2D table for tabulation
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // Perform tabulation
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                // If the last characters match, increment LCS length by 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                // Take the maximum LCS length by excluding the last character from one of the strings
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the LCS is stored in the bottom-right corner of the table
    return dp[len1][len2];
}

int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    int lcs_length = longestCommonSubsequence(str1, str2);
    cout << "Length of LCS: " << lcs_length << endl;

    return 0;
}
