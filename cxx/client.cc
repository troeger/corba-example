#include "echo.hh"
#include <iostream>
using namespace std;

static void hello(Echo_ptr e)
{
  CORBA::String_var src = (const char*) "Hello!";

  CORBA::String_var dest = e->echoString(src);

  cout << "I said, \"" << (char*)src << "\"." << endl
       << "The Echo object replied, \"" << (char*)dest <<"\"." << endl;
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

    Echo_var echoref = Echo::_narrow(obj);

    if (CORBA::is_nil(echoref)) {
      cerr << "Can't narrow reference to type Echo (or it was nil)." << endl;
      return 1;
    }

    for (CORBA::ULong count=0; count<10; count++)
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
