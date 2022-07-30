#ifndef common_H
#define common_H
#include <vector>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

#include <time.h>

#define X 10
#define Y 10

#define DELAY 20

using namespace std;
void wait(int factor)
{
	clock_t ew;
	ew = clock() +  CLOCKS_PER_SEC*factor/100;
	while (clock() < ew) {}
}
#endif
