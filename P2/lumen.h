#ifndef LUMEN_H 
#define LUMEN_H 
#include <stdio.h>
class lumen
{
private:
int threshold;
int brightness, power; 
int size;
int glowRequest;
int brigthBack, pwrBack;
bool Active = true;

public:
lumen ();
lumen(int aSize); 
bool isStable(); 
bool isActive ();
bool reset();
int glow();
bool recharge ();
int glowNum;
int unActiveCount = 0;
int unstableCount = 0;
};
#endif
