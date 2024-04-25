#include <stdio.h>

#define P   printf
#define S   scanf
#define R   return

typedef enum {
    union_var_none, union_var_ch, union_var_i, union_var_d
} TYPE_VAR; // перечисление

union tag_var {
    char var_ch;
    int var_i;
    double var_d;
}; // объединение

typedef struct {
    union tag_var var;
    TYPE_VAR type;
} VAR; // структура для работы с различными типами переменных через одно поле с использованием объединения

void show_var(VAR v)
{
    switch(v.type) { // вывод значения в зависимости от типа
        case union_var_ch:
            P("var_ch = %c\n", v.var.var_ch);
            break;
        case union_var_i:
            P("var_i = %d\n", v.var.var_i);
            break;
        case union_var_d:
            P("var_d = %.2f\n", v.var.var_d);
            break;
        case union_var_none:
            P("Undefined type var\n");
            break;
    }
}

int main(void)
{    
    VAR var;
    // проверка
    var.var.var_ch = 'Q';
    var.type = union_var_ch;

    show_var(var);


    R 0;

}
