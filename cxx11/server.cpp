#include "echoS.h"

#include <iostream>

class Server : public CORBA::servant_traits<Example::Echo>::base_type
{
public:
  Server() = default;
  virtual ~Server() {};
  virtual std::string echoString(const std::string& mesg) override;
};

std::string Server::echoString(const std::string& mesg)
{
  std::cout << "Got \"" << mesg << "\", sending it back." << std::endl;
  return mesg;
}

int main(int argc, char** argv)
{
	try {
    IDL::traits<CORBA::ORB>::ref_type orb = CORBA::ORB_init (argc, argv);
    IDL::traits<CORBA::Object>::ref_type obj = orb->resolve_initial_references ("RootPOA");
    IDL::traits<PortableServer::POA>::ref_type poa = IDL::traits<PortableServer::POA>::narrow (obj);

   CORBA::servant_traits<Example::Echo>::ref_type server = CORBA::make_reference<Server> ();

   PortableServer::ObjectId id = poa->activate_object (server);

   std::string sior(orb->object_to_string(server->_this()));
   std::cout << sior << std::endl;

   IDL::traits<PortableServer::POAManager>::ref_type pman = poa->the_POAManager ();

   pman->activate();

   orb->run();
   orb->destroy();
  }
  catch (CORBA::SystemException& ex) {
    std::cerr << "Caught CORBA::" << ex << std::endl;
  }
  catch (CORBA::Exception& ex) {
    std::cerr << "Caught CORBA::Exception: " << ex << std::endl;
  }
  catch (std::exception& ex) {
    std::cerr << "Caught std exception: " << ex.what() << std::endl;
  }
  return 0;
}
