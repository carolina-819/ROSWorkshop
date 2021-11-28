#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <iostream>
using namespace std;
ros::Publisher pub;

int main(int argc, char **argv){
    ros::init(argc, argv, "publisher_node");
    ros::NodeHandle nh;
    pub = nh.advertise<std_msgs::String>("comm_terminal", 1);

    cout << "press s to start publishing \n";
    std::string input;
    cin >> input; 
    while(input != "s"){
        cout << "press s to start publishing \n";
        cin >> input; 
    }
    cout << "press ctrl+z to exit \n";
    while(getline(cin, input)){
        std_msgs::String inpub;
        inpub.data = input;
        pub.publish(inpub);
       
        
    }
    ros::spin();
}