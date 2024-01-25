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
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ret = 0;
        auto  countnum = [](int num, int k) ->int {
            int count = 0;
            while(num > 0)
            {
                if(num & 1 == 1)
                    count++;
                num >>= 1;
            }
            return k == count;
        };

        for(int i = 0; i < nums.size(); i++)
        {
            if(countnum(i, k))
            {
                ret += nums[i];
            }
        }
        
        return ret;
    }
};