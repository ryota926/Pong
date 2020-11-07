#include <ncurses.h>
#include <stdlib.h>
#include "Player.h"
#include "Ball.h"
#include "Player2Factory.h"
#include "Player2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//State Definitions
static int START_MENU = 0;
static int PLAY_GAME = 1;
static int UPDATE_SCORE = 2;
static int GAME_OVER = 3;
int state = 0;
int check_game_over;

//Variables used
int num_players = 0;
int bot_diff = 0;
int ch;
int width = 80;
int height = 24;
int dir = 1;
int player1Points, player2Points = 0;
bool quit;
char wallTexture, playerTexture;
bool player1Serve, player2Serve = false;
int paddle_size;

Player player1(height / 2, 2);
Player2 *player2;

Ball ball(height / 2, 3, 1);

void setup();
void input();
void logic();
void draw();
void cmove();
void update_score(int x);
int game_over();

int main()
{
	srand((unsigned) time(0));
	state = START_MENU;
	if(state == START_MENU) {
		cout << "Please enter number of players: ";
		cin >> num_players;

		//Player2Factory
		if(num_players == 2)
			player2 = Player2Factory::choice(2);
		else if (num_players == 1){
			cout << "Please enter 1 for easy AI, or 2 for hard AI: ";
			cin >> bot_diff;
			if(bot_diff == 2)
				bot_diff++;
			player2 = Player2Factory::choice(bot_diff);
		}
		setup();
	}

    // Game loop
	if(state == PLAY_GAME) {
		if(num_players == 2) {
			while(1)
			{
				if(quit)
				{
					state = GAME_OVER;
					check_game_over = game_over();
					if(!check_game_over)
						break;
				}
				input();
				logic();
				draw();
			}
		}
		else if(num_players == 1) {
			while(1)
			{
				if(quit)
				{
					state = GAME_OVER;
					check_game_over = game_over();
					if(!check_game_over)
						break;
				}
				input();
				logic();
				cmove();
				draw();
			}
		}
	}
    endwin();
    return 0;
}

void setup()
{
    // Textures
    wallTexture = '@';

    // Init ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(50);

    //General setup functions
    quit = false;
    player1Points = 0;
    player2Points = 0;
    state = PLAY_GAME;
}

void input()
{
	if(state == PLAY_GAME) {
		ch = getch();
		switch(ch) {
			case KEY_UP:
				if(player2->getY() != 3)
					player2->setY(player2->getY() - 1);
				break;
			case KEY_DOWN:
				if(player2->getY() != height - 4)
					player2->setY(player2->getY() + 1);
				break;
			case 'w':
				if(player1.getY() != 3)
					player1.setY(player1.getY() - 1);
				break;
			case 's':
				if(player1.getY() != height - 4)
					player1.setY(player1.getY() + 1);
				break;
			case ' ':
				if(player1Serve) {
					player1Serve = false;
					dir = 1;
				}
				else if(player2Serve) {
					player2Serve = false;
					dir = 2;
				}
				break;
			case 'q':
				quit = true;
				state = GAME_OVER;
				break;
		}
	}
}

void cmove()
{
	if(state == PLAY_GAME){
		if(dir == 1) {
			if(ball.getY() > player2->getY())
				player2->setY(player2->getY() + 1);
			else if(ball.getY() < player2->getY())
				player2->setY(player2->getY() - 1);
		}
		if(dir == 3){
			if(ball.getY() > player2->getY())
				player2->setY(player2->getY() + 1);
			else if(ball.getY() < player2->getY())
				player2->setY(player2->getY() - 1);
		}
		if(dir == 4){
			if(ball.getY() > player2->getY())
				player2->setY(player2->getY() + 1);
			else if(ball.getY() < player2->getY())
				player2->setY(player2->getY() - 1);
			}
	}
}

