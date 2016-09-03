/*
 * Message.h
 *
 *  Created on: 3 sept. 2016
 *      Author: christof
 */

#ifndef COMMUNICATION_MESSAGE_HPP_
#define COMMUNICATION_MESSAGE_HPP_

namespace message {

class Message {
private:
	int m_faceCount = 0;

public:
	Message();
	virtual ~Message();
	int getFaceCount();
	void setFaceCount(int faceCount);
};

} /* namespace message */

#endif /* COMMUNICATION_MESSAGE_HPP_ */
