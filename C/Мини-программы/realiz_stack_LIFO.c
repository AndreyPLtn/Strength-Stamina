#include <stdio.h>
#include <stdlib.h>

#define P   printf
#define S   scanf
#define R   return

typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ; // объявление структуры OBJ с данными data и указателем на следующий элемент next

OBJ* push(OBJ* top , int data) // добавление элемента на вершину стека
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    
    R ptr;
}

OBJ* pop(OBJ* top) // удаление элемента из вершины стека с освобождением памяти
{
    if(top == NULL)
        R top;
    
    P("Deleted: %d\n", top->data);
    OBJ* ptr_next = top->next;
    free(top);

    R ptr_next;
}

void show(const OBJ* top) // вывод содержимого стека, начиная с вершины
{
    const OBJ* current = top;
    while(current != 0) {
        P("%d\n", current->data);
        current = current->next;
    }
}

int main(void)
{    
    OBJ* top = NULL;
    // проверка
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);

    show(top);

    while(top)
        top = pop(top);
    
    R 0;
}
