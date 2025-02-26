## 👉 Launch the ROS2 environment

* `WSL2` + `Ubuntu-22.04` + `ROS2` + `Gazebo Ignition Fortress`
  Created a user `robond` (password `robo-nd`) 

```sh
$ echo "export LIBGL_ALWAYS_SOFTWARE=1" >> ~/.bashrc  ## skip if it has been added to ~/.bashrc with user "guido"
$ source ~/.bashrc   ## skip if it has been added
$ echo $LIBGL_ALWAYS_SOFTWARE  
$ sudo adduser robond  ## skip if user "robond" has been created, password "robo-nd"
$ sudo usermod -aG sudo robond  ## skip if user "robond" has been created
$ su - robond   ## switch current user to robond
$ ign gazebo    
$ ign gazebo --render-engine ogre2
```