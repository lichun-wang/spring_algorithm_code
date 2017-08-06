#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("E:\\’’∆¨\\’’∆¨\\±œ“µ¬√––\\IMG_20150425_151833.jpg");
	Mat resizeImg;
	resize(img, resizeImg, Size(), 0.2, 0.2);
	

	HOGDescriptor hog;
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
	vector<Rect> regions;
	hog.detectMultiScale(resizeImg, regions, 0, Size(8, 8), Size(0, 0), 1.05, 1);
	for (size_t i = 0; i < regions.size(); i++)
	{
		rectangle(resizeImg, regions[i], Scalar(0, 0, 255), 2);
	}
	imshow("aa", resizeImg);
	waitKey();
	return 0;
}