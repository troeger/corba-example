#include "echo.hh"
#include <iostream>
using namespace std;

static void hello(Example::Echo_ptr e)
{
  CORBA::String_var src = (const char*) "Hello from C++";
  cout << "Sending: " << (char*)src << endl;
  CORBA::String_var result = e->echoString(src);
  cout << "Got back: " << (char*)result << endl;
}

int main(int argc, char** argv)
{
  try {
    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

    if (argc != 2) {
      cerr << "Usage: client <object reference>" << endl;
      return 1;
    }

    CORBA::Object_var obj = orb->string_to_object(argv[1]);

    Example::Echo_var echoref = Example::Echo::_narrow(obj);

    if (CORBA::is_nil(echoref)) {
      cerr << "Can't narrow reference." << endl;
      return 1;
    }

    hello(echoref);
    orb->destroy();
  }
  catch (CORBA::TRANSIENT&) {
    cerr << "Caught system exception TRANSIENT -- unable to contact the "
         << "server." << endl;
  }
  catch (CORBA::SystemException& ex) {
    cerr << "Caught a CORBA::" << ex._name() << endl;
  }
  catch (CORBA::Exception& ex) {
    cerr << "Caught CORBA::Exception: " << ex._name() << endl;
  }
  return 0;
}
