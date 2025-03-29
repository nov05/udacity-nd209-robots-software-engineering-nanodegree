# 🟢 **Udacity Robots Software Engineering Nanodegree**  

Fuse computer vision, machine learning, mechanics, and hardware systems to build bots of the future!  
* Course: https://www.udacity.com/course/robotics-software-engineer--nd209  
* GitHub repo:  
    * https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree (this repo)  
    * https://github.com/nov05/udacity-RoboND-myrobot (Course 2, Project 1, as `~/myrobot` in VM) 
    * https://github.com/nov05/udacity-RoboND-simple_arm (Course 3, as `~/catkin_ws/src/simple_arm` in VM) 
    * https://github.com/nov05/udacity-RoboND-p2-src (Course 3, Project 2, as `~/catkin_ws/src` in VM)  
    * https://github.com/nov05/udacity-RoboND-p3-src2 (Course 4, Proejct 3, as `~/catkin_ws2/src` in VM)
* Workflow: 
    * Create repositories on **GitHub**.  
    * Download them to both the virtual machine and the local computer.   
    * Use the VM for graphic design in **Gazebo**, and handle coding and other tasks on the local machine using **VS Code**.
    * Synchronize all the work through GitHub between both environments.    
* [All Bash commands](https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree/blob/main/docs/robond_notes.md) (to reproduce the results)


<br><br><br> 

# 👉 **Project 3: Localization - Where Am I?**  

