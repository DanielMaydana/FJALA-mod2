// 

function getCallbacks()
{
    var callbacks = []
    for(let i = 0; i < 6; i++)
    {
        callbacks.push(
        function(){
            console.log('value of i : ',i)
        });
    }
    return callbacks;
}

// const manyCallbacks = getCallbacks();
// const callback1 = manyCallbacks[0];
// callback1();
// getCallbacks().forEach(callbacks => callbacks());