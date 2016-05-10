$input = ""
$digits = []
$postfix = []
$operators = []

puts "Enter the equation and press ENTER"
$input = gets

def setNum
	if $digits.size > 0 then
		$postfix.push $digits.join
		$digits.clear
	end
end

def setOp(opThis, precNew)
	while $operators.size > 0 do
		opTop = $operators.pop
		if opTop === "("
			$operators.push opTop
			break
		else
			precOld = 0
			if opTop === "-" || opTop === "+"
				precOld = 1
			else
				precOld = 2
			end
			if precOld < precNew
				$operators.push opTop
				break
			else
				$postfix.push opTop
			end
		end
	end
	$operators.push opThis
end

def setParent
	while $operators.size > 0 do
		c = $operators.pop
		if c === "("
			break
		else
			$postfix.push c
		end
	end
end

$input.each_char do |c|
	if c =~ /[0-9]/
		$digits.push c
	else
		setNum	
		if c === "+" || c === "-"
			setOp(c, 1)
		elsif c === "*" || c === "/"
			setOp(c, 2)
		elsif c === "("
			$operators.push c
		elsif c === ")"
			setParent
		elsif c === " " || c === "\n" 
			next
		else
			puts "Only 0-9+-*/() are supported, please check your input"
			exit 1
		end
	end
end
setNum
while $operators.size > 0 do
	$postfix.push $operators.pop
end

print "Your input is: #{$input}"
print "Postfix form is: #{$postfix}\n"

$output = []

$postfix.each do |i|
	if i === "0"
		$output.push 0
	else
		num0 = i.to_i
		if num0 != 0
			$output.push num0
		else
			num2 = $output.pop
			num1 = $output.pop

			print "Calculating #{num2} #{num1} #{i}\n"
			case i
			when "+"
				interAns = num1 + num2
			when "-"
				interAns = num1 - num2
			when "*"
				interAns = num1 * num2
			when "/"
				if num2 != 0
					interAns = num1 / num2
				else
					puts "Division by zero!"
					exit 1
				end
			else
				interAns = 0
			end
			$output.push interAns
		end
	end
end

print "The answer is: #{$output.pop}\n"
