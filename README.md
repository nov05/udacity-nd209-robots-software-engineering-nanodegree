# 🟢 **Udacity Robots Software Engineering Nanodegree**  

Fuse computer vision, machine learning, mechanics, and hardware systems to build bots of the future!  
* Course: https://www.udacity.com/course/robotics-software-engineer--nd209  
* GitHub repo:  
    * https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree  
    * https://github.com/nov05/udacity-RoboND-myrobot 
* Workflow: 
    * Create repositories on **GitHub**.  
    * Download them to both the virtual machine and the local computer.   
    * Use the VM for graphic design in **Gazebo**, and handle coding and other tasks on the local machine using **VS Code**.
    * Synchronize all the work through GitHub between both environments.

<br><br><br> 

# 👉 **Project 1: Build My World - Udacity Office**

* ✅ [Directory structure](https://github.com/nov05/udacity-RoboND-myrobot) (<- Code is contained in this repo.)  

    ```bash
        .Project1                          # Build My World Project 
        ├── model                          # Model files 
        │   ├── Building
        │   │   ├── model.config
        │   │   ├── model.sdf
        │   ├── HumanoidRobot
        │   │   ├── model.config
        │   │   ├── model.sdf
        ├── script                         # Gazebo World plugin C++ script      
        │   ├── welcome_message.cpp
        ├── world                          # Gazebo main World containing models 
        │   ├── UdacityOffice.world
        ├── CMakeLists.txt                 # Link libraries 
        └──                              
    ```

* World design `UdacityOffice`  

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-02-14%2011_30_24-Udacity%20Robotics%20-%20VMware%20Workstation.jpg" width=800>  

* `UdacityOffice` world `welcome_message` plugin  

    <img src="https://raw.githubusercontent.com/nov05/pictures/refs/heads/master/Udacity/20250213_nd209_udacity_robotics_nanodegree/2025-02-14%2012_10_20-Udacity%20Robotics%20-%20VMware%20Workstation.jpg" width=800>

* Prompt **ChatGPT** to help design a robot model. Use **VS Code** to create the necessary model files locally, then commit those files to **GitHub**. Afterward, perform a `git pull` on the VM to retrieve the files from GitHub and import the model into Gazebo for testing and simulation.  

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
          VM name: `D:\Users\*\Virtual Machines\Udacity Robotics`
        * Check Ubuntu version in Terminator  
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
        * Check Robot Operating System (ROS) version in Terminator
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

* Clone GitHub repo to the VM `/home/workspace` folder  

    ```bash
    robond@udacity:/home/workspace$ sudo git clone https://github.com/nov05/udacity-RoboND-myrobot.git myrobot
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
    robond@udacity:/home/workspace/myrobot$ git push
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

* Gazebo plugin build

    ```sh
    $ sudo apt-get update && sudo apt-get upgrade -y
    $ gedit CMakeLists.txt
    $ cd build
    $ cmake ..
    $ make    ## You might get errors if your system is not up to date!
    $ export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/robond/myrobot/build
    $ echo $GAZEBO_PLUGIN_PATH
    $ cd /home/myrobot/world
    robond@udacity:~/myrobot/world$ gazebo UdacityOffice --verbose
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
<br><br><br>  

# 👉 **Tips**

* Once a building model is created, it can't be edited again using the `Building Editor`. ([StackExchange](https://robotics.stackexchange.com/a/27555))  

<br><br><br>  

# 👉 **Notes**

* [General notes](https://docs.google.com/document/d/1_Db2GAFUqI-keQkRsCEntAGOvuWH1VeEW4K6jkZvGR8)  

[All other notes for this project](https://drive.google.com/drive/folders/1rELDomnQWSf4vpBQr2bQLtAY1zxpogzx)  

<br><br><br>  

# 👉 **Logs**

* 2025-02-11 repo created  
