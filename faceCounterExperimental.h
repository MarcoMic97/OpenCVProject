#pragma once
#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <unordered_set>

using namespace cv;
using namespace std;

class FaceDetection {
public:
    FaceDetection(const String& faceCascadePath, const String& logFilePath);
    int runFaceDetection();

private:
    CascadeClassifier faceCascade;
    VideoCapture cap;
    String logFilePath;
    unordered_set<int> uniqueFaceIds; // Keep track of unique faces detected
    ofstream logFile;
    Rect lastDetectedFace; // Store the last detected face rectangle
    int totalUniqueFaces; // Counter for total number of unique faces
};

FaceDetection::FaceDetection(const String& faceCascadePath, const String& logFilePath)
    : logFilePath(logFilePath), totalUniqueFaces(0) {

    // Load the face cascade classifier
    if (!faceCascade.load(faceCascadePath)) {
        cerr << "Error: Could not load face cascade classifier." << endl;
        exit(EXIT_FAILURE);
    }

    // Open the webcam
    cap.open(0);
    if (!cap.isOpened()) {
        cerr << "Error: Could not open webcam." << endl;
        exit(EXIT_FAILURE);
    }

    // Open the log file for writing
    logFile.open(logFilePath);
    if (!logFile.is_open()) {
        cerr << "Error: Could not open log file." << endl;
        exit(EXIT_FAILURE);
    }
}

int FaceDetection::runFaceDetection() {
    namedWindow("Face Detection", WINDOW_NORMAL);

    const int consecutiveFramesThreshold = 5; // Adjust this threshold as needed
    int consecutiveFramesWithFace = 0;

    while (true) {
        Mat frame;
        cap >> frame;

        if (frame.empty()) {
            cerr << "Error: Could not read frame." << endl;
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
                consecutiveFramesWithFace = 1;

                // Increment the total number of unique faces
                totalUniqueFaces++;

                // Write the current frame's face count to the log file
                logFile << "Frame " << cap.get(CAP_PROP_POS_FRAMES) << ": New face introduced. Total unique faces: " << totalUniqueFaces << endl;
            }
            else {
                // Face already counted, keep the square on the face
                rectangle(frame, lastDetectedFace, Scalar(0, 255, 0), 2);
                consecutiveFramesWithFace++;
            }

            if (consecutiveFramesWithFace >= consecutiveFramesThreshold) {
                // Reset the face tracking if the face has been consistently detected for the specified frames
                uniqueFaceIds.clear();
                consecutiveFramesWithFace = 0;
            }
        }
        else if (!uniqueFaceIds.empty()) {
            // No face detected in this frame, but faces were detected in previous frames
            // Consider it as the face leaving the frame
            uniqueFaceIds.clear();
            consecutiveFramesWithFace = 0;
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
