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
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
//Two Base cases
//One recursive cases
//first case is if(in % 2==0){add to evens}
//else if(in%2==1){add to odds}
//with linked lists recursions the base case is always if(in==NULL){return;}
/*
if(in ==null){return
}else{
split(in->next, odds, evens)
//possibly call odds and evens function here (doing tails recursion)
//all numbers will go to each of the functions --> will be added according to if the condition
has been met or not
}


*/
/*A quick summary: for the odds and evens list we are just rearranging the pointers --> we do not use new because this will cause memory leaks (unless you create a user-defined destructor)*/
  if(in == NULL)
  {
    return;
  }else
  {
    
    split(in->next, odds, evens);
    //do nested if else statement here if(in%2 ==0)
    if(in->value % 2 == 0){
      //append to even list
      //two cases --> if even is null and if there is another value stored in there
      if(evens == NULL){
        //evens = new Node(in->value, NULL); //--> works
        //evens->value = in->value; //--> causes some seg fault
        // evens->next = NULL; --> causes some seg fault
        //*evens = *in;
        //evens is a pointer evens = NULL;
        //rearranging the pointer
        evens = in;
        evens->next = NULL;
      }else{
        //doing insert front ->
        //Node * temp = new Node(in->value, evens);
        //evens = temp;
        Node * temp = in;
        temp->next = evens;
        evens = temp;
        //delete temp;
      }
      //evens = new Node(in->value, nullptr); this works --> will only print one value
      //odds->value = in;
      //odd->next = nullptr;
    }
    if(in->value % 2 == 1){
        //append to odd list
        if(odds == NULL){
        //odds = new Node(in->value, NULL);
        odds = in;
        odds->next = NULL;
        //odds->value=in->value;
        //odds->next = NULL;
      }else{
        //doing insert front ->
        //Node * temp = new Node(in->value, odds);
        //odds = temp;
        Node * temp = in;
        temp->next = odds;
        odds = temp;
      }
      //odds = new Node(in->value, nullptr);
      //odds->value = in;
      //odd->next = nullptr;
    }
  }
  in = NULL;
  //when rearraging poitner in should automatically be set to null
}

/* If you needed a helper function, write it here */


//take in a linked list and split it into two lists
//one is odd and the other is even
//since there are three parameters --> in the main
//create a Node for odds and a Node for evens that are set to NULL