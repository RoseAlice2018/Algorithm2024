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
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low < high)
        {
            int pivot = low + (high - low) / 2;
            if(nums[pivot] < nums[high]){
                high = pivot;
            }
            else{
                low = pivot + 1;
            }
        }
        return nums[low];
    }
};

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            // IPv4
            int last = -1;
            for (int i = 0; i < 4; ++i) {
                int cur = (i == 3 ? queryIP.size() : queryIP.find('.', last + 1));
                if (cur == string::npos) {
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 3) {
                    return "Neither";
                }
                int addr = 0;
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j])) {
                        return "Neither";
                    }
                    addr = addr * 10 + (queryIP[j] - '0');
                }
                if (addr > 255) {
                    return "Neither";
                }
                if (addr > 0 && queryIP[last + 1] == '0') {
                    return "Neither";
                }
                if (addr == 0 && cur - last - 1 > 1) {
                    return "Neither";
                }
                last = cur;
            }
            return "IPv4";
        }
        else {
            // IPv6
            int last = -1;
            for (int i = 0; i < 8; ++i) {
                int cur = (i == 7 ? queryIP.size() : queryIP.find(':', last + 1));
                if (cur == string::npos) {
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 4) {
                    return "Neither";
                }
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j]) && !('a' <= tolower(queryIP[j]) && tolower(queryIP[j]) <= 'f')) {
                        return "Neither";
                    }
                }
                last = cur;
            }
            return "IPv6";
        }
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/validate-ip-address/solutions/1521467/yan-zheng-ipdi-zhi-by-leetcode-solution-kge5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。