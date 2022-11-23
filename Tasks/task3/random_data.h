#ifndef RANDOM_DATA_H
#define RANDOM_DATA_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct random_data_s
{
  int min;
  int max;
  int amount;
} RANDOM_DATA;

void validate_data (RANDOM_DATA *d);

void generate_rand_values (RANDOM_DATA *d);

#endif /* RANDOM_DATA_H */