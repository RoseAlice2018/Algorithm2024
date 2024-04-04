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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dic;
        for(string str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            dic[tmp].push_back(str);
        }
        vector<vector<string>> ret;
        for(auto key : dic)
        {
            ret.push_back(key.second);
        }
        return ret;
    }
};