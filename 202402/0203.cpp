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
class Solution {
public:
    int stoneGameVII(vector<int> &stones) {
        int n = stones.size();
        vector<int> s(n + 1);
        partial_sum(stones.begin(), stones.end(), s.begin() + 1);
        vector<int> f(n);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                f[j] = max(s[j + 1] - s[i + 1] - f[j], s[j] - s[i] - f[j - 1]);
            }
        }
        return f[n - 1];
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/stone-game-vii/solutions/2629582/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-zktx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。