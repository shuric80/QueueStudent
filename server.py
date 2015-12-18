#-*- coding:utf-8 -*-
#!/usr/bin/python

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import json
addr ="http://mirgif.com/humor/prikol104.jpg"

data = {"url":"http://mirgif.com/humor/prikol104.jpg",   "test":{"ping":"hello"},"first_name":"ЦУУВПАВЫМАВЫМАЫВПЫВПЫЫВПЫВПЫВП","last_name":"ыпаввпаывпаывпыв", "group":"rf", "rating":"10",
       "len":2,  "table":{"row0":{"date":"10-12-2015","time":"9-30","txt":"Phisics"},
"row1":{"date":"10-12-2015","time":"9-30","txt":"Phisics"}}}

class handler(BaseHTTPRequestHandler):
    def do_GET(self):
        print self.path
        self.send_response(200)
        self.send_header('content-type','application/json')
        self.end_headers()
        self.wfile.write(json.dumps(data))

server = HTTPServer(('localhost',8000),handler)
server.serve_forever()
del server