void logic()
{
	if(state == PLAY_GAME) {
		/*
		 * Ball directions
		 *
		 * 1 - Right
		 * 2 - Left
		 * 3 - Right Up
		 * 4 - Right down
		 * 5 - Left Up
		 * 6 - Left down
		 *
		 */

		// Ball logic
		if(ball.getX() == player1.getX() + 1 || ball.getX() == player1.getX()) {
			if(ball.getY() <= player1.getY() + 2 && ball.getY() >= player1.getY() - 2) {
				if(ball.getY() >= player1.getY() - 2 && ball.getY() < player1.getY())
					dir = 3;
				else if(ball.getY() <= player1.getY() + 2 && ball.getY() > player1.getY())
					dir = 4;
				else
					dir = 1;
			}
		}
		if(ball.getX() == player2->getX() - 1  || ball.getX() == player2->getX()) {
			if(ball.getY() <= player2->getY() + 2 && ball.getY() >= player2->getY() - 2) {
				if (ball.getY() >= player2->getY() - 2 && ball.getY() < player2->getY())
					dir = 5;
				else if (ball.getY() <= player2->getY() + 2 && ball.getY() > player2->getY())
					dir = 6;
				else
					dir = 2;
			}
		}

		if(ball.getY() == height - 2) {
			if (dir == 6)
				dir = 5;
			else
				dir = 3;
		}

		if(ball.getY() == 1) {
			if(dir == 5)
				dir = 6;
			else
				dir = 4;
		}

		if(ball.getX() == 0) {
			state = UPDATE_SCORE;
			update_score(1);
		}

		if(ball.getX() == width) {
			state = UPDATE_SCORE;
			update_score(2);
		}

		if(player1Serve) {
			ball.setX(player1.getX() + 1);
			ball.setY(player1.getY());
		}

		if(player2Serve) {
			ball.setX(player2->getX() - 1);
			ball.setY(player2->getY());
		}

		// Ball directions
		if(!player1Serve || !player2Serve) {
			if(dir == 1)
				ball.setX(ball.getX() + 1);
			if(dir == 2)
				ball.setX(ball.getX() - 1);

			if(dir == 3) {
				ball.setX(ball.getX() + 1);
				ball.setY(ball.getY() - 0.25);
			}
			if(dir == 4) {
				ball.setX(ball.getX() + 1);
				ball.setY(ball.getY() + 0.25);
			}
			if(dir == 5) {
				ball.setX(ball.getX() - 1);
				ball.setY(ball.getY() - 0.25);
			}
			if(dir == 6) {
				ball.setX(ball.getX() - 1);
				ball.setY(ball.getY() + 0.25);
			}
		}
	}
}

void draw()
{
	//Cannot put this function into a state, because it caused issues with the UI
	//Function to draw everything
	erase();
	refresh();

	//Fill wall textures
	for(int i = 0; i < width; i++) {
		mvaddch(0, i, wallTexture);
		mvaddch(height - 1, i, wallTexture);
	}

	//Draw center line
	for(int i = 1; i < height - 1; i++)
		mvaddch(i, width / 2, ':');

	//Display points
	mvprintw(1, width / 2 / 2, "%i", player1Points);
	mvprintw(1, width / 2 + width / 2 / 2, "%i", player2Points);

	//Draw ball
	ball.drawBall(ball.getY(), ball.getX());
	player1.drawPlayer(player1.getY(), player1.getX());
	player2->drawPlayer(player2->getY(), player2->getX());
}

void update_score(int x)
{
	//Function to update score
	//Use states to ensure it is correct before updated
	if(state == UPDATE_SCORE) {
		if(x == 1) {
			player2Points++;
			player1Serve = true;
		}
		else if (x == 2) {
			player1Points++;
			player2Serve = true;
		}
		state = PLAY_GAME;
	}
	else
		cout << "Game is still going on, will not update score" << endl;
}

int game_over()
{
	//Function to display game over screen
	if(state == GAME_OVER) {
		int gameover;
		cout << "\tGame Over!" << endl;
		cout << "Would you like to play again? (1 yes, 0 no, then hit enter)";
		cin >> gameover;
		if(gameover){
			state = PLAY_GAME;
			quit = false;
			player1Serve = true;
			player2Serve = false;
			setup();
			return 1;
		}
		else if (!gameover)
			return 0;
	}
	else
		cout << "state is not in GAME_OVER" << endl;

	cout << "Error detected, quitting" << endl;
	return 0;
}
