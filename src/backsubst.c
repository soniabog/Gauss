#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int n = mat->r;
	int r, c;

	if( x->c != 1 || b->c != 1 ) return 2;

	for( r = n-1; r >= 0; r--){
		double s = 0;

		for( c = r+1; c < n; c++)
			s += mat->data[r][c] * x->data[c][0];

		if( mat->data[r][r] == 0 )
			return 1;

		x->data[r][0] = (b->data[r][0] - s) / mat->data[r][r];
	}
				/* 
				int i;
				for (i =0; i < x->r; i++) {
								x->data[i][0] = b->data[i][0];
				}*/

	return 0;
}


