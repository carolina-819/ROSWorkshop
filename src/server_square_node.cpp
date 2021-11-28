#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <iostream>
#include "ex1/square.h"
using namespace std;
ros::Publisher pub;

bool square(ex1::square::Request  &req,
            ex1::square::Response &res)
    {
      res.num = req.num * req.num;
      cout << "sending back response! " << endl;
     return true;
   }

int main(int argc, char **argv){
    ros::init(argc, argv, "server_square_node");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("square", square);
    cout << ("Ready to square ints\n");
    ros::spin();
}