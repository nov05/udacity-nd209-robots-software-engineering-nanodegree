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
$ git clone -b master https://<PAT>@github.com/nov05/udacity-RoboND-myrobot.git myrobot
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
$ source devel/setup.bash
$ rosdep install -i simple_arm       ## output: e.g. #All required rosdeps installed successfully
$ rosdep check simple_arm            ## output: e.g. All system dependencies have been satisified
```

#### Launch the robot arm
```sh
cd ~/catkin_ws/
source devel/setup.bash
$ roslaunch simple_arm robot_spawn.launch
```

#### View the camera image stream, in a new terminal
```sh
cd ~/catkin_ws/
source devel/setup.bash
rqt_image_view /rgb_camera/image_raw           
```

or    
```sh
cd ~/catkin_ws/
source devel/setup.bash
rosrun rqt_image_view rqt_image_view
```

#### Run `look_away`, in a new terminal
```sh
cd ~/catkin_ws/
source devel/setup.bash
rosservice call /arm_mover/safe_move "joint_1: 0
joint_2: 0"
```

####  Run the `simple_mover` node
* This node will shut down `arm_mover` node. 
```sh
cd ~/catkin_ws/
source devel/setup.bash
rosrun simple_arm simple_mover
```

#### Clear logs
```sh
$ rm -rf ~/.ros/log
```



## 👉 Course 3, P2 my_robot

```sh
$ cd ~/catkin_ws/src/
$ git init
$ git remote add origin https://<PAT>@github.com/nov05/udacity-RoboND-p2-src.git
$ git fetch origin
$ git merge origin/main --allow-unrelated-histories
$ git add .
$ git commit -m "init, fetch, merge with simple_arm repo"
$ git config --global user.email "you@example.com"    ## any content
$ git config --global user.name "nov05"
$ git push --set-upstream origin main
$ cd ~/catkin_ws/
$ catkin_make
$ source devel/setup.bash
$ roslaunch my_robot empty_world.launch
```
