input = "22+2-8"
digits = []
operator = ""
postfix = []

def addOperator(op)
	postfix.push operator if operator
	operator = op
end

puts "Input the equation and press ENTER."

input.each_char do |c|
	print c
	if c =~ /\d/
		puts "Digit"
		digits.push c	
	else
		postfix.push(digits.join)
		digits.clear

		if c === '+'
			puts "Plus"
			addOperator(c)
		elsif c === '-'
			puts "Minus"
			addOperator(c)
		else
			puts "Else"
		end
	end
end

puts input
print stack
