g++ socketTest.cpp -I../src/transport -L../src/transport -lsocket -o server
g++ socketClient.cpp -I../src/transport -L../src/transport -lsocket -o client
