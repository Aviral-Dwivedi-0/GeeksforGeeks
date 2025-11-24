/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int carry=1;
    Node* solve(Node* head){
        if(!head->next){
            if(head->data==9){
                head->data=0;
            }
            else{
                head->data=head->data+1;
                carry=0;
            }
            return head;
        }
        addOne(head->next);
        
        if(carry==0) return head;
        if(head->data==9){
            head->data=0;
            carry=1;
        }
        else{
            head->data+=1;
            carry=0;
        }
        return head;
    }
    Node* addOne(Node* head) {
        // Your Code here
        solve(head);
        if(carry==1){
            Node* n1=new Node(1);
            n1->next=head;
            head=n1;
        }
        return head;
        // return head of list after adding one
    }
};