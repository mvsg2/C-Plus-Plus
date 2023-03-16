#include <bits/stdc++.h>
using namespace std;

//////////////////
// Naveen Hegde //
//    BITS H    //
//////////////////

#define int long long
#define uint unsigned long long
#define real long double

#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ss second
#define ff first
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

//#define mod 1000000007

#define trace(x)          cerr<<#x<<": "<<x<<endl
#define trace2(x, y)       cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl


const char human = 'X';
const char ai = 'O';

enum Player { HUMAN, AI };

struct Move {
	int x;
	int y;
};

class Game {
	char board[3][3];

public:
	Game();

	void rulesofthegame();
	//States the rules

	void printBoard();
	// Prints board

	bool gameOver();
	// Returns true if a winner has been found or there are no empty spaces

	bool checkWin(Player player);
	// Checks for a win

	void play();
	//Main game

	void easyplay();
	// Easy game driver

	void mediumplay();
	//Medium game driver

	void difficultplay();
	// Difficult game driver

	int selectdifficulty();
	//chooses difficulty

	void getHumanMove();
	// Takes in values from the input stream and places them on the board
	// if valid.  Expects input in coordinate notation, ex (1,3)

	int score();
	// Function to score game board states based on their outcome
	// Returns 10 for human win, -10 for AI win, 0 for draw

	Move minimax(char AIboard[3][3]);
	// Returns the best AI move's x, y coords via the minimax algorithm

	int minSearch(char AIboard[3][3]);
	// minimax helper fn for finding the next move for AI player, chooses the 
	// move with the least possible score

	int maxSearch(char AIboard[3][3]);
	// minimax helper fn for finding the next move for human player, chooses
	// the move with the least possible score

	Move randommove(char AIboard[3][3]);
	// Returns a valid random move by the AI

	Move searchtactics(char AIboard[3][3]);
	// Searches tactics for mediumplay
};


Game::Game() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			board[i][j] = '-';
		}
	}
}

void Game::printBoard() {

	cout << "\t\t";
	for(int i=0; i<3; i++)
    {
        cout << " "<< board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " ";
        if(i!=2)
        {
        cout << "\n\t\t---|---|---\n\t\t";
        }
    }
    cout << "\n";
}

void Game::rulesofthegame()
{
	cout << "\n\n\t*********RULES************\n\n\t";
	cout << "The object of Tic Tac Toe is to get three in a row.\n\tYou play on a three by three game board. \n\tThe first player is known as X and the second as O. \n\tPlayers alternate placing Xs and Os on the game board \n\tuntil either opponent has three in a row or all nine squares are filled.\n\tX always goes first, and in the event that no one has three in a row,\n\tthe game ends in a draw and is called a stalemate.\n";
}

bool Game::gameOver() 
{
	if(checkWin(HUMAN)) return true;
	else if(checkWin(AI)) return true;

	bool emptySpace = false;
	for(int i = 0; i < 3; i++) {
		if(board[i][0] == '-' || board[i][1] == '-' || board[i][2] == '-')
			emptySpace = true;
	}
	return !emptySpace;
}

bool Game::checkWin(Player player) 
{
	char playerChar;
	if(player == HUMAN) playerChar = human;
	else playerChar = ai;

	for(int i = 0; i < 3; i++) {
		// Check horizontals
		if(board[i][0] == playerChar && board[i][1] == playerChar
			&& board[i][2] == playerChar)
			return true;

		// Check verticals
		if(board[0][i] == playerChar && board[1][i] == playerChar
			&& board[2][i] == playerChar)
			return true;
	}

	// Check diagonals
	if (board[0][0] == playerChar && board[1][1] == playerChar 
		&& board[2][2] == playerChar) {
		return true;
	} else if (board[0][2] == playerChar && board[1][1] == playerChar 
		&& board[2][0] == playerChar) {
		return true;
	}

	return false;
}

int Game::score() 
{
	if(checkWin(HUMAN)) { return 10; }
	else if(checkWin(AI)) { return -10; }
	return 0; // draw
}

Move Game::minimax(char AIboard[3][3]) { 
	int bestMoveScore = 100; // -100 is arbitrary
	Move bestMove;

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(AIboard[i][j] == '-') {
				AIboard[i][j] = ai;
				int tempMoveScore = maxSearch(AIboard);
				if(tempMoveScore <= bestMoveScore) {
					bestMoveScore = tempMoveScore;
					bestMove.x = i;
					bestMove.y = j;
				}
				AIboard[i][j] = '-';
			}
		}
	}

	return bestMove;
}

int Game::maxSearch(char AIboard[3][3]) {
	if(gameOver()) return score();
	Move bestMove;

	int bestMoveScore = -1000;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(AIboard[i][j] == '-') {
				AIboard[i][j] = human;
				int tempMoveScore = minSearch(AIboard);
				if(tempMoveScore >= bestMoveScore) {
					bestMoveScore = tempMoveScore;
					bestMove.x = i;
					bestMove.y = j;
				}
				AIboard[i][j] = '-';
			}
		}
	}

	return bestMoveScore;
}

