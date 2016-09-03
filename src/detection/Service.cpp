/*
 * DetectionService.cpp
 *
 *  Created on: 2 sept. 2016
 *      Author: christof
 */

#include "Service.hpp"

#include <iostream>

namespace detection {
	Service::Service() {

	}

	Service::~Service() {
	}

	bool Service::createClassifiers() {
		if (!this->m_faceClassifier.read(this->m_faceFs->getFirstTopLevelNode()))
			return false;
		if (!this->m_eyesClassifier.read(this->m_eyesFs->getFirstTopLevelNode()))
			return false;

		return true;
	}

	bool Service::createEyesCascade(char * path) {
		this->m_eyesFs=new FileStorage(path, cv::FileStorage::READ);
		return this->m_eyesFs->isOpened();
	}

	bool Service::createFaceCascade(char * path) {
		this->m_faceFs=new FileStorage(path, cv::FileStorage::READ);
		return this->m_faceFs->isOpened();
	}

	void Service::detectMultiscale(Mat frame, CascadeClassifier cascade, std::vector<Rect> & faces)
	{
		cascade.detectMultiScale(frame, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
	}

	void Service::detectMultiscale(Mat frame, Data & datas)
	{
	   // Detect faces
		Mat gray;
		cvtColor(frame, gray, COLOR_BGR2GRAY, 0);
		detectMultiscale(gray, this->m_faceClassifier, datas.faces);
		detectMultiscale(gray, this->m_eyesClassifier, datas.eyes);
	}
}

