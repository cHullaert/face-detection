/*
 * DetectionService.h
 *
 *  Created on: 2 sept. 2016
 *      Author: christof
 */

#ifndef DETECTION_SERVICE_HPP_
#define DETECTION_SERVICE_HPP_

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "Data.hpp"

using namespace cv;

namespace detection {
	class Service {
	private:
		cv::FileStorage * m_faceFs=NULL;
		cv::FileStorage * m_eyesFs=NULL;
		CascadeClassifier m_faceClassifier;
		CascadeClassifier m_eyesClassifier;

		void detectMultiscale(Mat frame, CascadeClassifier cascade, std::vector<Rect> & faces);

	public:
		Service();
		virtual ~Service();

		bool createClassifiers();
		bool createEyesCascade(char * path);
		bool createFaceCascade(char * path);

		void detectMultiscale(Mat frame, Data & datas);
	};
}

#endif /* DETECTION_SERVICE_HPP_ */
