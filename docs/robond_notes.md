## 👉 Launch the ROS enviroment

* `VMWare Workstation Pro` + a image of (`Ubuntu-16.04` + `ROS` + `Gazebo Classic`) or     
* `WSL2` + `Ubuntu-20.04` + `ROS Noetic` + `Gazebo 11 (Classic)`   
  The default user is `robond` (password `robo-nd`).  

```sh
$ source /opt/ros/noetic/setup.bash    ## when open a terminal or
$ echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc  ## do only once
$ source ~/.bashrc   ## do only once
$ gazebo
```


## 👉 Course 2 Gazebo World, P1 Build a world (no ROS)

```sh
$ cd ~
$ git clone -b master https://<PAT>@github.com/nov05/udacity-RoboND-myrobot.git myrobot  ## replace <PAT> with your token
$ mkdir -p myrobt/build
$ cd myrobot/build
$ sudo cmake ..
$ sudo apt-get update && sudo apt-get upgrade -y  
$ sudo make    ## You might get errors if your system is not up to date!
$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/robond/myrobot/build
$ echo $GAZEBO_PLUGIN_PATH
$ cd ~/myrobot/world
$ gazebo UdacityOffice --verbose
```

## 👉 Course 3 ROS Essentials, the `catkin` workspace directory

```
catkin_ws/
├── build/
├── devel/
└── src/                   ## managed by GitHub repo `udacity-RoboND-p2-src`
    ├── CMakeLists.txt  
    ├── simple_arm/        ## managed by GitHub repo `udacity-RoboND-simple_arm`
    ├── my_robot/
    └── ball_chaser/
```

## 👉 Course 3 ROS Essentials, the `simple_arm` package

```sh
$ cd ~
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ catkin_init_workspace
$ cd ~/catkin_ws
$ catkin_make
$ cd ~/catkin_ws/src/
$ git clone -b first_interaction https://<PAT>@github.com/nov05/udacity-RoboND-simple_arm simple_arm
$ cd ~/catkin_ws
$ catkin_make
$ echo "cd ~/catkin_ws" >> ~/.bashrc                        ## add to user .bashrc
$ echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc   ## add to user .bashrc
$ source devel/setup.bash
$ rosdep install -i simple_arm       ## output: e.g. #All required rosdeps installed successfully
$ rosdep check simple_arm            ## output: e.g. All system dependencies have been satisified
$ roslaunch simple_arm robot_spawn.launch   ## launch the robot arm
```

* View the camera image stream, in a new terminal
```sh
$ rqt_image_view /rgb_camera/image_raw    ## or
$ rosrun rqt_image_view rqt_image_view         
```

* Run `look_away`, in a new terminal
```sh
$ rosservice call /arm_mover/safe_move "joint_1: 0
joint_2: 0"                                                   ## or
$ rosservice call /arm_mover/safe_move "joint_1: 1.57
joint_2: 1.57"
```

* Run the `simple_mover` node 
```sh
$ rosrun simple_arm simple_mover
```

* Clear logs, etc. if needed
```sh
$ rm -rf ~/.ros/log
$ rm -rf ~/.ros
$ rm -rf ~/.gazebo
```



## 👉 Course 3, P2 my_robot

* Get the catkin packages from the repo (except that `simple_arm` is managed by another repo)
```sh
$ cd ~/catkin_ws/src/
$ git config --global init.defaultBranch main
$ git config --global user.email "you@example.com"    ## any content, no need to change
$ git config --global user.name "nov05"               ## your GitHub user ID
$ git init
$ git remote add origin https://<PAT>@github.com/nov05/udacity-RoboND-p2-src.git
$ it checkout -b main
$ git fetch origin
$ git merge origin/main --allow-unrelated-histories
$ git add .
$ git commit -m "init, fetch, merge with simple_arm repo"
$ git push --set-upstream origin main
$ cd ~/catkin_ws/
$ catkin_make
$ source devel/setup.bash
$ roslaunch my_robot empty_world.launch            ## or
$ roslaunch my_robot udacity_office.launch
```

