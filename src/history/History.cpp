/*
 * History.cpp
 *
 *  Created on: 2 sept. 2016
 *      Author: christof
 */

#include "History.hpp"

#include <cmath>

History::History() {
	// TODO Auto-generated constructor stub

}

History::~History() {
	// TODO Auto-generated destructor stub
}

void History::push(HistoryTag tag) {
	this->m_tags.push_back(tag);
}

long unsigned int History::average(double delta) {
	int count=0;
	double sum=0;

	for (vector<HistoryTag>::reverse_iterator it = this->m_tags.rbegin(); it != this->m_tags.rend(); ++it ) {
		if(this->getTime(*it)>delta)
			break;

		sum+=(*it).data.analysedFaces.size();
		count++;
	}

	if(count>0)
		return round(sum/count);

	return 0;

}

HistoryTag History::getLast()
{
	return this->m_tags.back();
}

double History::getLastTime() {
	return this->m_tags.back().time;
}

double History::getTime(HistoryTag tag) {
	return this->getLastTime()-tag.time;
}

void History::flush(double delta) {

	int offset=-1;

	for(std::vector<HistoryTag>::iterator it = this->m_tags.begin(); it != this->m_tags.end(); ++it) {
		if(this->getTime(*it)<delta)
			break;
		offset++;
	}

	if(offset>-1)
		this->m_tags.erase(this->m_tags.begin() + 0, this->m_tags.begin() + offset );
}

double History::getTimeValue(double seconds) {
	return seconds*getTickFrequency();
}
