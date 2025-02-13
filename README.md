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

<br><br><br>  

# 👉 **Notes**

* [General notes](https://docs.google.com/document/d/1_Db2GAFUqI-keQkRsCEntAGOvuWH1VeEW4K6jkZvGR8)  

[All other notes for this project](https://drive.google.com/drive/folders/1rELDomnQWSf4vpBQr2bQLtAY1zxpogzx)  

<br><br><br>  

# 👉 **Logs**

* 2025-02-11 repo created  
