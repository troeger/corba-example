require 'corba/poa'
CORBA.implement('../echo.idl', {}, CORBA::IDL::SERVANT_INTF)

class MyEcho < POA::Example::Echo
  def initialize()
  end

  def echoString(instr)
    instr
  end
end #of servant MyEcho

begin
  orb = CORBA.ORB_init()
  obj = orb.resolve_initial_references('RootPOA')
  root_poa = PortableServer::POA._narrow(obj)
  poa_man = root_poa.the_POAManager
  poa_man.activate
  echo_srv = MyEcho.new()
  echo_obj = echo_srv._this()
  echo_ior = orb.object_to_string(echo_obj)
  puts echo_ior
  orb.run
ensure
  orb.destroy()
end
