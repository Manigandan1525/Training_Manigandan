#include "graphics.h"
#include "console.h"
#include <cstdlib>
#include <iostream> 

using namespace std;


int main(int argc, char *argv[])
{
	console con;

	//gf.box(50, 2, 75, 3);
	//gf.box(70, 3, 71, 25);
	//gf.box(55, 3, 56, 5);
	gf.box(35, 9, 36, 13);//h1
	gf.box(37, 11, 38, 11);//h2
	gf.box(39, 9, 40, 13);//h3

	gf.box(42, 9, 43, 13);//a1
	gf.box(43, 9, 47, 10);//a2
	gf.box(46, 9, 47, 13);//a3


	gf.box(50, 9, 54, 9);//n2
	gf.box(49, 9, 50, 13);//n1
	gf.box(53, 9, 54, 13);//n3
	gf.box(54, 13, 58, 13);//n4
	gf.box(57, 9, 58, 13);//n5



	//con.getusername();
	//con.game();
	/* while(1==1)
	{
	};*/
	system("PAUSE");
	return EXIT_SUCCESS;
}


/*	gf.box(50, 2, 75, 3);
	gf.box(70, 3, 71, 25);
	gf.box(55, 3, 56, 5);
	gf.box(52, 5, 59, 9);//1
	gf.box(54, 6, 54, 6);//1
	gf.box(57, 6, 57, 6);//1
	gf.box(55, 9, 56, 17);//2
	gf.box(46, 11, 54, 12);//3
	gf.box(57, 11, 65, 12);//4
	gf.box(47, 16, 54, 17);//5
	gf.box(47, 16, 48, 22);//5
	gf.box(57, 16, 64, 17);//6
	gf.box(63, 16, 64, 22);//6
	*/