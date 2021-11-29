#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <iostream>
#include "workshop_example/square.h"
using namespace std;
ros::Publisher pub;

bool square(workshop_example::square::Request  &req,
            workshop_example::square::Response &res)
    {
      res.num_out = req.num_in * req.num_in;
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