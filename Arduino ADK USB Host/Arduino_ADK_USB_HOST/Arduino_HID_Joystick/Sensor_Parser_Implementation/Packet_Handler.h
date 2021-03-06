/*
 * Packet_Handler.h
 *
 *  Created on: Jul 24, 2013
 *      Author: fjpapin
 */

#ifndef PACKET_HANDLER_H_
#define PACKET_HANDLER_H_

#include "Network_Protocol.h"

#define PACKET_TIMEOUT				1000 //100ms timeout

//! Internal State Machine
#define PACKET_WAIT_PHASE_1 		0
#define PACKET_WAIT_PHASE_2 		1
#define PACKET_WAIT_HEADER			2
#define PACKET_WAIT_PACKET			3
#define PACKET_WAIT_SUM_A			4
#define PACEKT_WAIT_SUM_B			5

/**
 * This is the packet handler structure.
 * It handles the incoming packets based in the ids, and the args.
 */
struct packet_handler_t {

	byte packet_id;
	void (* handler)(void* arg, byte packet_id, byte packet_ver, void* packet_data);
	void* args;
};

/**
 * This class contains the methods that handle and decode the packets,
 * as they come in the state machine.
 */
class PACKET_HANDLER {

	private:

		//! Variables used in the class.

		byte _phase;
		byte _data_in;
		byte _data_expected;
		byte _sum_A;
		byte _sum_B;
		byte _packet_ver;



		//! The handler table that contains
		//! packet handlers
		struct packet_handler_t *_handler_table;


		//! the buffer definition
		union {
			byte bytes[1];
			struct packet_header_t header;
		} _buf;

		/**
		 * The function that will move the state machine forwards.
		 * @param data_byte - byte
		 */
		void _move_state(byte data_byte);

	public:

		byte _packet_id;
		byte _guard_bool;

		unsigned long _last_received;	//! last received time stamp.

		/**
		 * The overwritten default constructor,
		 * that takes in a handler table.
		 * @param handler_table - packet_handler_t
		 */
		PACKET_HANDLER(void* handler_table);

		/**
		 * This is the poll loop for the incoming bytes.
		 */
		void poll(void);

};

#endif /* PACKET_HANDLER_H_ */
