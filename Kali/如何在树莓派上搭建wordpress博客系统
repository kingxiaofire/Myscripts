前提：树莓派2B+一个，笔记本电脑（装的manjaro系统），读卡器，网线（或者外置的无线网卡），HDMI线（或不用），键鼠（或不用）
1.在树莓派官网（www.raspberrypi.org)下载系统，用读卡器写好镜像（好在manjaro上自带的imagewrite可以写镜像）
2.在系统ROOT分区中新建一个名为“SSH"的文件 /×因为下的这个版本的系统默认ssh是关闭的，尽管通过”service ssh start“命令可以开启，但是关机后又关闭了，可以添加到启动项，可是我没有成功×/
3.进入路由器管理页面，找到Pi的ip /×我用的是小米路由器3C，并没有找到IP，可以用扫描ip的工具的，但是电脑系统不支持，所以NDMI线就派上用场了×/
4.开机，有Putty以ssh、方式连接树莓派 /×好在manjaro上有putty，打开后输入树莓派的ip就可以连接了，默认登录名为pi 密码 raspberry，输入passwd更换密码×/
5.换源： sudo nano /etc/apt/sources.list 我这里采用的是中科大的源，感觉良好
deb http://mirrors.ustc.edu.cn/raspbian/raspbian/ jessie main non-free contrib
deb-src http://mirrors.ustc.edu.cn/raspbian/raspbian/ jessie main non-free contrib
6.安装nginx，作为反向代理
sudo apt-get install nginx;
sudo /etc/init.d/nginx start;
sudo apt-get install php5-fpm php5-sqlite sqlite sqlite3;
7.修改配置文件
sudo nano /etc/nginx/sites-available/default;
进入后，端口和root不用修改
（1）修改index：在原有基础上加一个index.php
（2）修改php:(其实代码原来就有，只需要将注释符号去掉就行）
location ~ .php${
fastcgi_pass unix:?var/run?php5-fpm.sock;
fastcgi_index index.php;
include fastcgi_params;
}
8.重载
sudo /etc/init.d/nginx reload;
在浏览器中输入树莓派的ip，即可看到提示页面
welcome to nginx on debian
9.加一步操作
cd /var/www/html;
sudo vi index.php;
按a追加输入
按ESC
：wq 保存退出
/×讲真，这一步我不知道有什么作用，不过再输入ip的时候变成李phpinfo()页面了，暂且当作这是验证的操作×/
10.下载wordpress
删掉 /var/www/html 里面的东西，把wordpress的zip解压到里面
(1） 到wordpress官网（http://wordpress.org)找下载链接（我用的是：http://wordpress.org/lastest.tar.gz)
(2) cd /var/www/html;
(3) wget http://wordpress.org/lastest.tar.gz;
(4) sudo tar -xzvf lastest.tar.gz;
(5) mv /var/www/html wordpress/* /var/www/html; (把wprdpress移动到html里）
11.安装MYSQL 
(1) sudo apt-get install php5-mysql;／／(php5的mysql模块）
sudo apt-get install mysql-server;
(2) 设置MYSQL数据库（其中123456为wordpress数据库密码）
$mysql -u root -p;
mysql>CREATE DATABASE wordpress;
mysql>GRANT ALL PRIVILEGES ON wordpress.*TO "wordpress"@"localhost"IDENTIFIED BY "123456";
mysql>FLUSH PRIVILEGES;
mysql>EXIT
(3)打开 /var/www/html目录，将wp-config-sample.php文件名改为wp-config.php并修改：
sudo cd /var/www/html;
sudo mv wp-config-sample.php wp-config.php;
define('DB_NAME','wordpress');
define('DB_USER','wordpress');
define('DB_PASSWORD','123456');
(4)重启 nginx和php5-fpm
sudo service nginx restart;
sudo service php5-fpm restart;
12.在浏览器中输入192.168.1.107/wp-admin，进入管理页面，输入密码123456进入输入192.168.1.107访问博客
13.如何解决内网穿透（尚未实践）
   方法1：购买”花生棒“和网线 rmb：98元
   方法2：前提是有一个有公网ip的服务器用frp或者ngork:需要在服务器上装服务端，在树莓派上装客户端

参考资料： 
http://blog.csdn.net/embbnux/article/details/18841033 
https://www.linuxdashen.com/%e5%a6%82%e4%bd%95%e5%9c%a8%e6%a0%91%e8%8e%93%e6%b4%be%e4%b8%8a%e5%ae%89%e8%a3%85wordpress
http://zhidx.com/p/59.html 等
