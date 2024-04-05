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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
        {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b)->bool{
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> ret;
        ret.push_back(intervals[0]);
        for(auto interval : intervals)
        {
            auto& ret_last = ret[ret.size() - 1];
            if(ret_last[1] < interval[0])
            {
                ret.push_back(interval);
                continue;
            }
            else if(ret_last[0] <= interval[0] && ret_last[1] >= interval[1])
            {
                continue;
            }
            else if(ret_last[0] <= interval[0]&& ret_last[1] <= interval[1])
            {
                ret_last[1] = interval[1];
                continue;
            }
        }
        return ret;
    }
};