//recursive approach
#include <iostream>
using namespace std;
int recur(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;//if any str len is 0-> no common subseq
    if (s1[m - 1] == s2[n - 1])
        return 1 + recur(s1, s2, m - 1, n - 1);//if last char is equal we add 1 and call the next recursive call 
    else
        max(recur(s1, s2, m - 1, n), recur(s1, s2, m, n - 1));//here we take two cases one for ignoring a last char in s1 and other case for iganoring last char in s2 i.e. m-1, n-1
}
int main()
{
    string s1, s2;
    int m, n;
    cin >> s1 >> s2;
    m = s1.length();
    n = s2.length();
    cout << recur(s1, s2, m, n);
}

//TESTCASE 1 
// i/p -> s1:"AXYZ" s2:"BAZ"
// o/p -> 2