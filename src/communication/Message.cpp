/*
 * Message.cpp
 *
 *  Created on: 3 sept. 2016
 *      Author: christof
 */

#include "Message.hpp"

namespace message {

Message::Message() {
	// TODO Auto-generated constructor stub

}

Message::~Message() {
	// TODO Auto-generated destructor stub
}

int Message::getFaceCount() {
	return this->m_faceCount;
}


void Message::setFaceCount(int faceCount) {
	this->m_faceCount=faceCount;
}

} /* namespace message */
