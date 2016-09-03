/*
 * Drawer.h
 *
 *  Created on: 3 sept. 2016
 *      Author: christof
 */

#ifndef DRAW_DRAWER_HPP_
#define DRAW_DRAWER_HPP_

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "../history/History.hpp"

using namespace cv;

namespace draw {
	class Drawer {
	public:
		Drawer();
		virtual ~Drawer();
		virtual void draw(Mat frame, History * history)=0;
	};
}

#endif /* DRAW_DRAWER_HPP_ */
