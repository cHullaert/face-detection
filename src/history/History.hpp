/*
 * History.h
 *
 *  Created on: 2 sept. 2016
 *      Author: christof
 */

#ifndef HISTORY_HISTORY_HPP_
#define HISTORY_HISTORY_HPP_

#include <vector>

#include "../detection/Data.hpp"

using namespace std;
using namespace detection;

struct HistoryTag {
	double time;
	Data data;
};

class History {
private:
	std::vector<HistoryTag> m_tags;
	double getLastTime();
	double getTime(HistoryTag tag);

public:
	History();
	virtual ~History();
	long unsigned int average(double delta);
	void flush(double delta);
	void push(HistoryTag tag);
	double getTimeValue(double seconds);
	HistoryTag getLast();
};

#endif /* HISTORY_HISTORY_HPP_ */
