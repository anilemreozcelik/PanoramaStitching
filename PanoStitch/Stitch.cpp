#include < stdio.h >  
#include < opencv2\opencv.hpp >  
#include <opencv2\core\cuda.hpp>
#include < opencv2\stitching.hpp >



using namespace cv;
using namespace std;


int main()
{
	int index = 1;
	vector< Mat > vImg;

	Mat tempIm1;

	//vImg.push_back(imread("3.jpeg"));
	//vImg.push_back(imread("4.jpeg"));
	//vImg.push_back(imread("5.jpeg"));
	//vImg.push_back(imread("6.jpeg"));
	//vImg.push_back(imread("7.jpeg"));
	//vImg.push_back(imread("8.jpeg"));
	//vImg.push_back(imread("9.jpeg"));
	//vImg.push_back(imread("10.jpeg"));
	//vImg.push_back(imread("11.jpeg"));
	//vImg.push_back(imread("12.jpeg"));
	//vImg.push_back(imread("13.jpeg"));
	//vImg.push_back(imread("14.jpeg"));
	//vImg.push_back(imread("15.jpeg"));
	//vImg.push_back(imread("18.jpeg"));
	//vImg.push_back(imread("19.jpeg"));
	//vImg.push_back(imread("20.jpeg"));
	//vImg.push_back(imread("21.jpeg"));
	//vImg.push_back(imread("22.jpeg"));
	//vImg.push_back(imread("23.jpeg"));
	for (int i = 0; i <= 11; i++) {

		vImg.push_back(imread(to_string(i) + ".jpeg"));
	}




	Stitcher stitcher = Stitcher::createDefault(1);


	unsigned long AAtime = 0, BBtime = 0;
	AAtime = getTickCount();

	stitcher.stitch(vImg, tempIm1);
	if (!tempIm1.data)                              // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;

	}

	imshow("temp1", tempIm1);
	imwrite("temp1.jpeg", tempIm1);



	vImg.clear();



	BBtime = getTickCount();

	unsigned long elapsedTime = (BBtime - AAtime) / getTickFrequency();
	printf("%.2lf sec \n", (BBtime - AAtime) / getTickFrequency());

	getchar();




	return 0;










}