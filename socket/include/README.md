## about socket
tcp连接会等待连接断开，所以即使close也不代表socket断开的 -- 需要确认下原因， 因为这个东西不是用于做连接的socket， 是用来listen的socket（和网上说的情况不太一样）

## class - socket


```
class NioSocket{

public:
socket(domain, sockType, proType) - throw exception if socket() failed
socket(int socketFd);
socket();
~socket() - close socket-fd

v write(const string&)
v read(string&)

shutdown*()

private:
	int socketFd
	// client to connect , server to listen
	
}

```

```
class NConnectSocket: NioSocket{
NConnectSocket(domain, sT, pT):NioSocket(domain,sT,pT)
NConnectSocket(domain, sT, pT, ip, port=defaultPort):NioSocket(..){
	build+dst_addr(ip ,port);
}

~ NConnectSocket(){
	destory();
}
buildTarget(ip, port=defaultPort)  -- connect_build
connect() -- todo : retry-connect
private:
	void build+dst_addr()
	struct sockaddr_in dst_addr
}
```

```
class NServerSocket{
serverSocket()
~serverSocket()
bind()
listen()
accecpt().  -- from this ,we can get the transport socketFd with which we can construct NioSocket
private:
int socketFd;
}
```

```
demo-server
serverSocket();
build()
bind()
listen()
while(1){
	serverRwSocket rwSocket = accept()
	rwSocket.read()
	rwSocket.write()
}

demo-client
clientSocket()
buildTarget()
connect()
rwSocket()
```

## about server

```

```


## about compile dir
