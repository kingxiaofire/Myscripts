import requests

def login():
    url = 'http://172.16.1.11/drcom/login?callback=dr1009&DDDDD=studentNumber&upass=password&0MKKey=123456&R1=0&R2=&R3=0&R6=0&para=00&v6ip=&terminal_type=1&lang=zh-cn&jsVersion=4.1.3&v=2029&lang=zh'
    response = requests.get(url=url)
    print(response)
    print(response.text)

if __name__ == "__main__":
    login()    
