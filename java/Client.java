import Example.*;
import org.omg.CORBA.*;

public class Client
{
  static Echo echoImpl;

  public static void main(String args[])
    {
      try
      {
        // create and initialize the ORB
        ORB orb = ORB.init(args, null);

        org.omg.CORBA.Object objRef = orb.string_to_object(args[0]);
        echoImpl = EchoHelper.narrow(objRef);

        System.out.println("Obtained a handle on server object: " + echoImpl);
        System.out.println(echoImpl.echoString("Hello from Java"));

        } 
        catch (Exception e) {
          System.out.println("Error: " + e) ;
          e.printStackTrace(System.out);
        }
    }

}
 