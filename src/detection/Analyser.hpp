/*
 * DetectionAnalyser.h
 *
 *  Created on: 2 sept. 2016
 *      Author: christof
 */

#ifndef DETECTION_ANALYSER_HPP_
#define DETECTION_ANALYSER_HPP_

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "Data.hpp"

using namespace cv;

namespace detection {
	class Analyser {
	private:
		bool m_useEyes = true;

	public:
		Analyser();
		virtual ~Analyser();
		void analyse(Data & data);
		bool getUseEyes();
		void setUseEyes(bool useEyes);
	};
}

#endif /* DETECTION_ANALYSER_HPP_ */
