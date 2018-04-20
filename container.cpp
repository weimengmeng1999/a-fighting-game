//=======================
//		container.cpp
//=======================
#include <iostream>
#include <string>

using namespace std;

// default constructor initialise the inventory as empty
#include "container.h"
container::container()
{
	set(0, 0,0);
}

// set the item numbers
void container::set(int heal_n, int mw_n,int lu_n)
{
	numOfHeal = heal_n;
	numOfMW = mw_n;
	numOflu= lu_n;
}

// get the number of heal
int container::nOfHeal()
{
	return numOfHeal;
}

// get the number of magic water
int container::nOfMW()
{
	return numOfMW;
}

int container::nOflu(){
	return numOflu;
}

// display the items;
void container::display()
{
	cout << "Your bag contains: " << endl;
	cout << "Heal(HP+100): " << numOfHeal << endl;
	cout << "Magic Water (MP+80): " << numOfMW << endl;
	cout << "luck (avoid an attack): " << numOflu << endl;

}

//use heal
bool container::useHeal()
{
	numOfHeal--;
		return 1;		// use heal successfully
}

//use magic water
bool container::useMW()
{
	numOfMW--;
	return 1;		// use magic water successfully
}

bool container::useluck(){
	numOflu--;
	return 1;
}

container operator+(const container &x, const container &y){
	container c;
	c.numOfHeal = x.numOfHeal + y.numOfHeal;
	c.numOfMW = x.numOfMW + y.numOfMW;
	c.numOflu = x.numOflu + y.numOflu;
	return c;
}
