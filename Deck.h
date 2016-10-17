// DECK_H

#ifndef DECK_H
#define DECK_H

const int NUMCARDS = 52;
//Represents a playing card with 
//rank 2 - 14 and suit C, D, S, or H
struct Card
{
	int rank; //11=Jack, 12=Queen, etc.
	char suit;
};

class Deck
{
private:
    Card *deck;
    int top;
    void swap(Card *, Card *);
public:
    Deck();
    ~Deck();
    void shuffle();
    Card draw();
    bool isEmpty();
};

#endif
