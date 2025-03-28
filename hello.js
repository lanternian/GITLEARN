// hello.js
// This script demonstrates basic JavaScript concepts in 100 lines of code.

// Function to print a greeting
function greet(name) {
    console.log(`Hello, ${name}!`);
}

// Call the greet function
greet("World");

// Function to add two numbers
function add(a, b) {
    return a + b;
}

// Print the sum of two numbers
console.log("Sum:", add(5, 10));

// Function to check if a number is even
function isEven(num) {
    return num % 2 === 0;
}

// Print whether a number is even
console.log("Is 4 even?", isEven(4));

// Array of numbers
const numbers = [1, 2, 3, 4, 5];

// Print each number in the array
numbers.forEach((num) => console.log("Number:", num));

// Map numbers to their squares
const squares = numbers.map((num) => num * num);
console.log("Squares:", squares);

// Filter even numbers
const evens = numbers.filter(isEven);
console.log("Even Numbers:", evens);

// Reduce to calculate the sum of numbers
const total = numbers.reduce((sum, num) => sum + num, 0);
console.log("Total Sum:", total);

// Object representing a person
const person = {
    name: "Alice",
    age: 25,
    greet: function () {
        console.log(`Hi, I'm ${this.name} and I'm ${this.age} years old.`);
    },
};

// Call the greet method of the person object
person.greet();

// Class representing a Rectangle
class Rectangle {
    constructor(width, height) {
        this.width = width;
        this.height = height;
    }

    // Method to calculate area
    area() {
        return this.width * this.height;
    }

    // Method to calculate perimeter
    perimeter() {
        return 2 * (this.width + this.height);
    }
}

// Create a rectangle instance
const rect = new Rectangle(10, 5);
console.log("Rectangle Area:", rect.area());
console.log("Rectangle Perimeter:", rect.perimeter());

// Promise example
const fetchData = () => {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve("Data fetched successfully!");
        }, 1000);
    });
};

// Use the promise
fetchData().then((message) => console.log(message));

// Async/Await example
async function fetchAsyncData() {
    const data = await fetchData();
    console.log("Async/Await:", data);
}

fetchAsyncData();

// Set example
const uniqueNumbers = new Set([1, 2, 3, 3, 4, 4, 5]);
console.log("Unique Numbers:", uniqueNumbers);

// Map example
const userRoles = new Map();
userRoles.set("Alice", "Admin");
userRoles.set("Bob", "User");
console.log("User Roles:", userRoles);

// Loop through a Map
userRoles.forEach((role, user) => {
    console.log(`${user} is a ${role}`);
});

// Date example
const now = new Date();
console.log("Current Date and Time:", now);

// Error handling example
try {
    throw new Error("Something went wrong!");
} catch (error) {
    console.error("Error:", error.message);
}

// Function to calculate factorial
function factorial(n) {
    if (n === 0) return 1;
    return n * factorial(n - 1);
}

console.log("Factorial of 5:", factorial(5));

// Fibonacci sequence
function fibonacci(n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

console.log("Fibonacci of 6:", fibonacci(6));

// Event listener example (for browsers)
// Uncomment the following lines if running in a browser environment
// document.addEventListener("click", () => {
//     console.log("Document clicked!");
// });

// End of the 100-line JavaScript file