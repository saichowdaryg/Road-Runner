/*
 * Socket_Conn.h
 *
 *  Created on: Mar 29, 2014
 *      Author: smit
 */

#ifndef SOCKET_CONN_H_
#define SOCKET_CONN_H_

#define RX_BUFF_SIZE 10000
typedef struct SocketConn
		{
	int fd;
	char rx_buffer[RX_BUFF_SIZE];
	char *rx_wr_pos;
	char *rx_rd_pos;

		} SConn ;

#endif /* SOCKET_CONN_H_ */
