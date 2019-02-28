function sayA()
{
    console.log(this.a);
}
var obj = {
    a : 2,
    sayA : sayA
};

obj.sayA();