require 'corba'
CORBA.implement('../echo.idl')

orb = CORBA.ORB_init()

begin
  obj = orb.string_to_object(ARGV[0])

  echo_obj = Example::Echo._narrow(obj)

  message = "Hello from Ruby"
  puts "sending #{message}"
  the_string = echo_obj.echoString(message)
  puts "Got back: <#{the_string}>"

ensure
  orb.destroy()
end
