#include <iostream>
#include "nova.h"
#include <random>
#include <memory>
#include <vector>
using namespace std;

random device rd; // obtain a random number from hardware 
mt19937 gen (rd()); // seed the generator
int generateRandom(int lowerBound, int upperBound) { 
  uniform int distribution<> dist (lowerBound, upperBound); 
  return dist (gen);
}

lumen generateLumen () {
int lumenSize = generateRandom (1, 10);
return lumen (lumenSize);
}

unique_ptr<lumen[]> getLumenArr (int amount, int mode=0) {
if (mode != 0) {
  amount = 3;
  unique_ptr<lumen[]> Lumens (new lumen [3]); 
  for (int i =0; i<amount; i++) {
    Lumens [i] = lumen (i*20);
  }
  return Lumens;
}else{
  unique_ptr<lumen[]> Lumens (new lumen [amount]); 
  for (int i =0; i<amount; i++){
    Lumens [i] = generateLumen ();
  }
  return Lumens;
  }
}

int main() {
int numberOfNova = generateRandom (1,20); 
int amountOfLumen = generateRandom (1,20);

vector<nova> NovaArr;

for (int i=0;i<numberOfNova;i++) {
  int amountOfLumen = generateRandom (1,20);
  unique_ptr<lumen[]> Lumens = getLumenArr (amountOfLumen,1); 
  shared_ptr<lumen[]> sharedPtrLumen = std::move (Lumens);
  
  NovaArr.push_back(nova (sharedPtrLumen, amountOfLumen));
  
  int glowNum = generateRandom (1,20);
  
  unique_ptr<int> glowArr (NovaArr[i].glow(glowNum)) ;
  
  cout<<endl<<"Nova ["<< i<< "] has "<< amountOfLumen<<" lumens"<<endl; 
  cout<<"Number of lumen.glow() calls made: "<<glowNum<<endl;
  
  for (int j=0; j < glowNum; j++){
    if(glowNum>amountOfLumen) {
      glowNum = amountOfLumen;
      cout<<"number of glow request is bigger than the amount of lumens nova has, glow the existing lumens."<<endl; 
    }
    cout << "lumen[" << j << "]:" << (glowArr.get()) [j] << endl;
  }
  cout<<"Nova["<<i<<"]'s"<<" max glow: "<<(NovaArr[i].getMax())<<endl; 
  cout<<"Nova["<<i<<"]'s"<<" min glow: "<<(NovaArr[i].getMin())<<endl;
}

lumen lumenLeft = lumen (3);
lumen lumenRight = lumen (2);
lumen lumenAns;

unique_ptr<lumen []> lumen TestForNova = getLumenArr (3,1);
shared_ptr<lumen[]> sharedPtrTest = std::move (lumenTestForNova);
nova novaLeft = nova(sharedPtrTest,3); 
nova novaRight = nova (sharedPtrTest,3);
nova novaAns;

cout<<"operator testing: "<<endl;
cout<<"left lumen = "<<lumenLeft.getSize();
cout<<"right_lumen = "<<lumenRight.getSize();
lumenAns = lumenLeft+lumenRight;
cout<<"lumen_answer = left_lumen + right_lumen "<<endl<<"lumen_ans = " << lumenAns.getSize() << endl;
lumenAns = 5 + lumenAns;
cout<<"lumen answer = lumen answer + 5 "<<endl<<"lumen_ans = "<< lumenAns.getSize() << endl;
lumenAnswer = 5 + lumenAnswer;
cout<<"lumen_answer = 5 + lumen_answer "<<endl<<"lumen_ans = " << lumenAns.getSize() << endl;
lumenAnswer += lumenAnswer;
cout<<"lumen_answer += lumen_answer "<<endl<<"lumen_ans = " << lumenAns.getSize() << endl;
lumenAnswer += 2;
cout<<"lumen_answer += 2 "<<endl<<"lumen_ans = "  << lumenAns.getSize() << endl;
lumenAns = lumenAns - 3;
cout<<"lumen_answer = lumen_answer - 3 "<<endl<<"lumen_ans = "  << lumenAns.getSize() << endl;
lumenAns = 50 - lumenAns;
cout<<"lumen_answer = 50 - lumen_answer "<<endl<<"lumen_ans = " << lumenAns.getSize() <<endl; 
lumenAns -= lumenRight;
cout<<"lumen_answer -= lumenRight "<<endl<<"lumen_ans = "  << lumenAns.getSize() << endl;
lumenAns -= 10;
cout<<"lumenAns -= 10; "<<endl<<"lumen_ans = "  << lumenAns.getSize() << endl;

lumenAns++;
cout<<"lumen_answer ++ "<<endl<<"lumen_ans = "  << lumenAns.getSize() << endl;
lumenAns --;
cout<<"lumen_answer -- "<<endl<<"lumen_ans = "  << lumenAns.getSize() << endl;

++lumenAns;
cout<<"++lumen_answer "<<endl<<"lumen_ans = "  << lumenAns.getSize() << endl;
--lumenAns;
cout<<"--lumen_answer "<<endl<<"lumen_ans = "  << lumenAns.getSize() << endl;

cout<<"left_nova = "<<novaLeft.getCapacity(); 
cout<<"right_nova = "<<novaRight.getCapacity(); 

novaAns = novaLeft + novaRight;
cout<<"nova_answer = left_nova + right_nova " <<endl<<"nova_ans = " << novaAns.getCapacity() << endl;
  
novaAns = novaAns + 5;
cout<<"nova_answer = nova_answer + 5 " <<endl<<"nova_ans = " << novaAns.getCapacity() << endl;
  
novaAns += novaAns;
cout<<"novaAns += novaAns "<<endl<<"nova_ans = " << novaAns.getCapacity() << endl;

novaAns += 2;
cout<<"novaAns += 2 "<<endl<<"nova_ans = " << novaAns.getCapacity() << endl;

novaAns = novaAns-3;
cout << "novaAns = novaAns - 3" << endl<<"nova_ans = " << novaAns.getCapacity() << endl;

novaAns -= novaLeft;
cout<<"novaAns -= novaLeft " << endl<<"nova_ans = " << novaAns.getCapacity() << endl;

lumenAns -= 10;
cout<<"novaAns -= 10 " << endl<<"nova_ans = " << novaAns.getCapacity() << endl;

lumenAns++;
cout<<"novaAns ++ "<<endl<<"nova_ans = " << novaAns.getCapacity() << endl;

lumenAns --;
cout<<"novaAns -- " << endl<<"nova_ans = " << novaAns.getCapacity() << endl;

++lumenAns;
cout<<"++ novaAns "<<endl<<"nova_ans = " << novaAns.getCapacity() << endl;
--lumenAns;
cout<<"-- novaAns "<<endl<<"nova_ans = " << novaAns.getCapacity() << endl;
}
