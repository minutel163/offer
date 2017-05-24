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
		string x = "i:";
		string y = "j:";
		string icv = "icval";
		string inv = "inval:";
		string jcv = "jcval";
		string jnv = "jnval:";
		string delnext = "deleteNext";
		string delcurr = "deleteCurr";
        ListNode *currentNodeP = pHead;
        ListNode *lastNodeP = NULL;
		ListNode *nextNodeP = NULL;
		int i = 0;
        while(currentNodeP != NULL ){
			cout << x << i <<endl;
			i++;
			cout << icv << (*currentNodeP).val<<endl;
            nextNodeP = (*currentNodeP).next;
            bool dupFlag = false;
			int j = 0;
            while(nextNodeP != NULL){
				cout<< y << j <<endl;
				j++;
				cout << jcv << (*currentNodeP).val<<endl;
				cout << jnv << (*nextNodeP).val<<endl;
                if((*nextNodeP).val == (*currentNodeP).val){
                    dupFlag = true;
					(*currentNodeP).next = (*nextNodeP).next;
					cout<<delnext<<endl;
                    delete nextNodeP;
					cout << "next"<<endl;
					nextNodeP= (*currentNodeP).next;
                }else{
					nextNodeP= (*nextNodeP).next;
				}
            }
            if(dupFlag == true){
                if(currentNodeP == pHead){
                    pHead = (*pHead).next;
                    currentNodeP = (*currentNodeP).next;
					cout<<delcurr<<endl;
                    delete currentNodeP ;
                }else{
                    currentNodeP = (*currentNodeP).next;
                }
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
			cout << cString<<"  "<< counter << endl;
			cout << (*tmpNodeP).val<< endl;
			counter++;
			tmpNodeP = (*tmpNodeP).next;
		}
	}
};
int main(){
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(3);
	ListNode node5(3);
	ListNode node6(3);
	ListNode node7(4);
	ListNode node8(5);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node7;
	node7.next = &node8;
	node8.next = NULL;
	ListNode* head = &node1;
	Solution sol1 ;
	ListNode *tmpNode = sol1.deleteDuplication(head);
	cout << "=======";
	sol1.printNodeListVal(tmpNode);
	return 0;
}
