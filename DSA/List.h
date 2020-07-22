//Linked list
#pragma once

template <typename T>
class List {
  public:
    const T & operator[](unsigned index);
    void prepend(const T & data);

    //this constructor, head_ is null-initialized.
    List() : head_(nullptr) { }


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
    }

  private:
    class ListNode {
      public:
        const T & data;
        ListNode *next;
        ListNode(const T & data) : data(data), next(nullptr) { }
    };

    ListNode *head_;   /*< Head pointer for our List */

    ListNode* _find(const T & data);
};

// Finish including the rest of the header from the additional header file.
#include "List.cpp"
