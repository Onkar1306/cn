import socket
s=socket.socket()
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
host=socket.gethostname()
port=12345

s.bind((host,port))
s.listen(5)

while True:
    c,addr = s.accept()
    print('got connection from', addr)
    c.send(b"connection esatablish")
    c.close()


