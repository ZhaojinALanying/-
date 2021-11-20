#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        vector<int> stringIndex;
        int targetLen = t.size();
        for (const char c : t) {
            need[c]++;
        }
        int validNumInWindow = 0;
        while (right < s.size()) {
            const char c = s[right]; // 取值并向右滑动
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    validNumInWindow++;
                }
            }
            while (right - left >= targetLen) { // 窗口>=t.size就移动左边，因为是全排列字串
                // 满足条件就返回true
                if (validNumInWindow == need.size()) {
                    //if (strncmp(s.substr(left, targetLen), t) != 0) {
                        stringIndex.push_back(left);
                    //}   
                }
                const char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) { // 数量相等才是判断条件
                        validNumInWindow--;
                    }
                    window[d]--; // 重点！！与更新window操作是对称的！！！
                }
            }
        }
        return stringIndex;
    }
};

int main()
{

    string s = "cbaebabacd";
    string t = "abc";
    Solution sol;
    vector<int> r = sol.minWindow(s, t);
    for (int i = 0; i < r.size(); i++) {
        printf(R"(%d )", r[i]);
    }
    
}