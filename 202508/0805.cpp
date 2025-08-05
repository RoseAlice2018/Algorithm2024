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
    int binary_search(vector<int> &nums, int target, int left, int right)
    {
        if(left > right) return -1;
        int mid = (right + left) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] < target)
        {
            return binary_search(nums, target, mid + 1, right);
        }
        else{
            return binary_search(nums, target, left, mid - 1);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       return binary_search(nums, target, 0, nums.size() - 1); 
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (right + left) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                left = mid + 1;
                continue;
            }
            else{
                right = mid - 1;
                continue;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int getvalue(string v)
    {
        int ret = 0;
        for(int i = 0; i < v.size();i++)
        {
            ret = ret * 10 + v[i] - '0';
        }
        return ret;
    }
    int _compare(string version1, string version2)
    {
        int v1 = getvalue(version1);
        int v2 = getvalue(version2);
        cout<<v1<<"XXX"<<v2<<endl;
        if(v1 == v2) return 0;
        return v1 > v2 ? 1 : -1;
    }

    vector<string> split(string version)
    {
        string tmp;
        vector<string> ret;
        for(int i = 0; i < version.size(); i++)
        {
            if(version[i] == '.')
            {
                ret.emplace_back(tmp);
                tmp.clear();
                for(int j = i + 1; j < version.size(); j++)
                {
                    if(version[j] == '0')
                        continue;
                    else{
                        i = j - 1;
                    }
                }
            }
            else{
                tmp.push_back(version[i]);
            }
        }
        ret.push_back(tmp);
        return ret;
    }

    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1);
        vector<string> v2 = split(version2);
        for(int i = 0; i < max(v1.size(), v2.size()); i++)
        {
            string tmp1 =  i < v1.size() ? v1[i] : "0";
            cout<<tmp1<<" "<<v1.size()<<endl;;
            string tmp2 =  i < v2.size() ? v2[i] : "0";
            cout<<tmp2<<" "<<v2.size()<<endl;;
            int ret = _compare(tmp1, tmp2);
            cout<<ret<<endl;
            if(ret == 0)
                continue;
            return ret;
        }
        return 0;
    }
};

class Solution {
public:
	int compareVersion(string version1, string version2) {
		stringstream ss;
		vector<int> v1, v2;
		string s;
		ss << version1;
		while (getline(ss, s, '.')) {
			v1.push_back(stoi(s));
		}
		ss.clear();
		ss << version2;
		while (getline(ss, s, '.')) {
			v2.push_back(stoi(s));
		}
		while (v1.size() < v2.size())	v1.push_back(0);
		while (v2.size() < v1.size())	v2.push_back(0);
		for (int i = 0; i < v1.size(); ++i) {
			if (v1[i] > v2[i])	return 1;
			else if (v1[i] < v2[i])	return -1;
		}
		return 0;
	}
};
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ret = s2.top();
        s2.pop();
        return ret;
    }
    
    int peek() {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s2.empty() && s1.empty())
            return true;
        return false;
    }
};
