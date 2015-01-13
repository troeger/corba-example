all: server.jar client.jar

clean:
	rm *.class Example/*.class
	rm server.jar client.jar

server.jar: Server.class
	jar cfm server.jar ServerManifest.txt Server.class EchoServer.class Example/*.class

Server.class: Server.java ../echo.idl
	javac Server.java Example/*.java

client.jar: Client.class
	jar cfm client.jar ClientManifest.txt Client.class Example/*.class

Client.class: Client.java ../echo.idl
	javac Client.java Example/*.java



