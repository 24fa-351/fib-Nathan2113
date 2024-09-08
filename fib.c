#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibRecursion(int number);

// For this program, argv[0] is fib, argv[1] is the integer we are calculating the fibonacci for, argv[2] is the method, and argv[3] is the file
   // The methods include: 'r' for recursion, and 'i' for iterative
   
int main(int argc, char* argv[]) { // argc is the argument count and argv is a vector of arguments
   if(argc < 3) {
      printf("[-] Must pass an integer and either 'i' or 'r' as command line arguements\n");
      printf("[-] EXAMPLE: ./fib 5 r\n");
   } // END if(argc < 4)
   else {
      int fib_counter = 0; // This integer will read from the input file, and add that value to the integer arguement passed by the user
      int file_number = 0;

      // Open the input file
      FILE* file_ptr;
      file_ptr = fopen(argv[3], "r");

      if(file_ptr == NULL) {
         printf("[-] Could not find the file specified. Please enter a valid file as a command line argument\n");
      } // END (file_ptr == NULL)
      else {
         fscanf(file_ptr, "%d", &file_number);
      } // END else

      // TESTING - file input read
      // printf("Number in the file: %u\n", file_number);

      fib_counter = file_number + atoi(argv[1]) - 1;
      
      // strcmp returns 0 if the strings are equal
      if(!strcmp(argv[2], "i")) { // Iterative implementation of fibonacci
         __uint64_t current_number = 1; // __uint64_t can hold up to 18446744073709551615
         __uint64_t prev_number = 0;
         __uint64_t prev_prev_number = 0;

         if(fib_counter == 0) {
            current_number = 0;
         } // END if(fib_counter == 0)
         else {
            for(int i = 1; i < fib_counter; i++) {
               prev_prev_number = prev_number;
               prev_number = current_number;
               current_number = prev_prev_number + prev_number;
            }// END for(int i = 1; i < argv[1]; i++)
         } // END else
         

         // printf("The answer is %lu\n", current_number);
         printf("%lu", current_number);
      } // END if(argv[2] == 'i')
      else if(!strcmp(argv[2], "r")) { // Recursive implementation of fibonacci
         __uint64_t fibonacci_answer = fibRecursion(fib_counter);

         // printf("The answer is %lu\n", fibonacci_answer);
         printf("%lu", fibonacci_answer);
      } // END else else if(argv[2] == 'r')
      else {
         printf("[-] Invalid argument...Must pass in either 'i' or 'r'\n");
         printf("[-] EXAMPLE: ./fib 5 r\n");
         printf("Testing argv[2]: %s\n", argv[2]);
      }
   } // END else

   return 0;
}

// Recursive implementation of fibonacci
int fibRecursion(int number) {
   if(number == 0) {
      return 0;
   } // END if(number == 0)
   else if(number == 1) {
      return 1;
   } // END else if(number == 1)

   return fibRecursion(number - 1) + fibRecursion(number - 2);
}