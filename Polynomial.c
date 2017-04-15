#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Polynomial
{
	double coeff;
	int expo;
};

typedef struct Polynomial poly;

poly* polyRep(int); /* function to represent a polynomial */
void displayPoly(poly*, int); /* function to display a polynomial */
void polyEval(poly*, int, double); /* function to evaluate a polynomial using Horner's Rule */
void addPoly(poly*, poly*, int, int); /* function to add two polynomials */

int main(void)
{
	poly *p1, *p2;
    int choice, numofterms1, numofterms2;
    double x;
    printf("This program does the following:\n\n");
	printf("--------------------------------------------------------------------------------");
	printf("1. Represent a polynomial    2. Evaluate a polynomial    3. Add two polynomials\n");
    printf("--------------------------------------------------------------------------------");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
                  case 1:
                       printf("\n\nEnter the number of terms in the polynomial:\n");
                       scanf("%d", &numofterms1);
	                   p1 = polyRep(numofterms1);
	                   printf("\nThe polynomial you entered is = ");
	                   displayPoly(p1, numofterms1);
	                   break;
	                   
                  case 2:
                       printf("\n\n(Please note: Polynomial should be represented in the form A (x) = anxn + an-1xn-1 + ... + a1x + a0)");
                       printf("\n\nEnter the number of terms in the polynomial: ");
                       scanf("%d", &numofterms1);
	                   p1 = polyRep(numofterms1);
	                   printf("\nThe polynomial you entered is = ");
	                   displayPoly(p1, numofterms1);
	                   printf("\n\nEnter the value of x: ");
	                   scanf("%lf", &x);
	                   printf("\n\n");
	                   displayPoly(p1, numofterms1);
	                   printf("= ");
	                   polyEval(p1, numofterms1, x);
	                   break;
	                   
                  case 3:
	                   printf("\n\nEnter the number of terms in the first polynomial: ");
                       scanf("%d", &numofterms1);
	                   p1 = polyRep(numofterms1);
	                   printf("\n\nEnter the number of terms in the second polynomial: ");
                       scanf("%d", &numofterms2);
	                   p2 = polyRep(numofterms2);
	                   printf("\nThe first polynomial you entered is = ");
	                   displayPoly(p1, numofterms1);
	                   printf("\nThe second polynomial you entered is = ");
	                   displayPoly(p2, numofterms2);
	                   addPoly(p1, p2, numofterms1, numofterms2);
	                   break;
	                   
                  default:
                          exit(1);
    }
	getch();
	return 0;
}
	
/* function definition for polyRep */
poly* polyRep(int size)
{
	int i;
	poly *polynom;	
	polynom = (poly*)malloc(size*sizeof(poly));
	printf("\n\nEnter the following data with regards to the polynomial...");
	for(i=0; i<size; ++i)
	{
		printf("\n\nTerm %d -\n", i+1);
		printf("Enter coefficient: ");
		scanf("%lf", &polynom[i].coeff);
		printf("\nEnter exponent: ");
		scanf("%d", &polynom[i].expo);
	}
	return polynom;
}

/* function definition for displayPoly */
void displayPoly(poly *pol, int size)
{
	int i;
	for(i=0; i<size; ++i)
	{
		if(i!=0)
        {
                if(pol[i].coeff > 0)
                {
                    if(pol[i].coeff >= 1 && pol[i].expo == 0)
                    {
                        printf("+ %.2f ", pol[i].coeff);
                        continue;
                    }
                    if(pol[i].coeff >= 1 && pol[i].expo == 1)
                    {
                        if(pol[i].coeff == 1)
                            printf("+ x ");
                        else
                            printf("+%.2fx ", pol[i].coeff);
                        continue;
                    }
                    if(pol[i].coeff == 1 && pol[i].expo != 0)
                        printf("+ x^%d ", pol[i].expo);
                    else
                        printf("+ %.2fx^%d ", pol[i].coeff, pol[i].expo);
                }
                else
                {
                    if(pol[i].coeff <= -1 && pol[i].expo == 0)
                    {
                        printf("%.2f ", pol[i].coeff);
                        continue;
                    }
                    if(pol[i].coeff <= -1 && pol[i].expo == 1)
                    {
                        if(pol[i].coeff == -1)
                            printf("- x ");
                        else
                            printf("%.2fx ", pol[i].coeff);
                        continue;
                    }
                    if(pol[i].coeff == -1 && pol[i].expo != 0)
                        printf("- x^%d ", pol[i].expo);
                    else
                        printf("%.2fx^%d ", pol[i].coeff, pol[i].expo);
                }
        }
		else
        {
            if(pol[i].expo == 0)
            {
                printf("%.2f ", pol[i].coeff);
                continue;
            }
            if(pol[i].expo == 1)
            {
                if(pol[i].coeff == 1)
                    printf("x ");
                else
                    printf("%.2fx ", pol[i].coeff);
            }
            else
            {
                if(pol[i].coeff == 1)
                {
                    printf("x^%d ", pol[i].expo);
                    continue;
                }
                if(pol[i].coeff == -1)
                    printf("-x^%d ", pol[i].expo);
                else
                    printf("%.2fx^%d ", pol[i].coeff, pol[i].expo);
            }
        }	    
	}
}

/* function definition for polyEval */
void polyEval(poly *p, int size, double x)
{
     int i;
     double val = (p[0].coeff * x) + p[1].coeff;
     for(i = 1; i < (size-1); i++)
         val = (val * x) + p[i+1].coeff;
     printf("%.2f\n", val);
}
     

/* function definition for addPoly */
void addPoly(poly *pol1, poly *pol2, int size1, int size2)
{
	poly *sum = (poly*)malloc((size1+size2)*sizeof(poly)), temp;
	int i, j, k = 0, l, flag = 0;
	for(i = 0; i < size1; i++)
	{
		for(j = 0; j < size2; j++)
		{
			if(pol2[j].expo == pol1[i].expo)
			{
				sum[k].coeff = pol1[i].coeff + pol2[j].coeff;
				sum[k].expo = pol1[i].expo;
				k++;
				break;
			}
        }
   }
   l = k;
   for(i = 0; i < size1; i++)
   {
         for(j = 0; j < k; j++)
         {
               if(sum[j].expo == pol1[i].expo)
               {
                   flag = 1;
                   break;
               }
         }
         if(flag == 0)
         {
                 sum[k].coeff = pol1[i].coeff;
                 sum[k].expo = pol1[i].expo;
                 k++;
         }
   }
   flag = 0;
   for(i = 0; i < size2; i++)
   {
         for(j = 0; j < l; j++)
         {
               if(sum[j].expo == pol2[i].expo)
               {
                   flag = 1;
                   break;
               }
         }
         if(flag == 0)
         {
                 sum[k].coeff = pol2[i].coeff;
                 sum[k].expo = pol2[i].expo;
                 k++;
         }
   }
   sum = (poly*)realloc(sum, k * sizeof(poly));
   for(i = 0; i < (k - 1); i++)
   {
         for(j = 0; j < (k - 1 - i); j++)
         {
               if(sum[j].expo < sum[j+1].expo)
               {
                     temp = sum[j];
                     sum[j] = sum[j+1];
                     sum[j+1] = temp;
               }
         }
   }         
   printf("\n\n");
   displayPoly(pol1, size1);
   printf("+ ");
   displayPoly(pol2, size2);
   printf("= ");
   displayPoly(sum, k);
}
         			
