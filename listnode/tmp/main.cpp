#include <iostream>
using namespace std;
#include "listNode.h"
#include "listNode.cpp"
int main(){
	MyList myList = new MyList();
	myList.addNode(0);
	myList.addNode(1);
	myList.addNode(2);
	myList.addNode(3);
	myList.addNode(4);
	myList.addNode(5);
	myList.addNode(6);
	myList.addNode(7);
	myList.addNode(8);
	myList.addNode(9);
	myList.addNode(10);
	cout << "before deal ,List is :" << endl;
	myList.printNodeListVal();
	head = myList.deleteDuplication();
	//head = sol1.deleteOneNode(head , node7);
	//head = sol1.bubbleSort(head);
	cout << "after deal ,List is :" << endl;
	myList.printNodeListVal();
	return 0;
}
