#ifndef _RPC_COMMON_H_
#define _RPC_COMMON_H_
	
#define SERVER_IP	"127.0.0.1"
#define SERVER_PORT	2000

typedef enum {
	RPC_REQ,
	RPC_REPLY,
	RPC_AUTH
} rpc_enum_t;

typedef struct _rpc_hdr{
	unsigned int tid;
	unsigned int rpc_proc_id;
	rpc_enum_t msg_type; 
	unsigned int payload_size;
} rpc_hdr_t;

typedef struct _client_params{
	unsigned int recv_buff_size;
	ser_buff_t *recv_ser_b;
} client_param_t;

unsigned int
serialized_rpc_hdr_size();

#endif