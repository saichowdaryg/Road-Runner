import socket

s = socket.socket()
host='127.0.0.1'
port=9999

try:
	s.connect((host,port))
except:
	s.close()
	exit()

def senddata(a):
	try:
		s.send(a)
	except:
		exit()

while True:
	ch = raw_input("enter a char: ")
	try:
		senddata(ch)
		if ch == 'p':
			exit()
	except:
		exit()
