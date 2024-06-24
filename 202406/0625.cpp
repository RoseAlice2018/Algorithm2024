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
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_map<int, int> mp;
        int m = grid.size();
        int n = grid[0].size();

        for (int j = 0; j < m; j++) {
            int st = 0;
            for (int i = 0; i < n; i++) {
                st |= (grid[j][i] << i);
            }
            mp[st] = j;
        }

        if (mp.count(0)) {
            ans.push_back(mp[0]);
            return ans;
        }

        for (auto [x, i]: mp) {
            for (auto [y, j]: mp) {
                if (!(x & y)) {
                    return {min(i, j), max(i, j)};
                }
            }
        }

        return ans;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/find-a-good-subset-of-the-matrix/solutions/2817195/zhao-dao-ju-zhen-zhong-de-hao-zi-ji-by-l-qldc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。