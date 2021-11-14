#include <stdio.h>
#include <time.h> 

/*
  https://pubs.opengroup.org/onlinepubs/009604499/functions/ftime.html
  https://pubs.opengroup.org/onlinepubs/009604499/basedefs/sys/timeb.h.html
  https://stackoverflow.com/questions/17250932/how-to-get-the-time-elapsed-in-c-in-milliseconds-windows/17252934
*/

/*
  Reference execution time of 10^9 loops based on whether the loop counter and
  dest are set as volatile (no significant difference between x32 and x64):

    dest   | loop counter | time, ms
  ----------------------------------
  volatile |   volatile   |     1740
  volatile |      -       |      267
     -     |   volatile   |      267
*/

#ifndef VOLATILE_LOOP_COUNTER
  #define VOLATILE_LOOP_COUNTER volatile
#endif
#ifndef VOLATILE_DEST
  #define VOLATILE_DEST volatile
#endif

/*
  struct timeb {
    time_t time;
    unsigned short millitm;
    short timezone;
    short dstflag;
  };
*/


int main() { 
  struct timeb start, end;
  int diff;
  const int MSEC_IN_SEC = 1000;

  VOLATILE_DEST int dest;
 
  ftime(&start);
  for (VOLATILE_LOOP_COUNTER int i=0; i < 1e8 ; i++) {
    dest = i; 
  }
  ftime(&end);
  diff = MSEC_IN_SEC * (end.time - start.time)
                     + (end.millitm - start.millitm);

  printf("\nOperation took %u milliseconds\n", diff);
  printf("\nFinal value: %u\n", dest);
  return 0;
}