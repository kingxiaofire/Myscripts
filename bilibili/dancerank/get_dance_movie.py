import re
import os
import requests
import datetime as dt
import time

def init():
    today = dt.datetime.now().strftime('%F')
    name = str(today)

    if os.path.exists('path/html.txt'):
        #print('1')
        os.remove('path/html.txt')
    if os.path.exists('path/allurl.txt'):
        #print('2')
        os.remove('path/allurl.txt')
    if os.path.exists('path/geturl.txt'):
        #print('3')
        os.remove('path/geturl.txt')
    if os.path.exists('path'+name):
        #print('4')
        os.system('rm -rf $(date "+%Y-%m-%d")')
    os.mkdir('path'+name)

def getaddress():
    url = 'https://www.bilibili.com/v/popular/rank/dance'
    res = requests.get(url)
    address = re.findall('www.bilibili.com/video/(.*?) ', res.text)
    str1 = ''.join(address)
    str = 'https://www.bilibili.com/video/'
    zheng = str;
    with open('path/html.txt', 'w') as f:
        for i in str1:
            if i != '"':
                zheng = zheng + i
            elif i == '"':
                f.write(zheng + "\n")
                zheng = str
    #print("wirte done!")

def quchongfu():
    readPath = 'path/html.txt'
    writePath = 'path/allurl.txt'
    lines_seen = set()
    outfiile = open(writePath, 'a+', encoding='utf-8')
    f = open(readPath, 'r', encoding='utf-8')
    for line in f:
        if line not in lines_seen:
            outfiile.write(line)
            lines_seen.add(line)

def get_ten():
    readPath = 'path/allurl.txt'
    writePath = 'path/geturl.txt'
    lines_seen = set()
    outfiile = open(writePath, 'a+', encoding='utf-8')
    f2 = open(readPath, 'r', encoding='utf-8')
    tmp = 1
    for line in f2:
        if tmp <= 30:
            outfiile.write(line)
            lines_seen.add(line)
            # print(tmp)
            tmp = tmp + 1

def downloads():
    print("---------start downloading-----------")
    os.system('you-get -o path$(date "+%Y-%m-%d")  --no-caption -I path/geturl.txt')
    print("download ok!")

def severchan():
    key = "SCU93318Tead98719*************"
    url = "http://sc.ftqq.com/%s.send" % (key)
    payload = {'text': 'you-get nows', 'desp': 'you-get download is finished ！! !      完成时间是：'+time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())}
    requests.post(url, params=payload)

# def severchanNew():
#     key = "SCT7387TnRQ***********dWi"
#     url = "https://sctapi.ftqq.com/SENDKEY.send"%(key)
#     payload = {'text': 'you-get nows', 'desp': 'you-get download is finished'}
#     requests.post(url, params=payload)

if __name__ == '__main__':
    init()
    getaddress()
    quchongfu()
    get_ten()
    downloads()
    severchan()
    #severchanNew()
