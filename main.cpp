//Yahtzee, written by Dakota, Ethan, Lucas

#include <iostream>
#include <time.h>    
#include <string.h>

using namespace std;

struct Player
{
  int number;
  int totalScore;
  bool isUsed[13];
};


void Debug(int dice[])
{
  cout << "---debugmode---\n";
  cin >> dice[0];
  cin >> dice[1];
  cin >> dice[2];
  cin >> dice[3];
  cin >> dice[4];
}

//Teaches the player if they want
void tutorial()
{
  char temp;
  cout << "Do you want to take the tutorial? y/n\n";
  cin >> temp;
  if(temp == 'y' || temp == 'Y')
  {
    cout << "\t\t**TUTORIAL**\n"
         << "- The program autorolls the dice\n"
         << "- When it asks you which dice you want to keep\n"
         << "- Select the dice in order \n"
         << "- EX: if you had 1, 1, 1, 2, 3\n"
         << "  And you wanted to keep the 3 ones you would input 1, 2 and 3\n"
         << "- Then when you finished rolling or you rolled a maximum of 3\n  times \n"
         << "- You select the number that corresponds with the\n"
         << "  category you want your rolls to be scored in \n"
         << "- Continue this till you are finished, then the next player can play. \n";
  }
}



//used 2 swap 2 positions in an array, (for sorting function)
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

int addScore(int dice[], int num)//adds score for case 0-5 
{
  int temp = 0;
  for(int x = 0; x <= 4; x++)//check all dice
    {
      if(dice[x] == num) //check dice based on # 
      {
        temp += num; //addbased on # 
      }  
    }
  return temp;
}
//creates a visual scoring menu, listing used spaces, and open spaces
void scoringMenu(bool isUsed[])
{
  string fillTypes[] = {
    "\n1 - Ones ", 
    "\n2 - Twos ", 
    "\n3 - Threes ",
    "\n4 - Fours ",
    "\n5 - Fives ",
    "\n6 - Sixes ",
    "\n7 - Three of a Kind ",
    "\n8 - Four of a Kind ",
    "\n9 - Full House ",
    "\n10 - Small Straight ",
    "\n11 - Large Straight ",
    "\n12 - Yahtzee ",
    "\n13 - Chance "};
  
  //Puts filled next to any slots that got used. Better UI
  cout <<"Type in the number that coorelates with the scoring option you want. \n";
  //loops through, checks if spot filled, if filled, mark
  for(int i = 0; i<=12; i++){
    cout << fillTypes[i];
    if(isUsed[i] == true){
      cout <<" <- FILLED";
    }
  }
}
//contains all scoring cases
int scoring(int dice[], int totalScore[], bool isUsed[], int players)
{
  int match = 0;//used in cases to check matches between dice and vars
  int score;//what holds the users scoring input
  totalScore[players] = 0;
  //returns player if scoring position isnt valid
  do{
    cout <<"\nInput: ";
    cin >> score;
  
    if(isUsed[score] == true){
      cout<<"Score already used, please try again! \n";
    }

  }while(isUsed[score] == true);
  //marks position as used
  isUsed[score - 1] = true;
  
//let user decide which place they want the dice
switch(score)
{
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
      totalScore[players] += addScore(dice, (score));
  break;
  
 case 7: //3 of a kind
 //check for 3 in a row 3 times
 for (int i = 0; i <= 2; i++)
    {
      //check for 3 in a row (location based on for loop)
      if(dice[i] == dice[i + 1] && dice[i] == dice[i + 2]) 
      {
        totalScore[players] += (dice[2] * 3);
        break;
      }
    } 
 break;
 case 8: //4 of a kind
    //check 4 in a row twice
    for (int i = 0; i <= 1; i++)
    { 
      //checks first 4, pushes die index once, checks last 4
      if(dice[i] == dice[i + 1] && dice[i] == dice[i + 2] && dice[i] == dice[i+3])
      {
        totalScore[players] += (dice[2] * 4);
        break;
      }  
    }
    
 break;
 
 case 9: //Full house
    //checks if first and second eua;, then 3, and 5th, dont need to check 4th because it's sorted, (yyxxx)
    if(dice[0] == dice[1] && dice[2] == dice[4])
    {
      totalScore[players] += 25;
    }   
    //same as before, flips checking side
    if(dice[0] == dice[2] && dice[3] == dice[4])
    {
      totalScore[players] += 25;
    }
 break;
 case 10: //Small Straight
 //couple if statements to check for xyyzm pattern, and set y value to 0 if found
if(dice[1] == dice[2])
{
  dice[2] = 0;
  selectionSort(dice, 5);
}
else if (dice[2] == dice[3])
{
  dice[3] = 0;
  selectionSort(dice, 5);
}
else if(dice[3] == dice[4])
{
  dice[4] = 0;
  selectionSort(dice, 5);
}
  for(int x = 0; x <=1; x++)
  {
    for(int i=1; i<=3; i++)//check 4 other dice 
    {
      if(dice[x] + i == dice[i+x])//check dice in relation to the first (counting up)
      {
        match++;
      }
    }
      if(match == 3)//if all 4 in right place then award points
      {
        totalScore[players] += 30;
      }
  }
 break;
 case 11: //Large Straight
  for(int i=1; i<=4; i++)//check 4 other dice
  {
    if(dice[0] + i == dice[i])//check dice in relation to the first (counting up)
    {
      match++;
    }
  }
  if(match == 4)//if all 5 in right place then award points
  {
    totalScore[players] += 40;
  }

 break;
 case 12: //Yahtzee
  for(int i=1; i<=4; i++)//check 4 other dice
  {
    if(dice[0] == dice[i])//check dice in relation to first(without counting up)
    {
      match++;
    }
  }
  if(match == 4)//if all 5 were equal award points
  {
    totalScore[players] += 50;
  }
 break;
 
 case 13: //Chance
  for(int i = 0; i <= 4;i++) //add up all dice
  {
    totalScore[players] += dice[i];
  }
 break;
 
default:
  cout <<"That's not a category you can score in\n";
  break;
}

  cout <<"SCORE: " << totalScore[players] << endl << endl;
  
int i = 0;
  for(int x = 0; x <= 12; x++){
    if(isUsed[x] == true){
     i++;
    }
    if(i == 13){ 
      return totalScore[players];
    }  
  }
  return 0;
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
  if (keeping == 5) //If the user wants to keep 5 dice it doesn't ask
  {
    for (int x = 0; x < keeping; x++)
    {
      keep[x] = true;
    }
  }
  else
  {
    for(int x = 0; x < keeping; x++)
    {
      cin >> temp;
      keep[temp - 1] = true; 
      //Selects the inputted rolled die, -1 to line up with zero-indexing
    } 
  }
} 
//changed dice
void diceOutput(int dice[]){
  for(int i = 0; i<=4; i++){
    cout<<"D"<<i+1<<" value: "<< dice[i] <<endl; 
  }
}