* Launch `my_robot` and `amcl` nodes in the `udacity_office` world. 

    * Tips: 
        1. [The base link name of the robot](https://github.com/nov05/udacity-RoboND-p3-src2/tree/main/my_robot/urdf) has to be `base_link`, or warnings will flood the terminal.  
        2. `Shift`+`Ctrl`+`left click`: Move the world along the X and Y axes in `RViz`. 
    

  <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-28%2013_06_32-amcl.rviz%20-%20RViz%20(Ubuntu-20.04).jpg" width=800>      

    * Make sure to [configure the `amcl` parameters](http://wiki.ros.org/amcl#Parameters) properly. Check [my `config` folder](https://github.com/nov05/udacity-RoboND-p3-src2/tree/main/main/config) for reference.    

  <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-28%2014_05_19-Settings.jpg" width=800>

<br>  

* View the map topic `/move_base/global_costmap/costmap` in RViz. The walls and other obstacles are represented by black pixels, indicating that the cost is extremely high, which causes the path planning to avoid them.

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-28%2020_26_56_move_base-global_costmap-costmap.jpg" width=800>  


<br><br><br>  

# 👉 **Project 2: ROS Essentials - Go Chase It!**  

* [<img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/icons/youtube_red_2000x2000.png" width=30> Watch the demo video](https://www.youtube.com/watch?v=E2hdfOP_BzM)   

    * Note: `RViz` was causing insufficient memory issues on my local machine, so I’m using the camera window for visualization instead.

* Explore Room 3, find a Mars rover  

    <img src="https://github.com/nov05/pictures/blob/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/p2_cover_mars_rover.gif?raw=true" width=800>     

* Explore Room 2, go around the fountain  

    <img src="https://github.com/nov05/pictures/blob/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/p2_cover_02_hallway.gif?raw=true" width=800>  

* Explore Room 4, go under the ladder  

    <img src="https://github.com/nov05/pictures/blob/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/p2_cover_03_ladder.gif?raw=true" width=800>   

<br>  

* Environment: `Windows 11`, `WSL2`, `Ubuntu 20.04`, `Gazebo 11` (Classic), `ROS Noetic`, `Nvidia` GPU   

* Bash commands to reproduce the results:    
    * Launch `Go Chase It`.
        ```sh
        $ mkdir catkin_tmp
        $ cd ~/catkin_tmp/
        $ git clone https://github.com/nov05/udacity-RoboND-p2-src.git src
        $ git clone https://github.com/nov05/udacity-RoboND-simple_arm.git src/simple_arm  ## optional, skip if you want
        $ catkin_make
        $ source devel/setup.bash
        $ roslaunch my_robot udacity_office.launch          ## or
        $ roslaunch my_robot udacity_office_camera.launch   ## with "rqt_image_view" node to display the camera view
        $ cd ~
        $ rm -rf ~/catkin_tmp/                               ## ⚠️ delete the workspace
        ```
        
* Catkin Workspace `catkin_ws` Directory:  
    * ✅ 2 GitHub repositories: [`src`](https://github.com/nov05/udacity-RoboND-p2-src), [`simple_arm`](https://github.com/nov05/udacity-RoboND-simple_arm) (The development artifacts such as code, etc. are included here.) 
    * 3 Catkin packages: `my_robot`, `ball_chaser`, `simple_arm` (`simple_arm` isn't part of Project 2 "Go Chase It".)      
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
    * Detailed file structure of the repo `src`
        ```sh
        ~/catkin_ws/src/                   # Project 2, "Go Chase It"
        ├── my_robot                       # my_robot package                   
        │   ├── launch                     # launch folder for launch files   
        │   │   ├── my_robot.launch
        │   │   ├── udacity_office.launch
        │   │   └── empty_world.launch
        │   ├── meshes                     # meshes folder for sensors
        │   │   └── hokuyo.dae
        │   ├── urdf                       # urdf folder for xarco files
        │   │   ├── my_robot.gazebo
        │   │   └── my_robot.xacro
        │   ├── world                      # world folder for world files
        │   │   ├── udacity_office.world
        │   │   └── empty_world.world
        │   ├── CMakeLists.txt             # compiler instructions
        │   └── package.xml                # package info
        ├── ball_chaser                    # ball_chaser package                   
        │   ├── launch                     # launch folder for launch files   
        │   │   └── ball_chaser.launch
        │   ├── src                        # source folder for C++ scripts
        │   │   ├── drive_bot.cpp
        │   │   └── process_images.cpp
        │   ├── srv                        # service folder for ROS services
        │   │   └── DriveToTarget.srv
        │   ├── models                     # model folder for sdf files
        │   │   └── my_ball
        │   │       ├── model.config
        │   │       └── model.sdf
        │   ├── CMakeLists.txt             # compiler instructions
        │   └── package.xml                # package info                  
        └── ...  
        ```  

        <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-01%2014_16_10-p2_vscode_dir.jpg" width=800>  

    <br>  

    * The `/my_robot/launch/udacity_office.launch` file is responsible for launching the world and several other nodes. This includes `/my_robot/launch/my_robot.launch`, which launches the `my_robot` model, and `/ball_chaser/launch/ball_chaser.launch`, which launches the `my_ball` model. RViz was originally supposed to be launched as well, but due to the limited video memory on my local machine, I opted to use camera windows for visualizing the simulation instead.

    * If you would need to change the initial positions of `my_robot` and `my_ball`, you can edit the following arguments in `udacity_office.launch`.

        <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-01%2018_10_17-README.md%20-%20udacity-nd209_XML.jpg" width=400>  

        ```xml
        <!-- Launch other relevant files-->
        <include file="$(find my_robot)/launch/my_robot.launch">
            <!-- Robot Pose -->
            <arg name="my_robot_x" default="0" />
            <arg name="my_robot_y" default="-6.5" />
            <arg name="my_robot_z" default="0" />
            <arg name="my_robot_roll" default="0" />
            <arg name="my_robot_pitch" default="0" />
            <arg name="my_robot_yaw" default="1.5707" />
        </include>
        <include file="$(find ball_chaser)/launch/ball_chaser.launch">
            <!-- My Ball Pose -->
            <arg name="my_ball_x" default="0" />
            <arg name="my_ball_y" default="-10.5" />
            <arg name="my_ball_z" default="0" />
            <arg name="my_ball_roll" default="0" />
            <arg name="my_ball_pitch" default="0" />
            <arg name="my_ball_yaw" default="0" />
        </include>
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

### 🏷️ **Course 4, Localization**

* `Turtlebot3` on `ROS`-Noetic, launch the `burger` robot in an empty world.   

    ```sh
    cd ~/catkin_ws2/src
    source devel/setup.bash
    export TURTLEBOT3_MODEL=burger
    roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch
    ```

    ```sh
    cd ~/catkin_ws2/src  ## in a new terminal
    source devel/setup.bash  
    export TURTLEBOT3_MODEL=burger
    roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch    
    ```

    <img src="https://github.com/nov05/pictures/blob/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250307_turtlebot3_ros-noetic.gif?raw=true" width=800>   

* `turtlebot3_world.launch` and `turtlebot3_house.launch`  

    ```sh
    $ roslaunch turtlebot3_gazebo turtlebot3_world.launch  ## or
    $ roslaunch turtlebot3_gazebo turtlebot3_house.launch
    ```

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-07%2020_23_13-Gazebo%20(Ubuntu-20.04).jpg" width=350><img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-07%2020_28_00-Gazebo%20(Ubuntu-20.04).jpg" width=350>

* **Sensor fusion**: `ROS Noetic` + `Turtlebot3` + `robot_pose_ekf` (Extended Kalman Filter)

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-09%2013_16_28-rqt_graph__RosGraph%20-%20rqt%20(Ubuntu-20.04).jpg" width=800>


* There are 3 models in [`Turtlebot3`](https://web.archive.org/web/20250310023522/https://www.turtlebot.com/about/): `burger`, `waffle`, `waffle_pi`. However `burger` isn't equipped with camera, while `burger_for_autorace` is.  
    * burger: [`turtlebot3\turtlebot3_description\urdf\turtlebot3_burger.gazebo.xacro`](https://github.com/nov05/udacity-RoboND-p3-src2/blob/main/turtlebot3/turtlebot3_description/urdf/turtlebot3_burger.gazebo.xacro)   
    * burger_for_autorace: [`turtlebot3\turtlebot3_description\urdf\turtlebot3_burger_for_autorace.gazebo.xacro`](https://github.com/nov05/udacity-RoboND-p3-src2/blob/main/turtlebot3/turtlebot3_description/urdf/turtlebot3_burger_for_autorace.gazebo.xacro)    

    ```sh
    $ export TURTLEBOT3_MODEL=burger_for_autorace
    $ roslaunch turtlebot3_gazebo turtlebot3_world.launch
    $ rosrun rqt_image_view rqt_image_view   ## in a new terminal, topic /camera/image
    ```
    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-09%2021_18_45-turtlebot3_burger_for_autorace_emptyworld_camera.jpg" width=800>

* **Extended Kalman Filter** packages

    * `$ roslaunch main main.launch 2> >(grep -v TF_REPEATED_DATA|at line 278)   ## temporary fix`

    <img src="https://github.com/nov05/pictures/blob/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250309_ekf_lab.mp4.gif?raw=true" width=800>   

    * `$ rosrun rqt_multiplot rqt_multiplot --multiplot-config ~/catkin_ws2/src/main/multiplot/ekf_lab.xml`

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-03-09%2023_45_05-ekf_lab_multiplot.jpg" width=800>  

* **Monte Carlo Localization (MCL)** 

    * [<img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/icons/youtube_red_2000x2000.png" width=30> Watch the demo video](https://www.youtube.com/watch?v=v1gJgE3LUK0)    

    * To run a `C++` script including the `Python==2.7` pakcage `matplotlib==2.2` in `Windows 11` `VS Code` with the `C/C++ Extension Pack` plugin, carefully configurate `c_cpp_properties.json`, `launch.json`, `tasks.json` in [the `.vscode` folder](https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree/tree/main/.vscode), and `Shift+Ctrl+D` then select the right launch configuration label. Make sure to activate the right Python environment (e.g. `$ conda activate robond_py27` for me) in the debug terminal, and set the proper environment variables (e.g Powershell `$env:PYTHONHOME="D:\Users\guido\miniconda3\envs\robond_py27"` and `$env:PYTHONPATH="D:\Users\guido\miniconda3\envs\robond_py27\Lib"`).

    * Change the `matplotlibcpp.h` if necessary. E.g.
        ```cpp
        // Py_DECREF(args);  // nov05
		if (args) {
			Py_INCREF(args);
			Py_DECREF(args);
		}
        ```

    * [matplotlibcpp.h](https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree/blob/main/scripts/include/matplotlibcpp.h), [mcl_visualization.cpp](https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree/blob/main/scripts/pycpp/mcl_visualization.cpp)    

        <img src="https://github.com/nov05/pictures/blob/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/20250311_monte%20carlo%20localization.gif?raw=true" width=400>  

* The `bgm_map_creator` package    

    * [Install the package and generate `.pgm` maps](https://github.com/nov05/pgm_map_creator_JZX-MY_20250326).   
        ```sh
        $ cd ~/catkin_ws2
        ## ⚠️ add plugin to the world file, create launch files accordingly
        $ gzserver src/pgm_map_creator/worlds/udacity_office.world          ## no Gazebo GUI
        ## or $ roslaunch pgm_map_creator udacity_office_open_world.launch  ## Gazebo GUI
        $ roslaunch pgm_map_creator udacity_office_request_publisher.launch 
        ```

        If the map is generated successfully, you will see the following messages in the terminal.  
        ```sh
        ...
        Percent complete: 99.5
        Percent complete: 99.625
        Percent complete: 99.75
        Percent complete: 99.875
        Completed calculations, writing to image
        running
        Output location: /home/robond/catkin_ws2/src/pgm_map_creator/maps/map
        ```

    * [Check the `.pgm` maps](https://github.com/nov05/udacity-RoboND-p3-src2/tree/main/pgm_map_creator/maps). You can convert `.pgm` to `.jpg` and edit it then convert it back. For example, I added "doors" to the map of the `udacity_office.world`.      

        <img src="https://raw.githubusercontent.com/nov05/udacity-RoboND-p3-src2/refs/heads/main/pgm_map_creator/maps/20250326_udacity_office_bgm.jpg" width=400><img src="https://raw.githubusercontent.com/nov05/udacity-RoboND-p3-src2/refs/heads/main/pgm_map_creator/maps/20250326_udacity_office_pgm_edited.jpg" width=400>    


<br><br><br>  

# 👉 **Tips**

* Once a building model is created, it can't be edited again using the `Building Editor`. ([StackExchange](https://robotics.stackexchange.com/a/27555))    

* You could technically apply a monkey patch to the Python code, but it's generally not recommended.  
    ```sh
    $ sudo gedit /opt/ros/kinetic/lib/python2.7/dist-packages/gazebo_ros/gazebo_interface.py
    $ sudo gedit /opt/ros/noetic/lib/python3/dist-packages/gazebo_ros/gazebo_interface.py
    ```
    ```python  
    def spawn_sdf_model_client(model_name, model_xml, robot_namespace, initial_pose, reference_frame, 
                               gazebo_namespace):
    ...
    def spawn_urdf_model_client(model_name, model_xml, robot_namespace, initial_pose, reference_frame, 
                                gazebo_namespace):
        rospy.loginfo("Waiting for service %s/spawn_urdf_model"%gazebo_namespace)
        rospy.wait_for_service(gazebo_namespace+'/spawn_urdf_model')
        try:
            spawn_urdf_model = rospy.ServiceProxy(gazebo_namespace+'/spawn_urdf_model', SpawnModel)
            rospy.loginfo("Calling service %s/spawn_urdf_model"%gazebo_namespace)
            resp = spawn_urdf_model(model_name, model_xml, robot_namespace, initial_pose, reference_frame)
            rospy.loginfo("Spawn status: %s"%resp.status_message)
            return resp.success
        except rospy.ServiceException as e:
            print("Service call failed: %s" % e)
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

* Check `RViz`: In one terminal run `$ roscore`, in another run `$ rosrun rviz rviz`. (Cehck [example output](https://gist.github.com/nov05/4bc90dcbfdd213fd1072c3dc85becdbf?permalink_comment_id=5476872#gistcomment-5476872))

<br><br><br>  

# 👉 **Notes**

* [General notes](https://docs.google.com/document/d/1_Db2GAFUqI-keQkRsCEntAGOvuWH1VeEW4K6jkZvGR8) (Google Docs)  
* ⚠️ [Issues](https://gist.github.com/nov05/4bc90dcbfdd213fd1072c3dc85becdbf) (GitHub Gists, [Web Archive](https://web.archive.org/web/20250301014245/https://gist.github.com/nov05/4bc90dcbfdd213fd1072c3dc85becdbf))  
* ✅ [Create VM from `.ova` file on `Google Cloud Platform` (GCP)](https://docs.google.com/document/d/14UFho0Y016uKzwcONHoIvHx2xc6Wgn7RNHu0Xd1vahk) (Google Docs) 
* ✅ [Set up local environment: `WSL2` (Windows), `Ubuntu 20.04`, `ROS Noetic`, `Gazebo 11`](https://docs.google.com/document/d/1c6htbHJtTnH5DlThJWyB1n5-uOvXrUQCbhXYm8RntIk) (Google Docs)    
* ✅ [Set up local environment: `WSL2` (Windows), `Ubuntu 22.04`, `ROS2`, `Gazebo Ignition Fortress`](https://docs.google.com/document/d/1-kdRcZU29-APLef3PFzGOV_zRALEjms1VU0im_0pCfU) (Google Docs)     

[All other notes for this project](https://drive.google.com/drive/folders/1rELDomnQWSf4vpBQr2bQLtAY1zxpogzx) (Google Drive)  

<br><br><br>  

# 👉 **Logs**

* 2025-03-01 p2 submission, [LinkedIn Post](https://www.linkedin.com/posts/wenjingliu7_20250301-go-chase-it-robotics-simulation-activity-7301743680053252096-KB2n)    
* 2025-02-27 p2 milestone, robot car circling is enabled, [LinkedIn post](https://www.linkedin.com/posts/wenjingliu7_20250227-udacity-nd209-course-3-p2-robot-activity-7300978129106350080-dVn6/)   
* 2025-02-14 p1 submission, [LinkedIn post](https://www.linkedin.com/posts/wenjingliu7_robotics-simulation-activity-7296250187637735425-HLvY)    
* 2025-02-11 repo created   
