#ifndef NOVA_H 
#define NOVA_H 
#include "lumen.h"
#include <stdio.h>
class nova
{

private:
const unsigned HIGHEST_BOUND = 1000;
unsigned int capacity; 
lumen* arr;
void fixLumen ();
void copy (const nova& src);

public:
nova (int size, int num);
nova ();
nova (const nova& a);
~nova ();
unsigned int getCapacity();
void operator=(const nova& rhs); 
nova (nova&& source);
void operator=(nova&& rhs);

int glow (int pos);
unsigned getMin();
unsigned getMax();
unsigned min,max;
void replace (unsigned num);
};
#endif
