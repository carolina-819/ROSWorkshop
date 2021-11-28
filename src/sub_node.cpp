#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <iostream>
using namespace std;

ros::Subscriber sub;
string info;
void cbComm(const std_msgs::String::ConstPtr& msg){
   cout << msg->data.c_str() << endl;

}

int main(int argc, char **argv){
    ros::init(argc, argv, "subscriber_node");
    ros::NodeHandle nh;
    cout << "aqui vai aparecer o que escreveres no outro terminal\n";
        sub = nh.subscribe("comm_terminal", 1, cbComm);
        ros::spin();
    
   
    
    return 0;

}