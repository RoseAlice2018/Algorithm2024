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
    void dfs(vector<vector<char>>& grid, int m, int n)
    {
        if(m < 0 || m >= grid.size())
            return;
        if(n < 0 || n >= grid[0].size())
            return;
        if(grid[m][n] == '0' || grid[m][n] == '2')
            return;
        grid[m][n] = '2'; // visited
        dfs(grid, m - 1, n);
        dfs(grid, m + 1, n);
        dfs(grid, m, n - 1);
        dfs(grid, m, n + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int m = 0; m < grid.size(); m++)
        {
            for(int n = 0; n < grid[0].size(); n++)
            {
                if(grid[m][n] == '1')
                {
                    dfs(grid, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    void dfs(vector<int>& nums, unordered_set<int>& visited, vector<int> path, vector<vector<int>> &ans)
    {
        if(visited.size() == nums.size())
        {
            ans.push_back(std::move(path));
            return;
        }
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(!visited.count(nums[i]))
            {
                path.push_back(nums[i]);
                visited.insert(nums[i]);
                dfs(nums, visited, path, ans);
                visited.erase(nums[i]);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_set<int> visited;
        dfs(nums, visited, path, ans);
        return ans;
    }
};