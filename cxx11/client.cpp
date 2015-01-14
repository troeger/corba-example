#include "echoC.h"
#include <iostream>

static void hello(IDL::traits<Example::Echo>::ref_type e)
{
  std::string src ("Hello from C++");
  std::cout << "Sending: " << src << std::endl;
  std::string result = e->echoString(src);
  std::cout << "Got back: " << result << std::endl;
}

int main(int argc, char** argv)
{
  try {
    IDL::traits<CORBA::ORB>::ref_type orb = CORBA::ORB_init (argc, argv);

    if (argc != 2) {
      std::cerr << "Usage: client <object reference>" << std::endl;
      return 1;
    }

    IDL::traits<CORBA::Object>::ref_type obj = orb->string_to_object(argv[1]);

    IDL::traits<Example::Echo>::ref_type echoref = IDL::traits<Example::Echo>::narrow(obj);

    if (!echoref) {
      std::cerr << "Can't narrow reference." << std::endl;
      return 1;
    }

    hello(echoref);
    orb->destroy();
  }
  catch (const CORBA::TRANSIENT& ex) {
    std::cerr << "Caught system exception TRANSIENT -- unable to contact the "
         << "server." << ex << std::endl;
  }
  catch (CORBA::SystemException& ex) {
    std::cerr << "Caught a " << ex << std::endl;
  }
  catch (CORBA::Exception& ex) {
    std::cerr << "Caught CORBA::Exception: " << ex << std::endl;
  }
  catch (std::exception& ex) {
    std::cerr << "Caught std exception: " << ex.what() << std::endl;
  }
  return 0;
}
