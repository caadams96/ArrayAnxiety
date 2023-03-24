#include <stdio.h>

//Prototypes

int InitializeArray(long *alngValues);

long get_long(void);

int PopulateArray(long *alngValues);

int PrintArray(long *alngValues);

long GetArrayTotal(long *start, long *end);

int ShowArrayTotal(long *alngValues);

int GetArrayAverage(long *alngValues);

long GetArrayMaximum(long *alngValues);

int ShowEvenArrayLocations(long *alngValues);

int ShowEvenArrayElements(long *alngValues);


#define SIZE 4

int main() {
    long alngValues[SIZE];

    printf("*************** ARRAY ANXIETY **********************\n");

    InitializeArray(alngValues);

    PopulateArray(alngValues);

    PrintArray(alngValues);

    ShowArrayTotal(alngValues);

    GetArrayAverage(alngValues);

    GetArrayMaximum(alngValues);

    ShowEvenArrayLocations(alngValues);

    ShowEvenArrayElements(alngValues);

    printf("\n***********************");


    return 0;
}
//Functions


/***************************************************
 * Subroutine: InitializeArray
 *
 *
 * */
int InitializeArray(long *alngValues){
    long *arrPointer;
    for(arrPointer = &alngValues[0]; arrPointer < &alngValues[SIZE]; arrPointer = arrPointer + 1 ){
        *arrPointer = 0;
    }
    return 0;
}



/***************************************************
 * Subroutine: PrintArray
 *
 *
 * */
int PrintArray(long *alngValues){
    long *arrPointer;
    printf("The contents of the array are [");
    for(arrPointer = &alngValues[0]; arrPointer < &alngValues[SIZE]; arrPointer = arrPointer + 1 ){
        if (arrPointer == &alngValues[SIZE-1]){
            printf("%ld",*arrPointer);

        }else{
            printf("%ld, ",*arrPointer);
        }
    }
    printf("]\n");
    return 0;
}



/***************************************************
 * Subroutine: PopulateArray
 * Function: get_long
 *
 * */
int PopulateArray(long *alngValues){
    long input;
    long *arrPointer;
    printf("Enter four number:\n");
    for (arrPointer = &alngValues[0]; arrPointer<&alngValues[SIZE]; arrPointer = arrPointer + 1){
        input = get_long();
        *arrPointer = input;
        printf("%ld\n", input);
    }
    return 0;
}



long get_long(void) {
    long input;
    char ch;
    while (scanf_s("%ld", &input) != 1) {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a long value. \nPlease enter an ");
        printf("Long value: 2147483647 or lower\n");
    }
    return input;
}
/*******************************************************************************/


/***************************************************
 * Subroutine: GetArrayTotal
 * Subroutine: ShowArrayTotal
 *
 * */
long GetArrayTotal(long *start, long *end){
    long total = 0;
    while(start < end){
        total += *start;
        ++start;
    }
    return total;
}



int ShowArrayTotal(long *alngValues){
    printf("The total of the array is %ld\n", GetArrayTotal(alngValues, alngValues+SIZE));
    return 0;
}


/***************************************************
 * Subroutine: GetArrayAverage
 *
 *
 * */
int GetArrayAverage(long *alngValues){
    double average = (double) GetArrayTotal(alngValues, alngValues+SIZE) / SIZE;
    printf("The average of the array is %.2f\n", average);
    return 0;
}


/***************************************************
 * Subroutine: GetArrayMaximum
 *
 *
 * */
long GetArrayMaximum(long *alngValues){
    long maximum = 0;
    long *arrPointer;
    for (arrPointer = &alngValues[0]; arrPointer<&alngValues[SIZE]; arrPointer = arrPointer + 1){
        if(maximum <= *arrPointer){
            maximum = *arrPointer;
        }
    }
    printf("The maximum of the array is %ld\n",maximum);
    return 0;
}



/***************************************************
 * Subroutine: ShowEvenArrayLocations
 *
 *
 * */
int ShowEvenArrayLocations(long *alngValues){
    long *arrPointer;
    int index = 0;
    printf("Even Location values are ");
    for (arrPointer = &alngValues[0]; arrPointer<&alngValues[SIZE]; arrPointer = arrPointer + 1, ++index)
        if(index %  2  == 0){
            printf("Location %d = %ld, ",index,*arrPointer);
        }
    printf("\n");
    return 0;

}



/***************************************************
 * Subroutine: ShowEvenArrayElements
 *
 *
 * */
int ShowEvenArrayElements(long *alngValues){
    long *arrPointer;
    printf("Even elements of the array are ");
    for (arrPointer = &alngValues[0]; arrPointer<&alngValues[SIZE]; arrPointer = arrPointer + 1)
        if(*arrPointer %  2  == 0){
            printf("%ld ",*arrPointer);
        }
    return 0;
}