int Game::minSearch(char AIboard[3][3]) {
	if(gameOver()) return score();
	Move bestMove;

	int bestMoveScore = 1000; 
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(AIboard[i][j] == '-') {
				AIboard[i][j] = ai;
				int tempMove = maxSearch(AIboard);
				if(tempMove <= bestMoveScore) {
					bestMoveScore = tempMove;
					bestMove.x = i;
					bestMove.y = j;
				}
				AIboard[i][j] = '-';
			}
		}
	}

	return bestMoveScore;
}

void Game::getHumanMove() 
{
	int x, y = -1; // arbitrary assignment to init loop
	while(x < 0 || x > 2 || y < 0 || y > 2) 
	{
		// Loop until a valid move is entered
		cout << "\n\n\tEnter your move in the coordinate form, for ex: (1,3) " << endl;
		cout << "\tYour Move: ";
		char c;
		string restofline;
		cin >> c >> c;
		x = c - '0' - 1;
		cin >> c >> c;
		y = c - '0' - 1;
		getline(cin, restofline); // get garbage chars after move
	}
	board[x][y] = human;
}

void Game::difficultplay() {
	int turn = 0;
	
	printBoard();
	while(!checkWin(HUMAN) && !checkWin(AI) && !gameOver()) 
	{
		// human move
		if(turn % 2 == 0) 
		{
			getHumanMove();
			if(checkWin(HUMAN)) cout << "\n\t*****Human Player Wins*****\n" << endl;
			turn++;
			printBoard();
		} 
		else 
		{
			cout << endl << "\tComputer Move: ";
			Move AImove = minimax(board);
			board[AImove.x][AImove.y] = ai;
			cout << "(" << AImove.x+1 << "," << AImove.y+1 << ")"<< endl;
			if(checkWin(AI)) cout << "\n\t*****Computer Wins*****\n" << endl;
			turn++;
			printBoard();
		}
		if(turn==9)
		{
			cout << "\n\t*****Stalemate*****\n" << endl;
		}
	}
}

Move Game::searchtactics(char AIboard[3][3])
{
	Move bestmove;

	//going for the win
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(AIboard[i][j]=='-')
			{
				int count=0;
				for(int k=0;k<3;k++)
				{
					if(AIboard[i][k]=='O')
						count++;
				}
				if(count==2)
				{
					bestmove.x=i;
					bestmove.y=j;
					return bestmove;
				}
				count=0;
				for(int k=0;k<3;k++)
				{
					if(AIboard[k][j]=='O')
						count++;
				}
				if(count==2)
				{
					bestmove.x=i;
					bestmove.y=j;
					return bestmove;
				}
				if(i==j)
				{
					count=0;
					for(int k=0;k<3;k++)
					{
						if(AIboard[k][k]=='0')
							count++;
					}
					if(count==2)
					{
						bestmove.x=i;
						bestmove.y=j;
						return bestmove;
					}
				}
				if(i+j==4)
				{
					count=0;
					if(AIboard[0][2]=='0')
						count++;

					if(AIboard[1][1]=='0')
						count++;

					if(AIboard[2][0]=='0')
						count++;
					if(count==2)
					{
						bestmove.x=i;
						bestmove.y=j;
						return bestmove;
					}
				}

			}
		}
	}

	//going for the block
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(AIboard[i][j]=='-')
			{
				int count=0;
				for(int k=0;k<3;k++)
				{
					if(AIboard[i][k]=='X')
						count++;
				}
				if(count==2)
				{
					bestmove.x=i;
					bestmove.y=j;
					return bestmove;
				}
				count=0;
				for(int k=0;k<3;k++)
				{
					if(AIboard[k][j]=='X')
						count++;
				}
				if(count==2)
				{
					bestmove.x=i;
					bestmove.y=j;
					return bestmove;
				}
				if(i==j)
				{
					count=0;
					for(int k=0;k<3;k++)
					{
						if(AIboard[k][k]=='X')
							count++;
					}
					if(count==2)
					{
						bestmove.x=i;
						bestmove.y=j;
						return bestmove;
					}
				}
				if(i+j==4)
				{
					count=0;
					if(AIboard[0][2]=='X')
						count++;

					if(AIboard[1][1]=='X')
						count++;

					if(AIboard[2][0]=='X')
						count++;
					if(count==2)
					{
						bestmove.x=i;
						bestmove.y=j;
						return bestmove;
					}
				}

			}
		}
	}

	//centre snatch

	if(AIboard[1][1]=='-')
	{
		bestmove.x=1;
		bestmove.y=1;
		return bestmove;
	}

	//opposing corner snatch
	Move cor;
		if(AIboard[0][0]=='X')
		{
			if(AIboard[2][2]=='-')
			{
				cor.x=2;
				cor.y=2;
				return cor;
			}
		}
		if(AIboard[2][2]=='X')
		{
			if(AIboard[0][0]=='-')
			{
				cor.x=0;
				cor.y=0;
				return cor;
			}
		}
		if(AIboard[0][2]=='X')
		{
			if(AIboard[2][0]=='-')
			{
				cor.x=2;
				cor.y=0;
				return cor;
			}
		}
		if(AIboard[2][0]=='X')
		{
			if(AIboard[0][2]=='-')
			{
				cor.x=0;
				cor.y=2;
				return cor;
			}
		}
	vector<Move> corners(4);
	corners.clear();
	int count=0;
	int opposingcount=0;
	if(AIboard[0][0]=='-')
		{
			cor.x=0;
			cor.y=0;
			corners.push_back(cor);
			count++;
		}
	if(AIboard[2][2]=='-')
		{
			cor.x=2;
			cor.y=2;
			corners.push_back(cor);
			count++;
		}
	if(AIboard[0][2]=='-')
		{
			cor.x=0;
			cor.y=2;
			corners.push_back(cor);
			count++;
		}	
	if(AIboard[2][0]=='-')
		{
			cor.x=2;
			cor.y=0;
			corners.push_back(cor);
			count++;
		}
	if(count)
	{
		bestmove=corners[rand()%count];
		return bestmove;
	}

	//random

	bestmove=randommove(AIboard);
	return bestmove;
}


