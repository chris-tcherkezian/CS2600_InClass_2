#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Global counter to keep track of number of iterations before loshu is found
int counter;

//Global declaration of total that will add up rows, columns, and diagonal
int total;

//True Loshu Square that will be tested against
int trueLoshuSquare[3][3] =
{{8,1,6},
{3,5,7},
{4,9,2}};

//timer for loshu
time_t t;

//pointer used for runtime
int ptr = 0;

//takes calcLoshu as a parameter of 2d arrarow1 3
int getLoshu(int calcLoshu[3][3]){
//returns 0 if not a LoShuBorow2 (sum can never be 0)

    //returns common sum (15) if a LoShuBorow2
    int sumOfLoshu = 0;

    //For Loop to get sum of first row
    for (int row2 = 0; row2<3; row2++){

        sumOfLoshu = sumOfLoshu + calcLoshu[0][row2];

    }

    int sumOfRows = 0;
    
    //For loop to get sum of second and third row
    
    for (int row1 = 1; row1<3; row1++){

        for (int row2 = 0; row2<3; row2++){

            sumOfRows = sumOfRows + calcLoshu[row1][row2];

        }
        //return value if the sum of rows is not equal to the sum of the rows
        if(sumOfRows != sumOfLoshu){
            return 0;
        }
        sumOfRows = 0;
    }
  
  
    for(int row = 0; row < 3; row++){

        for(int column = 0; column < 3; column++){
            sumOfRows = sumOfRows + calcLoshu[column][row];
        }
        if(sumOfRows != sumOfLoshu){
            return 0;
        }
        sumOfRows = 0;
    }
    //check diagonals of right side
    for (int diagonal1 = 0; diagonal1 < 3; diagonal1++){

        sumOfRows = sumOfRows + calcLoshu[diagonal1][diagonal1];
    }
    if(sumOfRows != sumOfLoshu){
        return 0;
    }
    sumOfRows = 0;

    //check diagonals of left side
    for(int diagonal2 = 0; diagonal2 < 3; diagonal2++){

        sumOfRows = sumOfRows + calcLoshu[diagonal2][2-diagonal2];

    }
    if(sumOfRows != sumOfLoshu){

        return 0;

    }

    sumOfRows = 0;
    return sumOfLoshu;
}

void main(){
    srand((unsigned) time(&t));
    int Loshu[3][3];

    //numbers that will be randomized
    int numbers[9];
    //call global declaration to implement a counter
    counter = 0;
    //do loop to keep doing this until all spots in 2d array are filled
      do{
    //making sure numbers are not repeated in the rows, only have to verify 2 rows
    for(int row1 = 0; row1<3; row1++){

        for(int row2 = 0; row2<3; row2++){
            //randomizing the array with numbers that dont repeat for the first row
            Loshu[row1][row2] = rand() % 9 + 1;
            numbers[ptr] = Loshu[row1][row2];

            for(int valuesReturned = 0; valuesReturned < ptr; valuesReturned++){
                if(numbers[valuesReturned] == numbers[ptr]){
                    //randomizing the array with numbers that dont repeat for the first row
                    Loshu[row1][row2] = rand() % 9 + 1;
                    numbers[ptr] = Loshu[row1][row2];
                    valuesReturned = -1; 
                }
            }
            ptr++;
        }
    }
    ptr = 0;

    total = getLoshu(Loshu);
    
    counter++;
    //end do loop when numbers = 0, or all spaces have been populated
    } while (numbers == 0);
    //loop ends

    //Number of iterations before Loshu Magic Square was found
    printf("Times attempted until Lo Shu Magic Square was found: %d\n");
    //Creates and prints out the Loshu Magic Square
    for(int row1 = 0; row1<3; row1++){
        printf("[ ");
        for(int row2 = 0; row2<3; row2++){
            printf("%d ", Loshu[row1][row2]);
        }
        printf("]\n");
    }
    
}

