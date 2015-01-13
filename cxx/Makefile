LIBS = -lomnithread -lomniORB4 
#-lCOS4 -lCOSDynamic4 -lomniCodeSets4 -lomniConnectionMgmt4 -lomniDynamic4 

all: server

server: server.cc echoSK.cc
	g++ -o server $(LIBS) server.cc echoSK.cc

client: client.cc 
	g++ client.cc 

clean:
	rm -f client server
