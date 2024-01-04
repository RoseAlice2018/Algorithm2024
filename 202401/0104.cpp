#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> mask(m, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                mask[i] += matrix[i][j] << (n - j - 1);
            }
        }
        int res = 0;
        int cur = 0;
        int limit = (1 << n);
        while ((++cur) < limit) {
            if (__builtin_popcount(cur) != numSelect) {
                continue;
            }
            int t = 0;
            for (int j = 0; j < m; j++) {
                if ((mask[j] & cur) == mask[j]) {
                    ++t;
                }
            }
            res = max(res, t);
        }
        return res;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/maximum-rows-covered-by-columns/solutions/2587986/bei-lie-fu-gai-de-zui-duo-xing-shu-by-le-5kb9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。