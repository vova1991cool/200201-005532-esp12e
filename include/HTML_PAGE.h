#ifndef _HTML_PAGE_h
#define _HTML_PAGE_h

const char HTML_PAGE[] = "<html>\n"
"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
"<title>Esp8266GSM Settings</title>\n"
"<style>\n"
"    *, *:before, *:after {\n"
"        box-sizing: border-box;\n"
"    }\n"
"\n"
"    body{\n"
"        background-color: #8DA1BF;\n"
"        margin: 0px;\n"
"    }\n"
"\n"
"    .w3-sidebar {\n"
"        height: 100%;\n"
"        width: 20%;\n"
"        background-color: #fff;\n"
"        position: fixed !important;\n"
"        z-index: 1;\n"
"        overflow: auto;\n"
"        display: inherit;\n"
"    }\n"
"\n"
"    .w3-bar-block .w3-dropdown-hover .w3-bar-block .w3-dropdown-click .w3-dropdown-content {\n"
"        min-width: 100%\n"
"    }\n"
"\n"
"    .w3-bar-block .w3-dropdown-hover .w3-button, .w3-bar-block .w3-dropdown-click .w3-button {\n"
"        width: 100%;\n"
"        text-align: left;\n"
"        padding: 8px 16px\n"
"    }\n"
"    .w3-black {\n"
"        color: #fff !important;\n"
"        background-color: #66738d !important\n"
"    }\n"
"\n"
"    .w3-bar-block .w3-bar-item {\n"
"        width: 100%;\n"
"        display: block;\n"
"        padding: 8px 16px;\n"
"        text-align: left;\n"
"        border: none;\n"
"        white-space: normal;\n"
"        float: none;\n"
"        outline: 0\n"
"    }\n"
"    .w3-bar-block.w3-center .w3-bar-item {\n"
"        text-align: center\n"
"    }\n"
"    .w3-card, .w3-card-2 {\n"
"        box-shadow: 0 2px 5px 0 rgba(0, 0, 0, 0.16), 0 2px 10px 0 rgba(0, 0, 0, 0.12)\n"
"    }\n"
"    .w3-bar .w3-bar-item {\n"
"        padding: 8px 16px;\n"
"        float: left;\n"
"        width: auto;\n"
"        border: none;\n"
"        display: block;\n"
"        outline: 0\n"
"    }\n"
"    .w3-button {\n"
"        border: none;\n"
"        display: inline-block;\n"
"        padding: 8px 16px;\n"
"        vertical-align: middle;\n"
"        overflow: hidden;\n"
"        text-decoration: none;\n"
"        color: inherit;\n"
"        background-color: inherit;\n"
"        text-align: center;\n"
"        cursor: pointer;\n"
"        white-space: nowrap\n"
"    }\n"
"\n"
"    .w3-button:hover {\n"
"        color: #000 !important;\n"
"        background-color: #ccc !important\n"
"    }\n"
"\n"
"    .w3-button:disabled {\n"
"        cursor: not-allowed;\n"
"        opacity: 0.3\n"
"    }\n"
"    .w3-container:after, .w3-container:before {\n"
"        content: \"\";\n"
"        display: table;\n"
"        clear: both\n"
"    }\n"
"    .w3-container {\n"
"        padding: 0.01em 16px;\n"
"        background-color: #8DA1BF;\n"
"        display: table;\n"
"    }\n"
"    .w3-animate-opacity {\n"
"        animation: opac 0.5s\n"
"    }\n"
"    @keyframes opac {\n"
"        from {\n"
"            opacity: 0\n"
"        }\n"
"        to {\n"
"            opacity: 1\n"
"        }\n"
"    }\n"
"    .w3-red, .w3-hover-red:hover {\n"
"        color: #fff !important;\n"
"        background-color: #f44336 !important\n"
"    }\n"
"    .textField {\n"
"        box-shadow: inset 0 1px 3px rgba(0, 0, 0, 2);\n"
"        border: 1px solid #ccc;\n"
"        font-size: 20px;\n"
"        color: #007e19;\n"
"        width: 10em;\n"
"        font-weight: bold;\n"
"        background-color: #8DA1BF;\n"
"        display: block;\n"
"        margin: 1px 0 5px 0;\n"
"    }\n"
"    label {\n"
"        font-size: 16px;\n"
"        display: block;\n"
"    }\n"
"    td {\n"
"        padding: 30px;\n"
"        width: 10em;\n"
"        display: inherit;\n"
"        vertical-align: inherit;\n"
"    }\n"
"    .btns {\n"
"        background-color: #8DA1BF;\n"
"        border: none;\n"
"        color: #4B5056;\n"
"        margin-top: 30px;\n"
"        padding: 10px 50px;\n"
"        text-align: center;\n"
"        text-decoration: none;\n"
"        display: inline-block;\n"
"        font-weight: bold;\n"
"        font-size: 18px;\n"
"        -webkit-transition-duration: 0.4s; /* Safari */\n"
"        transition-duration: 0.3s;\n"
"        cursor: pointer;\n"
"    }\n"
"    .btns:hover {\n"
"        background-color: #afcae8;\n"
"        color: #4B5056;\n"
"    }\n"
"</style>\n"
"<body>\n"
"\n"
"<div class=\"w3-sidebar w3-bar-block w3-black w3-card\" style=\"width:20%\">\n"
"    <h5 class=\"w3-bar-item\">Esp8266GSM Settings</h5>\n"
"    <button class=\"w3-bar-item w3-button tablink\" onclick=\"openLink(event, 'netSet')\"><b>Network Settings</b></button>\n"
"    <button class=\"w3-bar-item w3-button tablink\" onclick=\"openLink(event, 'gsmSet')\"><b>GSM connection settings</b></button>\n"
"    <button class=\"w3-bar-item w3-button tablink\" onclick=\"openLink(event, 'callSet')\"><b>Calling Settings</b></button>\n"
"</div>\n"
"\n"
"<div style=\"margin-left:20%\">\n"
"\n"
"    <div id=\"netSet\" class=\"w3-container tab w3-animate-opacity\" style=\"display:none\">\n"
"    </div>\n"
"\n"
"    <div id=\"gsmSet\" class=\"w3-container tab w3-animate-opacity\" style=\"display:none\">\n"
"    </div>\n"
"\n"
"    <div id=\"callSet\" class=\"w3-container tab w3-animate-opacity\" style=\"display:none\">\n"
"    </div>\n"
"\n"
"</div>\n"
"\n"
"<script>\n"
"    let data = {\n"
"        arr:['Mode','Ssid','Pass','Host','Gateway','Recive','Transmit','Phone','Voice','USSD'],\n"
"        contSrt:[1,5,7,10],\n"
"        load:function () {\n"
"            fetch('/getData').then(function (response) {\n"
"                if (response.status !== 200) {\n"
"                    console.log('Looks like there was a problem. Status Code: ' + response.status);\n"
"                    return;\n"
"                }\n"
"                response.json().then(function (e) {\n"
"                    data.json = e;\n"
"                    console.log(data.json);\n"
"                    data.prepPage(data.json);\n"
"                })\n"
"            });\n"
"        },\n"
"        json:[0, \"ESP8266Default\", \"\", \"192.168.1.1\",\"192.168.1.1\", 12, 14, \"0965622167\", 0, \"\"],\n"
"        send:function(){\n"
"            if(!('json' in data)) return;\n"
"            let switchFunc = function(it, i){\n"
"                switch (i) {\n"
"                    case 0:\n"
"                        return document.getElementsByName(it)[0].selectedIndex;\n"
"                    case 5:\n"
"                    case 6:\n"
"                    case 8:\n"
"                        return parseInt(document.getElementsByName(it)[0].value);\n"
"                    default:\n"
"                        return document.getElementsByName(it)[0].value;\n"
"                }\n"
"            };\n"
"            data.arr.forEach(function (item, i) {\n"
"                data.json[i] = switchFunc(item, i);\n"
"                console.log(data.json);\n"
"            });\n"
"            fetch('/saveData', {method:'POST', headers:{'Content-Type': 'application/json'}, body: JSON.stringify(data.json)}).then(function (a) {\n"
"                console.log(a);\n"
"                alert('Settings send!');\n"
"            })\n"
"        },\n"
"\n"
"        prepPage:function (json) {\n"
"            Array.prototype.slice.call(document.getElementsByClassName('tab')).forEach(function (item, i) {\n"
"                let table = document.createElement('table');\n"
"                let options = json[0] ? '<option>AP</option><option selected>Station</option>':'<option selected>AP</option><option>Station</option>';\n"
"                let tr =  table.appendChild(document.createElement('tr'));\n"
"                let td = tr.appendChild(document.createElement('td'));\n"
"                for (let ind = data.contSrt[i]; ind < data.contSrt[i + 1]; ind++){\n"
"                    let lb = data.arr[ind];\n"
"                    let val = json[data.arr.indexOf(lb)];\n"
"                    td.insertAdjacentHTML('beforeend', lb + ':<input class=\\'textField\\' name=\\'' + lb + '\\' type=\\'text\\' value=\\'' + val + '\\'>');\n"
"                }\n"
"                if (i == 0) td.insertAdjacentHTML('afterbegin', data.arr[i] + ':<select name=\\'' + data.arr[i] + '\\' class=\"textField\">' + options + '</select>');\n"
"               // td = table.appendChild(document.createElement('td'));\n"
"                td.insertAdjacentHTML('beforeend', (function(){\n"
"                    let buttonsData = ['Save','Reset','data.send()', 'document.location.reload(true)'];\n"
"                    let btnTag = '';\n"
"                    for (let i = 0; i < 2; i++){\n"
"                        btnTag += '<input type=\\'button\\' class=\\'btns\\' value=\\'' + buttonsData[i] + '\\' onclick=\\'' + buttonsData[2 + i] + '\\'>';\n"
"                    }\n"
"                    btnTag += '</div>';\n"
"                    return '<div>' + btnTag;\n"
"                })());\n"
"                item.append(table);\n"
"            });\n"
"        }\n"
"    };\n"
"    // data.load();\n"
"    data.prepPage(data.json);\n"
"\n"
"    function openLink(evt, animName) {\n"
"        var i, x, tablinks;\n"
"        x = document.getElementsByClassName(\"tab\");\n"
"        for (i = 0; i < x.length; i++) {\n"
"            x[i].style.display = \"none\";\n"
"        }\n"
"        tablinks = document.getElementsByClassName(\"tablink\");\n"
"        for (i = 0; i < x.length; i++) {\n"
"            tablinks[i].className = tablinks[i].className.replace(\" w3-red\", \"\");\n"
"        }\n"
"        document.getElementById(animName).style.display = \"block\";\n"
"        evt.currentTarget.className += \" w3-red\";\n"
"    }\n"
"</script>\n"
"</body>\n"
"</html>\n";

#endif