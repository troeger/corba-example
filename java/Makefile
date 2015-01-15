STUB_CLASSES = Example/_EchoStub.class Example/Echo.class Example/EchoHelper.class Example/EchoHolder.class Example/EchoOperations.class Example/EchoPOA.class
STUB_SRC = Example/_EchoStub.java Example/Echo.java Example/EchoHelper.java Example/EchoHolder.java Example/EchoOperations.java Example/EchoPOA.java

all: server.jar client.jar

clean:
	rm -f *.class $(STUB_SRC) $(STUB_CLASSES)
	rm -rf Example
	rm -f server.jar client.jar

$(STUB_SRC): ../echo.idl
	idlj -fall ../echo.idl

server.jar: Server.class $(STUB_CLASSES)
	jar cfm server.jar ServerManifest.txt Server.class EchoServer.class $(STUB_CLASSES)

Server.class: Server.java $(STUB_SRC)
	javac Server.java $(STUB_SRC)

client.jar: Client.class $(STUB_CLASSES)
	jar cfm client.jar ClientManifest.txt Client.class $(STUB_CLASSES)

Client.class: Client.java $(STUB_SRC)
	javac Client.java $(STUB_SRC)



