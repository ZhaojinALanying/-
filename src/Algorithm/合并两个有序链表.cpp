#include<list>
using namespace std;
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        // ����ͷ���
        ListNode *dummy = new ListNode(-1);  // ��������ϳ�һ������Ҫ����һ������������ͷ�����ڹ���l1 l2 ��ÿ���ڵ㡣
        ListNode *p = dummy;
        ListNode *p1 = l1, *p2 = l2;

        while (p1 != nullptr && p2 != nullptr) {
            // �Ƚ� p1 �� p2 ����ָ��
            // ��ֵ��С�ĵĽڵ�ӵ� p ָ��
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            }
            else {
                p->next = p1;
                p1 = p1->next;
            }
            // p ָ�벻��ǰ��
            p = p->next;
        }

        if (p1 != nullptr) {
            p->next = p1;
        }

        if (p2 != nullptr) {
            p->next = p2;
        }

        return dummy->next;
    }
};
