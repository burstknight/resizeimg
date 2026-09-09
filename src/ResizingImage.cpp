#include "ResizingImage.h"
#include <cstdio>
#include <opencv2/core/types.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace ResizingImage;
using namespace cv;

void ResizingImage::resizeImage(std::unique_ptr<ParseArgs::Args_s> poArgs) {
	Mat mInputImage = imread(poArgs->m_sInputImagePath);
	if (mInputImage.empty()) {
		fprintf(stderr, "Error: Failed to open the image file: %s\n", poArgs->m_sInputImagePath.c_str());

		return;
	} // End of if-condition

	Mat mResultImage;

	printf("Resizing image...");
	resize(mInputImage, mResultImage, Size(poArgs->m_iWidth, poArgs->m_iHeight));
	printf(" Done!\n");

	printf("Storing the result image...");
	imwrite(poArgs->m_sResultImagePath, mResultImage);
	printf("Done!\n");
} // End of resizeImage
