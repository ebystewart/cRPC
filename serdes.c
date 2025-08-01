#include <stdio.h>
#include <stdint.h>
#include "serdes.h"

/* Init functions */
void init_serial_buffer(ser_buff_t **buff)
{
    (*buff) = (ser_buff_t *)calloc(1, sizeof(ser_buff_t));
    (*buff)->buff = calloc(1, SERIAL_BUFFER_DEFAULT_SIZE);
    (*buff)->size = SERIAL_BUFFER_DEFAULT_SIZE;
    (*buff)->next = 0; 
}

void init_serial_buffer_of_size(ser_buff_t **buff, int size)
{
    (*buff) = (ser_buff_t *)calloc(1, sizeof(ser_buff_t));
    (*buff)->buff = calloc(1, size);
    (*buff)->size = size;
    (*buff)->next = 0; 
}

/* Serialize functions */
void serialize_uint8(ser_buff_t *buff, char data);
{

}

void serialize_int8(ser_buff_t *buff, char data)
{

}

void serialize_int32(ser_buff_t *buff, int data)
{

}

void serialize_uint32(ser_buff_t *buff, unsigned int data)
{

}

void serialize_float(ser_buff_t *buff, float data)
{

}

void serialize_double(ser_buff_t *buff, double data)
{

}

void serialize_string(ser_buff_t *buff, char *data, int size)
{

}

void serialize_uint8(ser_buff_t *buff, char data)
{

}

/* check functions */
char is_serial_buffer_empty(ser_buff_t *buff)
{
    if(buff->next == 0){
        return 1;
    }
    return 0;
}

/* Get functions */
int get_serial_buffer_current_size(ser_buff_t *buff)
{
    return buff->next;
}

int get_serial_buffer_total_size(ser_buff_t *buff)
{
    return buff->size;
}

int get_serial_buffer_current_ptr_offset(ser_buff_t *buff)
{
    if(!buff)
        return -1;
    return buff->next;
}

char *get_serial_buffer_current_ptr(ser_buff_t *buff)
{
    if(!buff)
        return NULL;
    return ((buff->buff) + buff->next);
}

void serial_buffer_skip(ser_buff_t *buff, int size)
{
    int available_size = buff->size - buff->next;
    if(available_size >= size){
        buff->size += size;
        return;
    }
    while(available_size < size){
        buff->size += 4;
        available_size = buff->size - buff->next;
    }
    buff->buff = realloc(buff->buff, buff->size);
    buff->next += size;
}

void copy_to_serial_buffer_by_offset(ser_buff_t *buff, int size, char *value, int offset)
{

}

/* de-serialize function */
void de_serialize_string(char *dest, ser_buff_t *buff, int val_size)
{

}

void de_serialize_string_by_ref(char *dest, ser_buff_t *buff, int size){

}

/* Free resources */
void free_serial_buffer(ser_buff_t *buff)
{
    free(buff->buff);
    free(buff);
}

/* Reset Functions */
void truncate_serial_buffer(ser_buff_t **buff);
{

}

void reset_serial_buffer(ser_buff_t *buff)
{
    buff->next = 0;
}

/* Print functions */
void print_buffer_details(ser_buff_t *buff, const char *fn, int lineno)
{

}