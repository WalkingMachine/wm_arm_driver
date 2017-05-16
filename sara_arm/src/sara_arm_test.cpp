//
// Created by philippe on 08/05/17.
//
// Description: Petit scripte pour tester les hardwares interface des moteurs kinova du bras de Sara.
//

#include "../include/sara_arm/sara_arm_kinova_motors.h"


int main(int argc, char **argv) {
    // ROS
    // Initialisation
    ROS_INFO("LOAD! LOAD! LOAD!");

    auto KHI1 = torso_arm_joint();
    //auto KHI2 = arm_shoulder_joint();
    //auto KHI3 = arm_rot_elbow_joint();
    //auto KHI4 = arm_elbow_joint();
    //auto KHI5 = arm_rot_wrist_joint();


    KHI1.StartTemperatureMonitoring(argc, argv);
    //KHI2.StartTemperatureMonitoring( argc, argv );
    //KHI3.StartTemperatureMonitoring( argc, argv );
    //KHI4.StartTemperatureMonitoring( argc, argv );
    //KHI5.StartTemperatureMonitoring( argc, argv );

    kinova_hardware_interface::StartStatusMonitoring( argc, argv );

    ROS_INFO("run. run! RUN!");
    while(ros::ok()){

        KHI1.Read();

        if ( (ros::Time::now().sec/2)%2 == 1 ){
            KHI1.cmd = 10;
        } else {
            KHI1.cmd = -10;
        }

        KHI1.Write();

        usleep(2000);

    }

    return 0;
}