#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>
using namespace std;
using namespace cv;
int main(){
	int count=1;
	VideoCapture cap("./xx.mp4");
	if(!cap.isOpened()) return -1;
	Mat frame,edges;
	namedWindow("edges",CV_WINDOW_NORMAL);
	for(;;){
		cap>>frame;

		cvtColor(frame,edges,CV_BGRA2GRAY);
		if (count){
		uchar *p=edges.data;
		int nRows=edges.rows;
		int nCols=edges.cols;
		for(unsigned int i=0;i<nRows;i++){
			for(unsigned int j=0;j<nCols;j++){
				if((j!=nCols||j!=0) && (i!=nRows-1||i!=0) && (abs((*p)-*(p+1))<110 && abs(*(p)-*(p-1))<110)){
//					cout<<abs((*p)-*(p+1))<<endl;p++;
//					*p=(*p+*(p+1)+*(p-1)+*(p+2)+*(p-2))/5;
					p++;
//					*p=255;
				}
			}
		}
		}
//		GaussianBlur(edges,edges,Size(5,5),1.5,1.5);
//		Canny(edges,edges,0,30,3);
		imshow("edges",edges);
		if(waitKey(30)>=0 )break;
	}
	return 0;
}
