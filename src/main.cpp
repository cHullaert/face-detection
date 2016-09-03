//============================================================================
// Name        : faceDetection.cpp
// Author      : Christof
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "detection/Analyser.hpp"
#include "detection/Option.hpp"
#include "detection/Service.hpp"
#include "draw/Drawer.hpp"
#include "draw/StdDrawer.hpp"
#include "history/History.hpp"

using namespace draw;
using namespace detection;
using namespace std;
using namespace cv;

void displayFrame(Mat frame, History * history, Drawer* drawer, Option& options)
{
	if(options.enableWindow) {
		drawer->draw(frame, history);
	    imshow( "Detected Face", frame);
	}
}

int parseCommandLine(int argc, char* argv[], Option & options)
{
	options.enableVideo=false;
	options.enableWindow=false;
	options.enableImg=false;

	char param;
	if(argc==1)
		return 1;

	while((param=getopt(argc,argv,"c:e:wv:i:"))!=-1)
	{
		switch(param)
		{
		case 'c':
			options.cascadePath=optarg;
			break;
		case 'e':
			options.eyesCascadePath=optarg;
			break;
		case 'w':
			options.enableWindow=true;
			break;
		case 'v':
			options.enableVideo=true;
			options.video=atoi(optarg);
			break;
		 case 'i':
			options.enableImg=true;
			options.imgPath=optarg;
			break;
		 default:
			return 2;
		}
	}

	return 0;
}

int main(int argc,char *argv[])
{
	Option options;
	cout << "parse command\n";
	if(parseCommandLine(argc, argv, options)!=0)
		return 4;

	cout << "create window\n";
	if(options.enableWindow)
		namedWindow( "Detected Face", 1 );

	cout << "open cascade" << options.cascadePath << "\n";
    Service service;
    Analyser analyser;

    if(!service.createEyesCascade(options.eyesCascadePath))
    	return 1;
    if(!service.createFaceCascade(options.cascadePath))
    	return 2;
    if(!service.createClassifiers())
		return 3;

	Mat frame;
	History history;
	Drawer * drawer=new StdDrawer();

	if(options.enableVideo)
	{
		VideoCapture cap(0);
	    if(!cap.isOpened())
			return 1;
		for(;;)
		{
			cap >> frame;
			HistoryTag tag;
			tag.time=getTickCount();
			service.detectMultiscale(frame, tag.data);
			analyser.analyse(tag.data);

			history.push(tag);

			displayFrame(frame, &history, drawer, options);

			history.flush(history.getTimeValue(10.0));
			if(cv::waitKey(30) >= 0)
				break;

		}
	}
	else if(options.enableImg)
	{
	    frame = imread(options.imgPath, CV_LOAD_IMAGE_COLOR);

		HistoryTag tag;
		tag.time=getTickCount();
		service.detectMultiscale(frame, tag.data);
		analyser.analyse(tag.data);

		history.push(tag);

		displayFrame(frame, &history, drawer, options);

		waitKey(0);
	}

	cv::destroyAllWindows();
    return 0;
}
