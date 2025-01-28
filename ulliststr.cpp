#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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

void ULListStr::push_back(const std::string& val){

  if(tail_ == nullptr){
    Item* node = new Item();
    tail_ = node;
    if(head_ == nullptr){
      head_ = node;
    }
    tail_->val[tail_->first] = val;
    tail_->last += 1;
  } else if (tail_->last < 10){
    tail_->val[tail_->last] = val;
    tail_->last += 1;
  } else {
    Item* node = new Item();
    tail_->next = node;
    node->prev = tail_;
    tail_ = node;
    tail_->next = nullptr;
    tail_->val[tail_->first] = val;
    tail_->last += 1;
  }

  size_ += 1;
}


void ULListStr::push_front(const std::string& val){

  
  if(head_ == nullptr){
    Item* node = new Item();
    head_ = node;
    if(tail_ == nullptr){
      tail_ = node;
    }

    head_->first = 9;
    head_->last = 10;

    head_->val[head_->first] = val;

  } else if (head_->first > 0){
    head_->first -= 1;
    head_->val[head_->first] = val;
    
  } else {
    Item* node = new Item();
    node->last = 10;
    node->first = 9;
    node->val[9] = val;
    node->next = head_;
    head_->prev = node;
    head_ = node;
  }

  size_ += 1;
}

void ULListStr::pop_back(){

  if(size_ == 0){
    return;
  } else {
    tail_->last -= 1;
    size_ -= 1;

    if(tail_->first == tail_->last){
      Item* temp = tail_;
      tail_ = tail_->prev;
      if(tail_ != nullptr){
        tail_->next = nullptr;
      }

      delete temp;
      if(size_ == 0){
        head_ = nullptr;
      }
    }
  }
}

void ULListStr::pop_front(){

  if(size_ == 0){
    return;
  } else {
    head_->first += 1;
    size_ -= 1;

    if(head_->first == head_->last){
      Item* temp = head_;
      head_ = head_->next;
      if(head_ != nullptr){
        head_->prev = nullptr;
      }

      delete temp;
      if(size_ == 0){
        tail_ = nullptr;
      }
    }
  }
}

std::string const & ULListStr::back() const{
  if(size_ != 0){
    return tail_->val[tail_->last-1];
  }
}

std::string const & ULListStr::front() const{
  if(size_ != 0){
    return head_->val[head_->first];
  }
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(size_ == 0 || loc >= size_){
    return nullptr;
  }

  Item* curr = head_;
  size_t num = 0;

  while(curr != nullptr){
    size_t currStart = num;
    size_t currEnd = num + curr->last - curr->first;
    if(loc < currEnd){
      size_t returnIndex = curr->first + (loc - currStart);
      return &curr->val[returnIndex];
    }

    num = currEnd;
    curr = curr->next;
  }

  return nullptr;
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
