#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define mod 1000000007

using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {}
};

ListNode* Make(vector<int> nums) {
  ListNode* head = new ListNode(nums[0]);
  ListNode* curr = head;
  for (int i=1; i<nums.size(); ++i) {
    ListNode* next = new ListNode(nums[i]);
    curr->next = next;
    curr = next;
  }
  return head;
}

void Print(ListNode* head) {
  ListNode* curr = head;
  while (curr != nullptr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << "null" << endl;
}

ListNode* reverseKGroup(ListNode* head, int k) {
  if (k==1) {
    return head;
  }
  if (head == nullptr) {
    return head;
  }
  ListNode* entry = head; // the node before the part to reverse
  ListNode* first; ListNode* last;
  ListNode* curr = head;
  ListNode* new_head;
  int size = 0;
  while (curr != nullptr) {
    ++size;
    curr = curr->next;
  }
  curr = head;
  int num_groups = size / k; // number of groups
  // k = 2
  // 1 2    3 4    5 6
  for (int g=0; g<num_groups; ++g) {
    for (int i=1; i<=k; ++i) {
      ListNode* next = curr->next;
      if (i==1) {
        first = curr;
        last = curr;
      }
      if (i > 1) {
        curr->next = first;
        first = curr;
      }
      curr = next;
    }
    last->next = curr; // last node of the reverse list needs to point to the next node in the remaining list
    if (g==0) {
      new_head = first;
    }
    if (g>0) {
      entry->next = first; // node before part to reverse needs to point to the first node in reverse list
      // but only if this node is not head
    }
    entry = last; // the new node before the next part to reverse is the last node in the reversed list
  }
  return new_head;
}

int main() {
  ListNode* l = Make({1,2,3,4,5});
  ListNode* r = reverseKGroup(l, 3);
  Print(r);
}

