//Yahtzee, written by Dakota, Ethan, Lucas, and Dan

#include <iostream>
#include <time.h>    
#include <string.h>

using namespace std;


void scoring(int dice[], int &total_score)
{
  int match = 0;
  int score;
  cin >> score;
//let user decide which place they want the dice
switch(score)
{
  case 1: //1s
    for(int x = 0; x < 4; x++)
    {
      if(dice[x] == 1)
      {
        total_score += 1; 
      }
        
    }
 break;
 case 2: //2s
 
  for (int x = 0; x < 4; x++)
  {
     if(dice[x] == 2)
     {
        total_score += 2;  
     }  
  }

 break;
 case 3: //3s

   for (int x = 0; x < 4; x++)
   {
      if(dice[x] == 3)
      {
         total_score += 3;  
      }  
   } 

 break;
 case 4: //4s

   for (int x = 0; x < 4; x++)
   {
      if(dice[x] == 4)
      {
         total_score += 4;  
      }  
   } 
 
 break;
 case 5: //5s

   for (int x = 0; x < 4; x++)
   {
      if(dice[x] == 5)
      {
         total_score += 5;  
      }  
   }
 
 break;
 case 6: //6s

    for (int x = 0; x < 4; x++)
    {
      if(dice[x] == 6)
      {
         total_score += 6;  
      }  
    }
 
 break;

 case 7: //3 of a kind
    
 
 
    for (int i = 1; i <= 6; i++)
    {
      for (int x = 0; x < 4; x++)
      {
        if (dice[x] == i)
        {
          match++;
        }
        if (match == 3)
        {
          total_score += (dice[2] * 3);
        } 
      }
      match = 0;
    } 
 break;
 case 8: //4 of a kind
 
    for (int x = 0; x < 4; x++)
    {
      for (int i = 1; i <= 6; i++)
      {
        if (dice[x] == i)
        {
          match++;
        }
        if (match == 4)
        {
          total_score += (dice[2] * 4);
        } 
      }
      match = 0;
    }
    
 break;
 case 9: //Full house

 break;
 case 10: //Small Straight

 break;
 case 11: //Large Straight

 break;
 case 12: //Yahtzee

 break;
 case 13: //Chance

 break;
default:

  cout <<"You play Roblox \n";
}

cout <<"Your score is " << total_score << endl;

}







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
//used 2 swap 2 posiotions in an array
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
//overall sorting fuction
void selectionSort(int arr[], int n)  
{  
    int min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (int i = 0; i < n-1; i++)  
    {  
        // Find the minimum number in unsorted array  
        min_idx = i;  
        for (int j = i+1; j < n; j++) 
        { 
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
        }
        // Swap the found minimum number with the first number  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  









int main() {
  //Randomizing via time 
  srand(time(NULL));
  int total_score = 0;
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

  cout <<"Do you want to reroll any other dice? (Type: 'n', 'y') \n";
  cin >> finished;
}while(rollCounter <= 2 && finished == "y"); //Reroll Limits

//sort the numbers
selectionSort(dice, 5);
cout << dice[0] << ", "
     << dice[1] << ", "
     << dice[2] << ", " 
     << dice[3] << ", " 
     << dice[4] << endl;

scoring(dice, total_score);


return 0;  
}