int main() {
  //Randomizing via time 
  srand(time(NULL));
  int totalScore[4];
  int dice[5];  // 0 1 2 3 4 <--
  bool keep[5]; //Stops dice from being rerolled if user doesn't want it
  int keeping;  //How many dice user wants to keep
  int rollCounter = 0;  //How many times the user has rolled dice
  string finished; //If the user is muy contento with his rolls before 3 rolls
  int slotCounter = 0; //Counts how many times you've played one round of Yahtzee
  bool isUsed[13];
  char encore; //Input variable for a new player
  int players = -1;
  int highest = 0;//holds users highest score
  int comparingScore;
  tutorial();
do
{  
  players ++; //Counts what player is playing the game

if (slotCounter == 0){
  for(int x = 0; x < 13; x++){
    isUsed[x] = false;
  }
}
 
do
{
  diceRoll(dice, keep); //Dice rolling function
  diceOutput(dice);
//Asking how many dice the user wants to keep

  do{
    cout << "How many dice do you want to keep? (0-5) \n";
    cin >> keeping;
    hold(keeping, keep);
    diceRoll(dice, keep); //Dice rolling function
    selectionSort(dice, 5);
    diceOutput(dice);

    rollCounter ++;
    cout <<"Do you want to reroll any other dice? (Type: 'y', 'n') \n";
    cin >> finished;
  }while(rollCounter < 2 && finished == "y"); //Reroll Limits

  rollCounter = 0; //Reset the roll counter so you can always roll 3 times

  //Sort the numbers
  selectionSort(dice, 5);
  diceOutput(dice);
  scoringMenu(isUsed);
  scoring(dice, totalScore, isUsed, players);
  slotCounter ++;

  
}while(slotCounter < 13);
//clears screen
system("clear");

cout <<"FINAL SCORE: " << totalScore[players] << endl;
cout <<"Does another player want to play? (y,n) \n";
//if user wants to continue or not
cin >> encore;


comparingScore = totalScore[players];
if (comparingScore > highest) //Checking if the next player has a new high score
{
  highest = comparingScore;
}

}while(encore == 'y');

for (int x = 0; x < 4; x++) //Checking which person had the highest score
{
  if (totalScore[x] == highest)
  {
    cout <<"Player " << (x + 1) << " wins! \n";
  }
}

return 0;  
}
