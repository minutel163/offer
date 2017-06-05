#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
	struct ListNode *last;
    ListNode(int x) :
        val(x), next(NULL),last(NULL) {
    }
};

class Solution {
public :
	Solution(){}
    ListNode* deleteDuplication(ListNode* pHead){
        ListNode *currentNodeP = pHead->next;
		ListNode *nextNodeP = NULL;
        while(currentNodeP != NULL ){
            nextNodeP = currentNodeP->next;
            bool dupFlag = false;
            while(nextNodeP != NULL){
                if(nextNodeP->val == currentNodeP->val){
                    dupFlag = true;
					nextNodeP->last->next = nextNodeP->next;
					if(nextNodeP->next != NULL){
						nextNodeP->next->last = nextNodeP->last;
					}
					ListNode *tmpNodeP = nextNodeP;
					nextNodeP = tmpNodeP->next;
                    delete tmpNodeP;
                }else{
					nextNodeP= nextNodeP->next;
				}
            }
            if(dupFlag == true){
				currentNodeP->last->next = currentNodeP->next;
				if(currentNodeP->next != NULL){
					currentNodeP->next->last = currentNodeP->last;
				}
				ListNode *tmpNodeP = currentNodeP;
                currentNodeP = tmpNodeP->next;
				delete tmpNodeP;
            }else{
                currentNodeP = currentNodeP->next;
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
			cout << tmpNodeP->val<< endl;
			counter++;
			tmpNodeP = tmpNodeP->next;
		}
	}
    ListNode* deleteOneNode(ListNode* pHead , ListNode* nodeToBeDel){
		if(pHead == NULL || nodeToBeDel == NULL){
			return NULL;
		}
		if(pHead->next == NULL && pHead == nodeToBeDel){
			delete pHead;
			return NULL;
		}
		if(nodeToBeDel->next != NULL){
			ListNode *tmpNode = nodeToBeDel->next;
			nodeToBeDel->val = tmpNode->val;
			nodeToBeDel->next = tmpNode->next;
			tmpNode->next->last = nodeToBeDel;
			delete tmpNode;
			return pHead;
		}else{
			ListNode* currentNode = pHead;
			while(currentNode->next != nodeToBeDel){
				currentNode = currentNode->next;
			}
			delete nodeToBeDel;
			currentNode->next = NULL;
			return pHead;
		}
	}
	ListNode* bubbleSort(ListNode* pHead){
		if((*pHead).next == NULL){
			return pHead;
		}
		ListNode* currentNode = pHead->next;
		while(currentNode != NULL){
			ListNode* tmpNode = currentNode->next;
			while(tmpNode != NULL){
				if(currentNode->val > tmpNode->val){
					swap(currentNode , tmpNode);
				}
				tmpNode = tmpNode->next;
			}
			currentNode = currentNode->next;
		}
		return pHead;
	}
	void swap(ListNode* node1,ListNode* node2){
		int tmpVal = node1->val;
		node1->val = node2->val;
		node2->val = tmpVal;

	}
};
int main(){
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(0);
	ListNode* node3 = new ListNode(0);
	ListNode* node4 = new ListNode(10);
	ListNode* node5 = new ListNode(6);
	ListNode* node6 = new ListNode(7);
	ListNode* node7 = new ListNode(9);
	ListNode* node8 = new ListNode(1);
	node1->next = node2;
	node2->last = node1;
	node2->next = node3;
	node3->last = node2;
	node3->next = node4;
	node4->last = node3;
	node4->next = node5;
	node5->last = node4;
	node5->next = node6;
	node6->last = node5;
	node6->next = node7;
	node7->last = node6;
	node7->next = node8;
	node8->last = node7;
	node8->next = NULL;
	ListNode* head = new ListNode(-1);
	head->next = node1;
	node1->last = head;
	Solution sol1 ;
	cout << "before deal ,List is :" << endl;
	sol1.printNodeListVal(head->next);
	//head = sol1.deleteDuplication(head);
	head = sol1.deleteOneNode(head , node7);
	//head = sol1.bubbleSort(head);
	cout << "after deal ,List is :" << endl;
	sol1.printNodeListVal(head->next);
	cout<< "next->next->next->last"<<(*head->next->next->last).val<<endl;
	return 0;
}