void Game::mediumplay() {
	int turn = 0;
	
	printBoard();
	while(!checkWin(HUMAN) && !checkWin(AI) && !gameOver()) 
	{
		// human move
		if(turn % 2 == 0) 
		{
			getHumanMove();
			if(checkWin(HUMAN)) cout << "\n\t*****Human Player Wins*****\n" << endl;
			turn++;
			printBoard();
		} 
		else 
		{
			cout << endl << "\tComputer Move: ";
			Move AImove = searchtactics(board);
			board[AImove.x][AImove.y] = ai;
			cout << "(" << AImove.x+1 << "," << AImove.y+1 << ")" << endl;
			if(checkWin(AI)) cout << "\n\t*****Computer Wins*****\n" << endl;
			turn++;
			printBoard();
		}
		if(turn==9)
		{
			cout << "\n\t*****Stalemate*****\n" << endl;
		}
	}
}


Move Game::randommove(char AIboard[3][3]) 
{ 
	Move bestMove,empty;
	vector<Move> validmoves(9);
	validmoves.clear();
	int count=0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(AIboard[i][j] == '-') 
			{
				empty.x=i;
				empty.y=j;
				validmoves.push_back(empty);
				count++;
			}
		}
	}

	bestMove=validmoves[(rand()%count)];

	return bestMove;
}

void Game::easyplay() {
	int turn = 0;
	
	printBoard();
	while(!checkWin(HUMAN) && !checkWin(AI) && !gameOver()) 
	{
		// human move
		if(turn % 2 == 0) 
		{
			getHumanMove();
			if(checkWin(HUMAN)) cout << "\n\t*****Human Player Wins*****\n" << endl;
			turn++;
			printBoard();
		} 
		else 
		{
			cout << endl << "\tComputer Move: ";
			Move AImove = randommove(board);
			board[AImove.x][AImove.y] = ai;
			cout << "(" << AImove.x+1 << "," << AImove.y+1 << ")" << endl;
			if(checkWin(AI)) cout << "\n\t*****Computer Wins*****\n" << endl;
			turn++;
			printBoard();
		}
		if(turn==9)
		{
			cout << "\n\t*****Stalemate*****\n" << endl;
		}
	}
}

int Game::selectdifficulty()
{
	cout << "\n\t******Difficulty Selection*********\n";
	cout << "\n\tThere are 3 modes of difficulties\n";
	cout << "\t\t1. Easy\n";
	cout << "\t\t2. Medium\n";
	cout << "\t\t3. Difficult\n\n";
	cout << "\tEnter your chosen difficulty level, for ex: 1\n";
	cout << "\tChosen difficulty: ";
	int dif=-1;
	while(dif<1||dif>3)
	{
		char ch;
		cin >> ch;
		dif = ch - '0';
	}
	return dif;
}

void Game::play()
{
	rulesofthegame();
	int dif=selectdifficulty();
	cout << "\n\t*********Begin************\n\n";
	if(dif==1)
	{
		easyplay();
	}
	else if(dif==2)
	{
		mediumplay();
	}
	else
	{
		difficultplay();
	}
}

int32_t main() 
{
	Game tictactoe;
	tictactoe.play();

	return 0;
}