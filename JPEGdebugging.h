#pragma once
#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <unordered_set>

using namespace cv;
using namespace std;

String imagePath = "C:/Users/marco/Desktop/debug3.png";
int screenWidth = 1280;
int screenHeight = 720;

class FaceDetection {
public:
    FaceDetection(const String& imagePath, const String& cascadePath, const String& logFilePath);
    int runFaceDetection();

private:
    CascadeClassifier faceCascade;
    String logFilePath;
    unordered_set<int> uniqueFaceIds; // Keep track of unique faces detected
    ofstream logFile;
    Rect lastDetectedFace; // Store the last detected face rectangle
    int totalUniqueFaces; // Counter for the total number of unique faces
};

FaceDetection::FaceDetection(const String& imagePath, const String& cascadePath, const String& logFilePath)
    : logFilePath(logFilePath), totalUniqueFaces(0) {

    if (imagePath.empty() || cascadePath.empty()) {
        cerr << "Error: Image path or cascade path is empty." << endl;
        exit(EXIT_FAILURE);
    }

    // Load the face cascade classifier
    if (!faceCascade.load(cascadePath)) {
        cerr << "Error: Could not load face cascade classifier." << endl;
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
    Mat frame = imread(imagePath, IMREAD_COLOR);

    if (frame.empty()) {
        cerr << "Error: Could not read image from file." << endl;
        return -1;
    }

    Mat gray;
    cvtColor(frame, gray, COLOR_BGR2GRAY);

    std::vector<Rect> faces;
    faceCascade.detectMultiScale(gray, faces, 1.3, 5);

    if (!faces.empty()) {
        for (const auto& faceRect : faces) {
            rectangle(frame, faceRect, Scalar(0, 255, 0), 2);

            int faceId = static_cast<int>(faceRect.y + faceRect.height / 2); // Unique identifier for each face
            putText(frame, "ID: " + to_string(faceId), Point(faceRect.x, faceRect.y + faceRect.height + 20), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);

            if (uniqueFaceIds.find(faceId) == uniqueFaceIds.end()) {
                uniqueFaceIds.insert(faceId);
                lastDetectedFace = faceRect;

                 totalUniqueFaces++;

                logFile << "New face introduced. Total unique faces: " << totalUniqueFaces << endl;
            }
        }

        resize(frame, frame, Size(screenWidth, screenHeight));
        imshow("face detection", frame);

        //imshow("Face Detection", frame);
        waitKey(0);
    }

    destroyAllWindows();
    logFile.close();

    return 0;
}

// Function to be called from the main program
void faceDetection(const String& imagePath, const String& cascadePath, const String& logFilePath) {
    FaceDetection faceDetectionObj(imagePath, cascadePath, logFilePath);
    faceDetectionObj.runFaceDetection();
}