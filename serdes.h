#ifndef _SERDES_H_
#define _SERDES_H_

#define SERIAL_BUFFER_DEFAULT_SIZE 512
#define SENTINEL_NULLPTR 0xFFFFFFFFUL 

typedef struct ser_buff_{
    void *buff;
    int size;
    int next;
}ser_buff_t;

/* Init functions */
void init_serial_buffer(ser_buff_t **buff);
void init_serial_buffer_of_size(ser_buff_t **buff, int size);

/* Serialize functions */
void serialize_uint8(ser_buff_t *buff, char data);
void serialize_int8(ser_buff_t *buff, char data);
void serialize_int32(ser_buff_t *buff, int data);
void serialize_uint32(ser_buff_t *buff, unsigned int data);
void serialize_float(ser_buff_t *buff, float data);
void serialize_double(ser_buff_t *buff, double data);
void serialize_string(ser_buff_t *buff, char *data, int size);
void serialize_uint8(ser_buff_t *buff, char data);

/* check functions */
char is_serial_buffer_empty(ser_buff_t *buff);

/* Get functions */
int get_serial_buffer_current_size(ser_buff_t *buff);
int get_serial_buffer_total_size(ser_buff_t *buff);
int get_serial_buffer_current_ptr_offset(ser_buff_t *buff);
char *get_serial_buffer_current_ptr(ser_buff_t *buff);
void serial_buffer_skip(ser_buff_t *buff, int size);
void copy_to_serial_buffer_by_offset(ser_buff_t *buff, int size, char *value, int offset);

/* de-serialize function */
void de_serialize_string(char *dest, ser_buff_t *buff, int val_size);
void de_serialize_string_by_ref(char *dest, ser_buff_t *buff, int size);

/* Free resources */
void free_serial_buffer(ser_buff_t *buff);

/* Reset Functions */
void truncate_serial_buffer(ser_buff_t **buff);
void reset_serial_buffer(ser_buff_t *buff);

/* Print functions */
void print_buffer_details(ser_buff_t *buff, const char *fn, int lineno);

#endif