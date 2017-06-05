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
