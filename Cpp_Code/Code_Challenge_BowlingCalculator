/*************************************************
Author: Dustin Daily
Created: 11/12/16
Updated: 11/13/16
Description: This is my code challenge submission
Program Description: A bowling score calculator
*************************************************/

#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
using namespace std;

/**************************************
class to keep track of score and names
**************************************/
class playerClass
{
	public:
		playerClass();
		
		void setName(string);
		
		string getName();
		int getScore();
		
		void addScore(int);
		
	private:
		string name;
		int score;
};

/***********************************************
Constructor that defaults to 0 for all variables
***********************************************/
playerClass::playerClass()
{
	name = "";
	score = 0;
}

/**************************
Sets the name by user input
**************************/
void playerClass::setName(string userInput)
{
	name = userInput;
}

/***************
Returns the name
***************/
string playerClass::getName()
{
	return name;
}

/****************
Returns the score
****************/
int playerClass::getScore()
{
	return score;
}

/***************************************
Adds the user input to the overall score
***************************************/
void playerClass::addScore(int userInput)
{
	score = score + userInput;
}

int main()
{
	int numberOfPlayers = 0; // used to keep track of the number of players
	string inputName; // used to record names of each player
	string inputScore; //used to record the score for each frame
	
	cout << "Hello and welcome to my bowling score program. The rules are simple." << endl
		 << "If you get a strike please enter an 'X' for your score and if you get" << endl
		 << "a spare then please enter a '/'. If you are unable to get a spare before" << endl
		 << "two turns in a frame then enter in the exact number of pins you knocked down." << endl
		 << "Good Luck! " << endl << endl; // importent to not have too much text on a single line
		 
	/********************************
	user prompt for number of players
	********************************/
	cout << "How many players will be playing: ";
	cin >> numberOfPlayers;
	
	//check to make sure it is a number
	while (!cin >> numberOfPlayers)
	{
        cin.clear();
        cin.ignore( numeric_limits<std::streamsize>::max(), '\n' );
		cout << "Looks like you didn't enter a number please try again." << endl
			 << "Please enter in the number of players:";
		cin >> numberOfPlayers;
	}

	//create an array of players REMEMBER: players[0] = Player 1
	playerClass players[numberOfPlayers];
	
	//holds the scores of each frames
	string frames[numberOfPlayers][10][3]; //NOTE: frames 1-9 will only hold 2 values frame 10 can hold 3
	
	/*********************************
	loop to get the names of players
	*********************************/
	cin.ignore();// eliminates the character remaining from (cin >>)
	for(int i = 0; i < numberOfPlayers; i++)
	{
		cout << "What is Player " << i+1 << "'s name?:";
		getline(cin, inputName);
		players[i].setName(inputName);
	}
	
	/*********************************
	loop get the scores from the game
	*********************************/	
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < numberOfPlayers; j++)
		{
			//check if this is the last frame
			if(i != 9)
			{
				cout << endl << "This is " << players[j].getName() << "'s turn." << endl << endl;
				cout << "Frame " << i+1 << ":" << endl;
				cout << "What was your first score: ";
				cin >> inputScore; //scores such as X and / can be entered as well as numbers.
				
				//check to make sure first entry isnt a spare
				if(inputScore != "/")
				{
					frames[j][i][0] = inputScore;
				}
				// first entry was a spare
				else
				{
					//check to make sure they didnt keep entering a spare
					while(inputScore == "/")
					{
						cout << "You cannot have a spare on your first move. Please try again!" << endl;
						cin >> inputScore; //scores such as X and / can be entered as well as numbers.
					}
					frames[j][i][0] = inputScore;
				}
				
				//if strike was entered for first turn then no need for second
				if(frames[j][i][0] != "X" && frames[j][i][0] != "x")
				{
					cout << endl << "What was your second score: ";
					cin >> inputScore; //scores such as X and / can be entered as well as numbers.
					frames[j][i][1] = inputScore;
				}
			}
			//this is not the last frame
			else
			{
				// make sure to say it is last turn
				cout << endl << "This is " << players[j].getName() << "'s last turn. If you get a X then you get two more shots." << endl << endl;
				cout << "Frame " << i+1 << ":" << endl;
				cout << "What was your first score: ";
				cin >> inputScore; //scores such as X and / can be entered as well as numbers.
			
				//check to make sure first entry isnt a spare
				if(inputScore != "/")
				{
					frames[j][i][0] = inputScore;
				}
				// first entry was a spare
				else
				{
					//check to make sure they didnt keep entering a spare
					while(inputScore == "/")
					{
						cout << "You cannot have a spare on your first move. Please try again!" << endl;
						cin >> inputScore; //scores such as X and / can be entered as well as numbers.
					}
					frames[j][i][0] = inputScore;
				}
				
				//they get a second move no matter what
				cout << endl << "What was your second score: ";
				cin >> inputScore; //scores such as X and / can be entered as well as numbers.
				frames[j][i][1] = inputScore;

				
				if(frames[j][i][0] == "X" || frames[j][i][0] == "x" || frames[j][i][1] == "/")
				{
					cout << endl << "What was your third score: ";
					cin >> inputScore; //scores such as X and / can be entered as well as numbers.
					frames[j][i][2] = inputScore;
				}
			}// end of if last frame statement
			
		}//end of players turns
	}// end of frames
	
	/*********************************
	loop to calculate the score
	*********************************/	
	for(int j = 0; j < numberOfPlayers; j++)// loop through frames
	{
		//cosmetic to show score
		cout << endl << players[j].getName() << " your score by frame is " << endl << "-----------------------------" << endl;
		
		for(int i = 0; i < 10; i++)// loop through players
		{
			if(i <= 7)// check for last turn
			{
				// check if current is a strike
				if(frames[j][i][0] == "X" || frames[j][i][0] == "x")
				{
					players[j].addScore(10);
					
					// check if next frame is strike or spare then add 10
					if(frames[j][i+1][0] == "X" || frames[j][i+1][0] == "x") 
					{
						players[j].addScore(10);
						
						// check if next frame after is strike or spare
						if(frames[j][i+2][0] == "X" || frames[j][i+2][0] == "x")
						{
							players[j].addScore(10);
						}
						// if not then just add value
						else
						{
							players[j].addScore(atoi(frames[j][i+2][0].c_str()));
						}
					}
					// if next frame is not strike or spare then just add value
					else
					{
						players[j].addScore(atoi(frames[j][i+1][0].c_str()));
						
						// check if next turn is a spare
						if(frames[j][i+1][1] == "/")
						{
							players[j].addScore(10-atoi(frames[j][i+1][0].c_str()));
						}
						// if not then add the value
						else
						{
							players[j].addScore(atoi(frames[j][i+1][1].c_str()));
						}
					}
				}
				// check if current is a spare
				else if(frames[j][i][1] == "/")
				{
					players[j].addScore(atoi(frames[j][i][0].c_str()));
					players[j].addScore(10-atoi(frames[j][i][0].c_str()));
					
					//check if next frame is a strike or spare
					if(frames[j][i+1][0] == "X" || frames[j][i+1][0] == "x")
					{
						players[j].addScore(10);
					}
					else
					{
						players[j].addScore(atoi(frames[j][i+1][0].c_str()));
					}
				}
				// current is not strike
				else
				{
					players[j].addScore(atoi(frames[j][i][0].c_str()));
					players[j].addScore(atoi(frames[j][i][1].c_str()));
				}
				//cosmetic to show score
				cout << "Frame: " << i+1 << " Score: " << players[j].getScore() << endl;
			}
			//check if in the 9th frame. There is no eleventh frame so some checks need to be modified
			else if(i == 8)
			{
				// check if current is a strike
				if(frames[j][i][0] == "X" || frames[j][i][0] == "x")
				{
					players[j].addScore(10);
					
					// check if next frame is strike or spare then add 10
					if(frames[j][i+1][0] == "X" || frames[j][i+1][0] == "x") 
					{
						players[j].addScore(10);
						
						// check if next frame after is strike or spare
						if(frames[j][i+1][1] == "X" || frames[j][i+1][1] == "x")
						{
							players[j].addScore(10);
						}
						// if not then just add value
						else
						{
							players[j].addScore(atoi(frames[j][i+1][1].c_str()));
						}
					}
					// if next frame is not strike or spare then just add value
					else
					{
						players[j].addScore(atoi(frames[j][i+1][0].c_str()));
						
						// check if next turn is a spare
						if(frames[j][i+1][1] == "/")
						{
							players[j].addScore(10-atoi(frames[j][i+1][0].c_str()));
						}
						// if not then add the value
						else
						{
							players[j].addScore(atoi(frames[j][i+1][1].c_str()));
						}
					}
				}
				// check if current is a spare
				else if(frames[j][i][1] == "/")
				{
					players[j].addScore(atoi(frames[j][i][0].c_str()));
					players[j].addScore(10-atoi(frames[j][i][0].c_str()));
					
					//check if next frame is a strike or spare
					if(frames[j][i+1][0] == "X" || frames[j][i+1][0] == "x")
					{
						players[j].addScore(10);
					}
					else
					{
						players[j].addScore(atoi(frames[j][i+1][2].c_str()));
					}
				}
				// current is not strike
				else
				{
					players[j].addScore(atoi(frames[j][i][0].c_str()));
					players[j].addScore(atoi(frames[j][i][1].c_str()));
				}
				//cosmetic to show score
				cout << "Frame: " << i+1 << " Score: " << players[j].getScore() << endl;
			}
			else // this is last turn
			{
				//check if first turn is a strike
				if(frames[j][i][0] == "X" || frames[j][i][0] == "x")
				{
					players[j].addScore(10);
					
					if(frames[j][i][1] == "X" || frames[j][i][1] == "x" || frames[j][i][1] == "/")
					{
						players[j].addScore(10);
						
						if(frames[j][i][2] == "X" || frames[j][i][2] == "x" || frames[j][i][2] == "/")
						{
							players[j].addScore(10);
						}
						else
						{
							players[j].addScore(atoi(frames[j][i][2].c_str()));
						}
					}
					else
					{
						players[j].addScore(atoi(frames[j][i][0].c_str()));
					}
				}	
				//check if second score is a spare
				else if(frames[j][i][1] == "/")
				{
					players[j].addScore(atoi(frames[j][i][0].c_str()));
					players[j].addScore(10-atoi(frames[j][i][0].c_str()));
					
					if(frames[j][i][2] == "X" || frames[j][i][2] == "x")
					{
						players[j].addScore(10);
					}
					else
					{
						players[j].addScore(atoi(frames[j][i][2].c_str()));
					}						
				}
				else
				{
					players[j].addScore(atoi(frames[j][i][0].c_str()));
					players[j].addScore(atoi(frames[j][i][1].c_str()));
				}
				//cosmetic to show score
				cout << "Frame: " << i+1 << " Score: " << players[j].getScore() << endl;
			}
		}// end loop through players
	}// end loop through frames
	
	/*********************************
	loop to print out scores of players
	*********************************/
	cout << endl; // spacer for cosmetic
	for(int i = 0; i < numberOfPlayers; i++)
	{	
		cout << players[i].getName() << " had a final score of " << players[i].getScore() << endl;
	}
	cout << endl; // spacer for cosmetic
	
	// exit the program
	return 0; 
}

