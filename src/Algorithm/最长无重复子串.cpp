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
            char c = s[right++];        // ֱ�ӻ����ұߴ���
            window[c]++;                // ���봰��map���������жϴ�����Ԫ������Ƿ���������
            while (window[c] > 1) {     // �ж���Ŀ����
                char d = s[left++];     // ֱ�ӻ�����ߴ���
                window[d]--;            // �������������Ҫɾ��map��Ԫ��
            }
            maxLen = max(maxLen, right - left);  // �������������Ľ��
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