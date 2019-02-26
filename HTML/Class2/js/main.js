var submit = document.getElementById("submitId");


var newWindow = window.open();
newWindow.document.write(
    "<html><head><script type='text/javascript' src='yourCode.js'></scr"+"ipt></head><body>Your content</body></html>"
);
newWindow.document.close();