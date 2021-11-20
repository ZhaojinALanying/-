#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> window;
        while (right < s.size()) {
            char c = s[right++];        // 直接滑动右边窗口
            window[c]++;                // 加入窗口map，即用于判断窗口内元素组成是否满足条件
            while (window[c] > 1) {     // 判断题目条件
                char d = s[left++];     // 直接滑动左边窗口
                window[d]--;            // 条件还满足就需要删除map中元素
            }
            maxLen = max(maxLen, right - left);  // 更新满足条件的结果
        }
        return maxLen;
    }
};

int main()
{
    string s = "cdd";
    Solution sol;
    int r = sol.lengthOfLongestSubstring(s);
    printf("longest substr is %d\n", r);
}