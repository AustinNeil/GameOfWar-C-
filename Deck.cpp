/*
Name:  Austin Christensen
Date:  10/12/16
Description: This program sets up the funcitons required to play war.cpp
Sources Cited:  Slides provided by Adam Case
*/

#include <stdlib.h>
#include "deck.h"
#include <iostream>
#include <sstream>

using namespace std;
int rank;
char suit;


Deck::Deck() 
{
	int top = 0, r, rank;
	char s, suit;
	rank = r;
	suit = s;

	{
	ostringstream oss;
	// dynamicaly allocacte memory for the new array
	deck = new Card[NUMCARDS];

	// loop through the word given
    for(int i = 2; i < NUMCARDS; i++)
    	{
    		if(i <= 15)
    		{
    			Card s = {i, 'S'};
    			deck[i-2] = s;
    		}
    		else if(i > 15 and i <= 28)
    		{
    			Card h = {i, 'H'};
    			deck[i-2] = h;
    		}
    		else if(i > 28 and i <= 41)
    		{
    			Card c = {i, 'C'};
    			deck[i-2] = c;
    		}
    		else
    		{
    			Card d = {i, 'D'};
    			deck[i-2] = d;
    		}
    	}
	}
}


Deck::~Deck()
{
delete[] deck;
}

void Deck::shuffle()
{
	// initialize random function
	srand(time(0));

	int j;

	for (int i = 0; i < NUMCARDS; i++)
	{
		// create a random variable between 0 and the length of the word
		int j = rand()%NUMCARDS;
		// swap values in order with the character in the random location generated before
		swap(deck + i, deck + j);
	}
}

Card Deck::draw()
{
	top++;

	return deck[top];
}

bool Deck::isEmpty()
{

	if (top > 51)
		return true;
	else
		return false;
}

void Deck::swap(Card *a, Card *b)
{
	// assign a new variable to hold the variable being swapped
	Card swap = *a;
	// set =
	*a = *b;
	// change other variable back to the original value
	*b = swap;
}
