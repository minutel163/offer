#include "listNode.h"
class MyList {
public :
	ListNode *head = NULL;
	ListNode *tail = NULL;
public :
	MyList(){
		head = new ListNode(0);
		head->next = tail;

	}
	void addNode(int newVal){
		ListNode *newNode = new ListNode(newval);
		if(head->next == NULL){
			head->next = newNode;
			newNode->last = head;
			tail = newNode;
		}else{
			tail->next = newNode;
			newNode->last = tail;
			tail = newNode;
		}
	}
    ListNode* deleteDuplication(){
        ListNode *currentNodeP = head->next;
        ListNode *lastNodeP = head;
		ListNode *nextNodeP = NULL;
        while(currentNodeP != NULL ){
            nextNodeP = currentNodeP->next;
            bool dupFlag = false;
            while(nextNodeP != NULL){
                if(nextNodeP->val == currentNodeP->val){
                    dupFlag = true;
					currentNodeP->next = nextNodeP->next;
                    delete nextNodeP;
					nextNodeP= currentNodeP->next;
                }else{
					nextNodeP= nextNodeP->next;
				}
            }
            if(dupFlag == true){
				lastNodeP->next = currentNodeP->next;
				delete currentNodeP;
                currentNodeP = currentNodeP->next;
            }else{
                lastNodeP = currentNodeP;
                currentNodeP = currentNodeP->next;
            }
        }
		return head;
    }
	void printNodeListVal(){
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
    ListNode* deleteOneNode(ListNode* nodeToBeDel){
		if(head == NULL || nodeToBeDel == NULL){
			return NULL;
		}
		if(head->next == NULL && pHead == nodeToBeDel){
			delete pHead;
			return NULL;
		}
		if(nodeToBeDel->next != NULL){
			ListNode *tmpNode = nodeToBeDel->next;
			nodeToBeDel->val = tmpNode->val;
			nodeToBeDel->next = tmpNode->next;
			delete tmpNode;
			return head;
		}else{
			ListNode* currentNode = head;
			while(currentNode->next != nodeToBeDel){
				currentNode = currentNode->next;
			}
			delete nodeToBeDel;
			currentNode->next = NULL;
			return head;
		}
	}
	ListNode* bubbleSort(){
		if(head->next == NULL){
			return head;
		}
		ListNode* currentNode = head->next;
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
		return head;
	}
	void swap(ListNode* node1,ListNode* node2){
		int tmpVal = node1->val;
		node1->val = node2->val;
		node2->val = tmpVal;

	}
};
