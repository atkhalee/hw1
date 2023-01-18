/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <vector>
#include <limits>
#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

//created print function to output the linked lists for odds and evens and to check that list is set to NULL
Node * makeList(std::vector<int> const & content)
{
	Node * head = nullptr;

	if(!content.empty())
	{
		// create head
		head = new Node(content[0], nullptr);

		// create rest of list
		Node * currTail = head;
		std::vector<int>::const_iterator nextValIter(content.cbegin());
		++nextValIter;

		for(; nextValIter != content.cend(); ++nextValIter)
		{
			Node * newNode = new Node(*nextValIter, nullptr);
			currTail->next = newNode;

			currTail = newNode;
		}
	}

	return head;

}

void deleteList(Node * list)
{
	Node * currElement = list;

	while(currElement != nullptr)
	{
		Node * nextElement = currElement->next;

		delete currElement;

		currElement = nextElement;
	}
}

void print(Node *list){
  Node *temp = list;
  while(temp != NULL){
    cout<<temp->value<< " ->  ";
    temp = temp->next;
  }
}
int main(int argc, char* argv[])
{
//created 6 test cases
  //My test cases
  //Case 1: all events list
  cout<<"-------Case 1-------" <<endl;
  Node* list = makeList({2,4,6,8,10,12});
  Node* odds = NULL;
  Node* evens = NULL;
  split(list,odds, evens);
  cout<<"Odds List: ";
  print(odds);
  cout<<endl;
  cout<<"Evens List: ";
  print(evens);
  cout<<endl;
  cout<<"List: ";
  print(list);
  cout<<endl;

	deleteList(list);
  deleteList(odds);
	deleteList(evens);
  
  //Case 2: all odds list
  cout<<"-------Case 2-------" <<endl;
  Node* list1 = makeList({1,3,5,7,9,11});
  Node* odds1 = NULL;
  Node* evens1 = NULL;
  split(list1,odds1, evens1);
  cout<<"Odds List: ";
  print(odds1);
  cout<<endl;
  cout<<"Evens List: ";
  print(evens1);
  cout<<endl;
  cout<<"List: ";
  print(list1);
  cout<<endl;

	deleteList(list1);
  deleteList(odds1);
	deleteList(evens1);

  //Case 3: evens and odds list
  cout<<"-------Case 3-------" <<endl;
  Node* list2 = makeList({21,22,23,24,25,26,27,28,29,30});
  Node* odds2 = NULL;
  Node* evens2 = NULL;
  split(list2,odds2, evens2);
  cout<<"Odds List: ";
  print(odds2);
  cout<<endl;
  cout<<"Evens List: ";
  print(evens2);
  cout<<endl;
  cout<<"List: ";
  print(list2);
  cout<<endl;

	deleteList(list2);
  deleteList(odds2);
	deleteList(evens2);
  
  //Case 4: when list is NULL
  cout<<"-------Case 4-------" <<endl;
  Node* list3 = NULL;
  Node* odds3 = NULL;
  Node* evens3 = NULL;
  split(list3,odds3, evens3);
  cout<<"Odds List: ";
  print(odds3);
  cout<<endl;
  cout<<"Evens List: ";
  print(evens3);
  cout<<endl;
  cout<<"List: ";
  print(list3);
  cout<<endl;
	deleteList(list3);
  deleteList(odds3);
	deleteList(evens3);
  
  //Case 5: with a zero number
  cout<<"-------Case 5-------" <<endl;
  Node* list4 = makeList({0,5,10,15,20,44,79});
  Node* odds4 = NULL;
  Node* evens4 = NULL;
  split(list4,odds4, evens4);
  cout<<"Odds List: ";
  print(odds4);
  cout<<endl;
  cout<<"Evens List: ";
  print(evens4);
  cout<<endl;
  cout<<"List: ";
  print(list4);
  cout<<endl;

	deleteList(list4);
  deleteList(odds4);
	deleteList(evens4);
  
  //Case 6: duplicate odd and even numbers
  cout<<"-------Case 6-------" <<endl;
  Node* list5 = makeList({2,4,4,6,6,7,7,15,18,23,23,60,61,61});
  Node* odds5 = NULL;
  Node* evens5 = NULL;
  split(list5,odds5, evens5);
  cout<<"Odds List: ";
  print(odds5);
  cout<<endl;
  cout<<"Evens List: ";
  print(evens5);
  cout<<endl;
  cout<<"List: ";
  print(list5);
  cout<<endl;

	deleteList(list5);
  deleteList(odds5);
	deleteList(evens5);

}