/*************************************************************************
	> File Name: img.cpp
	> Author: jinlin 
	> Mail: 898141731@qq.com 
	> Created Time: Wednesday, September 21, 2016 PM09:19:46 GMT
 ************************************************************************/

#include <opencv2/opencv.hpp>
#include<iostream>
#include<iomanip>
using namespace std;
using namespace cv;
int main(int argc,char* argv[]){
	int a=0;
	Mat img=imread(argv[1]);
	Mat A=img.clone();
	uchar  *p; //=img.data;
	uchar  *q; //=img.data;
	namedWindow("xiaoguotu",CV_WINDOW_NORMAL);
	namedWindow("img",CV_WINDOW_NORMAL);
	int  channels=img.channels();
	int nRows=img.rows;
	int nCols=img.cols*channels;
	cout<<nRows<<":"<<nCols<<endl;
	for(int i=0;i<nRows;++i){
		p=img.ptr<uchar>(i);
		q=A.ptr<uchar>(i);
		for(int j=0;j<nCols;++j){
		//	if((i!=nRows-1 || !i) && (j!=nCols-1 || !j)){
			q[j]+=9;
			cout<<hex<<q[j]<<endl;
			if(q[j]>255)
				q[j]=255;
		}
	}

	imshow("xiaoguotu",A);
	imshow("img",img);
	waitKey(0);
	return 0;
}
