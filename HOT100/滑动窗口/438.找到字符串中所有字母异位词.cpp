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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(s.size() < p.size()) return ret;

        sort(p.begin(), p.end());
        int left = 0, right = p.size() - 1;
        //first init
        while(right < s.size())
        {
            string tmp = s.substr(left, right - left + 1);
            sort(tmp.begin(), tmp.end());
            if(tmp == p)
            {
                ret.push_back(left);
            }
            left++;
            right++;
        }
        return ret;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(s.size() < p.size()) return ret;

        sort(p.begin(), p.end());
        int left = 0, right = p.size() - 1;
        unordered_multiset<char> p_set;
        unordered_multiset<char> s_set;
        for(int i = 0; i < p.size(); i++)
        {
            s_set.insert(s[i]);
            p_set.insert(p[i]);
        } 
        //first init
        while(right < s.size())
        {
            if(s_set == p_set)
            {
                ret.push_back(left);
            }
            left++;
            right++;
            s_set.erase(s_set.find(s[left - 1]));
            s_set.insert(s[right]);
        }
        return ret;
    }
};
