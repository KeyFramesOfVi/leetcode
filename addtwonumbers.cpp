#include <iostream>
#include <vector>
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val{ x }, next{ nullptr } {}
};

ListNode* listToArray(std::vector<int>&);
void printSum(ListNode*);
ListNode* addTwoNumbers(ListNode*, ListNode*);
int main(){
	std::vector<int> list_one = { 2, 4, 3 };
	std::vector<int> list_two = { 5, 6, 4 };
	ListNode* l1 = listToArray(list_one);
	ListNode* l2 = listToArray(list_two);
	ListNode* sum = addTwoNumbers(l1, l2);
	printSum(sum);
	return 0;
}

/* Simple function to put a vector into a List
 * for the purposes of a simple test. For a more proper
 * test, test on leetcode.
 */
ListNode* listToArray(std::vector<int> & list) {
	ListNode * prev = new ListNode(0);
	ListNode * list_sum = prev;
	for(auto & val : list){
		ListNode * curr = new ListNode(0);
		curr->val = val;
		prev->next = curr;
		prev = curr; 
	}
	return list_sum->next;
}

// Goes through the list and prints the sum using a while loop.
void printSum(ListNode* sum){
	while(sum != nullptr){
		std::cout << sum->val << " ";
		sum = sum->next;
	}
	std::cout << std::endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	/* set a prev node that will allow you to correctly
	 * place each value of the sum. Use the list_sum node as 
	 * a sentinel node due to the lack of an initial constructor
	 * in the leetcode struct. This node also remains at the start 
	 * so you can return the whole list.
	 */
	ListNode* prev = new ListNode(0);
    ListNode* list_sum = prev;
    int carry = 0;

    /* There are 3 situations that can occur: list1 ends and list2 still
     * has nodes, vice versa, and both lists are empty but there is still 
     * a carry to add. Simply keep adding until all of these conditions are
     * met.
     */
    while(l1 != nullptr || l2 != nullptr || carry != 0) {
        ListNode * curr = new ListNode(0);

        /* This keeps track of those situations mentioned before. Add the list's contents or
         * add 0, and add the carry, which will always be 1 or 0 depending on the sum value.
         */
        int sum = ((l1 == nullptr) ? 0 : l1->val) + ((l2 == nullptr) ? 0 : l2->val) + carry;
        carry = sum / 10;
        sum = sum % 10;
        // Set curr's value and set prev->next to curr, updating your head. Then move prev to curr.
        curr->val = sum; 
        prev->next = curr;
        prev = curr;

        // Traverse each node if they are not finished 
        l1 = (l1 == nullptr) ? l1 : l1->next;
        l2 = (l2 == nullptr) ? l2 : l2->next;
    }
    // Return list_sum->next since head is a sentinel Node with the value 0.
    return list_sum->next;
}