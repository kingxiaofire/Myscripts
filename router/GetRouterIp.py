#GetRouterIp on TL-WVR1200G

import requests
import json
import time
import re
from pyserverchan import pyserver

def encrypt_pwd(password):
    input1 = "RDpbLfCPsJZ7fiv"
    input3 = "yLwVl0zKqws7LgKPRQ84Mdt708T1qQ3Ha7xv3H7NyU84p21BriUWBU43odz3iP4rBL3cD02KZciXTysVXiV8ngg6vL48rPJyAUw0HurW20xqxv9aYb4M9wK1Ae0wlro510qXeU07kV57fQMc8L6aLgMLwygtc0F10a0Dg70TOoouyFhdysuRMO51yY5ZlOZZLEal1h0t9YQW0Ko7oBwmCAHoic4HYbUyVeU3sfQ1xtXcPcf1aT303wAQhv66qzW"
    len1 = len(input1)
    len2 = len(password)
    dictionary = input3
    lenDict = len(dictionary)
    output = ''
    if len1 > len2:
        length = len1
    else:
        length = len2
    index = 0
    while index < length:
        # 十六进制数 0xBB 的十进制为 187
        cl = 187
        cr = 187
        if index >= len1:
            # ord() 函数返回字符的整数表示
            cr = ord(password[index])
        elif index >= len2:
            cl = ord(input1[index])
        else:
            cl = ord(input1[index])
            cr = ord(password[index])
        index += 1
        # chr() 函数返回整数对应的字符
        output = output + chr(ord(dictionary[cl ^ cr]) % lenDict)
    return output

def login(password=''):
    encrypt_password = encrypt_pwd(password)
    #print(encrypt_password)
    url = 'http://192.168.1.1/'
    headers = {'Content-Type': 'application/json; charset=UTF-8'}
    payload = '{"method":"do","login":{"username":"admin","password":"%s"}}' % encrypt_password
    response = requests.post(url, data=payload, headers=headers)
    response_body = json.loads(response.text)
    return response_body

def get_ip(password):
    stok = login(password).get('stok')
    #print(stok)
    headers = {'Content-Type': 'application/json; charset=UTF-8'}
    url = '%sstok=%s/ds' % ('http://192.168.1.1/', stok)
    #print(url)

    payload1 = '{"method":"get","network":{"name":"if_mode","table":"if_info","filter":[{"base_name":["lan","wan1_eth"]}]},"online_check":{"table":"state"},"qos":{"table":"interface"},"dhcpd":{"table":"dhcpd_list"},"port":{"table":"port"},"system":{"table":"ifstat_list","name":["cpu_usage","mem_usage"]},"wireless":{"name":["wlan_host_2g","wlan_host_5g"],"table":["cur_channel","wlan_wds","sta_list"],"filter":[{"radio_id":"1"},{"radio_id":"2"}]},"guest_network":{"name":"guest_2g"}}'
    response1 = requests.post(url,headers=headers,data = payload1)
    #print(response1)
    #print(response1.text)
    #print('ok')
    rejson = response1.json()
    #print(rejson)
    ip = re.findall("172.\d\d.\d\d.\d\d", response1.text)
    #print(ip)
    #print('over')
    return ip

if __name__ == "__main__":

    newip = get_ip("your router password")
    #print(newip)

    svc = pyserver.ServerChan('your serverchan key')
    svc.output_to_weixin(newip)
