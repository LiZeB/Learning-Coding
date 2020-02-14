/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *result = NULL;
		ListNode *index_A = headA, *index_B = headB;
		int count_A = 0, count_B = 0;
		while (index_A != NULL) {
			count_A += 1;
			index_A = index_A->next;
		}
		while (index_B != NULL) {
			count_B += 1;
			index_B = index_B->next;
		}

		index_A = headA, index_B = headB;
		if (count_A > count_B) {
			int temp = count_A - count_B;
			while (temp--) {
				index_A = index_A->next;
			}
		}
		if (count_A < count_B) {
			int temp = count_B - count_A;
			while (temp--) {
				index_B = index_B->next;
			}
		}
		while (index_A != NULL && index_B != NULL) {
			if (index_A == index_B) {
				result = index_A;
				break;
			}
			index_A = index_A->next;
			index_B = index_B->next;
		}

		return result;
	}
};