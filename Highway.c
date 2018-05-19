/**************************************************************
	Problem: 1084
	User: u6aie
	Language: C
	Result: Runtime Error
	RunId : 13933
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRIVALS 50

void printDynamicArray(char **arr,  int rows,  int columns); // method to print a dynamic 2d array
void traffic(char **arr, int r,int c); // method to simulate the traffic in simulation
void deallocate_memory(char** arr, int rows); // deallocates the heap memory of a 2d dynamic array

/*
Structure which stores the arrival time of a car, as well as the row index where it should appear.
*/
struct car {
   int arrival_time;
   int row_index;
};

int main()
{
    char **grid; // double pointer representing a dynamic 2d array which stores the highway
    int number_of_rows, number_of_colums, number_of_timesteps; // integers for input
    int i,j, step ; // integers used for iteration
    struct car *arrivals; // pointer to the structure car
    int car_arrival, car_lane, number_of_cars = 0, car_id =0;

    scanf("%d %d %d", &number_of_rows, &number_of_colums, &number_of_timesteps); // scan the size of the grid and the number of steps for simulation



    grid = malloc(number_of_rows * sizeof(char*));  // dynamically allocate memory for the number of rows necessary
	for(i = 0; i < number_of_rows ; i++)
    {
        grid[i] = malloc(number_of_colums * sizeof(char*)); // dynamically allocate memory for the number of columns necessary
    }
     if(grid == NULL)
    {
        printf("Error. Not enough space available"); // check whether exists enough memory
        exit(1);
    }

       for(i = 0; i < number_of_rows ; i++)
        for(j = 0; j < number_of_colums ; j++)
        {grid[i][j] = '.';} // assign every element of the array to '.' in order to initialise the highway as required


   arrivals = malloc(MAX_ARRIVALS * sizeof(arrivals)); // dynamically allocate memory for the 50 arrivals of cars

   if(arrivals == NULL)
       {
       printf("Error. Not enough space available"); // check whether exists enough memory
       exit(1);
       }

/*
Keep reading the list of arrival until the end-of-file, storing the input data in a dynamic array pointing to the structure car
*/
   while(scanf("%d %d", &car_arrival, &car_lane) != EOF) {
        arrivals[number_of_cars].arrival_time = car_arrival;
        arrivals[number_of_cars].row_index = car_lane;
        number_of_cars++; // retain the number of arrivals scanned
    }

     // reallocate the dynamic memory according to the number of arrivals entered above
     arrivals = realloc(arrivals, sizeof(arrivals) * number_of_cars  );

     if(arrivals == NULL)
       {
       printf("Error. Not enough space available"); // check whether exists enough memory
       }


for(step = 0; step < number_of_timesteps -1; step ++) // a for loop that executes the number of steps to simulate the highway
{

    loop:   if(arrivals[car_id].arrival_time == step) // check if the car arrived at the current step
            {grid[arrivals[car_id].row_index][0] = '1'; // mark the first element of the indicated lane with 1
             if(car_id < number_of_cars) // check whether the last arrival time is less than the current step
             {car_id++;} // if is not, then the next arrival time could be checked
             goto loop;} // jump back checking if the car arrived at the current step


       traffic(grid,number_of_rows,number_of_colums); // call the method to simulate traffic on highway

    }


 printDynamicArray(grid,number_of_rows,number_of_colums); // print the grid which represents the final output
 deallocate_memory(grid,number_of_rows); // deallocate the dynamic array's memory
 free(arrivals); // free the memory of array pointer of the structure car

    return 0;
}

/*
This method has as arguments a double pointer which represents the array and its size's numbers
*/
void traffic(char **arr, int r,int c)
{
    int i,j;
    for(i = 0; i < r; i++)
      for(j = c-1 ; j > 0 ; j--) // iterate backwards the columns of the array because the last element of the column will not be needed
        arr[i][j] = arr[i][j-1]; // assign the last element of the column with the second last value and so on

    for(i = 0; i < r; i++)
        arr[i][0] = '.'; // initiate the first element of each column with '.' in order to feel like everything moved
                         // with one position to right and the first space in lanes is now empty

}

/*
Method to print out a dynamic array by iterating through every element and printing out in a pleasant format.
*/
void printDynamicArray(char **arr, int rows, int columns)
{
    int i,j;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
          printf("%c%s", arr[i][j], (j==columns-1)?"\n":""); // print out elements of the array and go to a new line if the column finished

}

/*
Method to deallocate the heap memory assigned to the dynamic 2d arrays, for that reason it has two double pointer char variables as arguments.
*/
void deallocate_memory(char** arr, int rows)
{  int i;
   // De-allocate heap memory.
  	for(i = 0; i < rows; i++) {
		free(arr[i]); // Deallocate memory for each row.
	}
	free(arr); // deallocate memory for this pointer

}
