// FACTORIAL(x)

puts("This is factorial!");
ok = 0;
while (ok == 0) { 
  puts_("Please input a number between 0 and 20: ");
  geti(input);
  if (input >= 0 && input <= 20) ok = 1;
}
temp = input;
fact = 1;
while (temp > 1) {
  fact = fact * temp;
  temp = temp - 1;
}
puts_("Cool! The factorial of "); puti_(input);
puts_(" is "); puti(fact);
