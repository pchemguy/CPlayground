#include <stdio.h>
#include <math.h> 
#include <time.h> 

/*
  https://stackoverflow.com/questions/17250932/how-to-get-the-time-elapsed-in-c-in-milliseconds-windows/17252934
*/

/*
  Reference execution time of 10^9 loops based on whether the loop counter and
  dest are set as volatile (no significant difference between x32 and x64):

    dest   | loop counter | time, ms
  ----------------------------------
  volatile |   volatile   |     
  volatile |      -       |      
     -     |   volatile   |      
*/

#ifndef VOLATILE_LOOP_COUNTER
  #define VOLATILE_LOOP_COUNTER volatile
#endif
#ifndef VOLATILE_DEST
  #define VOLATILE_DEST volatile
#endif


int main() { 
  clock_t start, end;
  int diff;
  const double MSEC_IN_SEC = 1000.0;

  VOLATILE_DEST int dest;
 
  start = clock();
  for (VOLATILE_LOOP_COUNTER int i=0; i < 1e8 ; i++) {
    dest = i; 
  }
  end = clock();
  diff = round(MSEC_IN_SEC / CLOCKS_PER_SEC * (double)(end - start));

  printf("\nOperation took %u milliseconds\n", diff);
  printf("\nFinal value: %u\n", dest);
  return 0;
}