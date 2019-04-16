
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"var_type.h"


// char *get_data_var(var_t *var)
// {
// 	return var?var->data:NULL;
// }

// size_t get_size_var(var_t *var)
// {
// 	return var?var->size:0;
// }

// size_t get_length_var(var_t *var)
// {
// 	return var?var->length:0;
// }


// int set_data_var(char *data, var_t *var)
// {
// 	if(var){
// 		var->data = data;
// 	}
// 	return 0;
// }

// int set_size_var(size_t size, var_t *var)
// {
// 	if(var){
// 		var->size = size;
// 	}
// 	return 0;
// }

// int set_length_var(size_t length, var_t *var)
// {
// 	if(var){
// 		var->length = length;
// 	}
// 	return 0;
// }

int _increase_var_type(size_t need_size, var_t *var)
{
	register char *pTmp;

	need_size += (VAR_TYPE_BLOCK_SIZE - (need_size % VAR_TYPE_BLOCK_SIZE));
	
	// printf("%s,%d\n", pTmp?pTmp:"null", new_size);

	pTmp = (char *)malloc(need_size);
	if(!pTmp)
		return -1;
	
	if(var->data && var->length > 0){
		memcpy(pTmp, var->data, var->length);
		free(var->data);
	}

	var->data = pTmp;
	var->size = need_size;

	return 0;
}

int add_data_at_var(char *data, int data_len, size_t idx, var_t *var)
{

	register size_t total_len;

	// printf("%u,%d,%d\n", var->size, var->len, data_len);

	total_len = idx + data_len;

	if((int)var->size < total_len){
		_increase_var_type(total_len, var);
	}

	memcpy(&var->data[idx], data, (size_t)data_len);
	if(var->length < total_len)
		var->length = total_len;

	// var->data[var->length] = '\0';

	return (int)var->length;

}

int add_data_var(char *data, int data_len, var_t *var)
{

	register size_t total_len;

	// printf("%u,%d,%d\n", var->size, var->len, data_len);

	total_len = var->length + data_len;

	if((int)var->size < total_len)
		_increase_var_type(total_len, var);
	
	memcpy(&var->data[var->length], data, (size_t)data_len);
	var->length = total_len;

	return (int)var->length;

}

void clear_data_var(var_t *var)
{
	var->length = 0;
}

void clear_var_type(var_t *var)
{
	if(var){
		if(var->data){
			free(var->data);
		}
		var->length = 0;
		var->size = 0;
	}

	return ;
}

