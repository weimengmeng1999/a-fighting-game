//=======================
//		container.h
//=======================

// The so-called inventory of a player in RPG games
// contains two items, heal and magic water

#ifndef _CONTAINER		// Conditional compilation
#define _CONTAINER

class container		// Inventory
{
protected:
	int numOfHeal;			// number of heal
	int numOfMW;
	int numOflu;// number of magic water
public:
	container();			// constuctor
	void set(int heal_n, int mw_n, int lu_n);	// set the items numbers
	int nOfHeal();			// get the number of heal
	int nOfMW();	// get the number of magic water
	int nOflu();
	void display();			// display the items;
	bool useHeal();			// use heal
	bool useMW();			// use magic water
	bool useluck();


	// addition 1: add the heal and magic water after victory
friend container operator+(const container &x, const container &y);



};

#endif