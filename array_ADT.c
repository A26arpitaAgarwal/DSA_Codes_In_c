// Implementing arrays ADT
#include <stdio.h>
#include <stdlib.h>
struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

// creating array in heap
void createArray(struct myarray *s, int tsize, int usize)
{
    (*s).total_size = tsize;
    (*s).used_size = usize;
    (*s).ptr = (int *)malloc(tsize * sizeof(int)); // to allocate the memory in heap so that on request it can give us also after exiting from function
}

// taking value from the user
void value(struct myarray *s)
{
    for (int i = 0; i < s->used_size; i++)
    {
        printf("Enter the value for elemets: ");
        scanf("%d", &(s->ptr)[i]);
    }
}

// printing all those values
void show(struct myarray *s)
{
    for (int i = 0; i < s->used_size; i++)
    {
        printf("%d\t", (s->ptr)[i]);
    }
}

int main()
{
    struct myarray marks;
    createArray(&marks, 10, 2);
    value(&marks);
    show(&marks);
    return 0;
}