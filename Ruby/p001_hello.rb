puts "hello"

def g *args
	args
end

def f args
	args
end

x, y, z = ['one', 'two', 'three']

if a = f(x) and b = f(y) and c = f(z) then
	d = g( x, y, z )
end

p d

h = <<END_L
Hello, Ruby.
It's nice to meet you.
END_L

puts h
puts $0
puts $:
puts $$
