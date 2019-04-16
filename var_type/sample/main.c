#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/time.h>

#include<time.h>

#include"var_type.h"

var_t g_buffer = INIT_VAR_TYPE;


// #define GET_ELAPSE_USEC(_start, _end) \
// ((((*((struct timespec *)_end))->tv_sec * 1000000L) + ((*((struct timespec *)_end))->tv_nsec / 1000L)) \
// - (((*((struct timespec *)_start))->tv_sec * 1000000L) + ((*((struct timespec *)_start))->tv_nsec / 1000L)))

#define GET_ELAPSE_USEC(start, end) \
(((end.tv_sec * 1000000L) + (end.tv_nsec / 1000L)) \
- ((start.tv_sec * 1000000L) + (start.tv_nsec / 1000L)))


// long get_elapse_usec(struct timespec *begin, struct timespec *end)
// {
// 	return ((end->tv_sec * 1000000L) + (end->tv_nsec / 1000L))
// 			- ((begin->tv_sec * 1000000L) + (begin->tv_nsec / 1000L));
// }

int main()
{
	size_t total_len;
	size_t need_size;
	char *pTmp;

	int len, alphabat = 0, i = 0;
	char szTmp[4] = {'\0',};

	// struct timeval bgn, ed;
	double diff;

	struct timespec start, end;
	struct timespec _start, _end;


	clock_gettime(CLOCK_MONOTONIC, &start);


	while(i++ < 100000000){
#if 0
		if(alphabat > 25){
			alphabat = 0;
			// clear_var_type(&g_buffer);
			if(g_buffer.data)
				free(g_buffer.data);
			g_buffer.data = NULL;
			g_buffer.size = 0;
			g_buffer.length = 0;
		}

		szTmp[0] = 97 + alphabat;
		// printf("%s\n", szTmp);
		// len = add_data_var(szTmp, 1, &g_buffer);
		// len = add_data_at_var(szTmp, 1, alphabat, &g_buffer);
		// printf("(%zu)%.*s\n", get_size_var(&g_buffer), (int)get_length_var(&g_buffer), 
		//         get_data_var(&g_buffer));



		total_len = alphabat + 1;

		if((int)g_buffer.size < total_len){

			need_size = total_len + (VAR_TYPE_BLOCK_SIZE - (total_len % VAR_TYPE_BLOCK_SIZE));
			
			// printf("%s,%d\n", pTmp?pTmp:"null", new_size);

			pTmp = (char *)malloc(need_size);
			if(!pTmp){
				return -1;
			}

			if(g_buffer.data && g_buffer.length > 0){
				memcpy(pTmp, g_buffer.data, g_buffer.length);
				free(g_buffer.data);
			}

			g_buffer.data = pTmp;
			g_buffer.size = need_size; 
		}

		memcpy(&g_buffer.data[alphabat], szTmp, (size_t)1);
		if(g_buffer.length < total_len)
			g_buffer.length = total_len;

		// var->data[var->length] = '\0';

		len = (int)g_buffer.length;
#else
		if(alphabat > 25){
			alphabat = 0;
			clear_var_type(&g_buffer);
		}

		szTmp[0] = 97 + alphabat;
		len = add_data_at_var(szTmp, 1, alphabat, &g_buffer);
		// printf("(%zu)%.*s\n", get_size_var(&g_buffer), (int)get_length_var(&g_buffer), 
		//         get_data_var(&g_buffer));

#endif

		alphabat++;
		
	}

	// gettimeofday(&ed, NULL);
	clock_gettime(CLOCK_MONOTONIC, &end);

	// diff = ed.tv_sec + (ed.tv_usec / 1000000.0) - bgn.tv_sec - bgn.tv_usec / 1000000.0;
	// printf("%f\n", diff);

	// printf("%f\n", (double)get_elapse_usec(&start, &end) / 1000000);
	printf("%f\n", (double)GET_ELAPSE_USEC(start, end) / 1000000);




	return 0;
}
