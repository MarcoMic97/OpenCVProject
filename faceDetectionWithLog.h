#pragma once
#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

class FaceDetection {
public:
    FaceDetection(const String& faceCascadePath, const String& logFilePath);
    int runFaceDetection();

private:
    CascadeClassifier faceCascade;
    VideoCapture cap;
    String logFilePath;
    int totalDetectedFaces;
    std::ofstream logFile;
};

FaceDetection::FaceDetection(const String& faceCascadePath, const String& logFilePath)
    : logFilePath(logFilePath), totalDetectedFaces(0) {

    // Load the face cascade classifier
    if (!faceCascade.load(faceCascadePath)) {
        std::cerr << "Error: Could not load face cascade classifier." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Open the webcam
    cap.open(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open webcam." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Open the log file for writing
    logFile.open(logFilePath);
    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open log file." << std::endl;
        exit(EXIT_FAILURE);
    }
}

int FaceDetection::runFaceDetection() {
    namedWindow("Face Detection", WINDOW_NORMAL);

    while (true) {
        Mat frame;
        cap >> frame;

        if (frame.empty()) {
            std::cerr << "Error: Could not read frame." << std::endl;
            break;
        }

        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        std::vector<Rect> faces;
        faceCascade.detectMultiScale(gray, faces, 1.3, 5);

        for (const auto& faceRect : faces) {
            rectangle(frame, faceRect, Scalar(0, 255, 0), 2);
        }

        imshow("Face Detection", frame);

        int numFaces = static_cast<int>(faces.size());
        totalDetectedFaces += numFaces;

        // Write the current frame's face count to the log file
        logFile << "Frame " << cap.get(CAP_PROP_POS_FRAMES) << ": " << numFaces << " faces" << std::endl;

        std::cout << "Number of Faces: " << numFaces << " (Total: " << totalDetectedFaces << ")" << std::endl;

        if (waitKey(1) == 27) {
            break;
        }
    }

    cap.release();
    destroyAllWindows();
    logFile.close();

    return 0;
}

// Function to be called from the main program
void faceDetection(const String& faceCascadePath, const String& logFilePath) {
    FaceDetection faceDetectionObj(faceCascadePath, logFilePath);
    faceDetectionObj.runFaceDetection();
}
