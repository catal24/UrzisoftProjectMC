
#include<iostream>
#include "Map.h";
#include "Tank.h";
int main()
{
	Map map(50,25);
	//map.drawMap();
	Tank tanc(4,4,0,false,true,3,5,false,up);
	map.addTank(tanc);

	map.drawMap();
	return 0;
}