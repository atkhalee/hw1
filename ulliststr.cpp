#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
//start with the push cases --> there are 3 cases for these
//for the pop cases there may be 3-4 depending on hwo you write it 
//understand the program befroe you start the coding
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val)
{
	if(head_ == NULL){
	  Item * list = new Item();
    list->first = 0;
    list->val[0] =val;
		list->last = 1;
    head_ = tail_ = list;
    size_ += 1;
		list->prev = list->next = NULL;
		
  }else if(tail_->last == 10)
	{
		Item * list = new Item();
		tail_->next = list;
		list->prev = tail_;
		tail_ = list;
    list->val[0] =val;
		list->last+=1;
		size_+=1; //--> why is this causing a seg fault
	}
	else{
			tail_->val[tail_->last]=val;
			tail_->last +=1;
			size_+=1;
	}
	
}

/**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back()
{
	//Item * temp = tail_;
	if(size_ ==0){ return;}
	if(size_ == 1){ 
		size_ -=1;
		delete tail_;
		head_ = tail_ = NULL;
	}else if(tail_->last == 1){
		size_ -=1;
		tail_=tail_->prev;
		delete tail_-> next; 
		tail_->next = NULL;
	// tail_->last = tail_->last-1;
	// temp->last= tail_->last;
	}else{
		size_ -=1;
		tail_->last-=1;
	}
	
}

  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
	
void ULListStr::push_front(const std::string& val)
{
	if(head_ == NULL){
	  Item * list = new Item();
		head_ = tail_ = list;
    list->first = 9; //--> causing a seg fault
		//list->first = 0;
    list->val[list->first] =val;
		list->last = ARRSIZE;
    size_ += 1;
	}
	else if(head_->first == 0){
			Item * list = new Item();
			list->next = head_;
			head_->prev=list;
			head_ = list;
    	list->first = 9;
    	list->val[list->first] =val;
			list->last=10;
			
	
			//list->next = head_;
			//list->prev = NULL;
			//head_= list;
			size_+=1; //--> when I comment this out, then there is no seg fault
	}else{
			
			head_->first -=1;
			head_->val[head_->first] = val;
			size_+=1;
		}
	
}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front()
{
	if(size_ == 0){return;}
	if(size_ ==1){
		size_ -=1;
		Item* temp = head_;
    delete temp; 
    head_ = tail_ = NULL;
	}else if(head_->first ==9){
		size_ -=1;
		head_=head_->next;
		delete head_-> prev; //deleting the previous node and then setting the prev value to NULL
		head_->prev = NULL;
	}else{
		//head_->val[head_->first]= '\0';
		size_ -=1;
		head_->first +=1;
	}

}

/**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const
{

	Item * temp = tail_;
	temp->last = tail_->last-1;
	return temp->val[temp->last];

}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const
{
		Item * temp = head_;
		temp->first = head_->first;
		return temp->val[temp->first];
}

/* 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const
	{
			//if non-existent, then NULL will be returned
			//should return the i-th value in the entire list, not just a single item's array
			//need to use a while loop
			//the pointer will either be to the first or the last value in one of the linked list nodes
			Item * temp = head_;
			if (loc < 0 || loc > size_)
			{
				return NULL;
			} 
			
			size_t counter = 0;
			size_t location = head_->first;
			//we need to check if loc ==location
			while(loc != counter){
				counter += 1;
				location +=1;
				if(location == temp->last){
					temp = temp->next;
					location = temp->first;
				}	
			}
			//need to return the i-th value --> you are returning a string
			return &temp->val[location];
			//should bepointing to to the 0th position in the head_
			
	}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
