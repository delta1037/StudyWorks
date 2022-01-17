#!/usr/bin/python
# -*- coding: UTF-8 -*-
from __future__ import unicode_literals  # noqa

import re
import sys
import argparse
import getpass
import requests

try:
    result = requests.get('http://www.baidu.com')
except Exception:
    print('Failed to connect test website!')
    sys.exit()

if result.text.find('eportal') != -1:
    try:
        input = raw_input
    except NameError:
        pass

    pattarn = re.compile(r"href=.*?\?(.*?)'")
    query_str = pattarn.findall(result.text)

    url = 'http://192.168.50.3:8080/eportal/InterFace.do?method=login'
    post_data = {
#********填写学号
        'userId': 'U*********',
#******填写密码
        'password': '******',
        'queryString': query_str,
        'service': '',
        'operatorPwd': '',
        'validcode': '',
    }
    responce = requests.request('POST', url, data=post_data)
    responce.encoding = 'UTF-8'
    res_json = responce.json()

    if res_json['result'] == 'fail':
        print(res_json['message'])
    else:
        print('认证成功')

elif result.text.find('baidu') != -1:
    print('已在线')
else:
    print("Opps, something goes wrong!")
