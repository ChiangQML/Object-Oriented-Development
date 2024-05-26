/* Ting-Yi Chiang - cpsc3200
* 4 / 14 / 23
* revision history: 3/31 -> 4/3 -> 4/10 -> 4/14/2023
*/
  
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include "nova.h"
using namespace std;

int main() {
  
// Create an array of 10 lumen objects with seemingly random distribution of lumens, sizes, and initial power 
nova novaArr[10];
random_device rd;
unsigned int lumenNum;
  
for (int i = 0; i < 10; i++)
{
mt19937 GenSize(rd());
uniform_int_distribution<int> RangeSize(1, 10);
lumenNum = RangeSize (GenSize);
cout << "============" << i + 1 << "============" << "\n";
  
int firstSize = lumenNum % 5 + 1;
nova local (firstSize, lumenNum);
novaArr[i] = local;
for(int k = 0; k < novaArr[i].getCapacity(); k++)
{
cout<<"nova.glow("<<k<<") = "<<novaArr[i].glow(k)<<"\n";
}
cout<<"Max glow for nova["<<i<<"]: "<<novaArr[i].getMax()<<"\n"; 
cout<<"Min glow for nova["<<i<<"]: "<<novaArr[i].getMin()<<"\n";
}
}
