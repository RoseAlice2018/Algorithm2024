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
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> anc(n);   // 存储每个节点祖先的辅助数组
        vector<vector<int>> e(n);   // 邻接表
        vector<int> indeg(n);   // 入度表
        // 预处理
        for (const auto& edge: edges) {
            e[edge[0]].push_back(edge[1]);
            ++indeg[edge[1]];
        }
        // 广度优先搜索求解拓扑排序
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: e[u]) {
                // 更新子节点的祖先哈希表
                anc[v].insert(u);
                for (int i: anc[u]) {
                    anc[v].insert(i);
                }
                --indeg[v];
                if (!indeg[v]) {
                    q.push(v);
                }
            }
        }
        // 转化为答案数组
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            for (int j: anc[i]) {
                res[i].push_back(j);
            }
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/solutions/1364674/you-xiang-wu-huan-tu-zhong-yi-ge-jie-dia-6ed5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。