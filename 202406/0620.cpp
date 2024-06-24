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
    int gcd(int a, int b)
    {

    }
    int countBeautifulPairs(vector<int>& nums) {

    }
};



class Solution {
public:
    int countBeautifulPairs(vector<int> &nums) {
        int res = 0, cnt[10]{};
        for (int x: nums) {
            for (int y = 1; y <= 9; y++) {
                if (gcd(x % 10, y) == 1) {
                    res += cnt[y];
                }
            }
            while (x >= 10) {
                x /= 10;
            }
            cnt[x]++;
        }
        return res;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/number-of-beautiful-pairs/solutions/2815256/mei-li-xia-biao-dui-de-shu-mu-by-leetcod-b4jo/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。