#pragma once
#include<iostream>
//We can only add const varible to the list so do intialize them as const then add
template <typename T>
class List {
  public:
    const T & operator[](unsigned index);
    void prepend(const T & data);
    void presort(const T & data);
    //insert in the linked list on a ordered position
    void rever();
    //Returns the true length of the list
    int listlength();
    //this constructor, head_ is null-initialized.
    List() : head_(nullptr) {std::cout<<"constructed\n"; }
    //destructor to delete the memory allocated for the ListNode, when the List is destroyed.
    ~List() {
      //from the head.
      ListNode *thru = head_;
      while (thru != nullptr) {
        // Copy the address that the "thru" pointer has currently.
        ListNode* toDelete = thru;
        // Step the pointer to the "next" pointer of the current node.
        thru = thru->next;
        //we can delete the toDelete pointer.As we needed
        // the next pointer information first.
        delete toDelete;
        // We don't strictly need to set toDelete to nullptr here because
        // it goes out of scope immediately after, but remember that you
        // should generally do this after deleting a pointer:
        toDelete = nullptr;
      }
      std::cout<<"deletion executed\n";
    }


  private:
    class ListNode {
      public:
        const T & data;
        ListNode *next;
        ListNode *prev;
        ListNode(const T & data) : data(data), next(nullptr), prev(nullptr) {std::cout<<"data placed\n"; }
    };

    ListNode *head_;   /*< Head pointer for our List */
    ListNode *tail_;   /*< Tail pointer for our List */
    ListNode* _find(const T & data);


};

// Finish including the rest of the header from the additional header file.
#include "List.cpp"
