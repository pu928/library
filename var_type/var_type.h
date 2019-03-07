
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

// inline char *get_data_var(var_t *var);
// inline size_t get_size_var(var_t *var);
// inline size_t get_length_var(var_t *var);
#define get_data_var(var) (var ? var->data : NULL)
#define get_size_var(var) (var ? var->size : NULL)
#define get_length_var(var) (var ? var->length : NULL)

// inline int set_data_var(char *data, var_t *var);
// inline int set_size_var(size_t size, var_t *var);
// inline int set_length_var(size_t length, var_t *var);
#define set_data_var(data, var) (var->data = data)
#define set_size_var(size, var) (var->size = size)
#define set_length_var(length, var) (var->length = length)

var_t *vartype_create(char *data, int data_len);
int vartype_data_at(char *data, int data_len, size_t idx, var_t *var);
int vartype_data(char *data, int data_len, var_t *var);
void vartype_data_clean(var_t *var);
void vartype_destroy(var_t *var);

#endif // _VAR_TYPE_H
