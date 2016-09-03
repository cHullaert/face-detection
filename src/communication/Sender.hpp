/*
 * MessageSender.h
 *
 *  Created on: 3 sept. 2016
 *      Author: christof
 */

#ifndef COMMUNICATION_SENDER_HPP_
#define COMMUNICATION_SENDER_HPP_

#include "Message.hpp"

namespace message {

class Sender {
public:
	Sender();
	virtual ~Sender();
	virtual void send(Message message)=0;
};

} /* namespace draw */

#endif /* COMMUNICATION_SENDER_HPP_ */
