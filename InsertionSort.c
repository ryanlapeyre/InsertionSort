#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <stdbool.h> 
#define SORTSIZE 8
#define RANDOMRANGE 10
void InsertionSort2DimensionalArray(int[][SORTSIZE]);
void InsertionSortPointers(int*);
void InsertionSortArray(int[]);
void RandomizeArray(int[]);
void RandomizePointer(int*);
void Randomize2DimensionalArray(int[][SORTSIZE]);
void PrintArray(int[]);
void PrintPointer(int*);
void Print2DimensionalArray(int[][SORTSIZE]);
int main (void)
{
    srand(time(NULL)); 
    int* pointerElements = malloc(sizeof(int)*SORTSIZE);
    int arrayElements [SORTSIZE] = {0};
    int arrayElements2Dimensional[SORTSIZE][SORTSIZE] = {{0}};
    //Array Sort
    puts("");
    RandomizeArray(arrayElements);
    puts("One Dimensional Array Elements (least to greatest)");
    PrintArray(arrayElements);
    InsertionSortArray(arrayElements);
    PrintArray(arrayElements);
    puts("");
    //Pointer Sort
    RandomizePointer(pointerElements);
    puts("One Dimensional Pointer Elements (greatest to least)");
    PrintPointer(pointerElements);
    InsertionSortPointers(pointerElements);
    PrintPointer(pointerElements);
    free(pointerElements);
    puts("");
    //2Dimensional Array Sort
    Randomize2DimensionalArray(arrayElements2Dimensional);
    puts("Two Dimensional Array Elements (least to greatest)");
    Print2DimensionalArray(arrayElements2Dimensional);
    InsertionSort2DimensionalArray(arrayElements2Dimensional);
    Print2DimensionalArray(arrayElements2Dimensional);
    puts(""); 
    return 1;
}


void InsertionSort2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE] )
{
    int firstCounter = 0;
    int secondCounter = 0;
    int thirdCounter = 0;
    int spareItem = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE; firstCounter++ )
    {    
            for(thirdCounter = 1; thirdCounter < SORTSIZE; thirdCounter++)
            {
                //We have another nested for loop here to visit all of the elements in this 2Dimensional array (likea rowCounter basically)
                //It's so we can visit all of the rows in this array. The next loop is for the columns, which are sorted.
                //The for loop above sets up the correct positioning for the for loop below. Starting at index 1 makes sure we never swap when we cannot
                //(due to the subtraction, we don't want to access a negative array element.
                for(secondCounter = thirdCounter; secondCounter > 0; secondCounter--)
                {
                    if(arrayElements2Dimensional[firstCounter][secondCounter] < arrayElements2Dimensional[firstCounter][secondCounter - 1]) 
                    {
                        //Pay attention to how we're sorting if the previous element is greater. 
                        //Thus, if we have a condition to sort if this element is greater, our sort will be least to greatest.
                        spareItem = arrayElements2Dimensional[firstCounter][secondCounter - 1];
                        arrayElements2Dimensional[firstCounter][secondCounter - 1] = arrayElements2Dimensional[firstCounter][secondCounter];
                        arrayElements2Dimensional[firstCounter][secondCounter] = spareItem;
                    }
                }
            }
        }
    return;
}
void InsertionSortPointers(int* pointerElements)
{
    int firstCounter = 0;
    int secondCounter = 0;
    int spareItem = 0;
    for(firstCounter = 1; firstCounter < SORTSIZE; firstCounter++)
    {    
        for(secondCounter = firstCounter; secondCounter > 0; secondCounter--)
        {
            if ( *(pointerElements + secondCounter - 1) < *(pointerElements + secondCounter) )
            {
                //Pay attention to how we're sorting if the original element is bigger.
                //Thus, if we have a condition to sort if this element is bigger, our sort will be greatets to least.
                spareItem = *(pointerElements + secondCounter - 1);
                *(pointerElements + secondCounter - 1) = *(pointerElements +secondCounter);
                *(pointerElements + secondCounter ) = spareItem;
            }
        }
    }
    return;
}
void InsertionSortArray(int arrayElements[])
{
    int firstCounter = 0;
    int secondCounter = 0;
    int spareItem = 0;
    for(firstCounter = 1; firstCounter < SORTSIZE; firstCounter++)
    {    
        for(secondCounter = firstCounter; secondCounter > 0; secondCounter--)
        {
            if(arrayElements[secondCounter - 1] > arrayElements[secondCounter]) 
            {
                //Pay attention to how we're sorting if the previous element is greater. 
                //Thus, if we have a condition to sort if this element is greater, our sort will be least to greatest.
                spareItem = arrayElements[secondCounter - 1];
                arrayElements[secondCounter - 1] = arrayElements[secondCounter];
                arrayElements[secondCounter] = spareItem;
            }
        }
    }
    return;
}
void RandomizeArray(int arrayElements[])
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        arrayElements[counter] = rand() % RANDOMRANGE;
    }
    return;
}
void RandomizePointer(int* pointerElements)
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        *(pointerElements + counter) = rand() % RANDOMRANGE;
    }
    return;
} 
void Randomize2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE])
{
    int firstCounter = 0;
    int secondCounter = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE; firstCounter++)
    {
        for(secondCounter = 0; secondCounter < SORTSIZE; secondCounter++)
        {
            arrayElements2Dimensional[firstCounter][secondCounter] = rand() % RANDOMRANGE;
        }
    }
    return;
}

void PrintArray(int arrayElements[]) 
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        printf("%d | " , arrayElements[counter]);
    }
    puts("");
    return;
}
void PrintPointer(int* pointerElements)
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        printf("%d | " ,  *(pointerElements + counter) );
    }
    puts("");   
    return;
}
void Print2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE])
{
    int firstCounter = 0;
    int secondCounter = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE; firstCounter++)
    {
        for(secondCounter = 0; secondCounter < SORTSIZE; secondCounter++)
        {
            printf("%d | " , arrayElements2Dimensional[firstCounter][secondCounter] );
        }
        puts("");
    }
    puts("");
    return;
}
