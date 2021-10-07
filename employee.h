#include <stdio.h>
#include <stddef.h>

typedef struct {
    long number;
    char *name;
    char *phone;
    long salary;
} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;