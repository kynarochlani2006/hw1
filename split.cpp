/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"


/* Add a prototype for a helper function here if you need */

Node* odds_tail = nullptr;
Node* evens_tail = nullptr;

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  if(in == nullptr){
    return;
  }

  if(in->value % 2 != 0){

    if(odds == nullptr){
      odds = in;
      in = in->next;
      odds->next = nullptr;
      odds_tail = odds;
    } else {
      Node* curr = odds_tail;
      curr->next = in;
      odds_tail = curr->next;
      in = in->next;
      odds_tail->next = nullptr;
    }
    
  } else {

    if(evens == nullptr){
      evens = in;
      in = in->next;
      evens->next = nullptr;
      evens_tail = evens;
    } else {
      Node* curr = evens_tail;
      curr->next = in;
      evens_tail = curr->next;
      in = in->next;
      evens_tail->next = nullptr;
    }

  }
  split(in, odds, evens);
  
}

/* If you needed a helper function, write it here */

