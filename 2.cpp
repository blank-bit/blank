#include <vector>
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (s.length() < 2)
            return s;
        int col = s.length() / (2 * numRows - 2) * (numRows - 1);
        if (int t = (s.length() - col * (2 * numRows - 2)) != 0)
        {
            col++;
            if (t - numRows > 0)
            {
                col = col + t - numRows;
            }
        }
        // cout << col;
        // char ss[numRows][col];
        vector<vector<char>> ss;
        for (int i = 0; i < numRows; i++)
        {
            vector<char> s;
            ss.push_back(s);
        }

        // for (int i = 0; i < numRows; i++)
        // {
        //     for (int j = 0; j < col; j++)
        //     {
        //         ss[i][j] = 0;
        //     }
        // }
        int tmp = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            int row = 0;
            int col2 = 0;
            int a = i - 2 * (numRows - 1) * tmp;
            if (a < numRows)
            {
                row = a;
                col2 = tmp * (numRows - 1);
            }
            else
            {
                row = 2 * numRows - a - 2;
                col2 = tmp * (numRows - 1) + a - numRows + 1;
            }
            // ss[row][col2] = s[i];
            ss[row].push_back(s[i]);

            if (a == 2 * (numRows - 1) - 1)
            {
                tmp++;
            }
        }

        // char ret[s.length()];
        // int x = 0;
        // for (int i = 0; i < numRows; i++)
        // {
        //     for (int j = 0; j < col; j++)
        //     {
        //         if (ss[i][j] != 0)
        //         {
        //             ret[x] = ss[i][j];
        //             x++;
        //         }
        //         cout << ss[i][j] << " ";
        //         if (j == col - 1)
        //             cout << endl;
        //     }
        // }
        string ret;
        for (int i = 0; i < ss.size(); i++)
        {
            for (int j = 0; j < ss[i].size(); j++)
            {
                cout << ss[i][j];
                ret.push_back(ss[i][j]);
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    string t = s.convert("PAYPALISHIRING", 3);
    cout << t;
}