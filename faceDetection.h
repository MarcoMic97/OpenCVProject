#pragma once
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
String face = "C:/Users/marco/Desktop/haarcascade_frontalface_default.xml.txt";

int faceDetection() {
    CascadeClassifier faceCascade;
    if (!faceCascade.load(face)) {
        std::cerr << "Error: Could not load face cascade classifier." << std::endl;
        return -1;
    }
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open webcam." << std::endl;
        return -1;
    }
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
        for (const auto& face : faces) {
            rectangle(frame, face, Scalar(0, 255, 0), 2);
        }
        imshow("Face Detection", frame);
        int numFaces = static_cast<int>(faces.size());
        std::cout << "Number of Faces: " << numFaces << std::endl;
        if (waitKey(1) == 27) {
            break;
        }
    }
    cap.release();
    destroyAllWindows();

    return 0;
}
#pragma once
