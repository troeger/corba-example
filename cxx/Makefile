LIBS = -lomnithread -lomniORB4 
STUBS = echoSK.cc 
STUB_HEADERS = echo.hh

all: server client

$(STUBS): ../echo.idl
	omniidl -bcxx ../echo.idl

server: server.cc $(STUBS)
	g++ -o server $(LIBS) server.cc $(STUBS)

client: client.cc $(STUBS)
	g++ -o client $(LIBS) client.cc $(STUBS)

clean:
	rm -f client server $(STUBS) $(STUB_HEADERS)
