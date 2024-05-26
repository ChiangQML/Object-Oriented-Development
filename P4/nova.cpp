#include "nova.h" #include <iostream>
#include <memory>

nova::nova(const shared_ptr<lumen[]>& Lumens, unsigned size)
{
  if(!Lumens||size==0){
    size = 3;
    arr= shared_ptr<lumen []>(new lumen [3]); 
    for(int i = 0; i<size ; i++){
      arr[i] = lumen (i+2);
  }else{
      arr=Lumens;
    }
    capacity = size;
}

unsigned int nova::getCapacity() const{return capacity;}

nova::nova():capacity(0), arr(nullptr) {}

void nova::fixLumen () {
  int powerless = 0;
  int broken 0;
  for (int k = 0; k < capacity; k++) {
    if (!arr[k].Active) powerless++;
    if (!arr[k].Stable) broken++;
  }
  if (broken > 8) {
    std::cout<<"replace!\n"; 
    replace (capacity);
  }
  if (powerless > capacity / 2) {
    for (int k = 0; k < capacity; k++) { 
      arr[k].recharge ();
    }
  }
}

void nova::copy(const nova& src){
  capacity = src.capacity;
  arr=shared_ptr<lumen[]>(new lumen[src.capacity]);
  for (int i = 0; i < capacity; i++)
  { 
    arr[i] = src.arr[i];
  }
}
  
//copy constructor: support deep copy 
nova::nova (const nova& a) { copy (a); }
  
//overload assignment operator
//Pre-condition: rhs should not be the same address as lhs 
nova & nova::operator= (const nova& rhs){
  //avoid self-assign
  if (this == &rhs) return *this;
  delete[] arr.get();
  copy (rhs);
  return *this;
}
//Post-condition: lhs will be equal to rhs

//move semantic
nova:: nova (nova&& source) noexcept
{
  capacity = source.capacity;
  arr = source.arr;
  source.capacity = 0;
  source.arr = nullptr;
}

//move assignment operator
nova& nova::operator= (nova&& rhs) noexcept { 
  std::swap (capacity, rhs.capacity); 
  std::swap(arr,rhs.arr);
  return this;
}
//Post-condition: lhs will be equal to rhs

//Pre-condition: input index number must be valid 
int * nova::glow(unsigned num) {
  fixLumen ();
  if (num>capacity) num = capacity;
  int* glowArr=new int[num];
  for (int i=0; i<num; i++) {
    glowArr[i] = arr[i].glow ();
  }
  return glowArr;
}
//Post-condition: sub object's glow value at the index position will be returned

//Pre-condition: object can't be empty 
unsigned nova::getMin () const {
  if (capacity == 0) return 0;
  int min = arr[0].glowNum;
  for (int i = 1; i < capacity; i++) {
    if (arr[i].glowNum < min) {
      min = arr[i].glowNum;
    }
  }
  return min;
}
//Post-condition: min glow value among sub objects will be returned

//Pre-condition: object can't be empty 
unsigned nova::getMax() const {
  if (capacity == 0) return 0;
  int max = arr[0].glowNum;
  for (int i = 1; i < capacity; i++) {
    if (arr[i].glowNum > max) {
      max = arr[i].glowNum;
    }
  }
  return max;
}
//Post-condition: max glow value among sub objects will be returned

//Pre-condition: unstable object must be more than certain number 
void nova::replace (unsigned num) {
  delete[] arr.get();
  if (num != capacity) capacity = num % 10;
  arr = shared_ptr<lumen[]>(new lumen[capacity]);
}

nova nova::operator+ (const nova &rhs){
  unsigned size=this->capacity+rhs.capacity;
  nova_newnova=nova (shared_ptr<lumen[]>(new lumen[size]),size); 
  for (int i=0;i<capacity;i++) newnova.arr[i]=arr[i];
  for (int i=0;i<rhs.capacity;i++) newnova.arr[i+capacity]=rhs.arr[i];
  return newnova;
}

nova nova::operator- (const nova &rhs) {
  unsigned size=this->capacity;
  nova_newnova=nova (shared_ptr<lumen[]>(new lumen[size]),size);
  for(int i=0,j=0;i<capacity;i++,j++){
    if(rhs.contains(arr[i])) j--;
    else newnova.arr[j]=arr[i];
  }
  return newnova;
}

nova nova::operator+ (const lumen &l) const {
  if (contains (l)) return * new nova (*this);
  unsigned size=this->capacity+1;
  nova newnova=nova (shared_ptr<lumen[]>(new lumen[size]),size); 
  for (int i=0;i<capacity;i++) {
    newnova.arr[i]=arr[i];
  }
  newnova.arr[capacity]=l;
  return newnova;
}

nova nova::operator+(int n) const {
  return *this+lumen (n);
}

nova operator+(const lumen &left, const nova &right) {
  nova_n=right+left;
  return n;
}

nova operator+(int n, const nova &right) {
  return right+n;
}

nova nova::operator-(const lumen &l) const{
  unsigned size = this->capacity-1;
  nova newnova = nova(shared_ptr<lumen[]>(new lumen[size]),size);
  for(int i=0, j=0; i<capacity; i++, j++){
    if(arr[i] == l){
      j--;
      continue;
    }
    newnova.arr[j] = arr[i];
  }
  return newnova;
}

nova nova::operator-(int n) const{
  return *this-lumen(n);
}

nova &nova::operator+=(const nova &other){
  *this = *this + other;
  return *this;
}

nova &nova::operator+=(const lumen &other){
  *this = *this + other;
  return *this;
}

nova &nova::operator+=(int n){
  *this = *this + n;
  return *this;
}

nova &nova::operator-=(int n){
  *this = *this - n;
  return *this;
}

nova &nova::operator-=(const nova &other){
  *this = *this - other;
  return *this;
}

nova &nova::operator-=(const lumen &other){
  *this = *this - other;
  return *this;
}

nova &nova::operator++(){
  *this = *this+1;
  return *this;
}

nova &nova::operator++(int n){
  nova lu = *this;
  ++*this;
  return lu;
}

nova &nova::operator--(){
  *this = *this-1;
  return *this;
}

nova &nova::operator--(int n){
  nova lu = *this;
  --*this;
  return lu;
}

bool nova::contains(const lumen &l) const{
  for(int i=0; i<capacity; i++){
    if(l == arr[i]) return true;
  }
  return false;
}

bool nova::operator==(const nova &other) const{
  return capacity == other.capacity;
}

// Post-condition: Everything from previous object will be replaced
