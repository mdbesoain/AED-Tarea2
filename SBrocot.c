/*
 * SBrocot.c
 *
 *  Created on: Apr 27, 2014
 *      Author: mdbesoain
 */

#include <math.h>
#include <stdio.h>

//#include <string.h>
//#include <time.h>
//#include "sys/times.h"
//#include "sys/vtimes.h"

 struct sternBrocotTree {
	int denominador, numerador;
	struct sternBrocotTree * right, *left;
};

 typedef struct sternBrocotTree tree;
 tree * head;

void printsternBrocotTree(tree *r) {
	if (r != NULL)
	{
		printf("\n%d / %d\n", r->denominador, r->numerador);

		printsternBrocotTree(r->left);
		printsternBrocotTree(r->right);
	}
}
void insertNode(int a, int b, int c, int d) {
	struct sternBrocotTree *auxL;
	struct sternBrocotTree *auxR;
	auxL=(tree *)malloc(sizeof(tree));
	auxR=(tree *)malloc(sizeof(tree));
	auxL->denominador = a;
	auxL->numerador = b;
	auxR->denominador = c;
	auxR->numerador = d;
	auxR->right=auxR->left=NULL;
	auxL->right=auxL->left=NULL;
	head->left=auxL;
	head->right= auxR;
}



void brocotTree(int a, int c) {
	if (fmod(a / c, 1) != 0) {

	} else
	{
		insertNode(a, a + c, a + c, c);
		printsternBrocotTree(head);
//		printf("%d / %d", a, a + c);
//		printf("\n%d / %d", a + c, c);
//		printf("\n");
//		brocotTree(a, a + c);
//		brocotTree(a + c, c);
	}

}


void main() {

	head= NULL;
	brocotTree(1, 1);
}
