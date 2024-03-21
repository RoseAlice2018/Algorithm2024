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

//超时
class FrequencyTracker {
public:
    FrequencyTracker() {

    }
    
    void add(int number) {
        if(_dict.count(number))
            _dict[number]++;
        else 
            _dict[number] = 1;
    }
    
    void deleteOne(int number) {
        if(_dict.count(number))
        {
            _dict[number]--;
            if(_dict[number] == 0)
            {
                auto iter = _dict.find(number);
                if( iter != _dict.end())
                    _dict.erase(iter);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        for(auto iter = _dict.begin(); iter != _dict.end(); iter++)
        {
            if(iter->second == frequency)
                return true;
        }
        return false;
    }
    unordered_map<int, int> _dict;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

class FrequencyTracker {
public:
    FrequencyTracker():freq(N), freq_cnt(N) {
        
    }

    void add(int number) {
        --freq_cnt[freq[number]];
        ++freq[number];
        ++freq_cnt[freq[number]];
    }
    
    void deleteOne(int number) {
        if (freq[number] == 0) {
            return;
        }
        --freq_cnt[freq[number]];
        --freq[number];
        ++freq_cnt[freq[number]];
    }
    
    bool hasFrequency(int frequency) {
        return freq_cnt[frequency];
    }

private:
    static constexpr int N = 100001;
    vector<int> freq;
    vector<int> freq_cnt;
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/frequency-tracker/solutions/2679864/pin-lu-gen-zong-qi-by-leetcode-solution-3d04/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。