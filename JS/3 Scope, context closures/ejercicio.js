
const object = {
	vocales: ['a', 'e', 'i', 'o', 'u'],
	results: [],
	vocalCounter: function (word) {
		let vocalCounter = 0;
		for (let index = 0; index < word.length; index++) {
			const char = word[index];
			if(this.charContain(char)) {
				vocalCounter++;
			}
		}
		this.results.push(`word: ${word} has ${vocalCounter}`);
		return vocalCounter;
	},
	charContain: function (char) {
		return this.vocales.some(vocal => vocal === char);
	}
}


object.vocalCounter('dog');
object.vocalCounter('issue');
object.vocalCounter('nice to have');
object.vocalCounter('clear it all');
object.vocalCounter('forloco');

console.log(object.results);