#include <stdio.h>
#include <math.h> 
#include <string.h> 
#include <time.h> 

/*
*/

/*
  Reference execution time of 10^9 loops based on whether the loop counter and
  dest are set as volatile (no significant difference between x32 and x64):

*/


int main() { 
  clock_t start, end;
  int diff;
  const double MSEC_IN_SEC = 1000.0;

  int dest;
 
  start = clock();
  for (int i=0; i < 1e8 ; i++) {
    memcpy(&dest, &i, sizeof dest); 
  }
  end = clock();
  diff = round(MSEC_IN_SEC / CLOCKS_PER_SEC * (double)(end - start));

  printf("\nOperation took %u milliseconds\n", diff);
  printf("\nFinal value: %u\n", dest);
  return 0;
}