/*	
	Stern-Brocot tree
	Tarea 2 Algoritmos y Estructuras de Datos
	Autor: Matias Diaz B
	Email: mdiaz11@alumnos.utalca.cl

*/

#include <cstdlib>//limpiado de consola
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <stdio.h>
using namespace std; 

int inputs[3] = {0};
/*
##############################################
	    \begin{Estructura Utilizada para Arbol}
##############################################
*/
 
struct Tree
{
	int num; //numerator  of the fraction;
	int den; //denominator of the fraction;
	struct Tree *left;   // Pointer to the left subtree.
    struct Tree *right;  // Pointer to the right subtree.

    // Constructor.  Make a node containing str.
    Tree(int a,int b) {      
            num=a;
            den=b;
            left = NULL;
            right = NULL;
         }
};
/*
##############################################
	   \end{Estructura Utilizada para Arbol}
##############################################
*/

struct Tree *sBrocotTree;
void printVars( int ma, int mb,int caso)
{	
	switch(caso)
	{
	    case 1:	printf("\n############ ");
				//printf("\nla: %d",la);
				//printf("\nlb: %d",lb);
				printf("\nma: %d",ma);
				printf("\nmb: %d",mb);
				printf("\n############ ");
				break;

		case 2: printf("\n############ ");
				//printf("\nra: %d",la);
				//printf("\nrb: %d",lb);
				printf("\nma: %d",ma);
				printf("\nmb: %d",mb);
				printf("\n############ ");
				break; 

	}
}


void insert(int a,int b, struct Tree **tree, bool left)
{	
	if(NULL== *tree)
	{	
		*tree = (struct Tree*) malloc( sizeof( struct Tree ) );
		(*tree)->num=a;
		(*tree)->den=b;
		(*tree)->left = NULL;    
        (*tree)->right = NULL;  
	}
	if(left)
    {
        insert( a, b, &(*tree)->left, false);
    }
    else
    {
        insert( a, b, &(*tree)->right, true );
    }

}



void findPosition(int a, int b)
{
    int ma = 1, mb = 1;         // initial (current) node
    int Izqa = 0, Izqb = 1;         // left ancestor
    int Dera = 1, Derb = 0;         // right ancestor
    while(ma != a && mb != b)
    {
        if (b * ma < a * mb)
        {
            printf("R");
            Izqa = ma; 
            Izqb = mb;
			ma = ma + Dera;
            mb = mb + Derb;
            insert(ma,mb,(*sBrocotTree),false);
            printVars(ma,mb,1);
        }
        else if (b * ma > a * mb)
        {
           printf("L");
            Dera = ma;
            Derb = mb;
            ma = ma + Izqa;
            mb = mb + Izqb;
            insert(ma,mb,(*sBrocotTree),true);
            printVars(ma,mb,2);
        }
        else
            break;
    }
}
/*
##############################################
	    \begin{Funciones Utilitarias}
##############################################
*/

void printHeader()
{	
	if (system("CLS")){ system("clear");}

	cout << "##############################################" << endl;
  	cout << "              Stern-Brocot tree" << endl;
	cout << " Tarea 2 Algoritmos y Estructuras de Datos" << endl;
	cout << " Autor: Matias Diaz B" << endl;
	cout << " Email: mdiaz11@alumnos.utalca" << endl;
	cout << endl;
	cout << "Genera el arbol de Stern-Brocot, retorna la" << endl;
	cout << "Posicion de a/b en terminos de L y R, y ademas " << endl;
	cout << "imprime la bajada desde el primer nodo hasta el nodo buscado" << endl;
	cout << "##############################################" << endl;
}
void readAndExtractInputs()
{ string input;
  cout << "Ingrese Num Den printArbol(1/0)" << endl;
  getline (cin, input);
  istringstream iss(input);
  int i=0;
   do
    {
        
        iss >> inputs[i];
       
        i++;
    } while (iss && i<3);

}

void printInputs()
{
	for(int i=0;i<3;i++)
	{ 
		cout << "entrada: " << inputs[i] << endl;
	}
}

/*
##############################################
		\end{Funciones Utilitarias}
##############################################
*/
int main() {
   
    printHeader();
    readAndExtractInputs();
    //printInputs();
    findPosition(inputs[0],inputs[1]);
}