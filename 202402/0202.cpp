#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<tuple>
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
        int n = aliceValues.size();

        vector<tuple<int, int, int>> values;
        for(int i = 0; i < n; i++)
        {
            values.emplace_back(aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]);
        }

        sort(values.begin(), values.end(), [](tuple<int,int,int>& a,tuple<int, int, int> &b){
            return get<0>(a) > get<0>(b);
        });

        int aliceSum = 0, bobSum = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i % 2 == 0)
            {
                aliceSum += get<1>(values[i]);
            }
            else 
                bobSum += get<2>(values[i]);
        }

        if(aliceSum >bobSum)
            return 1;
        else if(aliceSum == bobSum)
            return 0;
        else 
            return -1;
        
        return 0;    
    }
};
