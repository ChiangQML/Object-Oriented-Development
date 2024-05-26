#ifndef NOVA_H
#define NOVA_H
#include "lumen.h"
#include <limits>
#include <memory>

using namespace std;

class nova
{
private:
unsigned int capacity, glowNum; 
shared_ptr<lumen []> arr;
void fixLumen ();
void copy (const nova& src);

public:
nova (const shared_ptr<lumen[]>& Lumens, unsigned size); 
nova ();
nova (const nova& a);
unsigned int getCapacity() const;
bool contains (const lumen & l) const;
bool operator==(const nova& other)const; nova & operator= (const nova& rhs);
nova operator+ (const nova& rhs);
nova operator- (const nova& rhs);

nova operator+ (const lumen& l) const;
nova operator+(int n) const;
friend nova operator+(const lumen& left, const nova& right); 
friend nova operator+(int n,const nova& right);

nova operator-(const lumen & l) const;
nova operator-(int n) const;

nova & operator+= (const nova& other); 
nova& operator+=(const lumen& other); 
nova & operator+=(int n);
nova & operator-= (int n);
nova & operator-=(const nova& other);
nova & operator-= (const lumen& other);

nova& operator++();
nova operator++ (int n);
nova & operator--();
nova operator--(int n);

nova (nova&& source) noexcept;
nova& operator=(nova&& rhs) noexcept ;
int * glow (unsigned pos);
unsigned getMin() const; 
unsigned getMax() const;

void replace (unsigned num);
};
#endif
