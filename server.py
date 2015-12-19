#-*- coding:utf-8 -*-
#!/usr/bin/python

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import json
import re

addr ="http://mirgif.com/humor/prikol104.jpg"

LOGIN = "admin"
PASSWORD = "admin"

data = {"url":"http://mirgif.com/humor/prikol104.jpg",
        "first_name":"Pupkin",
        "last_name":"Vasya",
        "group":"rf",
        "rating":"10",
        "attendance":"3",
        "table_busy":{
             "task_0":{"date":"10-12-2015","time":"9-30","txt":"Mathematic"},
             "task_1":{"date":"11-12-2015","time":"4-30","txt":"Phisics"}, 
             "task_2":{"date":"15-11-2019","time":"5-20","txt":"Dance"}
         },
        "table_queued":{
            
             "task_0":{"date":"14-12-2015","time":"9-30","txt":"Mathematic"},
             "task_1":{"date":"14-12-2015","time":"4-30","txt":"Phisics"}, 
        
        }
}

class handler(BaseHTTPRequestHandler):
    def do_GET(self):
        try:
          url_list =  self.path.split('&')
          login = url_list[0].split("=")[1]
          password = url_list[1].split("=")[1]
        except:
            return 'No correct URL'
        if login == LOGIN and password ==PASSWORD:
            self.send_response(200)
            self.send_header('content-type','application/json')
            self.end_headers()
            self.wfile.write(json.dumps(data))
            try:
              if 'queued' in url_list[2].split('='):
                  
                  print 'Add task: %s:task %s'%(login,url_list[2].split('=')[1])
            except:
                pass
             

server = HTTPServer(('localhost',8000),handler)
server.serve_forever()
del server

