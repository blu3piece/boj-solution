#include<iostream>
#include<cmath>
using namespace std;

int points[4][2];

double getDistance(double* point1, double* point2){
    return sqrt(pow(abs(point1[0] - point2[0]), 2) + pow(abs(point1[1] - point2[1]), 2));
}

double* getPortion(int* base, int* output, double portion){
    portion /= 100000.0;
    double* point = new double[2];
    point[0] = base[0] + portion*(double)(output[0] - base[0]);
    point[1] = base[1] + portion*(double)(output[1] - base[1]);
    return point;
}

int main(){
    for(int i = 0; i<4; ++i){
        for(int j=0; j<2; ++j){
            cin>>points[i][j];
        }
    }

    double left = 0.0;
    double right = 100000.0;
    double answer = -1.0;
    double left_portion = (2*left + right)/3;
    double right_portion = (left + 2*right)/3;

    while(abs(left_portion - right_portion) > 0.00001){
        left_portion = (2*left + right)/3;
        right_portion = (left + 2*right)/3;
        double leftDistance = getDistance(getPortion(points[0], points[1], left_portion), getPortion(points[2], points[3], left_portion));
        double rightDistance = getDistance(getPortion(points[0], points[1], right_portion), getPortion(points[2], points[3], right_portion));

        if(leftDistance < rightDistance){
            right = right_portion;
            answer = leftDistance;
        }
        else{
            left = left_portion;
            answer = rightDistance;
        }
    }
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << answer;
    return 0;
}