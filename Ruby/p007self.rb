puts "I'm in a class " + self.class.to_s
puts "I'm in an object " + self.to_s
print "The object methods are: "
puts self.private_methods.sort
