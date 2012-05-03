#ifndef  COMMON_H
#define COMMON_H

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<malloc.h>
#include<limits.h>
#include<stdlib.h>

#define TRUE    1
#define FALSE   0
#define OK      1
#define ERROR   0
#define INFEASIBLE  -1

typedef int     Status;
typedef int     Bool;

#if INT 
    typedef int Elem_type;
#else
#if CHAR
    typedef char Elem_type;
#endif //define typedef elem_type

#endif // define common.h
    
