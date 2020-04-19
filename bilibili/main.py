import re
import os
import requests

url = 'https://www.bilibili.com/read/cv2306631'
#地址及发送请求
res = requests.get(url)

address = re.findall('https://www.bilibili.com/video/(.*?)>',res.text)
#print(address)
#正则获取视频编号
str1 = ''.join(address)
#转list为str

str = 'https://www.bilibili.com/video/'
#拼接完整的视频地址，并调用you-get下载
zheng = str;
filename = 'test.txt'
with open(filename, 'w') as f:
    for i in str1:
        if i != '"':
            zheng = zheng + i
        elif i=='"':#print(zheng)
            f.write(zheng+"\n")
            zheng = str
print("wirte done!")
os.system('you-get -o /Volumes/BackUp/data/datastructure/ --no-caption -I test.txt')
print("download ok!")
