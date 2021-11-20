#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (const char c : t) {
            need[c]++;
        }
        int validNumInWindow = 0;
        int start = 0;
        int len = INT_MAX; // 最小覆盖字串的记录
        while (right < s.size()) {
            const char c = s[right++]; // 取值并向右滑动
            if (need.count(c)) {
                window[c]++;
                if (window.count(c) == need.count(c)) {
                    validNumInWindow++;
                }
            }
            while (validNumInWindow == need.size()) {
                // 最小覆盖字串的更新
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                const char d = s[left++];
                if (need.count(d)) {
                    window[d]--;
                    if (window.count(d) == need.count(d)) {
                        validNumInWindow--;
                    }
                }
            }

        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "BC";
    Solution sol;
    string r = sol.minWindow(s, t);
    printf(R"(min sub str is %s)", r.c_str());
}