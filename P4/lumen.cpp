/* Ting-Yi Chiang - CPSC 3200
* 5 / 19 / 23
* revision history: 5/10 -> 5/16 -> 5/19/2023
*
* Class Invariant :
* reset(): If the conditions are met, the lumen can be reset to its original state, otherwise it will reduce the power and brightness by a certain amount. 
*          The conditions for reset are limited, depending on the size of each lumen.
* glow(): return a number associated with lumen's states.
* glowNum: a number stored the return from glow() function.
* recharge(): if a lumen is stable, it can rechange certain amount of power.
* getSize(): return the size of lumen.
*
* inActiveCount: a number that stores the number of times a lumen has been in an inactive state.
* unstableCount: a number that stores the number of times a lumen has been in an unstable state.
*/
  
#include "lumen.h"
lumen::lumen ()
{
brightness = brigthBack = 0;
power = pwrBack = 0;
size = glowRequest = 0;
activeThreshold = stableThreshold = 0;
resetCount = glowNum = 0;
}

lumen:: lumen (int s): size (s % 10)
{
activeThreshold = s*2;
stableThreshold = s*2.2;
brigthBack = brightness = activeThreshold*s*0.2;
power = pwrBack = brightness * size;
glowRequest = 0;
resetCount = glowNum = 0;
}

// client can know if lumen is stable
bool lumen::isStable() const
{return brightness > stableThreshold;}

//client can know if lumen is active
bool lumen::isActive(){
  if(power > activeThreshold){
    Active = true;
  }else{
    Active = false;
  }
  return Active;
}

int lumen::getSize() const{return size;}

// if call reset() success the object will be reset back to it's initial value;
// if failed, power & brightness will decrease
bool lumen::reset()
{
  resetCount++;
  if(resetCount > size) return false;
  if(glowRequest % 4 == 0 && power > 0){
      brightness = brighthBack;
      power = pwrBack;
      return true;
  }else{
      power = int(power * 0.8);
      brightness = int(brightness * 0.8);
      return false;
  }
}

//lumen object must be initiallized
//Based on object's state, client will get a glow number as return value
int lumen::glow()
{
  glowRequest++;
  power = int(power * 0.9);
  //power > 50
  if(isActive()){
      //stable: bright * size
      if(isStable()){ return glowNum = brightness * size;}
      //!stable(Bright <=30) & active(neither) will generate a random machine
      else{
        if(power % 2 == 0){ return glowNum = brightness * size;}
        else { return glowNum = int(0.5 * brightness * size);}
      }
  }
  //in-active -> dimness
  //reduce bright
  else{
    inActiveCount++;
    return glowNum = int(brightness *= 0.2);
  }
}

bool lumen::recharge(){
  if(isStable()){
    power = power * 5;
    return Stable = true;
  }
  return Stable = false;
}

//type addition
//lumen + lumen
lumen lumen::operator+(const lumen& other) const{
  lumen newlumen;
  newlumen.size = size + other.size;
  return newlumen;
}

//mix addition
//lumen + int
lumen lumen::operator+(int n) const{
  lumen newlumen = lumen(n);
  newlumen.size = size + n;
  return newlumen;
}

//int + lumen
lumen operator+(int n, lumen& l){ return l+n;}

//type subtraction
//lumen - lumen
lumen lumen::operator-(const lumen& other) const{
  lumen newlumen;
  if(size < other.size) newlumen.size = 0;
  else newlumen.size = size - other.size;
  return newlumen;
}

//lumen - int
lumen lumen::operator-(int n) const{
  lumen newlumen = lumen(n);
  if(size < n) newlumen.size = 0;
  else newlumen.size = size - n;
  return newlumen;
}

//int - lumen
lumen operator-(int n, lumen& l){return lumen(n)-l;}

//lumen += lumen
lumen& lumen::operator+=(const lumen& other){
  size = size + other.size;
  return *this;
}

//lumen -= lumen
lumen& lumen::operator-=(const lumen& other){
  if(size < other.size) size = 0;
  else size = size + other.size;
  return *this;
}

//lumen += int
lumen& lumen::operator+=(int n){
  size = size + n;
  return *this;
}

//lumen -= int
lumen& lumen::operator-=(int n){
  if(size < n) size = 0;
  else size = size + n;
  return *this;
}

//lumen++ post
lumen lumen::operator++(int n){
  lumen lu = *this;
  ++size;
  return lu;
}

//++lumen pre addition
lumen lumen::operator++(){
  ++size;
  return *this;
}

//lumen-- post
lumen lumen::operator--(int n){
  lumen lu = *this;
  --size;
  return lu;
}

//--lumen pre subtraction
lumen lumen::operator--(){
  --size;
  if(size < 1) size = 0;
  return *this;
}

lumen operator+(int n, const lumen &right) {
  return right+n;
}

lumen operator-(int n, const lumen &right) { 
  return lumen (n)-right;
}
bool lumen::operator== (const lumen &right) const { 
  return this->size==right.size;
}

bool lumen::operator!= (const lumen &right) const {
  return !(*this==right);
}

bool lumen::operator>(const lumen &right) const { 
  return size>right.size;
}

bool lumen::operator>=(const lumen &right) const { 
  return size>=right.size;
}

bool lumen::operator<(const lumen &right) const { 
  return size<right.size;
}

bool lumen::operator<=(const lumen &right) const { 
  return size<=right.size;
}

*
Implement Invariant:
* in my design, the input parameter is an integer that represent the size of a lumen,
* the number undergo certain algorithm generating different value to initialize a lumen's properties, including brightness, power and threshold. * therefore each lumen is different from the other.
* activeThreshold: a standard for determine if lumen is active or not.
* stableThreshold: a standard for determine if lumen is stable or not.
* glowRequest: a number that stores the number of times the lumen has called the glow() function.
* resetCount: a number that stores the number of times the lumen has called the reset() function.
* isStable(): if brightness is greater than stableThreshold, the lumen is stable, otherwise it is unstable.
* isActive(): if power is greater than activeThreshold, the lumen is active, otherwise it is inactive.
* for the operator functions, the addition design I made is change size of lumen.
* the number of size calculasted will not be a negative number.
* lumen can do the post or pre increment as well.
*
* for the type additions or subtratcion, my lumen can do:
* 1. lumen + lumen or lumen - lumen
* 2. lumen + nova or lumen - nova
* 3. lumen += lumen or lumen -= lumen
* 4. lumen += nova or lumen -= nova
*
* for a mix addition:
* 1. lumen + int or int + lumen
* 2. lumen int or int - lumen
*/
