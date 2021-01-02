# coding=utf-8
import requests
key = "xxxxxxxxxxx9871955ed58be15e302a61a373fxxxxxxxxxxx # your-key
url = "http://sc.ftqq.com/%s.send"%(key)
payload = {'text': 'Server酱提醒', 'desp': '测试消息'}
requests.post(url, params=payload)
