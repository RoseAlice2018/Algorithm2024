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
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        unordered_set<int> chosen;
        auto getmin = [](vector<int>& values, unordered_set<int>& _chosen)->int{
            int idx = -1;
            int max = 0;
            for(int i = 0; i < values.size();i++)
            {
                if(_chosen.count(i))//skip
                    continue;
                if(values[i] >= max)
                {
                    max = values[i];
                    idx = i;
                }
            }
            return idx;
        };

        int A = 0, B = 0;
        for(int i = 0; i < aliceValues.size(); i++)
        {
            int chose = getmin(aliceValues, chosen);
            if(chose == -1) //done
                break;
            else 
            {
                chosen.insert(chose);
                A += aliceValues[chose];
            }
            chose = getmin(bobValues, chosen);
            if(chose == -1)
                break;
            else 
            {
                chosen.insert(chose);
                B += bobValues[chose];
            }
        }
        if(A > B)
            return 1;
        else if(A < B)
            return -1;
        return 0;
    }
};
