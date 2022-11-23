#ifndef PROMPT_H
#define PROMPT_H

#include "common.h"
#include "random_data.h"
#include <stdio.h>
#include <stdlib.h>

RANDOM_DATA *check_for_arguments (int args, char *argv[]);

void cleanup (RANDOM_DATA *data);

#endif /* PROMPT_H */