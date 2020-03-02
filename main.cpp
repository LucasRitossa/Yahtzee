//Yahtzee, written by Dakota, Ethan, Lucas, and Dan

#include <iostream>
#include <time.h>    
#include <string.h>

using namespace std;

void Debug(int dice[])
{
  cout << "---debugmode---\n";
  cin >> dice[0];
  cin >> dice[1];
  cin >> dice[2];
  cin >> dice[3];
  cin >> dice[4];
}

int addScore(int dice[], int num)//adds score
{
  int temp;
  for(int x = 0; x <= 4; x++)//check all dice
    {
      if(dice[x] == num) //check dice based on # 
      {
        temp += num; //addbased on # 
      }  
    }
  return temp;
}

void scoringMenu()
{
  cout <<"Type in the number that coorelates with the scoring option you want. \n";
  cout <<"1 - Ones \n"
       <<"2 - Twos \n"
       <<"3 - Threes \n"
       <<"4 - Fours \n"
       <<"5 - Fives \n"
       <<"6 - Sixes \n"
       <<"7 - Three of a Kind \n"
       <<"8 - Four of a Kind \n"
       <<"9 - Full House \n"
       <<"10 - Small Straight \n"
       <<"11 - Large Straight \n"
       <<"12 - Yahtzee \n"
       <<"13 - Chance \n"
       << "Input: ";
}



void scoring(int dice[], int &total_score)
{
  int match = 0;
  int score;

  bool categories[13];
  for (int x = 0; x <=12; x++)
  {
    categories[x] = false;
  }
  
  cin >> score;
//let user decide which place they want the dice
switch(score)
{
  case 1: //1s
    if (!categories[0]){
      total_score += addScore(dice, 1);
      categories[0] = true;
    }
 break;
 case 2: //2s
    if (!categories[1]){
      total_score += addScore(dice, 2);
      categories[1] = true;
    }
 break;
 case 3: //3s
    if (!categories[2]){
      total_score += addScore(dice, 3);
      categories[2] = true;
    }
 break;
 case 4: //4s
    if (!categories[3]){
      total_score += addScore(dice, 4);
      categories[3] = true;
    }
 break;
 case 5: //5s
    if (!categories[4]){
      total_score += addScore(dice, 5);
      categories[4] = true;
    }
 break;
 case 6: //6s
 if (!categories[5]){
    total_score += addScore(dice, 6);
    categories[5] = true;
 }
 break;

 case 7: //3 of a kind
 //check for 3 in a row 3 times
 if (!categories[6]){
 for (int i = 0; i <= 2; i++)
    {
      //check for 3 in a row (location based on for loop)
      if(dice[i] == dice[i + 1] && dice[i] == dice[i + 2]) 
      {
        total_score += (dice[2] * 3);
        break;
      }
    } 
    categories[6] = true;
 }
 break;
 case 8: //4 of a kind
    //check 4 in a row twice
  if (!categories[7]){
    for (int i = 0; i <= 1; i++)
    { 
      //checks first 4, pushes die index once, checks last 4
      if(dice[i] == dice[i + 1] && dice[i] == dice[i + 2] && dice[i] == dice[i+3])
      {
        total_score += (dice[2] * 4);
        break;
      }  
    }
    categories[7] = true;
  } 
    
 break;
 
 case 9: //Full house
    //checks if first and second eua;, then 3, and 5th, dont need to check 4th because it's sorted, (yyxxx)
  if (!categories[8]){
    if(dice[0] == dice[1] && dice[2] == dice[4])
    {
      total_score += 25;
    }   
    //same as before, flips checking side
    if(dice[0] == dice[2] && dice[3] == dice[4])
    {
      total_score += 25;
    }
    categories[8] = true;   
  }
 break;
 case 10: //Small Straight
 if (!categories[9]){
  for(int x = 0; x <=1; x++)
  {
    for(int i=1; i<=3; i++)//check 4 other dice
    {
      if(dice[x] + i == dice[i+x])//check dice in relation to the first (counting up)
      {
        match++;
      }
    }
      if(match == 3)//if all 5 in right place then award points
      {
        total_score += 30;
      }
      
  }
  categories[9] = true;
 } 
 break;
 case 11: //Large Straight
 if (!categories[10]){
  for(int i=1; i<=4; i++)//check 4 other dice
  {
    if(dice[0] + i == dice[i])//check dice in relation to the first (counting up)
    {
      match++;
    }
  }
  if(match == 4)//if all 5 in right place then award points
  {
    total_score += 40;
  }
  categories[10] = true;
 }

 break;
 case 12: //Yahtzee
 if (!categories[11]){
  for(int i=1; i<=4; i++)//check 4 other dice
  {
    if(dice[0] == dice[i])//check dice in relation to first(without counting up)
    {
      match++;
    }
  }
  if(match == 4)//if all 5 were equal award points
  {
    total_score += 50;
  }
  categories[11] = true;
 }
 break;
 
 case 13: //Chance
 if (!categories[12]){
  for(int i = 0; i <= 4;i++) //add up all dice
  {
    total_score += dice[i];
  }
  categories[12] = true; 
 }
 break;
default:
  cout <<"That's not a category you can score in\n";
}
  cout <<"SCORE: " << total_score << endl << endl;
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
//used 2 swap 2 positions in an array
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
  int slotCounter = 0; //Counts how many times you've played one round of Yahtzee

do
{
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
    selectionSort(dice, 5);
    cout << dice[0] << ", "
         << dice[1] << ", "
         << dice[2] << ", " 
         << dice[3] << ", " 
         << dice[4] << endl;

    rollCounter ++;
    cout <<"Do you want to reroll any other dice? (Type: 'n', 'y') \n";
    cin >> finished;
  }while(rollCounter <= 2 && finished == "y"); //Reroll Limits

  //Sort the numbers
  selectionSort(dice, 5);
  cout << dice[0] << ", "
       << dice[1] << ", "
       << dice[2] << ", " 
       << dice[3] << ", " 
       << dice[4] << endl;
  scoringMenu();
  scoring(dice, total_score);
  slotCounter ++;
}while(slotCounter < 13);


