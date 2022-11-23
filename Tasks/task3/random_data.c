#include "random_data.h"
#include "common.h"
#include <stdbool.h>

void
validate_data (RANDOM_DATA *d)
{
  if (d == NULL)
    {
      ERROR ("Wrong command line arguments");
      exit (1);
    }
  assert (d->amount <= (d->max - d->min + 1));
  assert (d->amount > 0);
  assert (d->max != d->min);
  assert (d->max > d->min);
}

void
generate_rand_values (RANDOM_DATA *d)
{
  srand (time (NULL));
  int buff, loop_counter = 0;
  int *values = malloc (sizeof (int) * d->amount);
  for (size_t i = 0; i < d->amount; i++)
  {
    printf("%d ", values[i]);
  }
  
  bool found;
  printf ("%d Random numbers in range[%d - %d]:\n", d->amount, d->min, d->max);
  while (loop_counter < d->amount)
    {
      buff = rand () % (d->max - d->min + 1) + d->min;
      found = false;
      /* Make sure the random number hasnt already been generated */
      for (int i = 0; i < d->amount; i++)
        {
          if (values[i] == buff)
            {
              found = true;
              break;
            }
        }

      /* Random value genertaed */
      if (!found)
        {
          loop_counter++;
          values[loop_counter] = buff;
          printf ("(%03d). %5d\n", loop_counter, buff);
        }
    }
  free (values);
}
