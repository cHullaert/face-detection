/*
 * StdDrawer.cpp
 *
 *  Created on: 3 sept. 2016
 *      Author: christof
 */

#include "StdDrawer.hpp"

namespace draw {

StdDrawer::StdDrawer() {
	// TODO Auto-generated constructor stub

}

StdDrawer::~StdDrawer() {
	// TODO Auto-generated destructor stub
}

void StdDrawer::draw(Mat frame, History * history) {
   // Draw circles on the detected faces
	for( long unsigned int i = 0; i < history->getLast().data.analysedFaces.size(); i++ )
	{
		Rect face=history->getLast().data.analysedFaces[i].face;
		if(history->getLast().data.analysedFaces[i].eyes.size()>=2) {
			drawRect(frame, history->getLast().data.analysedFaces[i].eyes.front());
			drawRect(frame, history->getLast().data.analysedFaces[i].eyes.back());
		}
		drawRect(frame, face);
	}

	char text[20];
	sprintf(text, "faces: %lu", history->getLast().data.analysedFaces.size());
	putText(frame, text, Point2f(10, 30), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 0), 2);

	if(history!=NULL) {
		sprintf(text, "average (1 sec): %lu", history->average(history->getTimeValue(1.0)));
		putText(frame, text, Point2f(10, 60), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 0), 2);
		sprintf(text, "average (3 sec): %lu", history->average(history->getTimeValue(3.0)));
		putText(frame, text, Point2f(10, 80), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 0), 2);
		sprintf(text, "average (5 sec): %lu", history->average(history->getTimeValue(5.0)));
		putText(frame, text, Point2f(10, 100), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 0), 2);
	}
}

void StdDrawer::drawRect(Mat frame, Rect rect) {
    Point center(rect.x + rect.width*0.5, rect.y + rect.height*0.5 );
    ellipse(frame, center, Size(rect.width*0.5, rect.height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
}

} /* namespace draw */
