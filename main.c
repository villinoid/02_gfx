#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"


int main() {
  screen s;
  color c;
  c.red=255;
  c.green=0;
  c.blue=0;
  struct matrix *edges;
  struct matrix *a;
  struct matrix *b;
  clear_screen(s);
  int i,j;

  edges = new_matrix(4, 4);
   a=new_matrix(4,4);
   b=new_matrix(4,6);
   ident(a);
   for (i=0;i<4;i++){
	   for(j=0;j<6;j++){
		   b->m[i][j]=i+j;
	   }
   }
   printf("testing ident on matrix a:\n");
   printf("matrix a:\n");
   print_matrix(a);
   printf("testing matrix mult:\n\n");
   printf("matrix b:\n");
   print_matrix(b);
   printf("b after matrix mult:\n");
   matrix_mult(a,b);
   printf("matrix b:\n");
   print_matrix(b);
      for (i=1;i<=4;i++){
	   for(j=0;j<4;j++){
		   a->m[i-1][j]=i;
	   }
   }
   printf("testing matrix mult again:\n");
   printf("matrix a:\n");
   print_matrix(a);
   matrix_mult(a,b);
   printf("matrix b:\n");
   printf("matrix mult a,b =\n");
   print_matrix(b);
   free_matrix(a);
   free_matrix(b);
   
   int arr[6];
   int ray[6];
   arr[0]=0;
   arr[1]=0;
   arr[2]=499;
   arr[3]=0;
   arr[4]=250;
   arr[5]=499;
   for (i=0;i<10;i++){
	   add_triangle(edges,arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]);
	   ray[0]=(arr[2]+arr[4])/2;
	   ray[2]=(arr[4]+arr[0])/2;
	   ray[4]=(arr[2]+arr[0])/2;
	   ray[1]=(arr[3]+arr[5])/2;
	   ray[3]=(arr[1]+arr[5])/2;
	   ray[5]=(arr[1]+arr[3])/2;
	   for (j=0;j<6;j++){
		   arr[j]=ray[j];
	   }
   }
   draw_lines(edges,s,c);
   display(s);
   save_extension(s, "matrix.png");
   
   
  free_matrix( edges );
}  