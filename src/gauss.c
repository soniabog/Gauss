#include "gauss.h"
#include <math.h>

#include <math.h>

/**
 *  * Zwraca 0 - elimnacja zakonczona sukcesem
 *   * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 *    */
int eliminate(Matrix *mat, Matrix *b){
	    /**
	     *   	 * Tutaj należy umieścić właściwą implemntację.
	     *   	 		 */

	int n = mat->r;

	int c, r, i;

	for( c = 0; c < n - 1; c++)
	{
		int cmax = c;
		for( r = c+1; r < n; r++)
			if(fabs(mat->data[r][c]) > fabs(mat->data[cmax][c]) )
				cmax = r;
		if( cmax != c)
		{
			double *tmp = mat->data[c];
			mat->data[c] = mat->data[cmax];
			mat->data[cmax] = tmp;
			double btmp = b->data[c][0];
			b->data[c][0] = b->data[cmax][0];
			b->data[cmax][0] = btmp;
		}


		for( r = c+1; r < n; r++)
		{ 

			if( mat->data[c][c] == 0 )
				return 1;

			double m = mat->data[r][c] / mat->data[c][c];
																			
			for( i = c; i < n; i++ )
				mat->data[r][i] -= m * mat->data[c][i];

			b->data[r][0] -= m * b->data[c][0];
		}	
	}
	return 0;
}
