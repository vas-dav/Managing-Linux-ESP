#include "prompt.h"
#include "random_data.h"

int
main (int argc, char *argv[])
{
  RANDOM_DATA *user_values = check_for_arguments (argc, argv);
  validate_data (user_values);
  generate_rand_values (user_values);
  cleanup (user_values);
  return 0;
}
