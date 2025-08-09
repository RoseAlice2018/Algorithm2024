#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode *next):val(x), next(next){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m + 1][n + 1];
        dp[0][0] = grid[0][0];
        for(int i = 1 ; i < m ; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for(int i = 1; i < n; i++)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/longest-consecutive-sequence/solutions/276931/zui-chang-lian-xu-xu-lie-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 
        int n = matrix.size();
        for(int i = 0; i < n/2; i++)
        {
            for(int j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n - i - 1][j]);
        }

        // 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int beigin_x = 0, beigin_y = n - 1;
        while(beigin_x >= 0 && beigin_x < m && beigin_y >= 0 && beigin_y < n)
        {
            if(target == matrix[beigin_x][beigin_y])
                return true;
            if(target > matrix[beigin_x][beigin_y])
            {
                beigin_x++;
            }
            else {
                beigin_y--;
            }
        }
        return false;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        int max_dp_j_0 = dp[0][0];
        int max_dp_j_1 = dp[0][1];
        int max_dp_j_2 = dp[0][2];
        for(int i = 1; i < n ;i++)
        {
            dp[i][0] = max(max_dp_j_0, max_dp_j_2);
            dp[i][1] = max(max_dp_j_0, max_dp_j_2) - prices[i];
            for(int j = 0; j < i; j++)
                dp[i][2] = max(dp[i][2], prices[i] + dp[j][1]);
            max_dp_j_0 = max(max_dp_j_0, dp[i][0]);
            max_dp_j_2 = max(dp[i][2], max_dp_j_2);
            cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        }
        return max(dp[n - 1][0], dp[n-1][2]);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solutions/476791/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode-s/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    void dfs(vector<vector<int>> &grid, int x, int y, int& count)
    {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        if(grid[x][y] == 2 || grid[x][y] == 0)
            return;
        count++;
        grid[x][y] = 2;
        dfs(grid, x-1, y, count);
        dfs(grid, x, y+1, count);
        dfs(grid, x+1, y, count);
        dfs(grid, x, y-1, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int ans = 0;
                    dfs(grid, i, j, ans);
                    if(ans > max_count)
                        max_count = ans;
                }
            }
        }
        return max_count;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/maximal-square/solutions/234964/zui-da-zheng-fang-xing-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。