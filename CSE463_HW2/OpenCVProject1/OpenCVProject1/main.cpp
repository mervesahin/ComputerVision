#include <cmath>
#include <iostream>
#include <stdlib.h>
//#include <pthread.h>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
#define PI 3.14159265
/// Global variables
Mat image, src_gray;
Mat dst, detected_edges;
int vote[500][500][60];
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 120;
int ratio = 3;
int kernel_size = 3;
char* window_name = "Edge Map";
void CannyThreshold(int, void*)
{
	/// Reduce noise with a kernel 3x3
	blur(src_gray, detected_edges, Size(3, 3));

	/// Canny detector
	Canny(detected_edges, detected_edges, max_lowThreshold, max_lowThreshold*ratio, kernel_size);

	/// Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);

	image.copyTo(dst, detected_edges);

}
void deleteVoteArray(int array[500][500][60], int size);
void findMaxTrashold(int array[500][500][60], int size);
int main(int, char)
{
	Size size(200, 200);
	VideoCapture capture(0);
	if (!capture.isOpened()){
		return -1;
	}

	// image = imread("resim.jpg"); 

	/*if (image.empty()){
	cout << "Image could not loaded"<< endl;
	return - 1;
	}*/
	//namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	int center;
	int x, y;
	/// Create a matrix of the same type and size as src (for dst)
	dst.create(image.size(), image.type());
	//resize(detected_edges, detected_edges, size);
	detected_edges.create(image.size(), image.type());
	///////////////////////////////////////////////////////////////resize(image, image, size);

	while (1){


		capture >> image;
		resize(image, image, size);
		/// Convert the image to grayscale
		cvtColor(image, src_gray, CV_BGR2GRAY);

		/// Create a window


		/// Create a Trackbar for user to enter threshold
		//createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);

		/// Show the image
		CannyThreshold(0, 0);

		deleteVoteArray(vote, image.rows);
		for (int i = 0; i < detected_edges.rows; i += 3){
			for (int j = 0; j < detected_edges.cols; j += 3){
				//if ((int)detected_edges.at<uchar>(Point(i, j)) == 0){
					for (int r = 20; r < 60; r += 10)
					{
						for (int t = 0; t < 180; t += 1)
						{

							x = i + r*cos(t);

							y = j + r*sin(t);

							if ((x > 0 && x < image.rows) && (y>0 && y < image.rows)){
								if ((int)detected_edges.at<uchar>(Point(x, y)) == 255)
									vote[i][j][r] += 1;
							}
						}
					}
				//}
			}
		}
		findMaxTrashold(vote, image.rows);

		imshow("window_name", image);
		/// Wait until user exit program by pressing a key
		if (waitKey(30) == 0)
			break;
	}
	return 0;
}
void deleteVoteArray(int array[500][500][60], int size){
	for (int j = 0; j < size; ++j){
		for (int i = 0; i < size; ++i){
			for (int k = 0; k < 60; ++k){
				array[j][i][k] = 0;
			}
		}
	}
}

void findMaxTrashold(int array[500][500][60], int size){
	int max = 0, max_i = 0, max_j = 0, max_k = 0;
	for (int i = 0; i <size; ++i){
		for (int j = 0; j < size; ++j){
			for (int k = 20; k < 40; ++k){
				if (array[i][j][k] >60){
					max = array[i][j][k];
					max_i = i;
					max_j = j;
					max_k = k;
					circle(image, Point(max_i, max_j), max_k, Scalar(0, 0, 255), 1, 8, 0); //max_k=> radius
					circle(image, Point(max_i, max_j), 1, Scalar(0, 0, 255), -1, 8, 0);
					

				}

			}
		}
	}
	cout <<"max"<< max<< endl;

}