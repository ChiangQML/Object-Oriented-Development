/* Ting-Yi Chiang
* 4 / 14 / 23
cpsc3200
* revision history: 3/31 -> 4/3 -> 4/14/2023
* Class Invariant :
* "size" is always between 0 and 9 inclusive.
* "brightness" and "power" are always non-negative integers.
* "threshold" is always non-negative and less than or equal to power.
* "glowRequest" is always non-negative.
* If isActive() returns true, then power is greater than threshold.
* If isStable() returns false, then brightness is less than or equal to 10.
* The value of glowNum returned by glow() is always non-negative.
* If isActive() returns false, then brightness is less than its previous value
* If reset() returns true, then brightness and power are reset to their initial values.
* If reset() returns false, then brightness and power are reduced by a factor of 0.8.
*/

#include "lumen.h"
lumen::lumen ()
{
brightness = brigthBack = 0;
power = pwrBack = 0;
size = glowRequest = 0;
threshold = 0;
}

lumen:: lumen (int s): size (s % 10)
{
brigthBack = brightness = 50;
power = pwrBack = brightness * size;
glowRequest = 0;
threshold = 50;
}

// client can know if lumen is stable 
bool lumen::isStable ()
{
return brightness > 10;
}

// client can know if lumen is active 
bool lumen::isActive()
{
if (power > threshold) {
Active = true;
}else{
Active = false;
}
return Active;
}

// If call reset() success the object will be reset back to it's initial value; 
// If failed, power & brightness will decrease
bool lumen::reset ()
{
if (glowRequest % 4 == 0 && power > 0)
{
brightness = brigthBack;
power = pwrBack;
return true;
}
else
{
power = int (power * 0.8);
brightness int (brightness * 0.8);
return false;
}
}

// lumen object must be initialized
// Based on object's state, client will get a glow number as return value 
int lumen::glow()
{
glowRequest++;
power = int (power * 0.9);
// power > 50
if (isActive())
{
//stable: bright * size
//Bright > 30
if (isStable())
{
return glowNum = brightness * size;
}
// !stable (Bright <= 30) & active (neither) will generate a random machi
else
{
unstableCount++;
if (power % 2 == 0) {
return glowNum = brightness * size;
}else{
return glowNum = int (0.5 * brightness * size);
}
}
}

//in-active -> dimness
// reduce bright
else
{
  unActiveCount++;
  return glowNum = int(brightness*=0.2);
}
}

bool lumen::recharge()
{
  if(isStable()){
    //brightness += 100;
    // size = 2;
    power = power*5;
    return ture;
  }
  return false;
}


/* implementation invariant:
* brightness and power must be non-negative integers.
* size must be an integer between 0 and 9 (inclusive).
* threshold must be an integer greater than 0.
* glowRequest, unActiveCount, and unstableCount must be non-negative integers
* The glowNum value returned by glow() must be a non-negative integer.
* The glow() method can be called only after the object has been initialized.
*    after client call the method, it will return a value based on the lumen states.
* The reset() method can be called only after the object has been initialized
*    lumen should met certain condition in order to successfully reset the brightness and power.
*    If reset() fails, brightness and power must be decreased. 
* The recharge() method can be called only if the object is stable. 
*    If recharge() succeeds, power must be increased.
*/
