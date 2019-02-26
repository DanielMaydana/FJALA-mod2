// Escribir un objeto que tenga una funcion que cuente las vocales de un string recibido como parametro,
// todos los resultados se tienen que almacenar en una variable del objeto
var myObject = {
    result:[],
    countVowels: function(wordToCount)
    {
        var vowels = 'aeiou';
        var cvow = 0;
        
        for(var i = 0; i < wordToCount.length ; i++)
        {
            if (vowels.indexOf(wordToCount[i]) !== -1) cvow++;  
        }
        this.result.push({word : wordToCount, vowelCount: cvow});
        return cvow;
    }
}

myObject.countVowels("black rebel motorcycle club");
myObject.countVowels("queens of the stone age");
myObject.countVowels("rufus wainwright");
myObject.countVowels("rolling stones");
console.log(myObject.result);