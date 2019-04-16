
#ifndef _VAR_TYPE_H
#define _VAR_TYPE_H

#include<stdio.h>

typedef struct _var_type{
	size_t size;
	size_t length;
	char *data;
}var_t;

#define VAR_TYPE_BLOCK_SIZE	4

#define INIT_VAR_TYPE   {0, 0, NULL}

#define get_data_var(var) (var ? var->data : NULL)
#define get_size_var(var) (var ? var->size : NULL)
#define get_length_var(var) (var ? var->length : NULL)

#define set_data_var(data, var) (var->data = data)
#define set_size_var(size, var) (var->size = size)
#define set_length_var(length, var) (var->length = length)

int add_data_at_var(char *data, int data_len, size_t idx, var_t *var);
int add_data_var(char *data, int data_len, var_t *var);
void clear_data_var(var_t *var);
void clear_var_type(var_t *var);

#endif // _VAR_TYPE_H
