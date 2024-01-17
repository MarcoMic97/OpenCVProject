//#pragma once
//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/utils/logger.hpp>
//
//using namespace std;
//using namespace cv;
//
//
////Øvelse 0
//int showImage()
//{
//	try
//	{
//		std::string image_path = "C:/opencv/sources/samples/data/starry_night.jpg";
//		Mat img = imread(image_path, IMREAD_COLOR);
//		imshow("Image", img);
//		waitKey(0);
//		return 0;
//	}
//	catch (const cv::Exception& e)
//	{
//		cerr << "Error opening image: " << e.what() << endl;
//		cerr << "Error code: " << e.code << endl;
//		return 0;
//	}
//}

//Øvelse 1
//int main()
//{
//    int a = 10;
//    int b = 20;
//    int c = a + b;
//    int e[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int f[10] = { 10,20,30,40,50,60,70,80,90,100};
//    int g[10];
//    for (int i = 0; i < 10; i++)
//    {
//        g[i] = e[i] + f[i];
//        cout << g[i] << endl;
//    }
//    int add(int a, int b);
//    {
//        c = a + b;
//        cout << c << endl;
//    }
//    return 0;
//}

//Øvelse 2
//int main()
//{
//	int count = 0;
//	int total = 0;
//	int roundedValue = 0;
//	std::string image_path = "C:/opencv/sources/samples/data/starry_night.jpg";
//	Mat img = imread(image_path, IMREAD_GRAYSCALE);
//	for (int i = 0; i < img.rows; i++)
//	{
//		uchar* row = img.ptr<uchar>(i);
//		for (int j = 0; j < img.cols; j++)
//		{
//			uchar* pixel = &row[j];
//			cout << (int)*pixel << endl;
//			total = total + (int)*pixel;
//			count++;
//
//		}
//		cout << endl;
//		roundedValue = (total / count);
//		cout << roundedValue << endl;
//		
//	}
//
//	int count1 = 0;
//	int total1 = 0;
//	int roundedValue1 = 0;
//	std::string image_path1 = "C:/opencv/sources/samples/data/LinuxLogo.jpg";
//	Mat img1 = imread(image_path1, IMREAD_GRAYSCALE);
//	for (int i = 0; i < img1.rows; i++)
//	{
//		uchar* row = img1.ptr<uchar>(i);
//		for (int j = 0; j < img1.cols; j++)
//		{
//			uchar* pixel = &row[j];
//			cout << (int)*pixel << endl;
//			total1 = total1 + (int)*pixel;
//			count1++;
//
//		}
//		cout << endl;
//		roundedValue1 = (total1 / count1);
//		cout << roundedValue1 << endl;
//
//	}
//
//	cout << endl; 
//	cout << roundedValue1 << endl;
//	cout << roundedValue << endl; 
//}
//
//

//int main()
//{
//	VideoCapture cap("C:/opencv/sources/samples/data/vtest.avi");
//	if (!cap.isOpened())
//	{
//		cout << "Error opening video stream or file" << endl;
//		return -1;
//	}
//	while (1)
//	{
//		Mat frame;
//		cap >> frame;
//		if (frame.empty())
//			break;
//		imshow("Frame", frame);
//		char c = (char)waitKey(25);
//		if (c == 27)
//			break;
//	}
//	cap.release();
//	destroyAllWindows();
//	return 0;
//}


