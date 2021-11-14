#include <stdio.h>
#include <math.h> 
#include <time.h> 

/*
*/

/*
  When optimization is not enabled, volatile option is unnecessary:
    time(volatile+opt)=time(no volatile + no opt)
*/


int main() { 
  clock_t start, end;
  int diff;
  const double MSEC_IN_SEC = 1000.0;

  int dest;
 
  start = clock();
  for (int i=0; i < 1e8 ; i++) {
    dest = i; 
  }
  end = clock();
  diff = round(MSEC_IN_SEC / CLOCKS_PER_SEC * (double)(end - start));

  printf("\nOperation took %u milliseconds\n", diff);
  printf("\nFinal value: %u\n", dest);
  return 0;
}