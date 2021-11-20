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
            need[c]++;   // ��ʼ��Ŀ��map��
        }
        int validNumInWindow = 0;
        while (right < s.size()) {
            const char c = s[right++]; // ȡֵ�����һ��������������ڵ�һ����
            if (need.count(c)) {       // ��������
                window[c]++;           // ����������������map��Ԫ�صĸ���
                if (window.count(c) == need.count(c)) { // ����Ŀ��map��Ԫ�ظ���
                    validNumInWindow++;                 // ���������ĸ�����1
                }
            }
            while (right - left >= t.size()) { // ����>=t.size���ƶ���ߣ���Ϊ��ȫ�����ִ�
                // ���������ͷ���true
                if (validNumInWindow == need.size()) {  // �ҵ��������������оͷ�����
                    return true;
                }
                const char d = s[left++];               // �������������ߴ���
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