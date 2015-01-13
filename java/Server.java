import Example.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.PortableServer.POA;

import java.util.Properties;

class EchoServer extends EchoPOA {
  public String echoString (String mesg) {
    System.out.println("Got \"" + mesg + "\", sending it back.");
    return mesg;
  }
}

public class Server {

  public static void main(String args[]) {
    try{
      // create and initialize the ORB
      ORB orb = ORB.init(args, null);

      // get reference to rootpoa & activate the POAManager
      POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
      rootpoa.the_POAManager().activate();

      // create servant
      EchoServer server = new EchoServer();

      // get object reference from the servant
      org.omg.CORBA.Object ref = rootpoa.servant_to_reference(server);
          
      System.out.println(ref);

      // wait for invocations from clients
      orb.run();
    } 
        
      catch (Exception e) {
        System.err.println("ERROR: " + e);
        e.printStackTrace(System.out);
      }
          
      System.out.println("Exiting ...");
        
  }
}
 