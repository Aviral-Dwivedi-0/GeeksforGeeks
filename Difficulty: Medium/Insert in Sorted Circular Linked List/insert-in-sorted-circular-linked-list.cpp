/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* newNode = new Node(data);

        
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;

        while (true) {
            if ((curr->data <= data && curr->next->data >= data)) {
                break;
            }
            if (curr->data > curr->next->data && (data >= curr->data || data <= curr->next->data)) {
                break;
            }
            curr = curr->next;
            if (curr == head) break;
        }

        newNode->next = curr->next;
        curr->next = newNode;

        if (data < head->data)
            return newNode;

        return head;
    }
};