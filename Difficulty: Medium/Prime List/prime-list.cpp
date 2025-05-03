//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    public:
    Node *primeList(Node *head) {
      
      Node* root=head;
      while(root){
          int ele=root->val;
          bool istrue=false;
          if(ele==1){
              root->val=2;
              root=root->next;
              continue;
          }
          for(int i=2;i*i<=ele;i++){
              if(ele%i==0){
                  istrue=true;
                  break;
              }
          }
          if(istrue){
              int num1=-1;
              int num2=-1;
              bool is1=false;
              bool is2=false;
              for(int i=ele;i<=1e5;i++){
                  for(int j=2;j*j<=i;j++){
                      if(i%j==0){
                          is1=true;
                          break;
                      }
                  }
                  if(!is1){
                      num1=i;
                      break;
                  }
                  is1=false;
              }
              
              
             for(int i=ele;i>=2;i--){
                  for(int j=2;j*j<=i;j++){
                      if(i%j==0){
                          is2=true;
                          break;
                      }
                  }
                  if(!is2){
                      num2=i;
                      break;
                  }
                  is2=false;
              } 
              if(num1-ele<ele-num2)
              root->val=num1;
              else
              root->val=num2;
          }
          root=root->next;
      }
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends