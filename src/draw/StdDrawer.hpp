/*
 * StdDrawer.h
 *
 *  Created on: 3 sept. 2016
 *      Author: christof
 */

#ifndef DRAW_STDDRAWER_HPP_
#define DRAW_STDDRAWER_HPP_

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "Drawer.hpp"

using namespace cv;

namespace draw {

class StdDrawer: public Drawer {
private:
	void drawRect(Mat frame, Rect rect);

public:
	StdDrawer();
	virtual ~StdDrawer();
	virtual void draw(Mat frame, History * history);
};

} /* namespace draw */

#endif /* DRAW_STDDRAWER_HPP_ */
