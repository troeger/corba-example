# CORBA Echo Server

This is a primitive CORBA echo server (and client) in five languages, straight from the omniORB and Java tutorials:

http://omniorb.sourceforge.net/omni42/omniORB/index.html
http://docs.oracle.com/javase/7/docs/technotes/guides/idl/jidlExample.html

All server applications print their IOR and block then. All client applications take the IOR as command-line argument, connect to that servant and call the echo() routine once. You can now run the different client / servers against each other for some 'CORBA is cool' demonstrations. Check the demo.py script.

Everything is optimized to be small, including the Makefiles. Therefore, the usage of a naming service is omitted.

## Python
- Install omniORB, test that it is available as Python package (import OMNIOrb).
- Go into the ./python subdirectory.
- (Optional) Re-generate stubs and skeletons with "omniorb -bpython ../echo.idl".
- Start the server with "python server.py". It will print the server IOR to be used by the client.
- Start the client with "python client.py <IOR>".

## C++
- Install omniORB.
- Go into the ./cxx subdirectory.
- (Optional) Re-generate stubs and skeletons with "omniorb -bcxx ../echo.idl".
- Call "make" to build client and server.
- Start the server with "./server". It will print the server IOR to be used by the client.
- Start the client with "./client <IOR>".

## C++11
- Obtain and install TAOX11, see http://taox11.remedy.nl
- Go into the ./cxx11 subdirectory.
- Call "brix11 gen build" to generate the GNU makefiles
- Call "make" to build the client and server
- Start the server with "./server". It will print the server IOR to be used by the client.
- Start the client with "./client <IOR>".

## Java
- Install a recent JDK.
- Go into the ./java subdirectory.
- (Optional) Re-generate stubs and skeletons with "idlj -fall ../echo.idl".
- Call "make" to build the JAR files for client and server.
- Run the server with "java -jar server.jar".  It will print the server IOR to be used by the client.
- Run the client with "java -jar client.jar <IOR>".

## Ruby
- Install R2CORBA, see http://www.remedy.nl/en/r2corba
- Go into the ./ruby subdirectory.
- No need to run an IDL compiler
- Start the server with "ruby server.rb". It will print the server IOR to be used by the client.
- Start the client with "ruby client.rb <IOR>".

# Compatibility Matrix

The following table shows which combinations of operating system and ORB product were reported to work with the different language implementations.

|                      | openSuSE 13.2  | MacOS X Yosemite  |
|----------------------|----------------|-------------------|
| omniORB 4.1.7        |                | Python, C++       |
| JDK 1.8              |                | Java              |
| Remedy R2CORBA 1.4.1 | Ruby           |                   |
| Remedy TAOX11 1.3.2  | C++11          |                   |

