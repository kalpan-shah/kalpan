#include "List.h"
#include<ostream>

//To review the data stored in List
template <typename T>
const T & List<T>::operator[](unsigned index) {
  // Start a `thru` pointer to advance thru the list:
  ListNode *thru = head_;
  // Loop until the end of the list (or until a `nullptr`):
  while (index > 0 && thru->next != nullptr) {
    thru = thru->next;
    index--;
  }
  // Return the data:
  return thru->data;
}
//Reverse the order of List
template <typename T>
void List<T>::rever(){
    ListNode *current = head_; // start from head and points the data around which the loop will work
    ListNode *node = nullptr; //To point the linked data that is before the current data
    ListNode *next = nullptr; //Locally using it for storing next link and also to update it indirectly
    while(current != nullptr){
        next = current->next;
        current->next = node;
        node = current;
        current = next;
    }
    std::cout<<"Before reversing head:"<<head_->data<<"\n";
    head_ = node;
    std::cout<<"after reversing head:"<<head_->data<<"\n";
}
//returns the length of the List
template <typename T>
int List<T>::listlength(){
    int cnt = 1;
    ListNode *node = head_;
    while(node->next != nullptr){
        node = node->next;
        cnt++;
    }
    return cnt;
}
//Insert data in front of the List
template <typename T>
void List<T>::prepend(const T & data) {

  // Create a new ListNode on the heap:
    ListNode *node = new ListNode(data);
  // Set the new node’s next pointer point the current
  // head of the List:
    node->next = head_;
  // Set the List’s head pointer to be the new node:
    head_ = node;

}
//Inserting data in a sorted manner
template <typename T>
void List<T>::presort(const T & data){
    ListNode *node = new ListNode(data);
    ListNode *thru = head_;
    ListNode *temp = nullptr;
    do{
        if((thru->data > node->data && thru->next->data <= node->data) ||
           (thru->data < node->data && thru->next->data >= node->data) ) {
            temp = thru->next;
            thru->next = node;
            thru->next->next = temp;
            break;
        }
        else if((thru->data < thru->next->data && node->data < thru->data) ||
                (thru->data > thru->next->data && node->data > thru->data)){
                node->next = head_;
                head_ = node;
                break;
        }
        else if(thru->next->next == nullptr && (
        (thru->data > thru->next->data && node->data < thru->next->data) || (
         thru->data < thru->next->data && node->data > thru->next->data))){
                thru->next->next = node;
                node->next = nullptr;
                break;
        }
        thru = thru->next;
    }while(thru != nullptr);
}
/**
 * Finds and returns the ListNode containing `data` in the
 * List or `nullptr` if the data is not found.
 */
template <typename T>
typename List<T>::ListNode *List<T>::_find(const T & data) {
  ListNode *thru = head_;
  while (thru != nullptr) {
    if (thru->data == data) { return thru; }
    thru = thru->next;
  }

  return nullptr;
}
