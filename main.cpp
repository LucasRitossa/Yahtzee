//Yahtzee, written by Dakota, Ethan, Lucas, and Dan

#include <iostream>
#include <time.h>    
#include <string.h>

using namespace std;


void diceRoll(int dice[], bool keep[])
{
  //loops through 5 dice
  for(int x = 0; x <= 4; x++)
  {
    
    if(keep[x] == false)
    {
      //randomizing set die from loop
      dice[x] = rand() % 6 + 1;
    }
  }

  for(int x = 0; x <= 4; x++)// line dedicated to clearing keep
  {
    keep[x] = false;
  }
  
}

void hold(int keeping, bool keep[])
{
  int temp;
  cout << "Which dice do you want to keep? \n";
  //loops up to how many dice user has kept
  for(int x = 0; x < keeping; x++)
  {
    cin >> temp;
    //selects a rolled die, -1 to line up with zero-indexing
    keep[temp - 1] = true;
  }
}







int main() {
  //Randomizing via time 
  srand(time(NULL));
  
  int dice[5];  // 0 1 2 3 4 <--
  bool keep[5]; //Stops dice from being rerolled if user doesn't want it
  int keeping;  //How many dice user wants to keep
  int rollCounter = 0;  //How many times the user has rolled dice
  string finished; //If the user is muy contento with his rolls before 3 rolls

  diceRoll(dice, keep); //Dice rolling function
  cout << dice[0] << ", "
       << dice[1] << ", "
       << dice[2] << ", " 
       << dice[3] << ", " 
       << dice[4] << endl;

//Asking how many dice the user wants to keep
do
{
  cout << "how many dice do you want to keep(1-5)\n";
  cin >> keeping;
  hold(keeping, keep);
    diceRoll(dice, keep); //Dice rolling function
    cout << dice[0] << ", "
         << dice[1] << ", "
         << dice[2] << ", " 
         << dice[3] << ", " 
         << dice[4] << endl;
  rollCounter ++;

  cout <<"Do you want to reroll any other dice? (Type: 'No', 'Yes' [Case Sensitive]) \n";
  cin >> finished;
}while(rollCounter <= 2 && finished == "Yes"); //Reroll Limits

//let user decide which place they want the dice
/*switch()
{


  
}*/









return 0;  
}