* View the camera image stream, in a new terminal
```sh
$ rqt_image_view /camera/rgb/image_raw     ## or
$ rosrun rqt_image_view rqt_image_view           
```

* Run `my_robot` in a circle
```sh
$ rostopic pub /cmd_vel geometry_msgs/Twist  "linear:
    x: 0.1
    y: 0.0
    z: 0.0
angular:
    x: 0.0
    y: 0.0
    z: 0.1"
```

* Test `drive_bot` node
```sh
$ rosrun ball_chaser drive_bot
$ rosservice call /ball_chaser/command_robot "linear_x: 0.5
angular_z: 0.0"             # This request should drive your robot forward
$ rosservice call /ball_chaser/command_robot "linear_x: 0.0
angular_z: 0.5"             # This request should keep your robot left turning
$ rosservice call /ball_chaser/command_robot "linear_x: 0.0
angular_z: -0.5"            # This request should keep your robot right turning
$ rosservice call /ball_chaser/command_robot "linear_x: 0.0
angular_z: 0.0"             # This request should bring your robot to a complete stop
```

* Test `prcess_image` node
```sh
$ roslaunch my_robot empty_world.launch  
$ roslaunch my_robot udacity_office.launch
$ rqt_image_view /camera/rgb/image_raw  
$ rosrun ball_chaser process_image  
```

* Adjust the worlds, models, etc. if needed  
  ⚠️ Use `$ gazebo` to edit the worlds. **Do NOT** edit or save anything in `$ roslaunch`! 
```sh
$ gazebo ~/catkin_ws/src/my_robot/worlds/empty.world
$ gazebo ~/catkin_ws/src/my_robot/worlds/udacity_office.world --verbose
```  

* Clear logs, etc. if needed
```sh
$ rm -rf ~/.ros/log
$ rm -rf ~/.ros
$ rm -rf ~/.gazebo      ## it might take a while to re-download and re-render
```

* Re-build packages if needed
```sh
cd ~/catkin_ws               
catkin_make clean
catkin_make 
```

👉 Course 4, P3

* Do the same with `~/catkin_ws/` to create `~/catkin_ws2/`  

```sh
$ cd ~
$ mkdir -p ~/catkin_ws2/src
$ cd ~/catkin_ws2/src
$ catkin_init_workspace
$ cd ~/catkin_ws2
$ catkin_make
$ source devel/setup.bash
$ sudo apt-get update
$ sudo apt-get upgrade -y
```

* TurtleBot3 Gazebo Package

```sh
$ cd ~/catkin_ws2/src
$ git clone -b noetic https://github.com/ROBOTIS-GIT/turtlebot3.git
$ git clone -b noetic https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
$ git clone -b noetic https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
$ cd ~/catkin_ws2
$ catkin_make
```

* Launch the `Burger` bot

```sh
cd ~/catkin_ws2
source devel/setup.bash
export TURTLEBOT3_MODEL=burger
roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch  ## or
$ roslaunch turtlebot3_gazebo turtlebot3_world.launch  ## or
$ roslaunch turtlebot3_gazebo turtlebot3_house.launch
```
```sh
cd ~/catkin_ws2 ## in a new terminal
source devel/setup.bash  
export TURTLEBOT3_MODEL=burger
roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch    
```

* 

```sh
$ cd ~/catkin_ws2/src/
$ git config --global init.defaultBranch main
$ git config --global user.email "you@example.com"    ## any content, no need to change
$ git config --global user.name "nov05"               ## your GitHub user
$ git init
$ git remote add origin https://<PAT>@github.com/nov05/udacity-RoboND-p3-src2.git
$ git checkout -b main
$ git fetch origin
$ git merge origin/main --allow-unrelated-histories
$ git add .
$ git commit -m "initial commit from vm"
$ git push --set-upstream origin main
$ cd ~/catkin_ws2/
$ catkin_make
```

```
$ rosdep -i install turtlebot_gazebo
$ source devel/setup.bash
```   



