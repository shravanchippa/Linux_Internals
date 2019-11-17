all: server client

server : threadSockServer.c send_recv.c
	gcc -o server  threadSockServer.c send_recv.c -lpthread
client : threadSockClient.c send_recv.c
	gcc -o client -lpthread threadSockClient.c send_recv.c
