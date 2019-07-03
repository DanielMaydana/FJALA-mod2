//Consider the following code, where we attempt to track how many times a function (printNumber) was called:

function printNumber(num) {
	console.log( "printNumber: " + num );
	this.count++;
}

printNumber.count = 0;

for (let index = 0; index < 5; index++) {
	printNumber(index);
}

// how many times was `foprintNumbero` called?
console.log( printNumber.count );




/* soluton
function printNumber(num) {
	console.log( "printNumber: " + num );
	printNumber.count++;
}

printNumber.count = 0;

for (let index = 0; index < 5; index++) {
	printNumber(index);
}

// how many times was `foprintNumbero` called?
console.log( printNumber.count ); */