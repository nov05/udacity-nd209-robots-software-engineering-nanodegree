# 🟢 **Udacity Robots Software Engineering Nanodegree**  

Fuse computer vision, machine learning, mechanics, and hardware systems to build bots of the future!  
* Course: https://www.udacity.com/course/robotics-software-engineer--nd209  
* GitHub repo:  
    * https://github.com/nov05/udacity-nd209-robots-software-engineering-nanodegree  
    * https://github.com/nov05/udacity-RoboND-myrobot 
* Local env:
    * Windows 11
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

* Gazebo plugin after build

    ```sh
    export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/robond/myrobot/build
    echo $GAZEBO_PLUGIN_PATH
    robond@udacity:~/myrobot/world$ gazebo myworld --verbose
    ```

<br><br><br>  

# 👉 **Notes**

* [General notes](https://docs.google.com/document/d/1_Db2GAFUqI-keQkRsCEntAGOvuWH1VeEW4K6jkZvGR8)  

[All other notes for this project](https://drive.google.com/drive/folders/1rELDomnQWSf4vpBQr2bQLtAY1zxpogzx)  

<br><br><br>  

# 👉 **Logs**

* 2025-02-11 repo created  
