#include <stdio.h>
#include "cpf.h"
#include "full_hashtable.h"
#include "hashfunc.h"
#include "hashtable.h"
#include "linkedlist.h"
#include "simple_hashtable.h"


int hashfunc(); 
int simple_ht(); 
int simple_ll(); 
int full_ht(); 


int main()
{
     hashfunc(); // Parte 1 - Problema 1
     simple_ht(); // Parte 1 - Problema 2
     simple_ll(); // Parte 2 - Problema 1
     full_ht(); // Parte 2 - Problema 2


return 0;
}
