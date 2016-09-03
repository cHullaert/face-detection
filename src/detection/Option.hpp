/*
 * detectionOption.hpp
 *
 *  Created on: 1 sept. 2016
 *      Author: christof
 */

#ifndef DETECTION_OPTION_HPP_
#define DETECTION_OPTION_HPP_

namespace detection {
	struct Option {
		bool enableVideo=false;
		bool enableImg=false;
		bool enableWindow=false;

		int video=0;
		char* cascadePath;
		char* eyesCascadePath;
		char* imgPath;
	};
}

#endif /* DETECTION_OPTION_HPP_ */
