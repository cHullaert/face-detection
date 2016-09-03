/*
 * DetectionData.hpp
 *
 *  Created on: 2 sept. 2016
 *      Author: christof
 */

#ifndef DETECTION_DATA_HPP_
#define DETECTION_DATA_HPP_

#include <iostream>
#include <vector>

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

namespace detection {
	struct Face {
		Rect face;
		std::vector<Rect> eyes;
	};

	struct Data {
		std::vector<Rect> faces;
		std::vector<Rect> eyes;


		std::vector<Face> analysedFaces;
	};
}

#endif /* DETECTION_DATA_HPP_ */
