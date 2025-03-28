import math
import random


def calculate_factorial(n):
    if n < 0:
        return "Factorial not defined for negative numbers"
    elif n == 0 or n == 1:
        return 1
    else:
        return n * calculate_factorial(n - 1)

# Function to generate a list of random numbers
def generate_random_numbers(count, start, end):
    return [random.randint(start, end) for _ in range(count)]

# Function to check if a number is prime
def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True

# Function to find the greatest common divisor (GCD)
def find_gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to calculate the Fibonacci sequence up to n terms
def fibonacci_sequence(n):
    sequence = []
    a, b = 0, 1
    for _ in range(n):
        sequence.append(a)
        a, b = b, a + b
    return sequence

# Function to reverse a string
def reverse_string(s):
    return s[::-1]

# Function to count vowels in a string
def count_vowels(s):
    vowels = "aeiouAEIOU"
    return sum(1 for char in s if char in vowels)

# Function to sort a list of numbers
def sort_numbers(numbers):
    return sorted(numbers)

# Function to calculate the area of a circle
def area_of_circle(radius):
    return math.pi * radius ** 2

# Function to find the maximum number in a list
def find_max(numbers):
    return max(numbers)

# Function to find the minimum number in a list
def find_min(numbers):
    return min(numbers)

# Function to calculate the sum of a list of numbers
def calculate_sum(numbers):
    return sum(numbers)

# Function to calculate the average of a list of numbers
def calculate_average(numbers):
    return sum(numbers) / len(numbers) if numbers else 0

# Function to check if a string is a palindrome
def is_palindrome(s):
    return s == s[::-1]

# Function to convert Celsius to Fahrenheit
def celsius_to_fahrenheit(celsius):
    return (celsius * 9/5) + 32

# Function to convert Fahrenheit to Celsius
def fahrenheit_to_celsius(fahrenheit):
    return (fahrenheit - 32) * 5/9

# Function to calculate the power of a number
def calculate_power(base, exponent):
    return base ** exponent

# Function to find the square root of a number
def calculate_square_root(num):
    return math.sqrt(num)

# Main function to demonstrate the above functions
def main():
    print("Factorial of 5:", calculate_factorial(5))
    print("Random numbers:", generate_random_numbers(5, 1, 100))
    print("Is 7 prime?", is_prime(7))
    print("GCD of 48 and 18:", find_gcd(48, 18))
    print("Fibonacci sequence (10 terms):", fibonacci_sequence(10))
    print("Reverse of 'hello':", reverse_string("hello"))
    print("Vowel count in 'hello world':", count_vowels("hello world"))
    print("Sorted numbers:", sort_numbers([5, 2, 9, 1, 5]))
    print("Area of circle (radius 3):", area_of_circle(3))
    print("Max of [1, 2, 3]:", find_max([1, 2, 3]))
    print("Min of [1, 2, 3]:", find_min([1, 2, 3]))
    print("Sum of [1, 2, 3]:", calculate_sum([1, 2, 3]))
    print("Average of [1, 2, 3]:", calculate_average([1, 2, 3]))
    print("Is 'radar' a palindrome?", is_palindrome("radar"))
    print("25°C to Fahrenheit:", celsius_to_fahrenheit(25))
    print("77°F to Celsius:", fahrenheit_to_celsius(77))
    print("2 to the power of 3:", calculate_power(2, 3))
    print("Square root of 16:", calculate_square_root(16))

if __name__ == "__main__":
    main()
