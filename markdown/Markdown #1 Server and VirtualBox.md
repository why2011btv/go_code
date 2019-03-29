
# 连接远程服务器
## 第一种：通过ssh连接

~ ssh why@amwork2017.55555.io -p 2212

## 第二种：通过OpenVPN连接服务器所在的LAN，下面的链接是在服务器（私网IP：10.1.1.12）上运行的一个container的jupyter

http://10.1.1.12:7771/

<img src="docker rl-gym.png" alt="drawing" width="1000"/>

注释：

why@junnan-gpu:~$ sudo docker pull jaimeps/rl-gym

why@junnan-gpu:~$ sudo nvidia-docker run -d -p 7771:8888 jaimeps/rl-gym

why@junnan-gpu:~$ sudo docker exec -it 26abd8a9f6df bash

<img src="docker 7771.png" alt="drawing" width="1000"/>
## 第三种：在服务器（私网IP：10.1.1.12）上运行jupyter notebook（端口8809）

https://amwork2017.55555.io:8809/

why@junnan-gpu:~$ nohup jupyter notebook > jupyter.out 2>&1 &
<img src="jupyter_notebook_config.png" width="500"/>

## 第四种：在服务器（私网IP：10.1.1.12）上运行tensorboard（端口6006），原理同第三种

## 下图展示了“虚拟服务器规则列表”

即必须从这里设置【外部端口】与【内部端口（即服务器的端口）】的映射规则

![](port 2212 8809 6006.png)

## 下图展示了“服务器所在的LAN的公网IP”

![](服务器所在的LAN的公网IP.png)

## 下图展示了“花生壳动态域名”，即amwork2017.55555.io

![](花生壳动态域名.png)
## 下图总结了上述的所有端口映射关系
![](端口映射关系.jpeg)

# VirtualBox
## 搭建过程
### 需要为虚拟机配置两个网络适配器

### Adapter 1
<img src="Adapter 1.png" alt="drawing" width="500"/>
### Adapter 2 (wrong)
<img src="Adapter 2 wrong.png" alt="drawing" width="500"/>

### 发现错误
<img src="could not start.png" alt="drawing" width="500"/>

### 需要create a new adapter：192.168.56.1，子网掩码 255.255.255.0
<img src="create a new adapter.png" alt="drawing" width="500"/>
### 这其实是一个gateway，网络的IP：192.168.56.0，广播的IP：192.168.56.255。虚拟机中的Adapter 1是enp0s3（inet: 10.0.2.15/24）即NAT，Adapter 2是enp0s8（inet: 192.168.56.101/24，这是私网IP，可通过MacBook的Terminal通过ssh连接，详见使用部分）即Host-Only Adapter
<img src="VirtualBox ifconfig.png" alt="drawing" width="1000"/>
### Adapter 2 (correct)
<img src="Adapter 2 correct.png" alt="drawing" width="500"/>

### 注释：
<img src="边缘路由器.jpeg" alt="drawing" width="300"/>
### 边缘路由器（如上图）为MacBook分配的IPv4为192.168.3.32
<img src="192.168.3.32.png" alt="drawing" width="500"/>
### 下图中的VirtualBox Host-Only Network即是前述name为【vboxnet0】的Adapter 2，在windows操作系统中它与WLAN都在【网络连接（网络适配器）】中设置
<img src="Network Adapter.png" alt="drawing" width="900"/>

## 使用
### ssh ubuntu@192.168.56.101
<img src="ssh ubuntu@192.168.56.101.png" width="600"/>
