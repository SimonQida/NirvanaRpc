## about socket
tcp连接会等待连接断开，所以即使close也不代表socket断开的 -- 需要确认下原因， 因为这个东西不是用于做连接的socket， 是用来listen的socket（和网上说的情况不太一样）

在四次挥手的时候服务器端会在发送最后的fin数据之后 再等待两个单位时间的时间，为了确保fin包确实被客户端接收，所以需要给服务端的socket加上这个reuse的选项。


## class - Nio
充当底层io的基本类

```
class Nio{
public:
Nio()
~Nio()
v write(const string&)
v read(string&)
}
```

## class - socket
负责底层的网络连接以及socket层面的数据运输

todo：

 + 开放各种配置条件，供NioSocket配置 @2
 + 实现多次尝试连接
 + 实现非阻塞io

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
accecpt()   -- from this ,we can get the transport socketFd with which we can construct NioSocket
private:
int socketFd;
struct sockaddr_in listen_addr
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

## about transport
负责上层数据到下层通信的读取格式，??避免粘包??@1
@1 通过在transport层每次读取数据时，都能显式或者隐式的指明数据长度，来做到避免粘包

通过shared_ptr进行传参， 是否可以使用引用，即(shared_ptr<NioBase>& NioPtr)@3

```
class Ntransport{
	writeSlow()
	readSlow()
	write(string& data, int len)  -- provide for write*
	read(string& data, int len)   -- provide for read*
	writeFlush();
	readFlush();
	
	batch of write* and read* to provide interface for upper layer
	
	private:
	char readBuf[bufSize];   //ring buf
	char writeBuf[bufSize];
	NioSocket* transportFd;
	int end;
	int cur;
	int readLeftSize;
	int writeLeftSize;
}

Ntransport::write(data, len)
	if(writeLeftSize < len)
		writeSlow();
		set pointer
	else
		fill data to buf
		set pointer;

Ntransport::read(data, len)
	if(readLeftSize < len)
		readSlow();
		set pointer;
	else
		get data from buf
		set pointer;

Ntransport::writeInt(data)
	write(data, 4)
		
```

## about Protocol

负责将要发送的用户结构数据序列化以及反序列化

```
class Nprotocol{
	Nprotocol(Ntransport());
	callMethod();
	
};
```

#### how to gtest
让NTransport 使用 Nio 当作构造的参数，从Nio中派生一个不涉及socket的子类NioVoid（or NioTest)，这样在gtest中生成一个NioTest，然后可以不通过socket这种麻烦的中介来测试Transport的行为逻辑NioSocket 从Nio中派生

## about client


```

```

## about server

```

```

## pic a demo for rpc-client and rpc-server
rpc-client demo:

```
NConnectSocket clientSocket("127.0.0.1", 11234);  -- set up info about ip and port
BufferedTransport BTrans(clientSocket);       -- declare data-buf way
TextMessage TMessage(BTrans);   -- declare using tab and text to serialize
calculateClient client(TMessage);   -- now we construct a client with calculate property
```

rpc-server demo:

```

```

## about compile dir

#### compile static lib in g++

static lib is compiled by these code.
first:
```
g++ -c 
```
to complie so we get the .o files, and use
```
ar cr libxxx.a xxx.o xxx2.o
```
to get the libxxx.a, and we can use these static lib in bin or other libs
 
#### CMakeLists.txt

###### project structure:

```
.
├── CMakeLists.txt
├── build
├── cmake_install.cmake
├── compiler
├── doc
├── lib
├── socket
├── source
├── test
├── tmp_log
└── tutorial
```

project root dir's CMake just includes sub-dirs and declares details about the compile

###### lib structure:

```
.
├── CMakeFiles
├── CMakeLists.txt
├── Makefile
├── cmake_install.cmake
├── gtest.    gtest code for unit test
├── src.   src lib code
└── test.   functional-normal test code
```

how to cmake:

+ src:
+ gtest:
+ test:


