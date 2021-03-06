#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <iostream>
#include "workshop_example/square.h"
using namespace std;



int main(int argc, char **argv){
    ros::init(argc, argv, "client_square_node");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<workshop_example::square>("square");
    workshop_example::square srv;
    cout << "Ready to get you numbers \n" << endl;
    //srv.request.num = atoll(argv[1]);
    string input;
    while(getline(cin, input)){
       
        srv.request.num_in = stoi(input);
        if (client.call(srv))
        {
            cout << "squared: " << (long int)srv.response.num_out << "\n";
        }
        else
        {
            ROS_ERROR("Failed to call service square");
            return 1;
        }
        
    }
    
 
   return 0;
}
   