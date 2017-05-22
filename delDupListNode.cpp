#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public :
	Solution(){}
    ListNode* deleteDuplication(ListNode* pHead){
        ListNode *currentNodeP = (*pHead).next;
        ListNode *lastNodeP = pHead;
		ListNode *nextNodeP = NULL;
        while(currentNodeP != NULL ){
            nextNodeP = (*currentNodeP).next;
            bool dupFlag = false;
            while(nextNodeP != NULL){
                if((*nextNodeP).val == (*currentNodeP).val){
                    dupFlag = true;
					(*currentNodeP).next = (*nextNodeP).next;
                    delete nextNodeP;
					nextNodeP= (*currentNodeP).next;
                }else{
					nextNodeP= (*nextNodeP).next;
				}
            }
            if(dupFlag == true){
				(*lastNodeP).next = (*currentNodeP).next;
				delete currentNodeP;
                currentNodeP = (*currentNodeP).next;
            }else{
                lastNodeP = currentNodeP;
                currentNodeP = (*currentNodeP).next;
            }
        }
		return pHead;
    }
	void printNodeListVal(ListNode* head){
		string cString = "counter";
		ListNode* tmpNodeP = head;
		if(tmpNodeP == NULL){
			return;
		}
		int counter = 0;
		while(tmpNodeP != NULL){
			cout << (*tmpNodeP).val<< endl;
			counter++;
			tmpNodeP = (*tmpNodeP).next;
		}
	}
};
int main(){
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(1);
	ListNode* node5 = new ListNode(3);
	ListNode* node6 = new ListNode(1);
	ListNode* node7 = new ListNode(4);
	ListNode* node8 = new ListNode(5);
	(*node1).next = node2;
	(*node2).next = node3;
	(*node3).next = node4;
	(*node4).next = node5;
	(*node5).next = node6;
	(*node6).next = node7;
	(*node7).next = node8;
	(*node8).next = NULL;
	ListNode* head = new ListNode(-1);
	(*head).next = node1;
	Solution sol1 ;
	head = sol1.deleteDuplication(head);
	sol1.printNodeListVal((*head).next);
	return 0;
}
