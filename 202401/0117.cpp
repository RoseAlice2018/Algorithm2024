#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
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
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i) {
            if (seen.count(words[i][1] * 100 + words[i][0])) {
                ++ans;
            }
            seen.insert(words[i][0] * 100 + words[i][1]);
        }
        return ans;
    }
};

