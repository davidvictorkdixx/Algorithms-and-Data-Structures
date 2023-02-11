#ifndef _AUXILIARY_H
#define _AUXILIARY_H

#include "nodeAdtSet.h"
//#include "vectorAdtSet.h"


set_t getUniverseSet(void);
set_t getFilteredSet(void);
void printSet(set_t);
void errorMessage(char *);
set_t unionSet(set_t, set_t);
set_t interSet(set_t, set_t);
set_t diffSet(set_t, set_t);
set_t compSet(set_t, set_t);


#endif

