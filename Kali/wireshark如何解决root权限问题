准备：笔记本（manjaro liunx),安装wireshark(版本为2.2.8）

解决权限问题，wireshark要进行监控必须要有root权限才行，这十分危险也非常不便
1.添加wireshark用户组
sudo groupadd wireshark

2.将dumpcap改为wireshark用户组
sudo chgrp wireshark /usr/bin/dumpcap

3.让wireshark用户组有root权限使用dumpcap
sudo chmod 4755 /usr/bin/dumpcap

4.将需要使用的用户名加入wireshark用户组，我的用户名是kingxiaofire
sudo gpasswd -a kingxiaofire wireshark


参考资料http://www.cnblogs.com/craftor/p/3811733.html
