# I got some weird blocking in readline() when calling the Python interpreter from POpen.
# Therefore, it is left-out here.

from subprocess import Popen, PIPE, check_output

print "Starting C++ Server ..."
cxx = Popen("cxx/server", shell=True, stdout=PIPE)
cxx_ior = cxx.stdout.readline()

print "Starting Java Server ..."
java = Popen("java -jar java/server.jar", shell=True, stdout=PIPE)
java_ior = java.stdout.readline()

print "Java -> Java"
print check_output("java -jar java/client.jar "+java_ior, shell=True)

print "Java -> C++"
print check_output("java -jar java/client.jar "+cxx_ior, shell=True)

print "C++ -> Java"
print check_output("cxx/client "+java_ior, shell=True)

print "C++ -> C++"
print check_output("cxx/client "+cxx_ior, shell=True)

cxx.terminate()
java.terminate()