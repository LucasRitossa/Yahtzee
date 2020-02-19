#include <iostream>

using namespace std;



void diceRoll(int keep)
{
  for(int x = 0; x <= 4; x++)
  {
    if(keep != x)
    {
      dice[x] = random() % 6 + 1;
    }
    else
    {
      
    }  
  }
}
int main() 
{
  int dice[5]; // 0 1 2 3 4 <--
  diceRoll(5);
  cout << dice[0];
  
}