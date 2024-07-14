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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row_max(grid.size(), 0);
        vector<int> col_max(grid[0].size(), 0);
        int ret = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            int row = 0;
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] >= row)
                {
                    row = grid[i][j];
                    row_max[i] = row; 
                }
            }
        }

        for(int i = 0; i < grid[0].size(); i++)
        {
            int col = 0;
            for(int j = 0; j < grid.size(); j++)
            {
                if(grid[j][i] >= col)
                {
                    col = grid[j][i];
                    col_max[i] = col; 
                }
            }
            for(int j = 0; j < grid.size(); j++)
                ret += min(col_max[i], row_max[j]) - grid[j][i];
        }
        return ret;
    }
};