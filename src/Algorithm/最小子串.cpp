#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (const char c : t) {
            need[c]++;   // 初始化目标map表
        }
        int validNumInWindow = 0;
        while (right < s.size()) {
            const char c = s[right++]; // 取值并向右滑动，（滑动窗口第一步）
            if (need.count(c)) {       // 满足条件
                window[c]++;           // 窗口内满足条件的map，元素的个数
                if (window.count(c) == need.count(c)) { // 等于目标map，元素个数
                    validNumInWindow++;                 // 满足条件的个数加1
                }
            }
            while (right - left >= t.size()) { // 窗口>=t.size就移动左边，因为是全排列字串
                // 满足条件就返回true
                if (validNumInWindow == need.size()) {  // 找到满足条件的排列就返回了
                    return true;
                }
                const char d = s[left++];               // 否则继续滑动左边窗口
                if (need.count(d)) {
                    window[d]--;
                    if (window.count(d) == need.count(d)) {
                        validNumInWindow--;
                    }
                }
            }

        }
        return false;
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "BAE";
    Solution sol;
    int r = sol.minWindow(s, t);
    printf(R"(min sub str is %d)", r);
}