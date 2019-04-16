
(function () {

    function toJSONobject(form) {

        var obj = {};
        var elements = form.querySelectorAll("input, select, textarea");

        for (var i = 0; i < elements.length; ++i) {

            var name = elements[i].name;
            var value = elements[i].value;

            if (name) {
                console.log(elements);
                obj[name] = value;
            }
        }

        return JSON.parse(JSON.stringify(obj))  ;
    }

    function JSONtoTable(jsonObj) {

        // var jsonObj = JSON.parse(jsonStr);
        var htmlGenerated = "<h1>TABLE</h1><br><table border=" + 1 + "><thead><tr>";

        Object.keys(jsonObj).forEach(function(k){
            
            htmlGenerated += "<th>" + k + "</th>";
        });

        htmlGenerated += "</tr></thead><tbody><tr>";

        Object.keys(jsonObj).forEach(function(k){
            
            htmlGenerated += "<th>" + jsonObj[k] + "</th>";
        });

        htmlGenerated += "</tr></tbody></table>";

        console.log(htmlGenerated);

        return htmlGenerated;
    }

    document.addEventListener("DOMContentLoaded", function () {

        var form = document.getElementById("test");
        var output = document.getElementById("output");

        form.addEventListener("submit", function (e) {

            e.preventDefault();

            var json = toJSONobject(this);

            var tableWindow = window.open('');

            tableWindow.document.write(JSONtoTable(json));

        }, false);
    });

})();