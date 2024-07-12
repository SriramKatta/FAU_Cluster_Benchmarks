#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "timing.h"

int main() {
  unsigned int seed = 1;
  long hist[16], j, n;
  int i;
  double wcstart,wcend,ct;
  n=2*pow(10,9);
  for(i=0; i<16; ++i)
    hist[i]=0;

  wcstart = getTimeStamp();

  for(j=0; j<n; ++j) {
    hist[rand_r(&seed) & 0xf]++;
  }

  wcend = getTimeStamp();

  for(i=0; i<16; ++i) {
    printf("hist[%d]=%ld\n",i,hist[i]);
  }

  printf("Time: %lf sec\n",wcend-wcstart);

  return 0;
}

