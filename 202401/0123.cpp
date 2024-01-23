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
    int alternatingSubarray(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        int firstIndex = 0;
        for (int i = 1; i < n; i++) {
            int length = i - firstIndex + 1;
            if (nums[i] - nums[firstIndex] == (length - 1) % 2) {
                res = max(res, length);
            } else {
                if (nums[i] - nums[i - 1] == 1) {
                    firstIndex = i - 1;
                    res = max(res, 2);
                } else {
                    firstIndex = i;
                }
            }
        }
        return res;
    }
};

