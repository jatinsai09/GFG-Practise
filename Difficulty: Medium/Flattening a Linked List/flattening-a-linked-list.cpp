/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* merge(Node* list1,Node* list2){
        Node* dummy = new Node(0);
        Node* cur = dummy;
        
        while(list1 && list2){
            if(list1->data < list2->data){
                cur->bottom = list1;
                list1 = list1->bottom;
            }
            else{
                cur->bottom = list2;
                list2 = list2->bottom;
            }
            
            cur->next = nullptr;
            cur = cur->bottom;
        }
        
        if(list1){
            cur->bottom = list1;
        }
        else{
            cur->bottom = list2;
        }
        
        return dummy->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *head) {
        // Your code here
        if(!head || !head->next){
            return head;
        }
        
        Node* mergedHead = flatten(head->next);
        head = merge(head, mergedHead);
        
        return head;
    }
};

