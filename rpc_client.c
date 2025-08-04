#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "serdes.h"
#include "rpc_common.h"

client_param_t client_param;

int
client_rpc_send_rcv (ser_buff_t *in_b, ser_buff_t *out_b){
	
	struct sockaddr_in dest;
	int sockfd = 0, rc = 0;
	int addr_len;

	dest.sin_family = AF_INET;
	dest.sin_port = SERVER_PORT;
	struct hostent *host = (struct hostent *)gethostbyname(SERVER_IP);
	dest.sin_addr = *((struct in_addr *)host->h_addr);
	addr_len = sizeof(struct sockaddr);
	
	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(sockfd == -1){
		printf("socket creation failed\n");
		return -1;
	}

	rc = sendto(sockfd, in_b->buff, get_serialize_buffer_size(in_b), 0,
		(struct sockaddr *)&dest, sizeof(struct sockaddr));

	printf("%s() : %d bytes sent\n", __FUNCTION__, rc);
	free_serialize_buffer(in_b);

	if(get_serial_buffer_current_size(client_param.recv_ser_b) < 1024){
		printf("%s() : Warning : Recv buffer size may be insufficient, size = %d\n", 
			__FUNCTION__, get_serial_buffer_current_size(client_param.recv_ser_b));
	}

	rc = recvfrom(sockfd, (char *)out_b->buff, get_serialize_buffer_length(out_b), 0, 
			(struct sockaddr *)&dest, &addr_len);

	printf("%s() : %d bytes recieved\n", __FUNCTION__, rc); 
		      
	return rc;
}