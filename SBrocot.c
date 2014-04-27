/*
 * SBrocot.c
 *
 *  Created on: Apr 27, 2014
 *      Author: mdbesoain
 */


#include<stdio.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "sys/times.h"
#include "sys/vtimes.h"


void brocotTree(int a, int c)
{
	if (fmod(a/c, 1) != 0)
	{


	}
	else
	{
	printf("%d / %d", a,a+c );
	printf("\n%d / %d", a+c ,c);
	printf("\n");
	brocotTree(a,a+c);
	brocotTree(a+c ,c);
	}

}


void main()
{
  int a,c;
  brocotTree(1,1);
}
