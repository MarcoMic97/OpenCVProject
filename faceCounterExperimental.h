#pragma once
#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <unordered_set>

using namespace cv;

class FaceDetection {
public:
    FaceDetection(const String& faceCascadePath, const String& logFilePath);
    int runFaceDetection();

private:
    CascadeClassifier faceCascade;
    VideoCapture cap;
    String logFilePath;
    std::unordered_set<int> uniqueFaceIds; // Keep track of unique faces detected
    std::ofstream logFile;
    Rect lastDetectedFace; // Store the last detected face rectangle
    int totalUniqueFaces; // Counter for total number of unique faces
};

FaceDetection::FaceDetection(const String& faceCascadePath, const String& logFilePath)
    : logFilePath(logFilePath), totalUniqueFaces(0) {

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

        if (!faces.empty()) {
            const Rect& faceRect = faces[0]; // Consider the first detected face
            int faceId = static_cast<int>(faceRect.y + faceRect.height / 2); // Unique identifier for each face

            if (uniqueFaceIds.find(faceId) == uniqueFaceIds.end()) {
                // New face detected, not counted before
                rectangle(frame, faceRect, Scalar(0, 255, 0), 2);
                uniqueFaceIds.insert(faceId);
                lastDetectedFace = faceRect;

                // Increment the total number of unique faces
                totalUniqueFaces++;

                // Write the current frame's face count to the log file
                logFile << "Frame " << cap.get(CAP_PROP_POS_FRAMES) << ": New face introduced. Total unique faces: " << totalUniqueFaces << std::endl;
            }
            else {
                // Face already counted, keep the square on the face
                rectangle(frame, lastDetectedFace, Scalar(0, 255, 0), 2);
            }
        }
        else {
            // No face detected, consider it as the face leaving the frame
            uniqueFaceIds.clear();
        }

        imshow("Face Detection", frame);

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
