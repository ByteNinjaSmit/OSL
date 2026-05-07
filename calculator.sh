#!/bin/bash
echo "Enter first number:"
read a
echo "Enter operator (+ - * /):"
read op
echo "Enter second number:"
read b
case $op in
  +) result=$(echo "$a + $b" | bc) ;;
  -) result=$(echo "$a - $b" | bc) ;;
  \*) result=$(echo "$a * $b" | bc) ;;
  /) result=$(echo "scale=2; $a / $b" | bc) ;;
  *) echo "Invalid operator"; exit 1 ;;
esac
echo "Result: $result"  