all: server.jar

run: server.jar
	java -jar server.jar

clean:
	rm *.class Example/*.class
	rm server.jar

server.jar: Server.class
	jar cfm server.jar Manifest.txt Server.class EchoServer.class Example/*.class

Server.class: Server.java ../echo.idl
	javac Server.java Example/*.java



