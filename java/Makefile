all: server.jar client.jar

clean:
	rm -f *.class Example/*.class
	rm -f server.jar client.jar

server.jar: Server.class
	jar cfm server.jar ServerManifest.txt Server.class EchoServer.class Example/*.class

Server.class: Server.java 
	javac Server.java Example/*.java

client.jar: Client.class
	jar cfm client.jar ClientManifest.txt Client.class Example/*.class

Client.class: Client.java 
	javac Client.java Example/*.java