//Øvelse 3
//int main()
//{
//	cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
//
//	std::string image_path = "C:/opencv/sources/samples/data/starry_night.jpg";
//	Mat img = imread(image_path, IMREAD_COLOR);
//	//split color channels
//	Mat bgr[3];
//	split(img, bgr);
	//show color channels
	//imshow("Blue", bgr[0]);
	//imshow("Green", bgr[1]);
	//imshow("Red", bgr[2]);
	//make a histogram of color channels
	/*int histSize = 256;
	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true, accumulate = false;
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	//calcHist(&bgr[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);*/
	//draw the histograms for B, G and R
	//int hist_w = 512, hist_h = 400;
	//int bin_w = cvRound((double)hist_w / histSize);
	//Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	////normalize the result to [0, histImage.rows]
	/*normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());*/
	//draw for each channel
	/*for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
						Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
						Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
						Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
						Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
						Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
						Scalar(0, 0, 255), 2, 8, 0);
	}*/
	//show the histogram
	//imshow("Histogram", histImage);

	//int bgr0_value = 0;	

	//for (int i = 0; i < bgr[0].rows; i++)
	//{
	//	for (int j = 0; j < bgr[0].cols; j++)
	//	{
	//		bgr0_value = bgr0_value + bgr[0].at<uchar>(i, j);
	//	}
	//}
	//int solution0 = (bgr0_value / (bgr[0].rows * bgr[0].cols));
	//cout << solution0 << endl;
	//waitKey(0);
	//int bgr1_value = 0;

	//for (int i = 0; i < bgr[1].rows; i++)
	//{
	//	for (int j = 0; j < bgr[1].cols; j++)
	//	{
	//		bgr1_value = bgr1_value + bgr[1].at<uchar>(i, j);
	//	}
	//}
	//int solution1 = (bgr1_value / (bgr[1].rows * bgr[1].cols));
	//cout << solution1 << endl;
	//waitKey(0);
	//int bgr2_value = 0;

	//for (int i = 0; i < bgr[2].rows; i++)
	//{
	//	for (int j = 0; j < bgr[2].cols; j++)
	//	{
	//		bgr2_value = bgr2_value + bgr[2].at<uchar>(i, j);
	//	}
	//}
	//int solution2 = (bgr2_value / (bgr[2].rows * bgr[2].cols));
	//cout << solution2 << endl;
	//return 0;

	//funny haha
	/*for (int i = 0; i < sizeof(bgr[0]); i++)
	{
		i = i + 1;
		cout << bgr[0] << endl;
	}*/
	//}


	//Øvelse 4
	//int main()
	//	{
	//	//load image
	//	std::string image_path = "C:/opencv/sources/samples/data/starry_night.jpg";
	//	Mat img = imread(image_path, IMREAD_COLOR);
	//	//make a histogram of the picture
	//	int histSize = 256;
	//	float range[] = { 0, 256 };
	//	const float* histRange = { range };
	//	bool uniform = true, accumulate = false;
	//	Mat b_hist, g_hist, r_hist;
	//	calcHist(&img, 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	//	calcHist(&img, 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	//	calcHist(&img, 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
	//	//draw the histograms for B, G and R
	//	int hist_w = 512, hist_h = 400;
	//	int bin_w = cvRound((double)hist_w / histSize);
	//	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	//	//normalize the result to [0, histImage.rows]
	//	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat()); 
	//	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat()); 
	//	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	//	//draw for each channel
	//	for (int i = 1; i < histSize; i++)
	//	{
	//		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
	//					Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
	//					Scalar(255, 0, 0), 2, 8, 0);
	//		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
	//					Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
	//					Scalar(0, 255, 0), 2, 8, 0);
	//		line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
	//					Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
	//					Scalar(0, 0, 255), 2, 8, 0);
	//	}
	//	//show the histogram
	//	imshow("Histogram", histImage);
	//	waitKey(0);
	//	return 0;
	//	}

	////Øvelse 5
	//// Function to be called when the trackbar value changes
	//void onTrackbarChange(int thresholdValue, void* userData) {
	//	Mat original = *(Mat*)userData;
	//
	//	// Apply binary thresholding
	//	Mat binaryImage;
	//	threshold(original, binaryImage, thresholdValue, 255, THRESH_BINARY);
	//
	//	// Display the result
	//	imshow("Binary Image", binaryImage);
	//}
	//
	//int main() {
	//	// Load an image in grayscale
	//	Mat original = imread("C:/opencv/sources/samples/data/starry_night.jpg", IMREAD_GRAYSCALE);
	//
	//	if (original.empty()) {
	//		std::cerr << "Error: Image not loaded!" << std::endl;
	//		return -1;
	//	}
	//
	//	// Create a window for the original image
	//	namedWindow("Original Image", WINDOW_NORMAL);
	//	imshow("Original Image", original);
	//
	//	// Create a window for the binary image
	//	namedWindow("Binary Image", WINDOW_NORMAL);
	//
	//	// Create a trackbar to adjust the threshold value
	//	int initialThreshold = 128;  // Initial threshold value
	//	createTrackbar("Threshold", "Binary Image", &initialThreshold, 255, onTrackbarChange, &original);
	//
	//	// Call the onTrackbarChange function once to initialize the binary image
	//	onTrackbarChange(initialThreshold, &original);
	//
	//	// Wait for a key press
	//	waitKey(0);
	//
	//	return 0;
	//}

	//// Function to be called when the trackbar value changes
	//void onTrackbarChange(int, void* userData) {
	//	Mat original = *(Mat*)userData;
	//
	//	// Apply Otsu's thresholding
	//	Mat binaryImage;
	//	threshold(original, binaryImage, 0, 255, THRESH_BINARY | THRESH_OTSU);
	//
	//	// Display the result
	//	imshow("Binary Image", binaryImage);
	//}
	//
	//int main() {
	//	// Load an image in grayscale
	//	Mat original = imread("C:/opencv/sources/samples/data/starry_night.jpg", IMREAD_GRAYSCALE);
	//
	//	if (original.empty()) {
	//		std::cerr << "Error: Image not loaded!" << std::endl;
	//		return -1;
	//	}
	//
	//	// Create a window for the original image
	//	namedWindow("Original Image", WINDOW_NORMAL);
	//	imshow("Original Image", original);
	//
	//	// Create a window for the binary image
	//	namedWindow("Binary Image", WINDOW_NORMAL);
	//
	//	// Create a trackbar (not used for Otsu's thresholding)
	//	int initialThreshold = 128;  // Initial threshold value (not used)
	//	createTrackbar("Threshold", "Binary Image", &initialThreshold, 255, onTrackbarChange, &original);
	//
	//	// Call the onTrackbarChange function once to initialize the binary image
	//	onTrackbarChange(0, &original);
	//
	//	// Wait for a key press
	//	waitKey(0);
	//
	//	return 0;
	//}

	////Øvelse 6
	//// Function to be called when the trackbar value changes
	//void onTrackbarChange(int blurKernelSize, void* userData) {
	//	Mat original = *(Mat*)userData;
	//
	//	// Apply Gaussian blur
	//	Mat blurredImage;
	//	GaussianBlur(original, blurredImage, Size(blurKernelSize, blurKernelSize), 0);
	//
	//	// Apply Otsu's thresholding
	//	Mat binaryImage;
	//	threshold(blurredImage, binaryImage, 0, 255, THRESH_BINARY | THRESH_OTSU);
	//
	//	// Display the result
	//	imshow("Binary Image", binaryImage);
	//}
	//
	//int main() {
	//	// Load an image in grayscale
	//	Mat original = imread("C:/opencv/sources/samples/data/starry_night.jpg", IMREAD_GRAYSCALE);
	//
	//	if (original.empty()) {
	//		std::cerr << "Error: Image not loaded!" << std::endl;
	//		return -1;
	//	}
	//
	//	// Create a window for the original image
	//	namedWindow("Original Image", WINDOW_NORMAL);
	//	imshow("Original Image", original);
	//
	//	// Create a window for the binary image
	//	namedWindow("Binary Image", WINDOW_NORMAL);
	//
	//	// Create a trackbar to adjust the blur kernel size
	//	int initialBlurKernelSize = 3;  // Initial blur kernel size
	//	createTrackbar("Blur Kernel Size", "Binary Image", &initialBlurKernelSize, 31, onTrackbarChange, &original);
	//
	//	// Call the onTrackbarChange function once to initialize the binary image
	//	onTrackbarChange(initialBlurKernelSize, &original);
	//
	//	// Wait for a key press
	//	waitKey(0);
	//
	//	return 0;
	//}




	////Øvelse 7
	//// Function to be called when the trackbar value changes
	//void onTrackbarChange(int filterSize, void* userData) {
	//	Mat original = *(Mat*)userData;
	//
	//	// Apply box filter
	//	Mat filteredImage;
	//	boxFilter(original, filteredImage, -1, Size(filterSize, filterSize));
	//
	//	// Apply Otsu's thresholding
	//	Mat binaryImage;
	//	threshold(filteredImage, binaryImage, 0, 255, THRESH_BINARY | THRESH_OTSU);
	//
	//	// Display the result
	//	imshow("Binary Image", binaryImage);
	//}
	//
	//
	//
	//
	//int main() {
	//	// Load an image in grayscale
	//	Mat original = imread("C:/opencv/sources/samples/data/starry_night.jpg", IMREAD_GRAYSCALE);
	//
	//	if (original.empty()) {
	//		std::cerr << "Error: Image not loaded!" << std::endl;
	//		return -1;
	//	}
	//
	//	// Create a window for the original image
	//	namedWindow("Original Image", WINDOW_NORMAL);
	//	imshow("Original Image", original);
	//
	//	// Create a window for the binary image
	//	namedWindow("Binary Image", WINDOW_NORMAL);
	//
	//	// Create a trackbar to adjust the box filter size
	//	int initialFilterSize = 3;  // Initial filter size
	//	createTrackbar("Filter Size", "Binary Image", &initialFilterSize, 31, onTrackbarChange, &original);
	//
	//	// Call the onTrackbarChange function once to initialize the binary image
	//	onTrackbarChange(initialFilterSize, &original);
	//
	//	// Wait for a key press
	//	waitKey(0);
	//
	//	return 0;
	//}



	//
	//Mat image = imread("C:/opencv/sources/samples/data/starry_night.jpg", IMREAD_COLOR);
	////Øvelse 8
	//Mat sharpen()
	//{
	//	Mat sharp_img;
	//	Mat kernel3 = (Mat_<double>(3, 3) << 0, -1, 0,
	//		-1, 5, -1,
	//		0, -1, 0);
	//	filter2D(image, sharp_img, -1, kernel3, Point(-1, -1), 0, BORDER_DEFAULT);
	//}
	//



	//
	//// Function to be called when the trackbar value changes
	//void onTrackbarChange(int filterSize, void* userData) {
	//	Mat original = *(Mat*)userData;
	//
	//	// Apply Gaussian blur
	//	Mat blurredImage;
	//	GaussianBlur(original, blurredImage, Size(filterSize, filterSize), 0);
	//
	//	// Apply sharpening filter
	//	Mat sharpImage;
	//	Mat kernel = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	//	filter2D(blurredImage, sharpImage, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);
	//
	//	// Display the result
	//	imshow("Sharpened Image", sharpImage);
	//}
	//
	//int main() {
	//	// Load an image in grayscale
	//	Mat original = imread("C:/opencv/sources/samples/data/starry_night.jpg", IMREAD_GRAYSCALE);
	//
	//	if (original.empty()) {
	//		std::cerr << "Error: Image not loaded!" << std::endl;
	//		return -1;
	//	}
	//
	//	// Create a window for the original image
	//	namedWindow("Original Image", WINDOW_NORMAL);
	//	imshow("Original Image", original);
	//
	//	// Create a window for the sharpened image
	//	namedWindow("Sharpened Image", WINDOW_NORMAL);
	//
	//	// Create a trackbar to adjust the Gaussian blur kernel size
	//	int initialFilterSize = 3;  // Initial filter size
	//	createTrackbar("Filter Size", "Sharpened Image", &initialFilterSize, 31, onTrackbarChange, &original);
	//
	//	// Call the onTrackbarChange function once to initialize the sharpened image
	//	onTrackbarChange(initialFilterSize, &original);
	//
	//	// Wait for a key press
	//	waitKey(0);
	//
	//	return 0;
	//}



	//Øvelse 9