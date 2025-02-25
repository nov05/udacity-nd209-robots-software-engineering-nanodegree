## 👉 Launch the enviroment

#### 🏷️ Launch the VMWare enviroment:
`Ubuntu-16.04` + `ROS` + `Gazebo Classic`  
The default user is `robond` (password `robo-nd`)  

```sh
$ gazebo
```

#### 🏷️ Launch the loacl environment: 
`WSL2 Ubuntu-22.04` + `ROS2` + `Gazebo Ignition Fortress`

```sh
$ echo "export LIBGL_ALWAYS_SOFTWARE=1" >> ~/.bashrc  ## skip if it has been added to ~/.bashrc with user "guido"
$ source ~/.bashrc   ## skip if it has been added
$ echo $LIBGL_ALWAYS_SOFTWARE  
$ ign gazebo    
$ ign gazebo --render-engine ogre2
$ sudo adduser robond  ## skip if user "robond" has been created, password "robo-nd"
$ sudo usermod -aG sudo robond  ## skip if user "robond" has been created
$ su - robond   ## switch current user to robond
```


## 👉 Course 2 Gazebo World, P1 Build a world (no ROS)

```sh
$ cd ~
$ git clone -b master https://<PAT>@github.com/nov05/udacity-RoboND-myrobot.git myrobot
$ mkdir -p myrobt/build
$ cd myrobot/build
$ sudo cmake ..
$ sudo make    ## You might get errors if your system is not up to date!
$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/robond/myrobot/build
$ echo $GAZEBO_PLUGIN_PATH
$ cd ~/myrobot/world
$ gazebo UdacityOffice --verbose
```

## 👉 Course 3 ROS Essentials, simple_arm

```sh
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
$ roslaunch simple_arm robot_spawn.launch
```

####  Run the simple_mover node in another terminal
```sh
$ cd ~/catkin_ws/
$ source devel/setup.bash
$ rosrun simple_arm simple_mover
```

#### To view the camera image stream, in one terminal:
```sh
$ rqt_image_view /rgb_camera/image_raw         ## or
$ rosrun rqt_image_view rqt_image_view         ## if run roscore first
```

#### Run look_away 
```sh
$ rosservice call /arm_mover/safe_move "joint_1: 0
joint_2: 0"
```

## 👉 Course 3, P2 my_robot

```sh
$ cd ~/catkin_ws/src
$ git clone -b main https://<PAT>@github.com/nov05/udacity-RoboND-p2-src.git src
$ cd ~/catkin_ws/
$ catkin_make
$ source devel/setup.bash
$ roslaunch my_robot my_empty_world.launch
```
