import Example.*;
import org.omg.CORBA.*;

public class Client
{
  static Echo echoImpl;
  static String message = "Hello from Java";

  public static void main(String args[])
    {
      try
      {
        // create and initialize the ORB
        ORB orb = ORB.init(args, null);

        org.omg.CORBA.Object objRef = orb.string_to_object(args[0]);
        echoImpl = EchoHelper.narrow(objRef);

        System.out.println("Sending: "+message);
        String result = echoImpl.echoString(message);
        System.out.println("Got back: "+result);

        } 
        catch (Exception e) {
          System.out.println("Error: " + e) ;
          e.printStackTrace(System.out);
        }
    }

}
 