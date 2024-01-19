#pragma once
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
//#include "ImageBasics.h"									//uncomment for general exercises
//#include "faceDetection.h"								//uncomment to use basic face detection
//#include "faceDetectionWithLog.h"                         //uncomment to use basic face detection with log
//#include "JPEGdebugging.h"								//uncomment to use JPEG debugging
//#include "multiCascadeClassifier.h"							//uncomment to use multiple cascade classifiers on single image
//#include "faceCounterExperimental.h"						//uncomment to use experimental face detection with log
#include "multiCascadeClassifierWEBCAM.h"					//uncomment to use multiple cascade classifiers on webcam
using namespace std;
using namespace cv;

String faceCascadePath = "C:/Users/marco/Desktop/haarcascade_frontalface_default.xml.txt";				//Stump-based 24x24 Discrete AdaBoost Frontal Face Detector
String logFilePath = "C:/Users/marco/Desktop/face_detection_log.txt";
vector<String> cascadePaths = { "C:/Users/marco/Desktop/haarcascade_frontalface_default.xml.txt",
									"C:/Users/marco/Desktop/haarcascade_profileface.xml.txt",
									"C:/Users/marco/Desktop/haarcascade_frontalface_alt.xml.txt",
									"C:/Users/marco/Desktop/haarcascade_eye.xml.txt",
									"C:/Users/marco/Desktop/haarcascade_frontalface_alt2.xml.txt" };

void main() {


	utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);

	/*
	//JPEG debug function
	FaceDetection faceDetection(imagePath, faceCascadePath, logFilePath);
	faceDetection.runFaceDetection();
	*/


	/*
	//JPEG debug function with multiple cascade classifiers
	FaceDetection faceDetection(imagePath, cascadePaths, logFilePath);
	faceDetection.runFaceDetection();
	*/


	/*
	//use basic face detection
	faceDetection();
	*/

	/*
	//Webcam function with log
	FaceDetection FaceDetection(faceCascadePath, logFilePath);
	FaceDetection.runFaceDetection();
	*/

	//Webcam function with multiple cascade classifiers using the included multiCascadeClassifierWEBCAM.h file
	FaceDetection faceDetection(cascadePaths, logFilePath); 
	faceDetection.runFaceDetection();
	}
