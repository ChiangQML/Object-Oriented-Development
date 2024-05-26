#ifndef LUMEN_H
#define LUMEN_H

class lumen
{
private:
int activeThreshold, stableThreshold; 
int brightness, power;
int size, resetCount;
int glowRequest;
int brigthBack, pwrBack;
bool isStable () const;
bool isActive();

public:
bool Active = true, Stable = true;
lumen ();
lumen (int aSize);
bool reset();
int glow();
bool recharge ();
int glowNum;
int inActiveCount = 0;
int unstableCount = 0;
int getSize() const;
lumen operator+(const lumen& other) const;
lumen operator+(int n) const;
friend lumen operator+(int n,const lumen& right);

lumen operator-(const lumen & other) const;
lumen operator-(int n) const;
friend lumen operator-(int n,const lumen& right);

lumen & operator+=(const lumen& other);
lumen& operator+=(int n);
lumen & operator-=(int n);
lumen & operator-=(const lumen & other);

lumen & operator++();
lumen operator++(int n); 
lumen & operator--();
lumen operator--(int n);

bool operator==(const lumen&) const; 
bool operator!=(const lumen&) const; 
bool operator>(const lumen&) const; 
bool operator>=(const lumen&) const; 
bool operator<(const lumen&) const; 
bool operator<=(const lumen&) const;
};
#endif
