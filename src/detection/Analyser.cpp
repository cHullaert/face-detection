/*
 * DetectionAnalyser.cpp
 *
 *  Created on: 2 sept. 2016
 *      Author: christof
 */

#include "Analyser.hpp"

namespace detection {
	Analyser::Analyser() {
	}

	Analyser::~Analyser() {
	}

	void Analyser::analyse(Data & data) {

		//(x−cx)²/rx²+(y−cy)²/ry²≤1

		std::vector<Rect> localEyes=data.eyes;

		for (std::vector<Rect>::iterator itFace = data.faces.begin() ; itFace != data.faces.end(); ++itFace)
		{
			Face sFace;
			sFace.face=*itFace;
			Point centerFace(sFace.face.x + sFace.face.width*0.5, sFace.face.y + sFace.face.height*0.5);

			double square_w=pow(sFace.face.width, 2.0);
			double square_h=pow(sFace.face.height, 2.0);

			for(int i=localEyes.size()-1; i>=0; i--)
			{
				Point centerEye(localEyes[i].x + localEyes[i].width*0.5, localEyes[i].y + localEyes[i].height*0.5);
				if(pow((centerEye.x-centerFace.x), 2.0)/square_w+pow((centerEye.y-centerFace.y), 2.0)/square_h<=1)
				{
					sFace.eyes.push_back(localEyes[i]);
					localEyes.erase(localEyes.begin()+i);
				}
			}

			if((sFace.eyes.size()>=2) || (this->getUseEyes()))
				data.analysedFaces.push_back(sFace);
		}

	}

	bool Analyser::getUseEyes() {
		return this->m_useEyes;
	}

	void Analyser::setUseEyes(bool useEyes) {
		this->m_useEyes=useEyes;
	}
}
