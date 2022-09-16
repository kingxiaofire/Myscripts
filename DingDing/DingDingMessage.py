import time
import hmac
import hashlib
import base64
import urllib.parse
import datetime
import json

timestamp = str(round(time.time() * 1000))
secret = '******'
secret_enc = secret.encode('utf-8')
string_to_sign = '{}\n{}'.format(timestamp, secret)
string_to_sign_enc = string_to_sign.encode('utf-8')
hmac_code = hmac.new(secret_enc, string_to_sign_enc, digestmod=hashlib.sha256).digest()
sign = urllib.parse.quote_plus(base64.b64encode(hmac_code))
#print(timestamp)
#print(sign)


url = f'https://oapi.dingtalk.com/robot/send?access_token=*******&timestamp={timestamp}&sign={sign}'

def send_request(url, datas):
    header = {
        "Content-Type": "application/json",
        "Charset": "UTF-8"
    }
    sendData = json.dumps(datas)
    sendDatas = sendData.encode("utf-8")
    request = urllib.request.Request(url=url, data=sendDatas, headers=header)
    opener = urllib.request.urlopen(request)
    # 输出响应结果
    print(opener.read())

def get_string():
    mess = '<font color=#00f0ff>这是一个测试</font> \n <font color=#0000ff>测试结果：成功！！！！</font>'
    return mess


def Send():
    # isAtAll：是否@所有人，建议非必要别选，不然测试的时候很尴尬
    dict = {
        "msgtype": "markdown",
        "markdown": {"title": "服务器通知",
                     "text": "这是text"
                     },
        "at": {
            "isAtAll": False
        }
    }

    #把文案内容写入请求格式中
    dict["markdown"]["text"] = get_string()
    send_request(url, dict)
    
if __name__=="__main__":
    Send()
