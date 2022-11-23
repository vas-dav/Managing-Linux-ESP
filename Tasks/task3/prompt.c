#include "prompt.h"

static const char *messages[3] = { "Enter min. value", "Enter max. value",
                                   "Enter amount of random digits" };

static int
get_int (const char *message)
{
  int value;
  printf ("%s\n", message);
  if (scanf ("%d", &value) != 1)
    {
      ERROR ("Value must be a digit.");
      exit (1);
    }
  return value;
}

static int
get_v_from_args (char *s)
{
  int value;
  if (sscanf (s, "%d", &value) != 1)
    {
      ERROR ("One of the arguments is not a digit");
      exit (1);
    }
  return value;
}

static RANDOM_DATA *
fulfill_args (int args, char *argv[])
{
  RANDOM_DATA *t = malloc (sizeof (RANDOM_DATA));
  switch (args)
    {
    case 1:
      t->min = get_int (messages[MIN]);
      t->max = get_int (messages[MAX]);
      t->amount = get_int (messages[AMOUNT]);
      break;
    case 2:
      t->min = get_v_from_args (argv[1]);
      t->max = get_int (messages[MAX]);
      t->amount = get_int (messages[AMOUNT]);
      break;
    case 3:
      t->min = get_v_from_args (argv[1]);
      t->max = get_v_from_args (argv[2]);
      t->amount = get_int (messages[AMOUNT]);
      break;
    case 4:
      t->min = get_v_from_args (argv[1]);
      t->max = get_v_from_args (argv[2]);
      t->amount = get_v_from_args (argv[3]);
      break;
    default:
      break;
    }
  return t;
}

RANDOM_DATA *
check_for_arguments (int args, char *argv[])
{
  switch (args)
    {
    case 1:
      ERROR ("No values provided.")
      return fulfill_args (1, argv);
    case 2:
      ERROR ("Only min. value provided.")
      return fulfill_args (2, argv);
    case 3:
      ERROR ("No amount value provided.")
      return fulfill_args (3, argv);
    case 4:
      return fulfill_args (4, argv);
    default:
      break;
    }
  return NULL;
}

void
cleanup (RANDOM_DATA *data)
{
  if (data)
    {
      free (data);
    }
}
