#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int lcsMemoization(string &str1, string &str2, int len1, int len2, vector<vector<int>> &memo)
{
    // Check if the result for the current subproblem is already stored in the memoization table
    if (memo[len1][len2] != -1)
    {
        return memo[len1][len2];
    }

    // Base case: if either string is empty, the length of LCS is 0
    if (len1 == 0 || len2 == 0)
    {
        memo[len1][len2] = 0;
    }
    else
    {
        // If the last characters of both strings match
        if (str1[len1 - 1] == str2[len2 - 1])
        {
            memo[len1][len2] = 1 + lcsMemoization(str1, str2, len1 - 1, len2 - 1, memo);
        }
        else
        {
            // Take the maximum length of LCS by excluding the last character from one of the strings
            memo[len1][len2] = max(lcsMemoization(str1, str2, len1 - 1, len2, memo),
                                   lcsMemoization(str1, str2, len1, len2 - 1, memo));
        }
    }

    // Store the computed result in the memoization table
    return memo[len1][len2];
}

int longestCommonSubsequence(string str1, string str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    // Create a memoization table initialized with -1
    vector<vector<int>> memo(len1 + 1, vector<int>(len2 + 1, -1));

    // Compute the LCS using memoization
    return lcsMemoization(str1, str2, len1, len2, memo);
}

int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    int lcs_length = longestCommonSubsequence(str1, str2);
    cout << "Length of LCS: " << lcs_length << endl;

    return 0;
}
