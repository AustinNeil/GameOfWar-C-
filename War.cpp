/*
Name:  Austin Christensen
Date:  10/12/16
Description: This program allows a user to simulate a game of WAR
Sources Cited:  Slides provided by Adam Case
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Deck.h"
using namespace std;

int main()
{
	// create a score of 0-0 for 2 players
	int score1 = 0, score2 = 0;

	//Declare new Deck Array
	Deck *d = new Deck;
	// Shuffle the Deck
	d->shuffle();

	// cout information
	cout << "The deck is shuffling..." << endl;
	cout << "Ready to play?" << endl;
	cout << "Just one thing, use the 'Enter' key to advance dialogue!" << endl;

	// Start Game Loop
	while(!((d->isEmpty())))
	{
	// 2 players draw a card
		Card player = d->draw();
		Card computer = d->draw();

		//print out the cards
		cout << "The first card is for you is: " << player.suit << "," << player.rank << endl;
		cout << "The computers first card is:" << computer.suit << "," << computer.rank << endl;
		cin.ignore();

	// Higher card wins, that player adds 1 to their deck
		if(player.rank > computer.rank)
		{
			score1 += 1;
			cout << "You win this one!" << endl;
			cout << "The score is:" << endl;
			cout << "Computer: " << score2 << endl;
			cout << "You: " << score1 << endl;
			cin.ignore();
		}
		else if(computer.rank > player.rank)
		{
			score2 +=1;
			cout << "The Computer won this one!" << endl;
			cout << "The score is:" << endl;
			cout << "Computer: " << score2 << endl;
			cout << "You: " << score1 << endl;
			cin.ignore();
		}
		else
		{
			//WAR
			cout << "OH YEA BABY! TIME FOR WAR!!" << endl;
			//In WAR, each player takes 2 more cards (4 total)
			Card player = d->draw();
			Card computer = d->draw();
			// They flip over 1st card, repeat the process of comparing.
			cout << "Your first WAR card is: " << player.suit << "," << player.rank << endl;
			cout << "The computers first WAR card is:" << computer.suit << "," << computer.rank << endl;
			cin.ignore();
		}
			if(player.rank > computer.rank)
			{
				score1 += 6;
				cout << "You win this one!" << endl;
				cout << "The score is:" << endl;
				cout << "Computer: " << score2 << endl;
				cout << "You: " << score1 << endl;
				cin.ignore();
			}
			else if(computer.rank > player.rank)
			{
				score2 += 6;
				cout << "The Computer won this one!" << endl;
				cout << "The score is:" << endl;
				cout << "Computer: " << score2 << endl;
				cout << "You: " << score1 << endl;
				cin.ignore();
			}
			else
			{
				//WAR round 2
				Card player = d->draw();
				Card computer = d->draw();

				cout << "Your first WAR card is: " << player.suit << "," << player.rank << endl;
				cout << "The computers first WAR card is:" << computer.suit << "," << computer.rank << endl;
			}
				if(player.rank > computer.rank)
				{
					score1 += 6;
					cout << "You win this one!" << endl;
					cout << "The score is:" << endl;
					cout << "Computer: " << score2 << endl;
					cout << "You: " << score1 << endl;
					cin.ignore();
				}
				else if(computer.rank > player.rank)
				{
					score2 += 6;
					cout << "The Computer won this one!" << endl;
					cout << "The score is:" << endl;
					cout << "Computer: " << score2 << endl;
					cout << "You: " << score1 << endl;
					cin.ignore();
				}
				// if both have equal cards both times in the war its a stalemate and nobody loses a card.
				else
				{
					score1 = score1;
					score2 = score2;
				}
	}
	if(score1 > score2)
		{
		cout << "Congratulations! You won with a score of: " << score1 << endl;
		cout << "The computer only had " << score2 << endl;
		}
	else if(score2 > score1)
		{
		cout << "Oh now... The computer beat you with a score of: " << score2 << endl;
		cout << "You only had " << score1 << endl;
		}
	else
		{
		cout << "WOW. That was exhilirating! The Game ended in a tie with both players having a score of: " << score1 << endl;
		}
return 0;
}