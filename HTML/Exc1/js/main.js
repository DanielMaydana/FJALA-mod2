
(function() {

	function toJSONString(form) {
        
        var obj = {};
        var elements = form.querySelectorAll( "input, select, textarea" );
        
        // console.clear();
        // elements.forEach(element => {
        //     console.log(element);
        // });

		for( var i = 0; i < elements.length; ++i ) {
        
            // var element = elements[i];
			var name = elements[i].name;
			var value = elements[i].value;

			if( name ) {
                console.log(name + "/" + value);
				obj[ name ] = value;
			}
		}

		return JSON.stringify( obj );
	}

	document.addEventListener( "DOMContentLoaded", function() {

		var form = document.getElementById( "test" );
		var output = document.getElementById( "output" );

        if(form)
        {
            form.addEventListener( "submit", function( e ) {

                e.preventDefault();
                var json = toJSONString( this );
                window.location.href = "tab1.html";
    
                if(output)
                {
                    output.innerHTML = json;
                }
    
            }, false);
        }

    });

})();