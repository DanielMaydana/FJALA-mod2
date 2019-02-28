
const vocales = ['a', 'e', 'i', 'o', 'u']

function vocalCounter(word) {
	let vocalCounter = 0;
	for (let index = 0; index < word.length; index++) {
		const char = word[index];
		if(charContain(char, vocales)) {
			vocalCounter++;
		}
	}
	return vocalCounter;
}

function charContain(char, vocales) {
	return vocales.some(vocal => vocal === char);
}

console.log(vocalCounter('dogy'));
console.log(vocalCounter('kickstart'));
console.log(vocalCounter('teacher'));
console.log(vocalCounter('man'));
