#include<iostream>
#include <conio.h>
#include <cstdlib>
#include "Game.h";



int main()
{
	Map map(50,25);
	//map.drawMap();
	Tank tanc(4,4,0,false,true,3,5,false,right);
	
	
	
	

	tanc.moveTank('w');
	map.addTank(tanc);
	map.drawMap();

	return 0;
}