return 0;  
}







//██╗  ░██████╗░░█████╗░████████╗  ██████╗░██╗░██████╗░  ██████╗░██████╗░
//██║  ██╔════╝░██╔══██╗╚══██╔══╝  ██╔══██╗██║██╔════╝░  ██╔══██╗██╔══██╗
//██║  ██║░░██╗░██║░░██║░░░██║░░░  ██████╦╝██║██║░░██╗░  ██████╔╝██████╔╝
//██║  ██║░░╚██╗██║░░██║░░░██║░░░  ██╔══██╗██║██║░░╚██╗  ██╔═══╝░██╔═══╝░
//██║  ╚██████╔╝╚█████╔╝░░░██║░░░  ██████╦╝██║╚██████╔╝  ██║░░░░░██║░░░░░
//╚═╝  ░╚═════╝░░╚════╝░░░░╚═╝░░░  ╚═════╝░╚═╝░╚═════╝░  ╚═╝░░░░░╚═╝░░░░░
//me gusta muy grande pene de sans
//░░░░░░░░██████████████████
//░░░░████░░░░░░░░░░░░░░░░░░████
//░░██░░░░░░░░░░░░░░░░░░░░░░░░░░██
//░░██░░░░░░░░░░░░░░░░░░░░░░░░░░██
//██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
//██░░░░░░░░░░░░░░░░░░░░██████░░░░██
//██░░░░░░░░░░░░░░░░░░░░██████░░░░██
//██░░░░██████░░░░██░░░░██████░░░░██
//░░██░░░░░░░░░░██████░░░░░░░░░░██
//████░░██░░░░░░░░░░░░░░░░░░██░░████
//██░░░░██████████████████████░░░░██
//██░░░░░░██░░██░░██░░██░░██░░░░░░██
//░░████░░░░██████████████░░░░████
//░░░░░░████░░░░░░░░░░░░░░████
//░░░░░░░░░░██████████████ 
//adoro el cuerpo de sans
//أنا أحب سيدنا والقائد المقدس ، sans
//Heil Sans
//s-s-s sans-senpai OwO *nuzzels sans*