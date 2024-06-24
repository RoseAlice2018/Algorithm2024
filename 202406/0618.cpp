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
    bool is_price(string word, int& number)
    {
        if(word[0] == '$')
        {
            number = 0;
            for(int idx = 0; idx < word.size(); idx++)
            {
                if(word[idx] - '0' >=0 && word[idx] - '0' <=9)
                {
                    number = number * 10 + word[idx] - '0';
                }
                else 
                    return false;
            }
            return true;
        }
        return false;
    }
    string discount_word(string word, int discount)
    {

    }
    string discountPrices(string sentence, int discount) {
        if(sentence.size() == 0) return sentence;

        int left = 0, right = 0;
        for(int idx = left; idx < sentence.size(); idx++)
        {
            if(sentence[idx] == ' '|| idx == sentence.size() - 1)
            {
                //find a word 
                string word = sentence.substr(left, idx - left);
                int number = 0;
                if(is_price(word, number))
                {
                    string tmp = discount_word(word, discount);
                }
            }
        }
    }
};


class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream sin(sentence), sout;
        sout << fixed << setprecision(2);

        vector<string> words;
        string word;
        while (sin >> word) {
            if (word[0] == '$' && word.size() > 1 && all_of(word.begin() + 1, word.end(), ::isdigit)) {
                double price = stoll(word.substr(1, word.size() - 1)) * (1.0 - discount / 100.0);
                sout << '$' << price;
            }
            else {
                sout << word;
            }
            sout << " ";
        }
        string ans = sout.str();
        ans.pop_back();
        return ans;
    }
};
