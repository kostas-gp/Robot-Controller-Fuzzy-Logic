
#include <cstdlib>

using namespace std;

//create a class for input in order to know if the input is low,medioum or high

class class_input { // The class
public:
    double number;
    double low;
    double medioum;
    double high;
};

//create a function in order to find the minimum value of 3 sensor

double find_min(double x1, double x2, double x3) {
    int smallest = 2;

    if (x1 < smallest)
        smallest = x1;
    if (x2 < smallest)
        smallest = x2;
    if (x3 < smallest)
        smallest = x3;
    return smallest;
}

double find_min(double x1, double x2) {
    int smallest = 2;

    if (x1 < smallest)
        smallest = x1;
    if (x2 < smallest)
        smallest = x2;
    return smallest;
}

int main(int argc, char** argv) {

    class_input inputx1, inputx2, inputx3; //define 3 class each class for each input

    //code for right follow
    double x1, x2;
    inputx1.number = x1;
    inputx1.number = x2;

    //find the low  medioum high of each input
    //input x1
    if (inputx1.number <= 300) {
        inputx1.low = 1;
        inputx1.medioum = 0;
        inputx1.high = 0;
    } else if (inputx1.number > 300 && inputx1.number <= 400) {
        inputx1.low = (400 - inputx1.number) / 100;
        inputx1.medioum = (inputx1.number - 300) / 100;
        inputx1.high = 0;
    } else if (inputx1.number > 400 && inputx1.number <= 500) {
        inputx1.low = 0;
        inputx1.medioum = 1;
        inputx1.high = 0;
    } else if (inputx1.number > 500 && inputx1.number <= 600) {
        inputx1.low = 0;
        inputx1.medioum = (400 - inputx1.number) / 100;
        inputx1.high = (inputx1.number - 300) / 100;
    } else {
        inputx1.low = 0;
        inputx1.medioum = 0;
        inputx1.high = 1;
    }

    //input x2
    if (inputx2.number <= 300) {
        inputx2.low = 1;
        inputx2.medioum = 0;
        inputx2.high = 0;
    } else if (inputx2.number > 300 && inputx2.number <= 400) {
        inputx2.low = (400 - inputx2.number) / 100;
        inputx2.medioum = (inputx2.number - 300) / 100;
        inputx2.high = 0;
    } else if (inputx2.number > 400 && inputx2.number <= 500) {
        inputx2.low = 0;
        inputx2.medioum = 1;
        inputx2.high = 0;
    } else if (inputx2.number > 500 && inputx2.number <= 600) {
        inputx2.low = 0;
        inputx2.medioum = (400 - inputx2.number) / 100;
        inputx2.high = (inputx2.number - 300) / 100;
    } else {
        inputx2.low = 0;
        inputx2.medioum = 0;
        inputx2.high = 1;
    }

    double min, y1left_follow_wall, y2right_follow_wall, numerator = 0, denominator = 0;

    int low_motor = 30, medioum_motor = 50, high_motor = 70;

    //compute the speed motors depends on rules
    //left motor

    //1th rule (l,l)
    min = find_min(inputx1.low, inputx2.low);
    numerator = min * low_motor + numerator;
    denominator = min + denominator;

    //2th rule (l,m)
    min = find_min(inputx1.low, inputx2.medioum);
    numerator = min * low_motor + numerator;
    denominator = min + denominator;

    //3th rule (l,h)
    min = find_min(inputx1.low, inputx2.high);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //4th rule (m,l)
    min = find_min(inputx1.medioum, inputx2.low);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //5th rule (m,m)
    min = find_min(inputx1.medioum, inputx2.medioum);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //6th rule (m,h)
    min = find_min(inputx1.medioum, inputx2.high);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //7th rule (h,l)
    min = find_min(inputx1.high, inputx2.low);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //8th rule (h,m)
    min = find_min(inputx1.high, inputx2.medioum);
    numerator = min * high_motor + numerator;
    denominator = min + denominator;

    //9th rule (h,h)
    min = find_min(inputx1.high, inputx2.high);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    y1left_follow_wall = numerator / denominator;

    //right motor
    numerator = 0;
    denominator = 0;

    //1th rule (l,l)
    min = find_min(inputx1.low, inputx2.low);
    numerator = min * high_motor + numerator;
    denominator = min + denominator;

    //2th rule (l,m)
    min = find_min(inputx1.low, inputx2.medioum);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //3th rule (l,h)
    min = find_min(inputx1.low, inputx2.high);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //4th rule (m,l)
    min = find_min(inputx1.medioum, inputx2.low);
    numerator = min * low_motor + numerator;
    denominator = min + denominator;

    //5th rule (m,m)
    min = find_min(inputx1.medioum, inputx2.medioum);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //6th rule (m,h)
    min = find_min(inputx1.medioum, inputx2.high);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //7th rule (h,l)
    min = find_min(inputx1.high, inputx2.low);
    numerator = min * low_motor + numerator;
    denominator = min + denominator;

    //8th rule (h,m)
    min = find_min(inputx1.high, inputx2.medioum);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    //9th rule (h,h)
    min = find_min(inputx1.high, inputx2.high);
    numerator = min * medioum_motor + numerator;
    denominator = min + denominator;

    y2right_follow_wall = numerator / denominator;

    //compute and the third sensor for obstacle avoid
    double x3;

    if (inputx3.number <= 300) {
        inputx3.low = 1;
        inputx3.medioum = 0;
        inputx3.high = 0;
    } else if (inputx3.number > 300 && inputx3.number <= 400) {
        inputx3.low = (400 - inputx3.number) / 100;
        inputx3.medioum = (inputx3.number - 300) / 100;
        inputx3.high = 0;
    } else if (inputx3.number > 400 && inputx3.number <= 500) {
        inputx3.low = 0;
        inputx3.medioum = 1;
        inputx3.high = 0;
    } else if (inputx3.number > 500 && inputx3.number <= 600) {
        inputx3.low = 0;
        inputx3.medioum = (400 - inputx3.number) / 100;
        inputx3.high = (inputx3.number - 300) / 100;
    } else {
        inputx3.low = 0;
        inputx3.medioum = 0;
        inputx3.high = 1;
    }

    double minimum, y_obstacle_left, y_obstacle_right;
    numerator = 0;
    denominator = 0;

    //compute the speed motors depends on rules
    //left motor

    //1th rule (l,l,l)
    minimum = find_min(inputx1.low, inputx2.low, inputx3.low); //find the minimum of each sensor in order to comput the speed of motor
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //2th rule (l,l,m)
    minimum = find_min(inputx1.low, inputx2.low, inputx3.medioum); //find the minimum of each sensor in order to comput the speed of motor
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //3th rule (l,l,h)
    minimum = find_min(inputx1.low, inputx2.low, inputx3.high);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //4th rule (l,m,l)
    minimum = find_min(inputx1.low, inputx2.medioum, inputx3.low);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //5th rule (l,m,m)
    minimum = find_min(inputx1.low, inputx2.medioum, inputx3.medioum);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //6th rule (l,m,h)
    minimum = find_min(inputx1.low, inputx2.medioum, inputx3.high);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //7th rule (l,h,l)
    minimum = find_min(inputx1.low, inputx2.high, inputx3.low);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //8th rule (l,h,m)
    minimum = find_min(inputx1.low, inputx2.high, inputx3.medioum);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //9th rule (l,h,h)
    minimum = find_min(inputx1.low, inputx2.high, inputx3.high);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //10th rule (m,l,l)
    minimum = find_min(inputx1.medioum, inputx2.low, inputx3.low);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //11th rule (m,l,m)
    minimum = find_min(inputx1.medioum, inputx2.low, inputx3.medioum);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //12th rule (m,l,h)
    minimum = find_min(inputx1.medioum, inputx2.low, inputx3.high);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //13th rule (m,m,l)
    minimum = find_min(inputx1.medioum, inputx2.medioum, inputx3.low);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //14th rule (m,m,m)
    minimum = find_min(inputx1.medioum, inputx2.medioum, inputx3.medioum);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //15th rule (m,m,h)
    minimum = find_min(inputx1.medioum, inputx2.medioum, inputx3.high);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //16th rule (m,h,l)
    minimum = find_min(inputx1.medioum, inputx2.high, inputx3.low);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //17th rule (m,h,m)
    minimum = find_min(inputx1.medioum, inputx2.high, inputx3.medioum);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //18th rule (m,h,h)
    minimum = find_min(inputx1.medioum, inputx2.high, inputx3.high);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //19th rule (h,l,l)
    minimum = find_min(inputx1.high, inputx2.low, inputx3.low);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //20th rule (h,l,m)
    minimum = find_min(inputx1.high, inputx2.low, inputx3.medioum);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //21th rule (h,l,h)
    minimum = find_min(inputx1.high, inputx2.low, inputx3.high);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //22th rule (h,m,l)
    minimum = find_min(inputx1.high, inputx2.medioum, inputx3.low);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //23th rule (h,m,m)
    minimum = find_min(inputx1.high, inputx2.medioum, inputx3.medioum);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //24th rule (h,m,h);
    minimum = find_min(inputx1.high, inputx2.medioum, inputx3.high);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //25th rule (h,h,l);
    minimum = find_min(inputx1.high, inputx2.high, inputx3.low);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //26th rule (h,h,m);
    minimum = find_min(inputx1.high, inputx2.high, inputx3.medioum);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //27th rule (h,h,h);
    minimum = find_min(inputx1.high, inputx2.high, inputx3.high);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    y_obstacle_left = numerator / denominator; //the speed of the left motor

    numerator = 0;
    denominator = 0;

    //right motor
    //1th rule (l,l,l)
    minimum = find_min(inputx1.low, inputx2.low, inputx3.low); //find the minimum of each sensor in order to comput the speed of motor
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //2th rule (l,l,m)
    minimum = find_min(inputx1.low, inputx2.low, inputx3.medioum); //find the minimum of each sensor in order to comput the speed of motor
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //3th rule (l,l,h)
    minimum = find_min(inputx1.low, inputx2.low, inputx3.high);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //4th rule (l,m,l)
    minimum = find_min(inputx1.low, inputx2.medioum, inputx3.low);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //5th rule (l,m,m)
    minimum = find_min(inputx1.low, inputx2.medioum, inputx3.medioum);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //6th rule (l,m,h)
    minimum = find_min(inputx1.low, inputx2.medioum, inputx3.high);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //7th rule (l,h,l)
    minimum = find_min(inputx1.low, inputx2.high, inputx3.low);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //8th rule (l,h,m)
    minimum = find_min(inputx1.low, inputx2.high, inputx3.medioum);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //9th rule (l,h,h)
    minimum = find_min(inputx1.low, inputx2.high, inputx3.high);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //10th rule (m,l,l)
    minimum = find_min(inputx1.medioum, inputx2.low, inputx3.low);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //11th rule (m,l,m)
    minimum = find_min(inputx1.medioum, inputx2.low, inputx3.medioum);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //12th rule (m,l,h)
    minimum = find_min(inputx1.medioum, inputx2.low, inputx3.high);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //13th rule (m,m,l)
    minimum = find_min(inputx1.medioum, inputx2.medioum, inputx3.low);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //14th rule (m,m,m)
    minimum = find_min(inputx1.medioum, inputx2.medioum, inputx3.medioum);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //15th rule (m,m,h)
    minimum = find_min(inputx1.medioum, inputx2.medioum, inputx3.high);
    numerator = minimum * low_motor + numerator;
    denominator = minimum + denominator;

    //16th rule (m,h,l)
    minimum = find_min(inputx1.medioum, inputx2.high, inputx3.low);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //17th rule (m,h,m)
    minimum = find_min(inputx1.medioum, inputx2.high, inputx3.medioum);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //18th rule (m,h,h)
    minimum = find_min(inputx1.medioum, inputx2.high, inputx3.high);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //19th rule (h,l,l)
    minimum = find_min(inputx1.high, inputx2.low, inputx3.low);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //20th rule (h,l,m)
    minimum = find_min(inputx1.high, inputx2.low, inputx3.medioum);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //21th rule (h,l,h)
    minimum = find_min(inputx1.high, inputx2.low, inputx3.high);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //22th rule (h,m,l)
    minimum = find_min(inputx1.high, inputx2.medioum, inputx3.low);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //23th rule (h,m,m)
    minimum = find_min(inputx1.high, inputx2.medioum, inputx3.medioum);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    //24th rule (h,m,h);
    minimum = find_min(inputx1.high, inputx2.medioum, inputx3.high);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //25th rule (h,h,l);
    minimum = find_min(inputx1.high, inputx2.high, inputx3.low);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //26th rule (h,h,m);
    minimum = find_min(inputx1.high, inputx2.high, inputx3.medioum);
    numerator = minimum * high_motor + numerator;
    denominator = minimum + denominator;

    //27th rule (h,h,h);
    minimum = find_min(inputx1.high, inputx2.high, inputx3.high);
    numerator = minimum * medioum_motor + numerator;
    denominator = minimum + denominator;

    y_obstacle_right = numerator / denominator; //the speed of the right motor


    //combine the two project (right linear and obstacles avoid)

    double final_left_motor, final_right_motor;
    //1st way with the if-else command
    if (inputx3.number > 500 && inputx2.number < 500)//check to see if there are any obstacles nearby if not continue to follow the line
    {
        //continue with the logic of follow the wall
        final_left_motor = y1left_follow_wall;
        final_right_motor = y2right_follow_wall;

    } else {
        //continue with the logic of obstacle avoid
        final_left_motor = y_obstacle_left;
        final_right_motor = y_obstacle_right;
    }
    return 0;
}

