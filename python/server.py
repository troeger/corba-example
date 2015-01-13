import sys
from omniORB import CORBA, PortableServer
import Example, Example__POA

class EchoServer (Example__POA.Echo):
  def echoString(self, mesg):
    print "Got \"%s\", sending it back."%msg
    return mesg

orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)
poa = orb.resolve_initial_references("RootPOA")

ei = EchoServer()
eo = ei._this()

print orb.object_to_string(eo)

poaManager = poa._get_the_POAManager()
poaManager.activate()

orb.run()
