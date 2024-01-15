#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>> &points) {
        int ans = 0;
        for (auto &p : points) {
            unordered_map<int, int> cnt;
            for (auto &q : points) {
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                ++cnt[dis];
            }
            for (auto &[_, m] : cnt) {
                ans += m * (m - 1);
            }
        }
        return ans;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/number-of-boomerangs/solutions/994189/hui-xuan-biao-de-shu-liang-by-leetcode-s-lft5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。