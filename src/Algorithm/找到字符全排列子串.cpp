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
            const char c = s[right]; // ȡֵ�����һ���
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    validNumInWindow++;
                }
            }
            while (right - left >= targetLen) { // ����>=t.size���ƶ���ߣ���Ϊ��ȫ�����ִ�
                // ���������ͷ���true
                if (validNumInWindow == need.size()) {
                    //if (strncmp(s.substr(left, targetLen), t) != 0) {
                        stringIndex.push_back(left);
                    //}   
                }
                const char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) { // ������Ȳ����ж�����
                        validNumInWindow--;
                    }
                    window[d]--; // �ص㣡�������window�����ǶԳƵģ�����
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