/*
* Ting-Yi Chiang
* 4 / 14 / 23
* cpsc3200
* revision history: 3/31 -> 4/3 -> 4/10 -> 4/14/2023
* Class Invariant:
* "capacity" is yielded by the value passed in form client, it is always non-negative. I use "capacity" as random number after certain algorithm.
* The "arr" member variable should point to a dynamic array of lumen objects with a size equal to "capacity".
* The glow method can be called on any lumen object in the nova object's dynamic array, with a valid position index between 0 and capacity-1 (inclusive)
*     This method will update the glowNum variable of the corresponding lumen object, and return its value.
* The getMin and getMax methods can be called on any nova object, and they will return the minimum and maximum glow numbers (respectively)
*     that any lumen object in the nova object's dynamic array has produced so far.
* The replace method can be called on any nova object, with a positive inte ger parameter.
*     This method will replace the lumen object at the index corresponding to the minimum glow number with a new lumen object with the specified number of lumens.
*/
  
#include "nova.h"
#include <iostream>

// pre-condition: at least have 2 subObject
nova::nova(int size, int num){
  if(num<=1){
      if(num == 0) num += 2;
      num += 1;
  }
  capacity = 2 + num % 10;
  arr = new lumen[capacity];
  arr[0] = lumen(size);
  int newSize;
  newSize = size;
  for(int i = 1; i < capacity; i++){
    if( i % 2 == 0){
      newSize = int(newSize * 0.9);
    }else{
      newSize = int(newSize * 2.0);
    }
    arr[i] = lumen(newSize);
  }
}

nova::nova():capacity(0),arr(nullptr){}

unsigned int nova::getCapacity(){
  return capacity;
}

void nova::fixLumen(){
  int powerless = 0;
  int broken = 0;
  for(int k = 0; k < capacity; k++){
      if(arr[k].isActive() == false) powerless;
      if(arr[k].isStable() == false) broken++;
  }
  if(broken > 8){
      std::cout<<"replace!\n";
      replace(capacity);
  }
  if(powerless > capacity / 2){
      for(int k = 0; k < capacity; k++){
          arr[k].recharge();
      }
  }
}

void nova::copy(const nova& src){
  capacity = src.capacity;
  arr = new lumen[capacity];
  for(int i = 0; i < capacity; i++){
      arr[i] = src.arr[i];
  }
}

//copy constructor: support deep copy
nova::nova(const nova& a){copy(a);}

nova::~nova(){delete[] arr;}

//overload assignment operator
void nova::operator=(const nova& rhs){
  //avoid self-assign
  if(this == &rhs) return;
  delete[] arr;
  copy(rhs);
}

//move semantic
nova::nova(nova&& source){
capacity = source.capacity;
arr = source.arr;
source.capacity = 0;
source.arr = 0;
}

//move assignment operator
void nova::operator=(nova&& rhs){
  std::swap(capacity,rhs.capacity);
  std::swap(arr,rhs.arr);
}

int nova::glow(int pos){
  fixLumen();
  return arr[pos].glow();
}

//pre-condition: object can't be empty
unsigned nova::getMin(){
  if(capacity == 0) return 0;
  min = HIGHEST_BOUND;
  for(int i = 0; i < capacity; i++){
      if(arr[i].glowNum < min){
          min = arr[i].glowNum;
      }
  }
  return min;
}

//pre-condition: object can't be empty
unsigned nova::getMax(){
  if(capacity == 0) return 0;
  max = 0;
  for(int i = 0; i< capacity; i++){
      if(arr[i].glowNum > max){
        max = arr[i].glowNum;
      }
  }
  return max;
}

//pre-condition: unstable object must be more than certain number
void nova::replace(unsigned num){
  delete[] arr;
  if(num != capacity) capacity = num % 10;
  arr = new lumen[capacity];
}

/* implementation invariant:
* fixLumen() is a private helper function that track is active and is stable's object number, to fullfill recharge or replace.
* The default constructor nova() initializes capacity to 0 and arr to nullptr.
* The constructor nova(int size, int num) initializes capacity to num and allocates memory for arr based on capacity.
*     It also creates num lumen objects and stores them in arr.
* The copy constructor nova (const nova& a) creates a deep copy of a by copying the capacity and lumen objects in a.arr.
* The move constructor nova (nova&& source) moves the capacity and lumen objects from source to the new nova object being constructed.
* The destructor ~nova() deallocates the memory used by arr.
* The assignment operator operator= (const nova& rhs) copies the capacity and lumen objects from rhs to the current nova object.
*    It also ensures that arr is properly deallocated before allocating new memory.
* The move assignment operator operator=(nova&& rhs) moves the capacity and lumen objects from rhs to the current nova object.
*    It also ensures that arr is properly deallocated before allocating new memory.
* getCapacity() returns the current value of capacity.
* glow(int pos) returns the glow value of the lumen object at position pos in arr.
* getMax () returns the maximum glow value of all lumen objects in arr. 
* getMin() returns the minimum glow value of all lumen objects in arr. 
* replace (unsigned num) replaces the lumen object with the minimum glow va lue with a new lumen object of size num.
*    If there are multiple lumen objects with the minimum glow value, the first one encountered is replaced.
*/
