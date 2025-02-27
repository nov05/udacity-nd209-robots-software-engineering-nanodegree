# 🟢 **Udacity Robots Software Engineering Nanodegree**  

Fuse computer vision, machine learning, mechanics, and hardware systems to build bots of the future!  
* Course: https://www.udacity.com/course/robotics-software-engineer--nd209  
* GitHub repo:  
    * https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree  
    * https://github.com/nov05/udacity-RoboND-myrobot (Course 2, Project 1) 
    * https://github.com/nov05/udacity-RoboND-simple_arm (Course 3, as `~/catkin_ws/src/simple_arm` in VM) 
    * https://github.com/nov05/udacity-RoboND-p2-src (Course 3, P2, as `~/catkin_ws/src` in VM)
* Workflow: 
    * Create repositories on **GitHub**.  
    * Download them to both the virtual machine and the local computer.   
    * Use the VM for graphic design in **Gazebo**, and handle coding and other tasks on the local machine using **VS Code**.
    * Synchronize all the work through GitHub between both environments.    
* [All Bash commands](https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree/blob/main/docs/robond_notes.md) (to reproduce the results)


<br><br><br> 


# 👉 **Project 2: ROS Essentials**  

* Catkin Workspace `catkin_ws` Directory:  
    * ✅ 2 GitHub repositories: [`src`](https://github.com/nov05/udacity-RoboND-p2-src), [`simple_arm`](https://github.com/nov05/udacity-RoboND-simple_arm) (<- The development artifacts such as code is included here.) 
    * 2 Catkin packages: `simple_arm`, `my_robot`, `ball_chaser`     
    ```sh
    ~/catkin_ws/
    ├── build/
    ├── devel/
    └── src/                   ## managed by GitHub repo `udacity-RoboND-p2-src`
        ├── CMakeLists.txt  
        ├── simple_arm/        ## managed by GitHub repo `udacity-RoboND-simple_arm`
        ├── my_robot/
        └── ball_chaser/
    ```

* Operations:  
    * Launch `udacity_office.world` 
        ```sh
        $ cd ~/catkin_ws/
        $ source devel/setup.bash
        $ roslaunch my_robot udacity_office.launch
        ```

<br><br><br>  



# 👉 **Project 1: Build My World - Udacity Office**

* [<img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/icons/youtube_red_2000x2000.png" width=30> Watch the demo video](https://youtu.be/z1w60MefD5I)   

* ✅ [Directory structure](https://github.com/nov05/udacity-RoboND-myrobot) (<- Code is contained in this repo.)  

    ```sh
    ~/myrobot/                          # Build My World Project 
    ├── model/                          # Model files 
    │   ├── Building/
    │   │   ├── model.config
    │   │   ├── model.sdf
    │   ├── HumanoidRobot/
    │   │   ├── model.config
    │   │   ├── model.sdf
    ├── script/                         # Gazebo World plugin C++ script      
    │   ├── welcome_message.cpp
    ├── world/                          # Gazebo main World containing models 
    │   ├── UdacityOffice.world
    ├── CMakeLists.txt                  # Link libraries 
    └── ...                             
    ```

* World design `UdacityOffice`  

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-02-14%2011_30_24-Udacity%20Robotics%20-%20VMware%20Workstation.jpg" width=800>  

* `UdacityOffice` world `welcome_message` plugin  

    * You can add `$ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/robond/myrobot/build` by using `$ nano ~/.bashrc`.

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-02-14%2012_10_20-Udacity%20Robotics%20-%20VMware%20Workstation.jpg" width=800>

* Prompt **ChatGPT** to help design a robot model (generating some `.sdf` content). Use **VS Code** to create the necessary model files locally, then commit those files to **GitHub**. Afterward, perform a `git pull` on the VM to retrieve the files from GitHub and import the model into Gazebo for testing and simulation.  

    * Prompts:  

        > Design a simple humanoid robot in Gazebo with a body supported by three spherical wheels arranged in an equilateral triangle. The wheels enable movement in all directions. To maintain the robot's stability, add links between the wheels to keep their relative positions fixed, and connect the wheels to the body to prevent it from sinking to the ground.

* The world `UdacityOffice` with 2 instances of the robot `HumanoidRobot`   

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/imgonline-com-ua-twotoone-biiKjJPC49GKkhu7.jpg" width=800>   


<br><br><br>  

# 👉 **Environment**

* Local env:
    * Windows 11, VS Code  
    * VMWare Workstation Player Pro 17.0 for Windows ([blog](https://blogs.vmware.com/workstation/2024/05/vmware-workstation-pro-now-available-free-for-personal-use.html), [archive](https://web.archive.org/web/20250212212707/https://blogs.vmware.com/workstation/2024/05/vmware-workstation-pro-now-available-free-for-personal-use.html))   
        * Release 17.6.2 (`D:\Program Files (x86)\VMware\VMware Workstation\`)  
    * VM image [`RoboVM V2.1.0.zip`](https://s3-us-west-1.amazonaws.com/udacity-robotics/Virtual+Machines/Lubuntu_071917/RoboVM_V2.1.0.zip):
        * `Ubuntu 64-bit Robo V2.1.0.ova`, 4.85 GB  
          Powershell `Get-FileHash -Path "Ubuntu 64-bit Robo V2.1.0.ova" -Algorithm MD5`  
          VM name: `D:\Users\*\Virtual Machines\Udacity Robotics`, password `robo-nd`  
        * Check **Ubuntu** version in Terminator  
            ```bash
            robond@udacity:~$ lsb_release -a
            No LSB modules are available.
            Distributor ID:	Ubuntu
            Description:	Ubuntu 16.04.2 LTS
            Release:	16.04
            Codename:	xenial
            ```
        * Check CMake version `cmake --version` in Terminator  
          `cmake 3.5.1`
        * Check **Robot Operating System (ROS)** version in Terminator
            ```bash
            robond@udacity:~$ rosversion -d
            kinetic
            robond@udacity:~$ rosversion roscpp
            1.12.7
            ```
        * Check Gazebo version in Terminator  
            ```bash
            robond@udacity:~$ gazebo --version
            Gazebo multi-robot simulator, version 7.8.1
            Copyright (C) 2012 Open Source Robotics Foundation.
            Released under the Apache 2 License.
            http://gazebosim.org
            ```
        * Update the image in Terminator $`sudo apt-get update && sudo apt-get upgrade -y`  
        * Launch Gazebo in Terminator $`gazebo`

* Clone GitHub repo as the VM `/home/robond/myrobot/` folder  

    ```bash
    $ sudo git clone -b master https://<GitHub-PAT>@github.com/nov05/udacity-RoboND-myrobot.git myrobot
    Cloning into 'myrobot'...
    remote: Enumerating objects: 49, done.
    remote: Counting objects: 100% (12/12), done.
    remote: Compressing objects: 100% (7/7), done.
    remote: Total 49 (delta 2), reused 4 (delta 1), pack-reused 37 (from 1)
    Unpacking objects: 100% (49/49), done.
    Checking connectivity... done.
    ```
* Create a `Personal Access Token` on GitHub and push from the VM 

    ```sh
    robond@udacity:/home/robond/myrobot$ git push
    warning: push.default is unset; its implicit value has changed in
    Git 2.0 from 'matching' to 'simple'. To squelch this message
    and maintain the traditional behavior, use:

    git config --global push.default matching

    To squelch this message and adopt the new behavior now, use:

    git config --global push.default simple

    When push.default is set to 'matching', git will push local branches
    to the remote branches that already exist with the same name.

    Since Git 2.0, Git defaults to the more conservative 'simple'
    behavior, which only pushes the current branch to the corresponding
    remote branch that 'git pull' uses to update the current branch.

    See 'git help config' and search for 'push.default' for further information.
    (the 'simple' mode was introduced in Git 1.7.11. Use the similar mode
    'current' instead of 'simple' if you sometimes use older versions of Git)

    Username for 'https://github.com': nov05
    Password for 'https://nov05@github.com': 
    Counting objects: 50, done.
    Delta compression using up to 2 threads.
    Compressing objects: 100% (47/47), done.
    Writing objects: 100% (50/50), 109.89 KiB | 0 bytes/s, done.
    Total 50 (delta 9), reused 0 (delta 0)
    remote: Resolving deltas: 100% (9/9), completed with 1 local object.
    To https://github.com/nov05/udacity-RoboND-myrobot.git
    d491e63..9210327  master -> master
    error: update_ref failed for ref 'refs/remotes/origin/master': cannot lock ref 'refs/remotes/origin/master': Unable to create '/home/workspace/myrobot/.git/refs/remotes/origin/master.lock': Permission denied
    ```

# 👉 **Build and Launch**    

* Gazebo plugin build

    ```sh
    $ sudo apt-get update && sudo apt-get upgrade -y  ## Update the image
    $ gedit CMakeLists.txt
    $ cd build
    $ sudo cmake ..
    $ sudo make    ## You might get errors if your system is not up to date!
    $ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/robond/myrobot/build
    $ echo $GAZEBO_PLUGIN_PATH
    $ cd ~/myrobot/world
    $ gazebo UdacityOffice --verbose
    ```

    * Edit the world file, add the plugin information   
    ```
    $ gedit UdacityOffice
    ```
    ```
    <world name="defaul">
        <plugin name="welcome_message" filename="libwelcome_message.so"/>
    ```
* ✅ Tips: Gazebo remove model dirs

    ```sh
    $ gedit ~/.gazebo/gui.ini
    ```

* The course image has pre-installed the following package.
    * For class workspace:
        ```sh
        $ sudo apt-get install ros-noetic-controller-manager
        ```
    * For the VM image: 
        ```sh
        $ sudo apt-get install ros-kinetic-controller-manager
        ```

* Run Turtlesim nodes in 3 terminals  
    ```sh
    $ roscore
    $ rosrun turtlesim turtlesim_node
    $ rosrun turtlesim turtle_teleop_key
    ```

### 🏷️ **Course 3, `simple_arm`** 

* Build a **Catkin** workspace
    ```sh
    $ mkdir -p ~/catkin_ws/src
    $ cd ~/catkin_ws/src
    $ catkin_init_workspace
    $ ls -l
    $ cd ~/catkin_ws
    $ catkin_make
    $ ls   ## two new directories: build and devel
    ```
    * Output example:  
        ```bash
        robond@udacity:~/catkin_ws/src$ catkin_init_workspace
        Creating symlink "/home/robond/catkin_ws/src/CMakeLists.txt" pointing to "/opt/ros/kinetic/share/catkin/cmake/toplevel.cmake"
        ...
        $ catkin_make
        $ ls
        robond@udacity:~/catkin_ws$ ls
        build  devel  src
        ```

* Build and launch `simple_arm` package    
    * \<PAT\> ~ GitHub Personal Access Token  
    * `Ctrl+c` to kill all procs    
    ```sh
    $ cd ~/catkin_ws/src/
    $ git clone -b first_interaction https://<PAT>@github.com/nov05/udacity-RoboND-simple_arm simple_arm
    $ cd simple_arm
    $ git remote -v  ## check GitHub remote setup
    $ cd ~/catkin_ws
    $ catkin_make
    $ source devel/setup.bash
    $ rosdep install -i simple_arm  ## output: e.g. #All required rosdeps installed successfully
    $ rosdep check simple_arm  ## output: e.g. All system dependencies have been satisified
    $ roslaunch simple_arm robot_spawn.launch
    ```

* Create a new node `simple_mover` in `C++`
    ```sh
    $ cd ~/catkin_ws/src/simple_arm/
    $ mkdir src
    $ cd ~/catkin_ws/src/simple_arm/src/
    $ touch simple_mover.cpp
    ```
    * Build the node
    ```sh
    $ cd ~/catkin_ws/
    $ catkin_make
    ```
    * Launch the arm setting in one terminal
    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ roslaunch simple_arm robot_spawn.launch
    ```
    * Run the `simple_mover` mode in another terminal
    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ rosrun simple_arm simple_mover
    ```
    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250217_simple%20mover.gif" width=800>
    
* Create a service `GoToPosition` and check
    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ rossrv show GoToPosition
    ```
    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250217_gotoposition%20service.jpg" width=800>

* Add a node `arm_mover`, build and check. Make sure node `/arm_mover` and service `/arm_mover/safe_move` are there.  
    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ roslaunch simple_arm robot_spawn.launch
    $ rosnode list
    $ rosservice list
    ```

* To view the camera image stream, in one terminal:    
    ```sh
    $ rqt_image_view /rgb_camera/image_raw
    ```

    * In another terminal, rotate both joint 1 and joint 2 by approximately pi/2 radians: 
    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ rosservice call /arm_mover/safe_move "joint_1: 1.57
    joint_2: 1.57"
    ```
    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250218_simple_arm_camera_view.jpg" width=800>  

    * The resulting position of the arm was not expected. Looking at the roscore console, we can see the problem. The requested angle for joint 2 was out of the safe bounds, so it was clamped. We requested 1.57 radians, but the maximum joint angle was set to 1.0 radians.  

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250218_joint2_out_of_bounds.jpg" width=800>

    * By setting the max_joint_2_angle on the parameter server, we should be able to increase joint 2’s maximum angle and bring the blocks into view the next time we request a service.  
    ```sh
    $ rosparam set /arm_mover/max_joint_2_angle 1.57
    $ rosservice call /arm_mover/safe_move "joint_1: 1.57
    joint_2: 1.57"
    ```
    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250218_simple_arm_camera_view_2.jpg" width=800>  
 
* Add a node `look_away`. Launch `simple_arm` and camera view. Run the node.
    * Whenever the camera is pointed towards an uninteresting image - in this case, an image with uniform color - the callback function will request a safe_move service to safely move the arm back to the center position.   
    * The command below will direct the camera upwards, toward the ceiling, which has a uniform gray color.

    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ rosservice call /arm_mover/safe_move "joint_1: 0
    joint_2: 0"
    ```

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250218_look_away.gif" width=800>  

### 🏷️ **Course 3, P2 `my_robot` with `ball_chaser`**   

* Launch `empty.world`, with a Rviz (ROC Visualization) node  
    ```sh
    $ cd ~/catkin_ws/
    $ catkin_make
    $ source devel/setup.bash
    $ roslaunch my_robot empty_world.launch
    ```
    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250220-p2-my_robot-rviz.jpg" width=800> 
    
* ✅ Tips: Check Gazebo pre-defined materials (colors)
    ```sh
    $ nano /usr/share/gazebo-7/media/materials/scripts/gazebo.material    ## Gazebo 7 (ROS Kinetic)
    $ gedit /usr/share/gazebo-11/media/materials/scripts/gazebo.material   ## Gazebo 11 (ROS Notiec)
    ```

* Launch RViz seperately 
    ```sh
    $ roscore     ## in one terminal
    $ cd ~/catkin_ws      ## in another terminal 
    $ source devel/setup.bash
    $ rosrun rviz rviz
    ```    

* ✅ Tips: Remove unwanted RViz config save directories  
    ```sh
    $ gedit ~/.rviz/persistent_settings
    ```

* ✅ Tips: Check ROS topics, nodes, services
    ```sh
    $ rostopic list
    $ rosnode list
    $ rosservice list
    ```

* Create `ball_chaser` package
    ```sh
    $ cd ~/catkin_ws/src/
    $ catkin_create_pkg ball_chaser roscpp std_msgs message_generation
    ```

* Check `GoToTarget.srv`
    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ rossrv show DriveToTarget
    ```

* Test `drive_bot.cpp`
    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ roslaunch my_robot empty_world.launch
    $ rqt_image_view /camera/rgb/image_raw
    ```

* Enable the robot to move in a circle, without RViz node for performance issues caused by insufficient memory.     
    * *Testing the robot in a simple world, like an empty world, before using it in `udacity_office.world` will save you time.*  
    ```sh
    rostopic pub /cmd_vel geometry_msgs/Twist  "linear:
        x: 0.1
        y: 0.0
        z: 0.0
    angular:
        x: 0.0
        y: 0.0
        z: 0.1"
    ```
    <img src="https://github.com/nov05/pictures/blob/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250227_udacity_nd209_p2_robot_circling_in_empty_world.gif?raw=true" width=800>    

* Request a `ball_chaser/command_robot` service
    ```sh
    $ cd ~/catkin_ws/
    $ source devel/setup.bash
    $ rosservice call /ball_chaser/command_robot "linear_x: 0.5
    angular_z: 0.0"  # This request should drive your robot forward
    $ rosservice call /ball_chaser/command_robot "linear_x: 0.0
    angular_z: 0.5"  # This request should drive your robot left
    $ rosservice call /ball_chaser/command_robot "linear_x: 0.0
    angular_z: -0.5"  # This request should drive your robot right
    $ rosservice call /ball_chaser/command_robot "linear_x: 0.0
    angular_z: 0.0"  # This request should bring your robot to a complete stop
    ```




<br><br><br>  

# 👉 **Tips**

* Once a building model is created, it can't be edited again using the `Building Editor`. ([StackExchange](https://robotics.stackexchange.com/a/27555))    

* The 
    `$ sudo gedit opt/ros/kinetic/lib/python2.7/dist-packages/gazebo_ros/gazebo_interface.py` 
    ```python  
    ```

* Find ROSLaunch processes and kill them  
    ```sh
    $ ps aux | grep roslaunch
    $ kill -9 <PID>
    ```
    * Output example 
        ```sh
        robond@udacity:~/catkin_ws$ ps aux | grep roslaunch
        robond    15057  0.1  0.4 323936 54212 pts/0    Tl   14:36   0:02 /usr/bin/python /opt/ros/kinetic/bin/roslaunch my_robot udacity_office.launch
        robond    16575  0.6  0.4 317344 53844 pts/0    Tl   15:02   0:00 /usr/bin/python /opt/ros/kinetic/bin/roslaunch my_robot udacity_office.launch
        robond    16989  0.0  0.0  14224   940 pts/0    S+   15:03   0:00 grep --color=auto roslaunch
        robond@udacity:~/catkin_ws$ kill -9 15057
        robond@udacity:~/catkin_ws$ kill -9 16575
        [1]-  Killed                  roslaunch my_robot udacity_office.launch
        ```
    ```sh
    rm -rf ~/.gazebo
    rm -rf ~/.ros
    ```

* Check model xacro files  

    ```sh
    $ sudo apt install liburdfdom-tools
    $ check_urdf simple_arm.gazebo
    ```  

    * e.g.  

        ```sh
        robond@guido:~/catkin_ws/src/simple_arm/urdf$ check_urdf simple_arm.gazebo.xacro                                                                        
        Error:   No name given for the robot.                                                                                                                   
                at line 118 in /build/urdfdom-VnCcob/urdfdom-1.0.4+ds/urdf_parser/src/model.cpp
        ERROR: Model Parsing the xml failed
        ```

<br><br><br>  

# 👉 **Notes**

* [General notes](https://docs.google.com/document/d/1_Db2GAFUqI-keQkRsCEntAGOvuWH1VeEW4K6jkZvGR8) (Google Docs)  
* ⚠️ [Issues](https://gist.github.com/nov05/4bc90dcbfdd213fd1072c3dc85becdbf) (GitHub Gists)  
* ✅ [Create VM from `.ova` file on GCP](https://docs.google.com/document/d/14UFho0Y016uKzwcONHoIvHx2xc6Wgn7RNHu0Xd1vahk) (Google Docs) 
* ✅ [Set up local environment: `WSL2` (Windows), `Ubuntu 20.04`, `ROS`, `Gazebo 11`](https://docs.google.com/document/d/1c6htbHJtTnH5DlThJWyB1n5-uOvXrUQCbhXYm8RntIk) (Google Docs)    
* ✅ [Set up local environment: `WSL2` (Windows), `Ubuntu 22.04`, `ROS2`, `Gazebo Ignition Fortress`](https://docs.google.com/document/d/1-kdRcZU29-APLef3PFzGOV_zRALEjms1VU0im_0pCfU) (Google Docs)     

[All other notes for this project](https://drive.google.com/drive/folders/1rELDomnQWSf4vpBQr2bQLtAY1zxpogzx) (Google Drive)  

<br><br><br>  

# 👉 **Logs**

* 2025-02-14 p1 submission, [LinkedIn post](https://www.linkedin.com/posts/wenjingliu7_robotics-simulation-activity-7296250187637735425-HLvY)    
* 2025-02-11 repo created  
