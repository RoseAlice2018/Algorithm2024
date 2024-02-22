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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        int n = preorder.size();
        unordered_map<int, int> postMap;
        for (int i = 0; i < n; i++) {
            postMap[postorder[i]] = i;
        }
        function<TreeNode *(int, int, int, int)> dfs = [&](int preLeft, int preRight, int postLeft, int postRight) -> TreeNode * {
            if (preLeft > preRight) {
                return nullptr;
            }
            int leftCount = 0;
            if (preLeft < preRight) {
                leftCount = postMap[preorder[preLeft + 1]] - postLeft + 1;
            }
            return new TreeNode(preorder[preLeft],
                dfs(preLeft + 1, preLeft + leftCount, postLeft, postLeft + leftCount - 1),
                dfs(preLeft + leftCount + 1, preRight, postLeft + leftCount, postRight - 1));
        };
        return dfs(0, n - 1, 0, n - 1);
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-postorder-traversal/solutions/2645281/gen-ju-qian-xu-he-hou-xu-bian-li-gou-zao-6vzt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
