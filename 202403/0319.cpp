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
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k - 1, right = k + 1;
        int ans = 0;
        for (int i = nums[k];; --i) {
            while (left >= 0 && nums[left] >= i) {
                --left;
            }
            while (right < n && nums[right] >= i) {
                ++right;
            }
            ans = max(ans, (right - left - 1) * i);
            if (left == -1 && right == n) {
                break;
            }
        }
        return ans;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/maximum-score-of-a-good-subarray/solutions/2688286/hao-zi-shu-zu-de-zui-da-fen-shu-by-leetc-94gx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。