/* Program to solve Towers of Hanoi problem with 0/1/2/3 disks */

#include <stdio.h>
#include <conio.h>

#define MAXDISK 3

void move(int, int, int, int); /* function to move disks from Tower 1 to Tower 3 */

/* main */
int main(void)
{
    int disks;
    printf("How many disks? (Max. 3)\n");
    do
    {
                scanf("%d", &disks);
                if(disks > MAXDISK)
                    printf("\n\nInvalid input. Enter again.\n\n");
    } while(disks > MAXDISK);
    printf("\n\nInstructions are as follows:\n");
    if(disks == 0)
        printf("\nDo nothing.\n");
    else
        move(disks, 1, 3, 2);
    getch();
    return 0;
} /* end of main */

/* function definition for move */
void move(int count, int start, int finish, int temp)
{
     int swap;
     while(count > 0)
     {
                 move(count - 1, start, temp, finish);
                 printf("\nMove Disk %d from Tower %d to Tower %d.\n", count, start, finish);
                 --count;
                 swap = start;
                 start = temp;
                 temp = swap;
     }
}
