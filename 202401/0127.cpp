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
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int left = 1, right = 2e8, ans = 0;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            bool valid = false;
            for(int i = 0; i < k; ++i)
            {
                long long spend = 0;
                for(int j = 0; j < n; ++j)
                {
                    spend += max(static_cast<long long>(composition[i][j]) * mid -stock[j], 0LL) * cost[j];
                }
                if(spend <= budget)
                {
                    valid = true;
                    break;
                }
            }
            if(valid){
                ans = mid;
                left = mid  + 1;
            }
            else 
                right = mid -1;
        }
        return ans;
    }
};

